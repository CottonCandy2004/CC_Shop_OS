#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"
int locating(freight *freight, int list_length, unsigned long long EAN)
{
    int flag = -1;
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("正在定位数据...");
    SetColor(15, 0);
    for (int i = 0; i < list_length; i++)
    {
        if (freight[i].EAN == EAN)
        {
            flag = i;
            break;
        }
    }
    return flag;
}
void del_freight(freight *freight, int *list_length, int id)
{
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("正在处理...");
    SetColor(15, 0);
    for (int i = id; i < *list_length - 1; i++)
    {
        freight[i] = freight[i + 1];
    }
    init_freight(freight + (*list_length) - 1);
    (*list_length)--;
    // Sleep(1000);
}