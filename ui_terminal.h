#ifndef UI_TERMINAL_H
#define UI_TERMINAL_H

#include <windows.h>
void SetColor(UINT uFore, UINT uBack);
void HideConsoleCursor();
void ShowConsoleCursor();

void SetColor(UINT uFore, UINT uBack)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), uFore + uBack * 0x10);
}
// Black, Blue, Green, Light Blue,
// Red, Purple, Yellow, White,
// Grey, Nattier Blue, Nattier Green, Natter Light Green,
// Natter Red, Natter Purple, Natter Yellow, Light White

void HideConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void ShowConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

#endif