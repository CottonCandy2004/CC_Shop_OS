#ifndef STOCK_H
#define STOCK_H
#include "struct.h"
#include <stdio.h>
#include "freightlib.h"
#include "ui.h"
#include "show_stock.h"
#include "freight.h"
#include "freight_import.h"
#include "clear.h"
#include "destroy.h"

void stock_main()
{
    freight *stock_data = (freight *)malloc(sizeof(freight) * 3000);
    freight *stock_data_head = stock_data;
    int length = 0, changed = 0;
    int load_satus = load_stock_data(stock_data, &length);
    if (load_satus == -1)
        return;
    stock_data += length;
    char *notice1 = "��ѡ�����Ĳ�����";
    char *stock_choice[6] = {"1.����", "2.����̨", "3.����", "4.�Ƴ���Ʒ", "5.��ʾ���", "6.����"};
    char *Error1 = "��δʵ��";
    char *result = "";
    int ch = ui_choice(notice1, stock_choice, 6);
    int is_changed = 0;
    while (1)
    {
        if (ch == 0)
        {
            is_changed += import_stock(stock_data_head, &length);
        }
        if (ch == 2)
        {
            destroy();
        }
        if (ch == 3)
        {
            clear();
        }
        if (ch == 4)
        {
            show_mode(stock_data_head, length);
        }
        else if (ch == 1 || ch == 2 || ch == 3)
        {
            result = Error1;
            ch = ui_re_choice(notice1, stock_choice, 6, result, 4);
            break;
        }
        else if (ch == 5)
        {
            if (is_changed)
                save_stock_data(stock_data_head, &length);
            return;
        }
        ch = ui_choice(notice1, stock_choice, 6);
    }
}

#endif