#ifndef _DEREGISTER_H_
#define _DEREGISTER_H_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "ui_terminal.h"
#include "ui.h"
#include <string.h>
#include "viplib.h"
int deregister(struct vip *vip, int list_length);
int is_in_list(struct vip *vip, int list_length, unsigned long long phone_number);
void del_vip(struct vip *vip, int *list_length, int id);

void del_vip(struct vip *vip, int *list_length, int id)
{
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("���ڴ���...");
    SetColor(15, 0);
    for (int i = id; i < *list_length - 1; i++)
    {
        vip[i] = vip[i + 1];
    }
    init_vip(vip + (*list_length) - 1);
    (*list_length)--;
    // Sleep(1000);
}

int deregister(struct vip *vip, int list_length)
{
    unsigned long long phone_number = 1;
    system("cls");
    while (1)
    {
        printf("\n������Ҫע����Ա���ֻ��ţ�����0���˳�����");
        ShowConsoleCursor();
        scanf("%lld", &phone_number);
        if (phone_number == 0)
        {
            fflush(stdin);
            return -1;
        }
        else if (phone_number == 1)
        {
            system("cls");
            SetColor(4, 0);
            printf("�ֻ��Ÿ�ʽ�������������룡");
            fflush(stdin);
            SetColor(15, 0);
            continue;
        }
        int serch_id = is_in_list(vip, list_length, phone_number);
        if (serch_id == -1)
        {
            system("cls");
            SetColor(4, 0);
            printf("�ֻ��Ų����ڣ����������룡");
            SetColor(15, 0);
            fflush(stdin);
            continue;
        }
        else
        {
            char msg[200] = "�Ƿ�ȷ��ɾ����Ա��";
            vip_msg(msg, vip, serch_id);
            char *choices[2] = {"[N]ȡ��ע��", "[Y]ȷ��ע��"};
            int result = ui_choice(msg, choices, 2);
            if (result == 1)
            {
                del_vip(vip, &list_length, serch_id);
                system("cls");
                SetColor(10, 0);
                printf("ע���ɹ���\n");
                SetColor(15, 0);
                fflush(stdin);
                // system("pause");
                return 200;
            }
            else
            {
                system("cls");
                SetColor(4, 0);
                printf("ע���Ѿ�ȡ����\n");
                SetColor(15, 0);
                fflush(stdin);
                // system("pause");
                return -1;
            }
        }
    }
}
#endif