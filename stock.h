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
#include "Cash_register.h"

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
    int is_changed = 0;
    int ch;
    while (1)
    {
        ch = ui_choice(notice1, stock_choice, 6);
        switch(ch){
        case 0:
            is_changed += import_stock(stock_data_head, &length);
        	break;
        case 2:
            destroy();
        	break;
        case 3:
            clear();
        	break;
        case 4:
            show_mode(stock_data_head, length);
        	break;
        case 1:
        	casher();
            break;
        case 5:
            if (is_changed)
        		save_stock_data(stock_data_head, &length);
            return;
        }
    }
}

#endif