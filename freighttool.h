#ifndef FEIGHTTOOL_H
#define FEIGHTTOOL_H

#include <string.h>
#include <stdio.h>
#include "struct.h"
void freight_msg(char *msg, freight *freight, int serch_id)
{
    memset(msg, 0, sizeof(char) * 100);
    int length = strlen(msg);
    char *tail = msg + length;
    sprintf(tail, "该商品信息如下：\n\n"
                  "商品EAN码：%llu\n"
                  "商品名称：%s\n"
                  "商品库存数量：%d\n"
                  "商品进货价：%.2lf\n"
                  "商品售价：%.2lf\n",
            freight[serch_id].EAN,
            freight[serch_id].name,
            freight[serch_id].stock,
            freight[serch_id].purchase_price,
            freight[serch_id].sale_price);
}

#endif