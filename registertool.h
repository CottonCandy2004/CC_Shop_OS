#ifndef REGISTERTOOL_H
#define REGISTERTOOL_H
#include <stdio.h>
#include <time.h>
#include "struct.h"

void timeput(struct vip *vip_data, int vip_search_id)
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    vip_data[vip_search_id].last_consume_day.year = (localTime->tm_year + 1900);
    vip_data[vip_search_id].last_consume_day.month = localTime->tm_mon;
    vip_data[vip_search_id].last_consume_day.day = localTime->tm_mday;
}
void timesearch(struct vip *vip_data, int vip_search_id)
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    if (vip_data[vip_search_id].last_consume_day.year < localTime->tm_year && vip_data[vip_search_id].last_consume_day.month < localTime->tm_mon && vip_data[vip_search_id].last_consume_day.day < localTime->tm_mday)
    {
        vip_data[vip_search_id].total_consume = 0;
    }
}

void Discount_calculation(receipts *receipts_data, struct vip *vip_data, int vip_search_id, int m)
{
    double discount = 1;
    if (vip_data[vip_search_id].total_consume >= 300 && vip_data[vip_search_id].total_consume < 600)
    {
        discount = 0.95;
    }
    else if (vip_data[vip_search_id].total_consume >= 600)
    {
        discount = 0.9;
    }
    receipts_data[m].discount_price = (receipts_data[m].unit_price * discount);
}
double fresum(receipts *receipts_data, int *receipts_length)
{
    double sum = 0;
    int i;
    while (receipts_data[*receipts_length].EAN != 0)
    {
        (*receipts_length)++;
    }
    for (i = 0; i < (*receipts_length); i++)
    {
        sum += (receipts_data[i].discount_price * receipts_data[i].num);
    }
    return sum;
}

void receipts_vip(receipts *receipts, int length, double sum)
{
    system("cls");
    SetColor(3, 0);
    printf("商品名称\t商品单价\t商品折扣价\t数量\t总价\n");
    for (int i = 0; i < length; i++)
    {
        printf("%-16s%-16.2f%-16.2f%-8d%-16.2f\n", receipts[i].name, receipts[i].unit_price, receipts[i].discount_price, receipts[i].num, receipts[i].sum_price);
    }
    printf("\n总计\t\t\t\t\t\t\t%.2f\n", sum);
    return;
}

#endif