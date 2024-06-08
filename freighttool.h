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
    sprintf(tail, "����Ʒ��Ϣ���£�\n\n"
                  "��ƷEAN�룺%llu\n"
                  "��Ʒ���ƣ�%s\n"
                  "��Ʒ���������%d\n"
                  "��Ʒ�����ۣ�%.2lf\n"
                  "��Ʒ�ۼۣ�%.2lf\n",
            freight[serch_id].EAN,
            freight[serch_id].name,
            freight[serch_id].stock,
            freight[serch_id].purchase_price,
            freight[serch_id].sale_price);
}

#endif