#ifndef CLEAR_H
#define CLEAR_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"
#include "cleartool.h"
#include "freighttool.h"
int clear()
{
    char *clear_notice1 = "请您最后确认是否清除此商品？";
    char *choice1 = "[Y]是";
    char *choice2 = "[N]否";
    char *clear_choice[2] = {choice1, choice2};
    char *msg = (char *)malloc(sizeof(char) * 100);
    int load_satus, length = 0, n, serch_id, ch1, x;
    unsigned long long EAN;
    freight *p = (freight *)malloc(sizeof(freight) * 1000);
    load_satus = load_stock_data(p, &length);
    if (load_satus == -1)
    {
        return -1;
    }
    while (1)
    {
        system("cls");
        printf("请输入想要清除商品的EAN：（输入0以退出）\n");
        ShowConsoleCursor();
        scanf("%llu", &EAN);
        char buff = getchar();
        while (buff != '\n' || (EAN > 0 && EAN < 1e12) || EAN >= 1e13 || EAN < 0)
        {
            printf("输入不合法，请重新输入\n");
            fflush(stdin);
            system("pause");
            system("cls");
            printf("请输入想要清除商品的EAN：（输入0以退出）\n");
            ShowConsoleCursor();
            scanf("%llu", &EAN);
            buff = getchar();
        }
        if (EAN == 0)
        {
            fflush(stdin);
            x = silent_save_stock_data(p, &length);
            free(p);
            return -1;
        }
        serch_id = locating(p, length, EAN);
        if (serch_id == -1)
        {
            system("cls");
            SetColor(4, 0);
            printf("商品不存在，请重新输入！\n");
            SetColor(15, 0);
            fflush(stdin);
            system("pause");
            continue;
        }
        else
        {
            system("cls");
            freight_msg(msg, p, serch_id);
            printf("%s", msg);
            system("pause");
            ch1 = ui_choice(clear_notice1, clear_choice, 2);
            if (ch1 == 0)
            {
                del_freight(p, &length, serch_id);
                system("cls");
                SetColor(10, 0);
                printf("清除成功！\n");
                SetColor(15, 0);
                system("pause");
                fflush(stdin);
            }
            else
            {
                printf("已经取消此操作\n");
                system("pause");
                continue;
            }
        }
    }
    free(p);
}

#endif