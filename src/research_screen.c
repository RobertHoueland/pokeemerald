#include "global.h"
#include "bg.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "research.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define RESEARCH_BORDER_TILE           0x200
#define RESEARCH_BORDER_PALETTE        14
#define RESEARCH_SCROLL_TAG            0x5253
#define RESEARCH_PROTO_VISIBLE         7
#define RESEARCH_MUTATION_LOG_VISIBLE  6
#define RESEARCH_CONTENT_WIDTH         224
#define RESEARCH_SCROLLBAR_X           216
#define RESEARCH_SCROLLBAR_TOP         20
#define RESEARCH_SCROLLBAR_HEIGHT      80
#define RESEARCH_SCROLLBAR_WIDTH       4
#define RESEARCH_SCROLLBAR_MIN_THUMB   8

// Window IDs
enum
{
    WIN_RESEARCH_HEADER,
    WIN_RESEARCH_CONTENT,
};

// Page IDs
enum
{
    RESEARCH_PAGE_SUMMARY,
    RESEARCH_PAGE_MUTATIONS,
    RESEARCH_PAGE_MUTATION_LOG,
    RESEARCH_PAGE_PROTO_LEGENDS,
    RESEARCH_PAGE_COUNT,
};

struct ResearchScreenState
{
    u8 page;
    u8 categoryCursor;
    bool8 showingDescription;
    u8 protoCursor;
    u16 protoScroll;
    u8 scrollArrowTaskId;
};

struct ResearchPageDefinition
{
    const u8 *title;
    void (*draw)(void);
};

static void Task_ResearchFadeIn(u8 taskId);
static void Task_ResearchInput(u8 taskId);
static void Task_ResearchFadeOut(u8 taskId);
static void DrawResearchScreen(void);
static void DrawSummaryPage(void);
static void DrawMutationDetailsPage(void);
static void DrawMutationLogPage(void);
static void DrawProtoLegendsPage(void);
static void DrawResearchScrollBar(u16 scroll, u8 count);

EWRAM_DATA static struct ResearchScreenState sResearchScreen = {0};

static const u8 sText_Research[] = _("RESEARCH");
static const u8 sText_Summary[] = _("SUMMARY");
static const u8 sText_MutationDetails[] = _("MUTATION DETAILS");
static const u8 sText_MutationLog[] = _("MUTATION LOG");
static const u8 sText_RecentMutationsRecorded[] = _("RECENT MUTATIONS RECORDED");
static const u8 sText_ProtoLegends[] = _("PROTO LEGENDS");
static const u8 sText_NoResearch[] = _("NO RESEARCH RECORDED");
static const u8 sText_NoRecentMutations[] = _("NO RECENT MUTATIONS");
static const u8 sText_Unknown[] = _("???");
static const u8 sText_Slash[] = _("/");
static const u8 sText_Colon[] = _(":");
static const u8 sText_Space[] = _(" ");
static const u8 sText_Separator[] = _(" - ");
static const u8 sText_UnknownTime[] = _("--:--");
static const u8 sText_LevelPrefix[] = _(" Lv.");
static const u8 sText_UnknownLevel[] = _("??");
static const u8 sText_LogNameColor[] = _("{COLOR BLUE}{SHADOW LIGHT_BLUE}");
static const u8 sText_LogMutationColor[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
static const u8 sText_LogNeutralColor[] = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
static const u8 sText_TotalMutations[] = _("TOTAL MUTATIONS");
static const u8 sText_TypesDiscovered[] = _("TYPES DISCOVERED");
static const u8 sText_StatsDiscovered[] = _("STATS DISCOVERED");
static const u8 sText_ProtoLines[] = _("PROTO LEGEND LINES");
static const u8 sText_Footer[] = _("L/R: PAGE   A: DETAILS");
static const u8 sText_MutationFooter[] = _("L/R: PAGE");
static const u8 sText_ListFooter[] = _("L/R: PAGE");
static const u8 sText_DescriptionFooter[] = _("B: RETURN");

static const u8 *const sMutationCategoryNames[RESEARCH_MUTATION_CATEGORY_COUNT] =
{
    [RESEARCH_MUTATION_STAT] = COMPOUND_STRING("STAT"),
    [RESEARCH_MUTATION_TYPE] = COMPOUND_STRING("TYPE"),
    [RESEARCH_MUTATION_ABILITY] = COMPOUND_STRING("ABILITY"),
    [RESEARCH_MUTATION_NATURE] = COMPOUND_STRING("NATURE"),
    [RESEARCH_MUTATION_MOVE] = COMPOUND_STRING("MOVE"),
    [RESEARCH_MUTATION_FORM] = COMPOUND_STRING("FORM"),
    [RESEARCH_MUTATION_SHINY] = COMPOUND_STRING("SHINY"),
    [RESEARCH_MUTATION_POKERUS] = COMPOUND_STRING("POKERUS"),
};

static const u8 *const sMutationCategoryDescriptions[RESEARCH_MUTATION_CATEGORY_COUNT] =
{
    [RESEARCH_MUTATION_STAT] = COMPOUND_STRING("Strengthens one of the body's\ncore attributes."),
    [RESEARCH_MUTATION_TYPE] = COMPOUND_STRING("Manifests an additional\nelemental affinity."),
    [RESEARCH_MUTATION_ABILITY] = COMPOUND_STRING("Awakens dormant ability potential."),
    [RESEARCH_MUTATION_NATURE] = COMPOUND_STRING("Alters the POKéMON's\nunderlying temperament."),
    [RESEARCH_MUTATION_MOVE] = COMPOUND_STRING("Produces an unexpected move."),
    [RESEARCH_MUTATION_FORM] = COMPOUND_STRING("Reshapes the POKéMON into a\nregional form."),
    [RESEARCH_MUTATION_SHINY] = COMPOUND_STRING("Changes the POKéMON's coloration."),
    [RESEARCH_MUTATION_POKERUS] = COMPOUND_STRING("A rare mutation associated with\nbeneficial viral growth."),
};

static const u8 *const sMutationResultNames[MUTATION_CHOSEN_POKERUS + 1] =
{
    [MUTATION_CHOSEN_NONE] = COMPOUND_STRING("???"),
    [MUTATION_CHOSEN_HP] = COMPOUND_STRING("HP"),
    [MUTATION_CHOSEN_ATK] = COMPOUND_STRING("ATTACK"),
    [MUTATION_CHOSEN_DEF] = COMPOUND_STRING("DEFENSE"),
    [MUTATION_CHOSEN_SPATK] = COMPOUND_STRING("SP. ATK"),
    [MUTATION_CHOSEN_SPDEF] = COMPOUND_STRING("SP. DEF"),
    [MUTATION_CHOSEN_SPEED] = COMPOUND_STRING("SPEED"),
    [MUTATION_CHOSEN_TYPE] = COMPOUND_STRING("TYPE"),
    [MUTATION_CHOSEN_ABILITY] = COMPOUND_STRING("ABILITY"),
    [MUTATION_CHOSEN_NATURE] = COMPOUND_STRING("NATURE"),
    [MUTATION_CHOSEN_MOVE] = COMPOUND_STRING("MOVE"),
    [MUTATION_CHOSEN_FORM] = COMPOUND_STRING("FORM"),
    [MUTATION_CHOSEN_SHINY] = COMPOUND_STRING("SHINY"),
    [MUTATION_CHOSEN_POKERUS] = COMPOUND_STRING("POKERUS"),
};

static const u8 *const sStatNames[NUM_STATS] =
{
    [STAT_HP] = COMPOUND_STRING("HP"),
    [STAT_ATK] = COMPOUND_STRING("ATTACK"),
    [STAT_DEF] = COMPOUND_STRING("DEFENSE"),
    [STAT_SPEED] = COMPOUND_STRING("SPEED"),
    [STAT_SPATK] = COMPOUND_STRING("SP. ATK"),
    [STAT_SPDEF] = COMPOUND_STRING("SP. DEF"),
};

static const enum Stat sDisplayedStats[NUM_STATS] =
{
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
};

static const u8 *const sProtoLineNames[RESEARCH_PROTO_LINE_COUNT] =
{
    [RESEARCH_PROTO_LINE_MEWTWO] = COMPOUND_STRING("MEWTWO LINE"),
    [RESEARCH_PROTO_LINE_BIRDS] = COMPOUND_STRING("LEGENDARY BIRDS LINE"),
    [RESEARCH_PROTO_LINE_BEASTS] = COMPOUND_STRING("LEGENDARY BEASTS LINE"),
    [RESEARCH_PROTO_LINE_TOWER] = COMPOUND_STRING("TOWER DUO LINE"),
    [RESEARCH_PROTO_LINE_REGI] = COMPOUND_STRING("REGI LINE"),
    [RESEARCH_PROTO_LINE_EON] = COMPOUND_STRING("EON DUO LINE"),
    [RESEARCH_PROTO_LINE_WEATHER] = COMPOUND_STRING("ANCIENT LEGEND LINE"),
    [RESEARCH_PROTO_LINE_LAKE] = COMPOUND_STRING("LAKE GUARDIAN LINE"),
    [RESEARCH_PROTO_LINE_CREATION] = COMPOUND_STRING("CREATION LINE"),
    [RESEARCH_PROTO_LINE_DISTORTION] = COMPOUND_STRING("DISTORTION LINE"),
    [RESEARCH_PROTO_LINE_RELIC] = COMPOUND_STRING("RELIC LINE"),
    [RESEARCH_PROTO_LINE_SWORDS] = COMPOUND_STRING("SWORDS OF JUSTICE LINE"),
    [RESEARCH_PROTO_LINE_FORCES] = COMPOUND_STRING("FORCES OF NATURE LINE"),
    [RESEARCH_PROTO_LINE_TAO] = COMPOUND_STRING("TAO LINE"),
    [RESEARCH_PROTO_LINE_KYUREM] = COMPOUND_STRING("KYUREM LINE"),
    [RESEARCH_PROTO_LINE_AURA] = COMPOUND_STRING("AURA TRIO LINE"),
    [RESEARCH_PROTO_LINE_TAPU] = COMPOUND_STRING("TAPU LINE"),
    [RESEARCH_PROTO_LINE_TYPE_NULL] = COMPOUND_STRING("TYPE: NULL LINE"),
    [RESEARCH_PROTO_LINE_COSMOG] = COMPOUND_STRING("COSMOG LINE"),
    [RESEARCH_PROTO_LINE_NECROZMA] = COMPOUND_STRING("NECROZMA LINE"),
};

static const u8 sResearchTextColors[] =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_DARK_GRAY,
    TEXT_COLOR_LIGHT_GRAY,
};

static const struct BgTemplate sResearchBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sResearchWindowTemplates[] =
{
    [WIN_RESEARCH_HEADER] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_RESEARCH_CONTENT] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 28,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 57,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct ResearchPageDefinition sResearchPages[RESEARCH_PAGE_COUNT] =
{
    [RESEARCH_PAGE_SUMMARY] = {
        .title = sText_Summary,
        .draw = DrawSummaryPage,
    },
    [RESEARCH_PAGE_MUTATIONS] = {
        .title = sText_MutationDetails,
        .draw = DrawMutationDetailsPage,
    },
    [RESEARCH_PAGE_MUTATION_LOG] = {
        .title = sText_MutationLog,
        .draw = DrawMutationLogPage,
    },
    [RESEARCH_PAGE_PROTO_LEGENDS] = {
        .title = sText_ProtoLegends,
        .draw = DrawProtoLegendsPage,
    },
};

static void ResearchMainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void ResearchVBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void PrintResearchText(u8 fontId, const u8 *text, u8 x, u8 y)
{
    AddTextPrinterParameterized4(WIN_RESEARCH_CONTENT, fontId, x, y, 0, 0,
                                 sResearchTextColors, TEXT_SKIP_DRAW, text);
}

static void PrintResearchHeaderText(u8 fontId, const u8 *text, u8 x, u8 y)
{
    AddTextPrinterParameterized4(WIN_RESEARCH_HEADER, fontId, x, y, 0, 0,
                                 sResearchTextColors, TEXT_SKIP_DRAW, text);
}

static void PrintNumberRightAligned(u16 value, u8 x, u8 y, u8 rightEdge)
{
    ConvertIntToDecimalStringN(gStringVar4, value, STR_CONV_MODE_LEFT_ALIGN, 5);
    PrintResearchText(FONT_SHORT, gStringVar4,
                      x + GetStringRightAlignXOffset(FONT_SHORT, gStringVar4, rightEdge), y);
}

static void PrintFractionRightAligned(u16 value, u16 maximum, u8 x, u8 y, u8 rightEdge)
{
    ConvertIntToDecimalStringN(gStringVar4, value, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar4, sText_Slash);
    ConvertIntToDecimalStringN(gStringVar1, maximum, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar4, gStringVar1);
    PrintResearchText(FONT_SHORT, gStringVar4,
                      x + GetStringRightAlignXOffset(FONT_SHORT, gStringVar4, rightEdge), y);
}

static void PrintLabelAndNumber(const u8 *label, u16 value, u8 x, u8 y, u8 width)
{
    PrintResearchText(FONT_SHORT, label, x, y);
    PrintNumberRightAligned(value, x, y, width);
}

static void PrintLabelAndFraction(const u8 *label, u16 value, u16 maximum, u8 x, u8 y, u8 width)
{
    PrintResearchText(FONT_SHORT, label, x, y);
    PrintFractionRightAligned(value, maximum, x, y, width);
}

static void PrintNoResearchRecorded(void)
{
    u8 x = GetStringCenterAlignXOffset(FONT_NORMAL, sText_NoResearch, RESEARCH_CONTENT_WIDTH);
    PrintResearchText(FONT_NORMAL, sText_NoResearch, x, 44);
}

static void PrintNoRecentMutations(void)
{
    u8 x = GetStringCenterAlignXOffset(FONT_NORMAL, sText_NoRecentMutations, RESEARCH_CONTENT_WIDTH);
    PrintResearchText(FONT_NORMAL, sText_NoRecentMutations, x, 44);
}

static void FormatMutationTimestamp(u32 timestamp)
{
    u32 hours;
    u8 minutes;

    if (timestamp == RESEARCH_TIMESTAMP_UNKNOWN)
    {
        StringCopy(gStringVar1, sText_UnknownTime);
        return;
    }

    hours = timestamp / (60 * 60);
    minutes = (timestamp / 60) % 60;
    ConvertIntToDecimalStringN(gStringVar1, hours, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringAppend(gStringVar1, sText_Colon);
    ConvertIntToDecimalStringN(gStringVar2, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar1, gStringVar2);
}

static void EnsureCategoryCursorIsDiscovered(void)
{
    u32 i;

    if (Research_GetMutationCategoryCount(sResearchScreen.categoryCursor) != 0)
        return;

    for (i = 0; i < RESEARCH_MUTATION_CATEGORY_COUNT; i++)
    {
        if (Research_GetMutationCategoryCount(i) != 0)
        {
            sResearchScreen.categoryCursor = i;
            return;
        }
    }
}

static void PrintMutationCategory(enum ResearchMutationCategory category, u8 x, u8 y)
{
    u16 count = Research_GetMutationCategoryCount(category);

    if (category == sResearchScreen.categoryCursor && count != 0)
        PrintResearchText(FONT_SHORT, COMPOUND_STRING(">"), x, y);

    if (count == 0)
    {
        PrintResearchText(FONT_SHORT, sText_Unknown, x + 8, y);
    }
    else
    {
        PrintResearchText(FONT_SHORT, sMutationCategoryNames[category], x + 8, y);
        PrintNumberRightAligned(count, x, y, 100);
    }
}

static void DrawCategoryDescription(void)
{
    enum ResearchMutationCategory category = sResearchScreen.categoryCursor;

    PrintResearchText(FONT_NORMAL, sMutationCategoryNames[category], 0, 8);
    PrintResearchText(FONT_NORMAL, sMutationCategoryDescriptions[category], 0, 32);
}

static void DrawSummaryPage(void)
{
    u16 total = Research_GetLifetimeMutationTotal();
    u8 protoCount = Research_GetRegisteredProtoLineCount();
    u32 i;

    if (total == 0 && protoCount == 0)
    {
        PrintNoResearchRecorded();
        return;
    }

    EnsureCategoryCursorIsDiscovered();
    if (sResearchScreen.showingDescription)
    {
        DrawCategoryDescription();
        return;
    }

    PrintLabelAndNumber(sText_TotalMutations, total, 0, 0, RESEARCH_CONTENT_WIDTH);

    for (i = 0; i < RESEARCH_MUTATION_CATEGORY_COUNT; i++)
        PrintMutationCategory(i, (i & 1) * 112, 14 + (i / 2) * 14);

    PrintLabelAndFraction(sText_ProtoLines, protoCount, RESEARCH_PROTO_LINE_COUNT,
                          0, 70, RESEARCH_CONTENT_WIDTH);
}

static void DrawMutationDetailsPage(void)
{
    u32 i;

    if (Research_GetDiscoveredMutationCount() == 0 && Research_GetDiscoveredStatCount() == 0)
    {
        PrintNoResearchRecorded();
        return;
    }

    PrintLabelAndFraction(sText_TypesDiscovered, Research_GetDiscoveredMutationCount(),
                          RESEARCH_MUTATION_CATEGORY_COUNT, 0, 0, RESEARCH_CONTENT_WIDTH);
    PrintLabelAndFraction(sText_StatsDiscovered, Research_GetDiscoveredStatCount(),
                          NUM_STATS, 0, 14, RESEARCH_CONTENT_WIDTH);
    for (i = 0; i < NUM_STATS; i++)
    {
        enum Stat stat = sDisplayedStats[i];
        u16 count = Research_GetStatMutationCount(stat);
        u8 y = 28 + i * 14;

        if (count == 0)
            PrintResearchText(FONT_SHORT, sText_Unknown, 8, y);
        else
            PrintLabelAndNumber(sStatNames[stat], count, 8, y, RESEARCH_CONTENT_WIDTH - 8);
    }
}

static void DrawMutationLogPage(void)
{
    u8 count = min(Research_GetRecentMutationCount(), RESEARCH_MUTATION_LOG_VISIBLE);
    u32 row;

    PrintResearchText(FONT_SHORT, sText_RecentMutationsRecorded, 0, 0);
    if (count == 0)
    {
        PrintNoRecentMutations();
        return;
    }

    for (row = 0; row < count; row++)
    {
        const struct ResearchMutationLogEntry *entry = Research_GetRecentMutation(row);
        const u8 *speciesName;
        u8 fontId;

        if (entry == NULL)
            break;

        FormatMutationTimestamp(Research_GetRecentMutationTimestamp(row));
        StringCopy(gStringVar4, gStringVar1);
        StringAppend(gStringVar4, sText_Space);
        StringAppend(gStringVar4, sText_LogNameColor);
        if (entry->species > SPECIES_NONE && entry->species < NUM_SPECIES)
        {
            speciesName = GetSpeciesName(entry->species);
            if (StringCompare(entry->nickname, speciesName) == 0)
                StringAppend(gStringVar4, speciesName);
            else
            {
                StringAppend(gStringVar4, entry->nickname);
                StringAppend(gStringVar4, sText_Slash);
                StringAppend(gStringVar4, speciesName);
            }
        }
        else
            StringAppend(gStringVar4, entry->nickname);
        StringAppend(gStringVar4, sText_LogNeutralColor);
        StringAppend(gStringVar4, sText_LevelPrefix);
        if (Research_GetRecentMutationLevel(row) == RESEARCH_LEVEL_UNKNOWN)
            StringAppend(gStringVar4, sText_UnknownLevel);
        else
        {
            ConvertIntToDecimalStringN(gStringVar2, Research_GetRecentMutationLevel(row),
                                       STR_CONV_MODE_LEFT_ALIGN, 3);
            StringAppend(gStringVar4, gStringVar2);
        }
        StringAppend(gStringVar4, sText_Space);
        StringAppend(gStringVar4, sText_LogMutationColor);
        if (entry->mutation <= MUTATION_CHOSEN_POKERUS)
            StringAppend(gStringVar4, sMutationResultNames[entry->mutation]);
        else
            StringAppend(gStringVar4, sText_Unknown);
        fontId = GetFontIdToFit(gStringVar4, FONT_SMALL, 0, RESEARCH_CONTENT_WIDTH - 8);
        PrintResearchText(fontId, gStringVar4, 8, 15 + row * 15);
    }
}

static u8 GetRegisteredProtoLineByListIndex(u8 listIndex)
{
    u32 line;

    for (line = 0; line < RESEARCH_PROTO_LINE_COUNT; line++)
    {
        if (Research_GetRegisteredProtoSpecies(line) != SPECIES_NONE)
        {
            if (listIndex == 0)
                return line;
            listIndex--;
        }
    }
    return RESEARCH_PROTO_LINE_COUNT;
}

static void RemoveResearchScrollArrows(void)
{
    if (sResearchScreen.scrollArrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sResearchScreen.scrollArrowTaskId);
        sResearchScreen.scrollArrowTaskId = TASK_NONE;
    }
}

static void DrawProtoLegendsPage(void)
{
    u8 count = Research_GetRegisteredProtoLineCount();
    u32 row;

    if (count == 0)
    {
        PrintNoResearchRecorded();
        return;
    }

    if (sResearchScreen.protoCursor >= count)
        sResearchScreen.protoCursor = count - 1;
    if (sResearchScreen.protoScroll > sResearchScreen.protoCursor)
        sResearchScreen.protoScroll = sResearchScreen.protoCursor;
    if (sResearchScreen.protoCursor >= sResearchScreen.protoScroll + RESEARCH_PROTO_VISIBLE)
        sResearchScreen.protoScroll = sResearchScreen.protoCursor - RESEARCH_PROTO_VISIBLE + 1;

    for (row = 0; row < RESEARCH_PROTO_VISIBLE; row++)
    {
        u8 listIndex = sResearchScreen.protoScroll + row;
        u8 line;
        u16 species;

        if (listIndex >= count)
            break;
        line = GetRegisteredProtoLineByListIndex(listIndex);
        species = Research_GetRegisteredProtoSpecies(line);
        StringCopy(gStringVar4, sProtoLineNames[line]);
        StringAppend(gStringVar4, sText_Separator);
        StringAppend(gStringVar4, GetSpeciesName(species));
        PrintResearchText(FONT_SHORT, gStringVar4, 0, row * 15);
    }

    if (count > RESEARCH_PROTO_VISIBLE)
    {
        sResearchScreen.scrollArrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 228, 44, 144, count - RESEARCH_PROTO_VISIBLE,
            RESEARCH_SCROLL_TAG, RESEARCH_SCROLL_TAG, &sResearchScreen.protoScroll);
    }
}

static void DrawResearchHeader(void)
{
    u8 pageTitleX;

    PrintResearchHeaderText(FONT_NORMAL, sText_Research, 0, 0);
    pageTitleX = GetStringRightAlignXOffset(FONT_SMALL,
                                            sResearchPages[sResearchScreen.page].title,
                                            RESEARCH_CONTENT_WIDTH);
    PrintResearchHeaderText(FONT_SMALL, sResearchPages[sResearchScreen.page].title, pageTitleX, 1);
}

static void DrawResearchScreen(void)
{
    const u8 *footer = sText_Footer;

    RemoveResearchScrollArrows();
    FillWindowPixelBuffer(WIN_RESEARCH_HEADER, PIXEL_FILL(1));
    FillWindowPixelBuffer(WIN_RESEARCH_CONTENT, PIXEL_FILL(1));
    DrawResearchHeader();
    sResearchPages[sResearchScreen.page].draw();
    if (sResearchScreen.page == RESEARCH_PAGE_PROTO_LEGENDS)
        DrawResearchScrollBar(sResearchScreen.protoScroll, Research_GetRegisteredProtoLineCount());
    if (sResearchScreen.showingDescription)
        footer = sText_DescriptionFooter;
    else if (sResearchScreen.page == RESEARCH_PAGE_MUTATIONS)
        footer = sText_MutationFooter;
    else if (sResearchScreen.page == RESEARCH_PAGE_MUTATION_LOG
          || sResearchScreen.page == RESEARCH_PAGE_PROTO_LEGENDS)
        footer = sText_ListFooter;
    PrintResearchText(FONT_SMALL, footer, 0, 106);
    CopyWindowToVram(WIN_RESEARCH_HEADER, COPYWIN_GFX);
    CopyWindowToVram(WIN_RESEARCH_CONTENT, COPYWIN_GFX);
}

static void DrawResearchScrollBar(u16 scroll, u8 count)
{
    u16 maxScroll;
    u16 thumbHeight;
    u16 thumbOffset;

    if (count <= RESEARCH_PROTO_VISIBLE)
        return;

    maxScroll = count - RESEARCH_PROTO_VISIBLE;
    thumbHeight = RESEARCH_SCROLLBAR_HEIGHT * RESEARCH_PROTO_VISIBLE / count;
    thumbHeight = max(thumbHeight, RESEARCH_SCROLLBAR_MIN_THUMB);
    // Match pokedex, thumb is at the top at the first entry and moves down
    thumbOffset = (RESEARCH_SCROLLBAR_HEIGHT - thumbHeight) * scroll / maxScroll;

    FillWindowPixelRect(WIN_RESEARCH_CONTENT, PIXEL_FILL(3),
                        RESEARCH_SCROLLBAR_X, RESEARCH_SCROLLBAR_TOP,
                        RESEARCH_SCROLLBAR_WIDTH, RESEARCH_SCROLLBAR_HEIGHT);
    FillWindowPixelRect(WIN_RESEARCH_CONTENT, PIXEL_FILL(2),
                        RESEARCH_SCROLLBAR_X, RESEARCH_SCROLLBAR_TOP + thumbOffset,
                        RESEARCH_SCROLLBAR_WIDTH, thumbHeight);
}

static void SwitchResearchPage(s8 direction)
{
    s8 page = sResearchScreen.page + direction;

    if (page < 0)
        page = RESEARCH_PAGE_COUNT - 1;
    else if (page >= RESEARCH_PAGE_COUNT)
        page = 0;
    sResearchScreen.page = page;
    sResearchScreen.showingDescription = FALSE;
    DrawResearchScreen();
}

static void MoveCategoryCursor(s8 direction)
{
    u32 i;
    s8 category;

    if (Research_GetDiscoveredMutationCount() == 0)
        return;

    // Categories are displayed in a two-column grid. Horizontal movement must
    // stay on the current row instead of advancing through the linear array.
    if (direction == -1 || direction == 1)
    {
        s8 row = sResearchScreen.categoryCursor / 2;
        s8 column = sResearchScreen.categoryCursor & 1;

        if ((direction == -1 && column == 0) || (direction == 1 && column == 1))
            return;

        // Search the other column from the current row outward, so ??? entries
        // are skipped while keeping horizontal movement intuitive.
        for (i = 0; i < RESEARCH_MUTATION_CATEGORY_COUNT / 2; i++)
        {
            s8 targetRow = row + direction * i;
            while (targetRow < 0)
                targetRow += RESEARCH_MUTATION_CATEGORY_COUNT / 2;
            targetRow %= RESEARCH_MUTATION_CATEGORY_COUNT / 2;
            category = targetRow * 2 + (column ^ 1);
            if (Research_GetMutationCategoryCount(category) != 0)
            {
                sResearchScreen.categoryCursor = category;
                DrawResearchScreen();
                return;
            }
        }
        return;
    }

    for (i = 1; i <= RESEARCH_MUTATION_CATEGORY_COUNT; i++)
    {
        category = sResearchScreen.categoryCursor + direction * i;

        while (category < 0)
            category += RESEARCH_MUTATION_CATEGORY_COUNT;
        category %= RESEARCH_MUTATION_CATEGORY_COUNT;
        if (Research_GetMutationCategoryCount(category) != 0)
        {
            sResearchScreen.categoryCursor = category;
            DrawResearchScreen();
            return;
        }
    }
}

static void HandleSummaryInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (sResearchScreen.showingDescription)
        {
            PlaySE(SE_SELECT);
            sResearchScreen.showingDescription = FALSE;
            DrawResearchScreen();
        }
        else if (Research_GetMutationCategoryCount(sResearchScreen.categoryCursor) != 0)
        {
            PlaySE(SE_SELECT);
            sResearchScreen.showingDescription = TRUE;
            DrawResearchScreen();
        }
    }
    else if (!sResearchScreen.showingDescription && JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        MoveCategoryCursor(-1);
    }
    else if (!sResearchScreen.showingDescription && JOY_NEW(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        MoveCategoryCursor(1);
    }
    else if (!sResearchScreen.showingDescription && JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        MoveCategoryCursor(-2);
    }
    else if (!sResearchScreen.showingDescription && JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        MoveCategoryCursor(2);
    }
}

static void HandleProtoInput(void)
{
    u8 count = Research_GetRegisteredProtoLineCount();
    u8 maxScroll;

    if (count == 0)
        return;

    maxScroll = (count > RESEARCH_PROTO_VISIBLE) ? count - RESEARCH_PROTO_VISIBLE : 0;
    if (JOY_NEW(DPAD_UP) && sResearchScreen.protoScroll != 0)
    {
        PlaySE(SE_SELECT);
        if (sResearchScreen.protoScroll > RESEARCH_PROTO_VISIBLE)
            sResearchScreen.protoScroll -= RESEARCH_PROTO_VISIBLE;
        else
            sResearchScreen.protoScroll = 0;
        sResearchScreen.protoCursor = sResearchScreen.protoScroll;
        DrawResearchScreen();
    }
    else if (JOY_NEW(DPAD_DOWN) && sResearchScreen.protoScroll < maxScroll)
    {
        PlaySE(SE_SELECT);
        sResearchScreen.protoScroll += RESEARCH_PROTO_VISIBLE;
        if (sResearchScreen.protoScroll > maxScroll)
            sResearchScreen.protoScroll = maxScroll;
        sResearchScreen.protoCursor = sResearchScreen.protoScroll;
        DrawResearchScreen();
    }
}

static void Task_ResearchFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ResearchInput;
}

static void Task_ResearchInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        if (sResearchScreen.showingDescription)
        {
            PlaySE(SE_SELECT);
            sResearchScreen.showingDescription = FALSE;
            DrawResearchScreen();
            return;
        }

        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ResearchFadeOut;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        SwitchResearchPage(-1);
    }
    else if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        SwitchResearchPage(1);
    }
    else if (sResearchScreen.page == RESEARCH_PAGE_SUMMARY)
    {
        HandleSummaryInput();
    }
    else if (sResearchScreen.page == RESEARCH_PAGE_PROTO_LEGENDS)
    {
        HandleProtoInput();
    }
}

static void Task_ResearchFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RemoveResearchScrollArrows();
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        gFieldCallback = FieldCB_ReturnToFieldNoScript;
        SetMainCallback2(CB2_ReturnToField);
    }
}

void CB2_InitResearchScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sResearchBgTemplates, ARRAY_COUNT(sResearchBgTemplates));
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 1:
        InitWindows(sResearchWindowTemplates);
        DeactivateAllTextPrinters();
        LoadUserWindowBorderGfx(WIN_RESEARCH_HEADER, RESEARCH_BORDER_TILE,
                                BG_PLTT_ID(RESEARCH_BORDER_PALETTE));
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
        PutWindowTilemap(WIN_RESEARCH_HEADER);
        PutWindowTilemap(WIN_RESEARCH_CONTENT);
        DrawStdFrameWithCustomTileAndPalette(WIN_RESEARCH_HEADER, FALSE,
                                             RESEARCH_BORDER_TILE, RESEARCH_BORDER_PALETTE);
        DrawStdFrameWithCustomTileAndPalette(WIN_RESEARCH_CONTENT, FALSE,
                                             RESEARCH_BORDER_TILE, RESEARCH_BORDER_PALETTE);
        sResearchScreen.page = RESEARCH_PAGE_SUMMARY;
        sResearchScreen.categoryCursor = 0;
        sResearchScreen.showingDescription = FALSE;
        sResearchScreen.protoCursor = 0;
        sResearchScreen.protoScroll = 0;
        sResearchScreen.scrollArrowTaskId = TASK_NONE;
        DrawResearchScreen();
        CopyBgTilemapBufferToVram(0);
        ShowBg(0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gMain.state++;
        break;
    case 2:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_ResearchFadeIn, 0);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(ResearchVBlankCB);
        SetMainCallback2(ResearchMainCB);
        break;
    }
}
