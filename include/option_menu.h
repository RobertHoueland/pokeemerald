#ifndef GUARD_OPTION_MENU_H
#define GUARD_OPTION_MENU_H

#include "bg.h"
#include "window.h"

enum
{
    WIN_HEADER,
    WIN_OPTIONS,
};

extern const struct WindowTemplate sOptionMenuWinTemplates[WIN_OPTIONS + 2];
extern const struct BgTemplate sOptionMenuBgTemplates[2];
extern const u16 sOptionMenuBg_Pal[1];
extern const u16 sOptionMenuText_Pal[16];

void CB2_InitOptionMenu(void);
void CB2_InitSpeedOptionsMenu(void);
void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style);

#endif // GUARD_OPTION_MENU_H
