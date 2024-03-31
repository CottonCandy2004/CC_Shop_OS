#ifndef _VIPLIB_
#define _VIPLIB_
#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "ui_terminal.h"
#include "stdio.h"
void vip_msg(char *msg, struct vip *vip, int serch_id)
{
    char phone_number_str[12];
    sprintf(phone_number_str, "%lld", vip[serch_id].phone_number);
    strcat(msg, phone_number_str);
    strcat(msg, "\n�û�Ա�ĵǼ���Ϣ���£�\n\n��Աid��");
    char id_str[sizeof(int) + 1];
    sprintf(id_str, "%d", vip[serch_id].id);
    strcat(msg, id_str);
    strcat(msg, "\n��Ա������");
    strcat(msg, vip[serch_id].name);
    strcat(msg, "\n��Ա�绰��");
    strcat(msg, phone_number_str);
    strcat(msg, "\n��Ա�����ܶ");
    char total_consume_str[sizeof(double) + 1];
    sprintf(total_consume_str, "%lf", vip[serch_id].total_consume);
    strcat(msg, total_consume_str);
    strcat(msg, "\n��Ա�������ʱ�䣺");
    char last_consume_day_str[12];
    sprintf(last_consume_day_str, "%d-%d-%d\n", vip[serch_id].last_consume_day.year, vip[serch_id].last_consume_day.month, vip[serch_id].last_consume_day.day);
    strcat(msg, last_consume_day_str);
}

int is_in_list(struct vip *vip, int list_length, unsigned long long phone_number)
{
    int flag = -1;
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("���ڶ�λ����...");
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

int load_vip_data(struct vip *vip_data, int *length)
{
    FILE *fp;
    fp = fopen("vip.dat", "r");
    if (fp == NULL)
    {
        fp = fopen("vip.dat", "w");
        if (fp == NULL)
        {
            system("cls");
            SetColor(4, 0);
            printf("���̶�д������������Ƿ�����ӦĿ¼�Ķ�дȨ�ޣ�\n");
            SetColor(15, 0);
            system("pause");
            return -1;
        }
    }

    while (1)
    {
        struct vip *vip_data_temp = (struct vip *)malloc(sizeof(struct vip));
        if (fread(vip_data_temp, sizeof(struct vip), 1, fp) == 1)
        {
            (*length)++;
            *vip_data = *vip_data_temp;
            vip_data++;
        }
        else
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}

int save_vip_data(struct vip *vip_data_head, int *length)
{
    FILE *fp2;
    fp2 = fopen("vip.dat", "w");
    fwrite(vip_data_head, sizeof(struct vip), *length, fp2);
    fclose(fp2);
    system("cls");
    SetColor(10, 0);
    printf("����ɹ���\n");
    SetColor(15, 0);
    system("pause");
}
#endif