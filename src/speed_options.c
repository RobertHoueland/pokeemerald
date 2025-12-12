#include "global.h"
#include "bg.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gpu_regs.h"
#include "option_menu.h"
#include "constants/rgb.h"
#include "international_string_util.h"
#include "sprite.h"
#include "strings.h"
#include "gba/m4a_internal.h"

// Lots of redefinitions of functions from options_menu.c

// Define task data indices
#define tMenuSelection data[0]
#define tTextSpeed data[1]
#define tMoveSpeed data[2]

// Define menu item indices
enum
{
    SPEEDMENU_TEXTSPEED,
    SPEEDMENU_MOVESPEED,
    SPEEDMENU_BACK,
    SPEEDMENU_COUNT
};

// Define Y positions for menu items
#define YPOS_TEXTSPEED  (SPEEDMENU_TEXTSPEED * 16)
#define YPOS_MOVESPEED  (SPEEDMENU_MOVESPEED * 16)
#define YPOS_BACK       (SPEEDMENU_BACK * 16)

// Function declarations
static void Task_SpeedOptionsMenuFadeIn(u8 taskId);
static void Task_SpeedOptionsMenuProcessInput(u8 taskId);
static void Task_SpeedOptionsMenuFadeOut(u8 taskId);
static void HighlightSpeedOptionMenuItem(u8 selection);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8 MoveSpeed_ProcessInput(u8 selection);
static void MoveSpeed_DrawChoices(u8 selection);
static void DrawHeaderText(void);
static void DrawSpeedOptionMenuTexts(void);
static void DrawBgWindowFrames(void);

// Define menu item names
static const u8 *const sSpeedOptionMenuItemsNames[SPEEDMENU_COUNT] =
{
    [SPEEDMENU_TEXTSPEED] = COMPOUND_STRING("TEXT SPEED"),
    [SPEEDMENU_MOVESPEED] = COMPOUND_STRING("MOVEMENT SPEED"),
    [SPEEDMENU_BACK]      = COMPOUND_STRING("BACK"),
};

static const u8 gText_Option[]             = _("OPTION");
static const u8 gText_TextSpeedSlow[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW");
static const u8 gText_TextSpeedMid[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST");
static const u8 gText_TextSpeedFast[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ZOOM");
static const u8 gText_MoveSpeedDefault[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}DEFAULT");
static const u8 gText_MoveSpeedFast[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST");

// Use same window templates and BG templates as main option menu
extern const struct WindowTemplate sOptionMenuWinTemplates[];
extern const struct BgTemplate sOptionMenuBgTemplates[];
extern const u16 sOptionMenuBg_Pal[];
extern const u16 sOptionMenuText_Pal[];

static bool8 sArrowPressed = FALSE;

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitSpeedOptionsMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, 2);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawSpeedOptionMenuTexts();
        gMain.state++;
        break;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_SpeedOptionsMenuFadeIn, 0);

        gTasks[taskId].tMenuSelection = 0;
        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tMoveSpeed = gSaveBlock2Ptr->optionsMoveSpeed;

        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
        MoveSpeed_DrawChoices(gTasks[taskId].tMoveSpeed);
        HighlightSpeedOptionMenuItem(gTasks[taskId].tMenuSelection);

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_SpeedOptionsMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_SpeedOptionsMenuProcessInput;
}

static void Task_SpeedOptionsMenuProcessInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == SPEEDMENU_BACK)
        {
            // Save the speed option values and return to main menu
            gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
            gSaveBlock2Ptr->optionsMoveSpeed = gTasks[taskId].tMoveSpeed;
            
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_SpeedOptionsMenuFadeOut;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        // Save the speed option values and return to main menu
        gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
        gSaveBlock2Ptr->optionsMoveSpeed = gTasks[taskId].tMoveSpeed;
        
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_SpeedOptionsMenuFadeOut;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = SPEEDMENU_BACK;
        HighlightSpeedOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < SPEEDMENU_BACK)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightSpeedOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case SPEEDMENU_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);

            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
            break;
        case SPEEDMENU_MOVESPEED:
            previousOption = gTasks[taskId].tMoveSpeed;
            gTasks[taskId].tMoveSpeed = MoveSpeed_ProcessInput(gTasks[taskId].tMoveSpeed);

            if (previousOption != gTasks[taskId].tMoveSpeed)
                MoveSpeed_DrawChoices(gTasks[taskId].tMoveSpeed);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_SpeedOptionsMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitOptionMenu); // Return to main option menu
    }
}

static void HighlightSpeedOptionMenuItem(u8 index)
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, DISPLAY_WIDTH - 16));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(index * 16 + 40, index * 16 + 56));
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection)
{
    u8 styles[3];
    s32 widthSlow, widthMid, widthFast, xMid;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, YPOS_TEXTSPEED, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);

    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, YPOS_TEXTSPEED, styles[1]);

    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), YPOS_TEXTSPEED, styles[2]);
}

static u8 MoveSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void MoveSpeed_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_MoveSpeedDefault, 104, YPOS_MOVESPEED, styles[0]);
    DrawOptionMenuChoice(gText_MoveSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_MoveSpeedFast, 198), YPOS_MOVESPEED, styles[1]);
}

static void DrawHeaderText(void)
{
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawSpeedOptionMenuTexts(void)
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < SPEEDMENU_COUNT; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sSpeedOptionMenuItemsNames[i], 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawBgWindowFrames(void)
{
    #define TILE_TOP_CORNER_L 0x1A2
    #define TILE_TOP_EDGE     0x1A3
    #define TILE_TOP_CORNER_R 0x1A4
    #define TILE_LEFT_EDGE    0x1A5
    #define TILE_RIGHT_EDGE   0x1A7
    #define TILE_BOT_CORNER_L 0x1A8
    #define TILE_BOT_EDGE     0x1A9
    #define TILE_BOT_CORNER_R 0x1AA

    // Draw title window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    // Draw options list window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

extern void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style);