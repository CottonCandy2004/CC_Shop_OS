#ifndef _REGISTER_H_
#define _REGISTER_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>
#include "ui_terminal.h"

struct vip *register_vip();
struct vip *register_vip()
{
    int step = 0;
    struct vip *vip;
    vip = (struct vip *)malloc(sizeof(struct vip));
    init_vip(vip);
    system("cls");
    while (1)
    {
        printf("\n请输入会员姓名：");
        ShowConsoleCursor();
        if (step == 0 || step == 2)
        {
            fgets(vip->name, 20, stdin);
            char *find = strchr(vip->name, '\n');
            if (find)
                *find = '\0';
            if (vip->name[0] == '\0')
            {
                system("cls");
                SetColor(4, 0);
                printf("请输入会员姓名！");
                SetColor(15, 0);
                step = 2;
                continue;
            }
            fflush(stdin);
        }
        else
        {
            printf("%s\n", vip->name);
        }
        if (step == 2)
        {
            system("cls");
            step = 1;
            continue;
        }
        step = 1;
        printf("请输入会员电话：");
        scanf("%lld", &vip->phone_number);
        fflush(stdin);
        if ((vip->phone_number == 0) || (vip->phone_number >= 1e11) || (vip->phone_number < 1e10))
        {
            system("cls");
            SetColor(4, 0);
            printf("电话号码错误，请重新输入！");
            SetColor(15, 0);
            continue;
        }
        else
        {
            system("cls");
            SetColor(10, 0);
            HideConsoleCursor();
            printf("录入成功！");
            SetColor(15, 0);
            break;
        }
    }
    return vip;
}
#endif