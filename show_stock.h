#ifndef SHOW_STOCK_H
#define SHOW_STOCK_H

#include "struct.h"
#include "algorithm.h"
#include "ui.h"
#include "ui_terminal.h"
#include <stdlib.h>

void show_stock(freight *data,int length);
void show_stock_sort(freight *data,int length);
void show_mode(freight *data,int length)
{
    while (1)
    {
        system("cls");
        fflush(stdin);
        char *message = "��ѡ��Ҫ��ʾ����ģʽ��";
        char *ch1 = "��ʾ���";
        char *ch2 = "��ʾ��棨��ӯ������";
        char *ch3 = "����";
        char *choice[3] = {ch1, ch2,ch3};
        int ch = ui_choice(message, choice, 3);
        switch (ch)
        {
        case 0:
            show_stock(data,length);
            continue;
        case 1:
            show_stock_sort(data,length);
            continue;
        }
        if (ch == 2)
        {
            break;
        }
    }
}

void show_stock(freight *data,int length)
{
    system("cls");
    SetColor(3,0);
    printf("��Ʒ���\t��Ʒ����\t\t��Ʒ���\t��Ʒ����\t��Ʒ�ۼ�\t��Ʒ����\n");
    for (int i = 0; i < length; i++)
    {
        printf("%llu\t%-24s%d\t\t%d\t\t%d\t\t%d\n", data[i].EAN, data[i].name, data[i].stock, data[i].purchase_price, data[i].sale_price, data[i].margins);
    }
    system("pause");
    SetColor(15,0);
}

void show_stock_sort(freight *data,int length)
{
    system("cls");
    SetColor(3,0);
    printf("Sorting...");
    freight *buff=(freight*)malloc(length*sizeof(freight));
    for (int i = 0; i < length; i++)
    {
        buff[i]=data[i];
    }
    sort_freight(buff,buff+length-1);
    SetColor(15,0);
    show_stock(buff,length);
    free(buff);
}

#endif