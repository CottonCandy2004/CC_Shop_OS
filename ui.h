#ifndef ui_h
#define ui_h

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void SetColor(UINT uFore, UINT uBack)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}

void HideConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; // To SunPeng : left: type, right: visible
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void ShowConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void flush(char *notice, char **arr, int length, int *choice)
{
    system("cls");
    SetColor(15, 0);
    printf("%s\n", notice);
    for (int i = 0; i < length; i++)
    {
        if (i == *choice)
        {
            SetColor(0, 15);
            printf("%s\n", arr[i]);
            SetColor(15, 0);
        }
        else
        {
            printf("%s\n", arr[i]);
        }
    }
}

int ui_choice(char *notice, char **arr, int length)
{
    HideConsoleCursor();
    int choice = 0;
    while (1)
    {
        flush(notice, arr, length, &choice);
        int key = getch();
        if (key == 224)
        {
            switch (getch())
            {
            case 72:
                choice--;
                if (choice < 0)
                {
                    printf("\a");
                    choice = 0;
                }
                break;
            case 80:
                choice++;
                if (choice > length - 1)
                {
                    printf("\a");
                    choice = length - 1;
                }
                break;
            default:
                printf("\a");
                break;
            }
        }
        else
        {
            switch (key)
            {
            case 'w':
                choice--;
                if (choice < 0)
                {
                    printf("\a");
                    choice = 0;
                }
                break;
            case 's':
                choice++;
                if (choice > length - 1)
                {
                    printf("\a");
                    choice = length - 1;
                }
                break;
            default:
                if (key == '\r')
                {
                    return choice;
                }
                printf("\a");
                break;
            }
        }
    }
}
#endif
