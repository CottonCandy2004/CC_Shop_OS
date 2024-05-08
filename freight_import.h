#ifndef FREIGHT_IMPORT_H
#define FREIGHT_IMPORT_H

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include "freightlib.h"
#include <string.h>
#include <conio.h>
#include "ui.h"

int EANcheck(unsigned long long EAN)
{
    return EAN >= 1e12 && EAN < 1e13;
}

void input_purchase_price(freight *buff, int stock, int stock_in)
{
    double temp = 0;
    while (temp <= 0)
    {
        printf("����������۸�\n");
        scanf("%lf", &temp);
        if (temp <= 0)
        {
            printf("�����۸񲻺Ϸ������������롣\n");
        }
        fflush(stdin);
    }
    buff->purchase_price = (buff->purchase_price * stock + temp * stock_in) / (stock + stock_in);
}

void input_sale_price(freight *buff)
{
    double temp = 0;
    while (temp <= 0)
    {
        printf("�������۳��۸�\n");
        scanf("%lf", &temp);
        if (temp <= 0)
        {
            printf("�۳��۸񲻺Ϸ������������롣\n");
            fflush(stdin);
            continue;
        }
        fflush(stdin);
        if (temp < buff->purchase_price)
        {
            printf("�۳��۸���ڽ����۸��ٴλس���ȷ�ϡ�\n");
            int key = getch();
            if (key == '\r')
            {
                buff->sale_price = temp;
                printf("��ȷ�ϡ�\n");
                break;
            }
            else
            {
                printf("��ȡ����\n");
                temp = 0;
                continue;
            }
        }
        buff->sale_price = temp;
    }
}

int import_stock(freight *stock, int *length)
{
    int is_changed = 0;
    freight *buff = (freight *)malloc(sizeof(freight));
    int flag = 0;
    init_freight(buff);
    while (1)
    {
        if (flag == 0)
        {
            buff->EAN = 1;
            printf("��������ƷEAN��ţ�0�˳�����\n");
            fflush(stdin);
            scanf("%lld", &buff->EAN);
            if (buff->EAN == 0)
            {
                free(buff);
                return is_changed;
            }
            if (!EANcheck(buff->EAN))
            {
                printf("��ƷEAN��Ų��Ϸ������������롣\n");
                continue;
            }
            flag = 1;
        }
        fflush(stdin);
        int no = is_in_stock(stock, *length, buff->EAN);
        int stock_num = 0;
        if (no != -1)
        {
            system("cls");
            *buff = stock[no];
            char msg_confirm[100] = "";
            stock_msg(msg_confirm, stock, no);
            stock_num = stock[no].stock;
            printf("%s", msg_confirm);
            flag = 2;
        }
        if (flag == 1)
        {
            printf("�������Ʒ���ƣ�\n");
            fgets(buff->name, 20, stdin);
            buff->name[strlen(buff->name) - 1] = '\0';
            fflush(stdin);
            flag = 2;
        }
        int stock_num_in = -1;
        if (flag == 2)
        {
            while (stock_num_in < 0)
            {
                printf("���������������\n");
                scanf("%d", &stock_num_in);
                if (stock_num_in < 0)
                {
                    printf("����������������롣\n");
                }
                fflush(stdin);
            }
            buff->stock += stock_num_in;
            flag = 3;
        }
        if (flag == 3)
        {
            input_purchase_price(buff, stock_num, stock_num_in);
            flag = 4;
        }
        if (no != -1)
        {
            system("cls");
            char msg_buff[500] = "�Ƿ��޸��ۼۣ�\n";
            char *arr[2] = {"��", "��"};
            stock_msg(msg_buff, buff, 0);
            if (ui_choice(msg_buff, arr, 2) == 0)
            {
                flag = 5;
            }
            else
            {
                flag = 4;
            }
        }
        if (flag == 4)
        {
            input_sale_price(buff);
            flag = 5;
        }
        if (flag == 5)
        {
            char msg[100] = "";
            stock_msg(msg, buff, 0);
            char *arr[2] = {"ȷ����ȷ", "��������"};
            if (ui_choice(msg, arr, 2) == 1)
            {
                flag = 0;
                continue;
            }
            else
            {
                flag = 0;
                is_changed = 1;
                if (no != -1)
                {
                    stock[no] = *buff;
                }
                else
                {
                    stock[*length] = *buff;
                    (*length)++;
                }
            }
        }
    }
}
#endif