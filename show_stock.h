#ifndef SHOW_STOCK_H
#define SHOW_STOCK_H

#include "struct.h"
#include "algorithm.h"
#include "ui.h"
#include "ui_terminal.h"
#include <stdlib.h>
#include "auth.h"
#include "freightlib.h"

void show_stock(freight *data, int length);
void show_stock_sort(freight *data, int length);
int clean_mergins(freight *data, int length);
void show_mode(freight *data, int length)
{
    fflush(stdin);
    while (1)
    {
        system("cls");
        fflush(stdin);
        char *message = "请选择要显示库存的模式：";
        char *ch1 = "显示库存";
        char *ch2 = "显示库存（按盈利排序）";
        char *ch3 = "清除所有盈利记录";
        char *ch4 = "返回";
        char *choice[4] = {ch1, ch2, ch3, ch4};
        int ch = ui_choice(message, choice, 4);
        switch (ch)
        {
        case 0:
            show_stock(data, length);
            continue;
        case 1:
            show_stock_sort(data, length);
            continue;
        case 2:
        {
            int pwd = -2;
            while (pwd == -2)
            {
                pwd = clean_mergins(data, length);
            }
            continue;
        }
        }
        if (ch == 3)
        {
            break;
        }
    }
}

void show_stock(freight *data, int length)
{
    system("cls");
    SetColor(3, 0);
    printf("商品编号\t商品名称\t\t商品库存\t商品进价\t商品售价\t商品利润\n");
    for (int i = 0; i < length; i++)
    {
        printf("%llu\t%-24s%d\t\t%d\t\t%d\t\t%d\n", data[i].EAN, data[i].name, data[i].stock, data[i].purchase_price, data[i].sale_price, data[i].margins);
    }
    system("pause");
    SetColor(15, 0);
}

void show_stock_sort(freight *data, int length)
{
    system("cls");
    SetColor(3, 0);
    printf("Sorting...");
    freight *buff = (freight *)malloc(length * sizeof(freight));
    for (int i = 0; i < length; i++)
    {
        buff[i] = data[i];
    }
    sort_freight(buff, buff + length - 1);
    SetColor(15, 0);
    show_stock(buff, length);
    free(buff);
}

int clean_mergins(freight *data, int length)
{
    system("cls");
    char *choice1 = "[N]否";
    char *choice2 = "[Y]是";
    char *choi[2] = {choice1, choice2};
    int choice = ui_re_choice("是否确认清除所有盈利记录？", choi, 2, "警告：该操作一旦进行无法复原", 4);
    SetColor(15, 0);
    if (choice == 0)
    {
        system("cls");
        printf("操作已取消。");
        Sleep(1000);
        return -1;
    }
    else if (choice == 1)
    {
        int auth_satus = auth();
        if (auth_satus == -2)
        {
            system("cls");
            printf("密码错误。");
            Sleep(1000);
            return -2;
        }
        else if (auth_satus == 200)
        {
            system("cls");
            printf("正在清除所有盈利记录...");
            for (int i = 0; i < length; i++)
            {
                data[i].margins = 0;
            }
            silent_save_stock_data(data, &length);
            system("cls");
            printf("操作已完成。");
            Sleep(1000);
            return 0;
        }
    }
}

#endif