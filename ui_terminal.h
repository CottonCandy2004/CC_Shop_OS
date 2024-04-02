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
    CONSOLE_CURSOR_INFO cursor_info;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursor_info);
    cursor_info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursor_info);
}

void ShowConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursor_info);
    cursor_info.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

char *summonsha(char *str_)
{
    FILE *fp, *buff;
    buff = fopen("sha", "w");
    fwrite(str_, 1, strlen(str_), buff);
    fclose(buff);
    fp = popen("certutil.exe -hashfile sha sha256", "r");
    char *buffer = (char *)malloc(1024);
    char *q=buffer;
    memset(buffer, 0, 1024);
    while (!feof(fp))
    fread(q++, 1, 1, fp);
    pclose(fp);
    char *p = strstr(buffer, "CertUtil");
    p--;
    *p='\0';
    p-=64;
    system("del sha");
    char *sha = (char *)malloc(65);
    strcpy(sha, p);
    free(buffer);
    return sha;
}
#endif