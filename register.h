#ifndef _REGISTER_H_
#define _REGISTER_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>
#include "ui_terminal.h"
#include "viplib.h"
int register_vip(int length, struct vip *vip, struct vip *vip_data);
int register_vip(int length, struct vip *vip, struct vip *vip_data)
{
    int step = 0;
    // fflush(stdin);
    init_vip(vip);
    system("cls");
    while (1)
    {
        printf("\n�������Ա����������0���أ���");
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
                printf("�������Ա������");
                SetColor(15, 0);
                step = 2;
                continue;
            }
            else if (*vip->name == '0')
            {
                return -1;
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
        printf("�������Ա�绰��");
        scanf("%lld", &vip->phone_number);
        fflush(stdin);
        int in_list_satus = is_in_list(vip_data, length, vip->phone_number);
        if ((vip->phone_number == 0) || (vip->phone_number >= 1e11) || (vip->phone_number < 1e10))
        {
            system("cls");
            SetColor(4, 0);
            printf("�绰����������������룡");
            SetColor(15, 0);
            continue;
        }
        else if (in_list_satus == -1)
        {
            system("cls");
            SetColor(10, 0);
            HideConsoleCursor();
            printf("¼��ɹ���\n");
            SetColor(15, 0);
            return 0;
        }
        else
        {
            system("cls");
            SetColor(4, 0);
            SetColor(15, 0);
            char msg[200] = "";
            vip_msg(msg, vip_data, in_list_satus);
            system("cls");
            printf("�û�Ա�Ѵ��ڣ�");
            printf("%s\n", msg);
            system("pause");
            step = 0;
            system("cls");
            continue;
        }
    }
}
#endif