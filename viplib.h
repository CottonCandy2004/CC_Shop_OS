#ifndef _VIPLIB_
#define _VIPLIB_
#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "ui_terminal.h"
#include "stdio.h"
#include "vip_show.h"
#include <iconv.h>

void vip_msg(char *msg, struct vip *vip, int serch_id)
{
    int length = strlen(msg);
    char *tail = msg + length;
    sprintf(tail, "\n�û�Ա�ĵǼ���Ϣ���£�\n\n"
                  "��Աid��%d\n"
                  "��Ա������%s\n"
                  "��Ա�绰��%lld\n"
                  "��Ա�����ܶ%lf\n"
                  "��Ա�������ʱ�䣺%d-%d-%d\n",
            vip[serch_id].id,
            vip[serch_id].name,
            vip[serch_id].phone_number,
            vip[serch_id].total_consume,
            vip[serch_id].last_consume_day.year,
            vip[serch_id].last_consume_day.month,
            vip[serch_id].last_consume_day.day);
}

int is_in_list(struct vip *vip, int list_length, unsigned long long phone_number)
{
    int flag = -1;
    system("cls");
    SetColor(15, 3);
    HideConsoleCursor();
    printf("���ڶ�λ����...");
    SetColor(15, 0);
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
    fp = fopen("vip.dat", "rb");
    if (fp == NULL)
    {
        fp = fopen("vip.dat", "wb");
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
        fread(vip_data_temp, sizeof(struct vip), 1, fp);
        if (!feof(fp))
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
    fp2 = fopen("vip.dat", "wb");
    for (int i = 0; i < *length; i++)
    {
        fwrite(vip_data_head, sizeof(struct vip), 1, fp2);
        vip_data_head ++;
    }
    fclose(fp2);
    system("cls");
    SetColor(10, 0);
    printf("����ɹ���\n");
    SetColor(15, 0);
    system("pause");
}

char *utb(char *in)
{
    unsigned long long inlen = strlen(in);
    unsigned long long outlen = inlen * 2;
    char *out = (char *)malloc(sizeof(char) * 20);
    char *out_head = out;
    iconv_t cd;
    char **pin = &in;
    char **pout = &out;
    cd = iconv_open("gb2312", "utf-8");
    memset(out, 0, 20);
    iconv(cd, pin, &inlen, pout, &outlen);
    iconv_close(cd);
    *pout = '\0';
    return out_head;
}

int import_from_csv(struct vip *vip_data_head, int *length)
{
    struct vip *vip_buff = (struct vip *)malloc(sizeof(struct vip) * 1000);
    struct vip *vip_head = vip_buff;
    int length_buff = *length;
    *length = 0;
    FILE *fp;
    fp = fopen("vip.csv", "r");
    if (fp == NULL)
    {
        system("cls");
        SetColor(4, 0);
        printf("�ļ������ڣ�\n");
        SetColor(15, 0);
        system("pause");
        return -1;
    }
    struct vip *vip_data_temp = (struct vip *)malloc(sizeof(struct vip));
    char temp[200];
    char szFlag[3];
    fread(szFlag, sizeof(char) * 3, 1, fp);
    fgets(temp, sizeof(temp), fp);
    while (1)
    {
        fscanf(fp, "%d,%lld,%[^,],%d,%d,%d,%lf", &vip_data_temp->id, &vip_data_temp->phone_number, vip_data_temp->name, &vip_data_temp->last_consume_day.year, &vip_data_temp->last_consume_day.month, &vip_data_temp->last_consume_day.day, &vip_data_temp->total_consume);
        char *name_2312 = utb(vip_data_temp->name);
        strcpy(vip_data_temp->name, name_2312);
        free(name_2312);
        if (!feof(fp))
        {
            (*length)++;
            *vip_buff = *vip_data_temp;
            vip_buff++;
            continue;
        }
        break;
    }
    show_vip(vip_head, *length);
    printf("\n�Ƿ�ȷ�ϵ���������Ϣ�� [Y]ȷ�� [N]ȡ��");
    while (1)
    {
        char choose = getch();
        if (choose == 'y' || choose == 'Y')
        {
            break;
        }
        else if (choose == 'n' || choose == 'N')
        {
            free(vip_data_temp);
            free(vip_head);
            *length = length_buff;
            system("cls");
            SetColor(4, 0);
            printf("��ȡ�����룡\n");
            SetColor(15, 0);
            system("pause");
            return -1;
        }
    }
    memcpy(vip_data_head, vip_head, sizeof(struct vip) * (*length));
    system("cls");
    SetColor(10, 0);
    printf("����ɹ���\n");
    SetColor(15, 0);
    free(vip_data_temp);
    free(vip_head);
    fclose(fp);
    return 0;
}
#endif