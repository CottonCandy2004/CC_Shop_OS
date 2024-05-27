#ifndef __FREIGHTLIB_H__
#define __FREIGHTLIB_H__
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "ui_terminal.h"

int load_stock_data(freight *stock_data, int *length)
{
    FILE *fp;
    fp = fopen("stock.dat", "rb");
    if (fp == NULL)
    {
        fp = fopen("stock.dat", "wb");
        if (fp == NULL)
        {
            system("cls");
            SetColor(4, 0);
            printf("磁盘读写错误，请检查程序是否有相应目录的读写权限！\n");
            SetColor(15, 0);
            system("pause");
            return -1;
        }
        return 0;
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
        free(stock_data_temp);
    }
    fclose(fp);
    return 0;
}

int save_stock_data(freight *stock_data_head, int *length)
{
    FILE *fp2;
    fp2 = fopen("stock.dat", "wb");
    if (fp2 == NULL)
    {
        system("cls");
        SetColor(4, 0);
        printf("磁盘读写错误，请检查程序是否有相应目录的读写权限！\n");
        SetColor(15, 0);
        system("pause");
        return -1;
    }
    fwrite(stock_data_head, sizeof(freight), *length, fp2);
    fclose(fp2);
    system("cls");
    SetColor(10, 0);
    printf("保存成功！\n");
    SetColor(15, 0);
    system("pause");
}

int is_in_stock(freight *stock, int length, unsigned long long EAN)
{
    for (int i = 0; i < length; i++)
    {
        if (stock[i].EAN == EAN)
        {
            return i;
        }
    }
    return -1;
}

void stock_msg(char *msg, freight *stock, int serch_id)
{
    int length = strlen(msg);
    char *tail = msg + length;
    sprintf(tail, "\n该货物的登记信息如下：\n\n"
                  "EAN：%lld\n"
                  "货物名称：%s\n"
                  "库存量：%d\n"
                  "进货价格：%.2lf￥\n"
                  "售出价格：%.2lf￥\n"
                  "盈利价格：%.2lf￥\n",
            stock[serch_id].EAN,
            stock[serch_id].name,
            stock[serch_id].stock,
            stock[serch_id].purchase_price,
            stock[serch_id].sale_price,
            stock[serch_id].margins);
}

int silent_save_stock_data(freight *stock_data_head, int *length)
{
    FILE *fp2;
    fp2 = fopen("stock.dat", "wb");
    fwrite(stock_data_head, sizeof(freight), *length, fp2);
    fclose(fp2);
}
#endif