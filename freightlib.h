#ifndef __FREIGHTLIB_H__
#define __FREIGHTLIB_H__
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "ui_terminal.h"

int load_stock_data(freight *stock_data, int *length)
{
    FILE *fp;
    fp = fopen("stock.dat", "r");
    if (fp == NULL)
    {
        fp = fopen("stock.dat", "w");
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
        freight *stock_data_temp = (freight *)malloc(sizeof(freight));
        if (fread(stock_data_temp, sizeof(freight), 1, fp) == 1)
        {
            (*length)++;
            *stock_data = *stock_data_temp;
            stock_data++;
        }
        else
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}

int save_stock_data(freight *stock_data_head, int *length)
{
    FILE *fp2;
    fp2 = fopen("stock.dat", "w");
    fwrite(stock_data_head, sizeof(freight), *length, fp2);
    fclose(fp2);
    system("cls");
    SetColor(10, 0);
    printf("����ɹ���\n");
    SetColor(15, 0);
    system("pause");
}

int silent_save_stock_data(freight *stock_data_head, int *length)
{
    FILE *fp2;
    fp2 = fopen("stock.dat", "w");
    fwrite(stock_data_head, sizeof(freight), *length, fp2);
    fclose(fp2);
}
#endif