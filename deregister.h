#ifndef _DEREGISTER_H_
#define _DEREGISTER_H_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "ui_terminal.h"
#include "ui.h"
#include <string.h>
void deregister(struct vip *vip, int list_length);
int is_in_list(struct vip *vip, int list_length,unsigned long long phone_number);
void del_vip(struct vip *vip, int *list_length, int id);

int is_in_list(struct vip *vip, int list_length, unsigned long long phone_number)
{
    int flag = -1;
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("正在定位数据...");
    SetColor(15, 0);
    // Sleep(1000);
    for (int i = 0; i < list_length; i++)
    {
        if (vip[i].phone_number == phone_number)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

void del_vip(struct vip *vip, int *list_length, int id)
{
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("正在处理...");
    SetColor(15, 0);
    for (int i = id; i < *list_length - 1; i++)
    {
        vip[i] = vip[i + 1];
    }
    init_vip(vip + (*list_length) - 1);
    (*list_length)--;
    // Sleep(1000);
}

void deregister(struct vip *vip, int list_length)
{
    unsigned long long phone_number;
    system("cls");
    while (1)
    {
        printf("\n请输入要注销会员的手机号：");
        ShowConsoleCursor();
        scanf("%lld", &phone_number);
        int serch_id=is_in_list(vip, list_length, phone_number);
        if (serch_id == -1)
        {
            system("cls");
            SetColor(4, 0);
            printf("手机号不存在，请重新输入！");
            SetColor(15, 0);
            continue;
        }
        else
        {
            char msg[200]="是否确认删除会员";
            char phone_number_str[12];
            sprintf(phone_number_str, "%lld", phone_number);
            strcat(msg, phone_number_str);
            strcat(msg,"？\n该会员的登记信息如下：\n\n会员id：");
            char id_str[sizeof(int)+1];
            sprintf(id_str, "%d", vip[serch_id].id);
            strcat(msg, id_str);
            strcat(msg, "\n会员姓名：");
            strcat(msg, vip[serch_id].name);
            strcat(msg, "\n会员电话：");
            strcat(msg, phone_number_str);
            strcat(msg, "\n会员消费总额：");
            char total_consume_str[sizeof(int)+1];
            sprintf(total_consume_str, "%d", vip[serch_id].total_consume);
            strcat(msg, total_consume_str);
            strcat(msg,"\n会员最后消费时间：");
            char last_consume_day_str[12];
            sprintf(last_consume_day_str, "%d-%d-%d\n", vip[serch_id].last_consume_day.year, vip[serch_id].last_consume_day.month, vip[serch_id].last_consume_day.day);
            strcat(msg, last_consume_day_str);
            char *choices[2] = {"[N]取消注销", "[Y]确认注销"};
            int result = ui_choice(msg, choices, 2);
            if (result == 1)
            {
                del_vip(vip, &list_length, serch_id);
                system("cls");
                SetColor(10, 0);
                printf("注销成功！\n");
                SetColor(15, 0);
                system("pause");
                return;
            }
            else
            {
                system("cls");
                SetColor(4, 0);
                printf("注销已经取消！\n");
                SetColor(15, 0);
                system("pause");
                return;
            }
        }
    }
}
#endif