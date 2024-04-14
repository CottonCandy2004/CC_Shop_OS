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
        char *message = "��ѡ��Ҫ��ʾ����ģʽ��";
        char *ch1 = "��ʾ���";
        char *ch2 = "��ʾ��棨��ӯ������";
        char *ch3 = "�������ӯ����¼";
        char *ch4 = "����";
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
    printf("��Ʒ���\t��Ʒ����\t\t��Ʒ���\t��Ʒ����\t��Ʒ�ۼ�\t��Ʒ����\n");
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
    char *choice1 = "[N]��";
    char *choice2 = "[Y]��";
    char *choi[2] = {choice1, choice2};
    int choice = ui_re_choice("�Ƿ�ȷ���������ӯ����¼��", choi, 2, "���棺�ò���һ�������޷���ԭ", 4);
    SetColor(15, 0);
    if (choice == 0)
    {
        system("cls");
        printf("������ȡ����");
        Sleep(1000);
        return -1;
    }
    else if (choice == 1)
    {
        int auth_satus = auth();
        if (auth_satus == -2)
        {
            system("cls");
            printf("�������");
            Sleep(1000);
            return -2;
        }
        else if (auth_satus == 200)
        {
            system("cls");
            printf("�����������ӯ����¼...");
            for (int i = 0; i < length; i++)
            {
                data[i].margins = 0;
            }
            silent_save_stock_data(data, &length);
            system("cls");
            printf("��������ɡ�");
            Sleep(1000);
            return 0;
        }
    }
}

#endif