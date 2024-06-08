#ifndef DESTROY_H
#define DESTROY_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"
#include "cleartool.h"
#include "freighttool.h"
int destroy()
{
    char *destroy_notice1 = "����ȷ���Ƿ����ٴ���Ʒ��";
    char *destroy_notice2 = "�������ȷ�����������Ƿ���ȷ��";
    char *choice1 = "[Y]��";
    char *choice2 = "[N]��";
    char *destroy_choice[2] = {choice1, choice2};
    char *msg = (char *)malloc(sizeof(char) * 100);
    int load_satus, length = 0,serch_id, ch1, ch2, x, num;
    unsigned long long EAN;
    freight *p;
    p = (freight *)malloc(sizeof(freight) * 1000);
    load_satus = load_stock_data(p, &length);
    if (load_satus == -1)
    {
        return -1;
    }
    while(1)
    {
        system("cls");
        printf("������Ҫ���ٵĻ�Ʒ��EAN�루����0���˳���\n");
        ShowConsoleCursor();
        scanf("%llu", &EAN);
        char buff = getchar();
        while (buff != '\n' || (EAN >0&&EAN < 1e12) || EAN >= 1e13|| EAN < 0)
        {
            printf("���벻�Ϸ�������������\n");
            fflush(stdin);
            system("pause");
            system("cls");
            printf("������Ҫ���ٵĻ�Ʒ��EAN�루����0���˳���\n");
            ShowConsoleCursor();
            scanf("%llu", &EAN);
            buff = getchar();
        }
        if (EAN == 0)
        {
            fflush(stdin);
            x = silent_save_stock_data(p, &length);
            return -1;
        }
        serch_id = locating(p, length, EAN);
        if (serch_id == -1)
        {
            system("cls");
            SetColor(4, 0);
            printf("��Ʒ�����ڣ����������룡\n");
            SetColor(15, 0);
            fflush(stdin);
            system("pause");
            continue;
        }
        else
        {
            system("cls");
            freight_msg(msg,p,serch_id);
            printf("%s",msg);
            system("pause");
            ch1 = ui_choice(destroy_notice1, destroy_choice, 2);
            if (ch1 == 0)
            {
                while (1)
                {
                    printf("������Ҫ���ٶ��ٸ�������Ʒ��\n");
                    ShowConsoleCursor();
                    scanf("%d", &num);
                    buff = getchar();
                    if (buff != '\n')
                        num = -1;
                    while (num < 0 || num > p[serch_id].stock)
                    {
                        if (num > p[serch_id].stock)
                        {
                            printf("��治�㣬����������\n");
                        }
                        else
                        {
                            printf("���벻�Ϸ�������������\n");
                        }
                        fflush(stdin);
                        system("pause");
                        system("cls");
                        printf("������Ҫ���ٶ��ٸ�������Ʒ��\n");
                        ShowConsoleCursor();
                        scanf("%d", &num);
                        char buff = getchar();
                        if (buff != '\n')
                            num = -1;
                    }
                    ch2 = ui_choice(destroy_notice2, destroy_choice, 2);
                    if (ch2 == 0)
                    {
                        dest_freight(p, serch_id, num);
                        system("cls");
                        SetColor(10, 0);
                        printf("���ٳɹ���\n");
                        SetColor(15, 0);
                        system("pause");
                        fflush(stdin);
                        break;
                    }
                    else
                    {
                        printf("�Ѿ�ȡ���˲���\n");
                        system("pause");
                        continue;
                    }
                }
            }
            else
            {
                printf("�Ѿ�ȡ���˲���\n");
                system("pause");
                continue;
            }
        }
    }
}

#endif