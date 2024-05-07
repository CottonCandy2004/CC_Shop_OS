#ifndef _FREIGHT_H_
#define _FREIGHT_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"

int fright_import()
{
    char *notice1 = "请选择您的操作：";
    char *notice2 = "请选择你要重新输入的选项";
    char *notice3 = "是否还有需要更改的选项？";
    char *choice1 = "1.确认正确";
    char *choice2 = "2.重新输入";
    char *choice3 = "1.EAN码";
    char *choice4 = "2.名称";
    char *choice5 = "3.进货数量";
    char *choice6 = "4.进货价";
    char *choice7 = "5.售价";
    char *choice8 = "Y.是";
    char *choice9 = "N.否";
    char *freight_choice1[2] = {choice1, choice2};
    char *freight_choice2[5] = {choice3, choice4, choice5, choice6, choice7};
    char *freight_choice3[2] = {choice8, choice9};
    printf("请问您要引进多少种货品？\n");
    int n = -1, i, q, ch, ch1, ch2, x, y, length = 0, mode, m = 0;
    scanf("%d", &n);
    char buff = getchar();
    if (buff != '\n')
        n = -1;
    while (n < 0)
    {
        printf("输入不合法，请重新输入\n");
        fflush(stdin);
        system("pause");
        printf("请问您要引进多少种货品？\n");
        scanf("%d", &n);
        char buff = getchar();
        if (buff != '\n')
            n = -1;
    }
    freight *p = (freight *)malloc(1000 * sizeof(freight));
    fflush(stdin);
    y = load_stock_data(p, &length);
    for (i = 0; i < (n + m); i++)
    {
        q = 0, mode = 0;
        system("cls");
        printf("请输入\n第%d种货品的EAN码:", (i + 1));
        scanf("%lld", &p[length + i].EAN);
        buff = getchar();
        if (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
            p[length + i].EAN = 0;
        while (p[length + i].EAN <= 0)
        {
        EANER:
            printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品EAN码:");
            scanf("%lld", &p[length + i].EAN);
            buff = getchar();
            if (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
                p[length + i].EAN = 0;
        }
        while (length + i > q)
        {
            if (p[length + i].EAN == p[q].EAN)
            {
                printf("此商品已在库中\n");
                mode = 1;
            }
            q++;
        }
        if (mode == 0)
        {
            printf("此商品为首次入库\n");
        }
        printf("货品的名称:");
        scanf("%s", p[length + i].name);
        fflush(stdin);
        printf("货品的进货数量:");
        scanf("%d", &p[length + i].stock);
        buff = getchar();
        if (buff != '\n')
            p[length + i].stock = -1;
        while (p[length + i].stock < 0)
        {
            printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的进货数量:");
            scanf("%d", &p[length + i].stock);
            buff = getchar();
            if (buff != '\n')
                p[length + i].stock = -1;
        }
        printf("货品的进货价:");
        scanf("%d", &p[length + i].purchase_price);
        buff = getchar();
        if (buff != '\n')
            p[length + i].purchase_price = -1;
        while (p[length + i].purchase_price < 0)
        {
        PURCHASEER:
            printf("进货价不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的进货价:");
            scanf("%d", &p[length + i].purchase_price);
            buff = getchar();
            if (buff != '\n')
                p[length + i].purchase_price = -1;
        }
        printf("货品的售价:");
        scanf("%d", &p[length + i].sale_price);
        buff = getchar();
        if (buff != '\n')
            p[length + i].sale_price = -1;
        while (p[length + i].sale_price < 0)
        {
        SALEER:
            printf("售价不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的售价:");
            scanf("%d", &p[length + i].sale_price);
            buff = getchar();
            if (buff != '\n')
                p[length + i].sale_price = -1;
        }
        while (p[length + i].purchase_price > p[length + i].sale_price)
        {
            printf("进货价不能大于售价，请重新输入\n");
            printf("货品的进货价:");
            scanf("%d", &p[length + i].purchase_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[length + i].purchase_price = -1;
                goto PURCHASEER;
            }
            printf("货品的售价:");
            scanf("%d", &p[length + i].sale_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[length + i].sale_price = -1;
                goto SALEER;
            }
        }
        system("cls");
        printf("请确认您输入的商品信息\n");
        printf("EAN:%lld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[length + i].EAN, p[length + i].name, p[length + i].stock, p[length + i].purchase_price, p[length + i].sale_price);
        system("pause");
        int result_colour = 0;
        ch = ui_choice(notice1, freight_choice1, 2);
        if (ch == 1)
        {
            ch2 = 0;
            for (; ch2 == 0;)
            {
                ch1 = ui_choice(notice2, freight_choice2, 5);
                fflush(stdin);
                switch (ch1)
                {
                case 0:
                    printf("请重新输入货品的EAN码\n");
                    scanf("%lld", &p[length + i].EAN);
                    buff = getchar();
                    if (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
                        p[length + i].EAN = 0;
                    while (p[length + i].EAN <= 0)
                    {
                    EAN2ER:
                        printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("请重新输入货物的EAN码:");
                        scanf("%lld", &p[length + i].EAN);
                        buff = getchar();
                        if (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
                            p[length + i].EAN = 0;
                    }
                    q = 0;
                    while (length + i > q)
                    {
                        if (p[length + i].EAN == p[q].EAN)
                        {
                            printf("此商品已在库中\n");
                            mode = 1;
                        }
                        q++;
                    }
                    if (mode == 0)
                    {
                        printf("此商品为首次入库\n");
                    }
                    break;
                case 1:
                    printf("重新输入货品的名称:");
                    scanf("%s", p[length + i].name);
                    break;
                case 2:
                    printf("重新输入货品的进货数量:");
                    scanf("%d", &p[length + i].stock);
                    buff = getchar();
                    if (buff != '\n')
                        p[length + i].stock = -1;
                    while (p[length + i].stock < 0)
                    {
                        printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的进货数量:");
                        scanf("%d", &p[length + i].stock);
                        buff = getchar();
                        if (buff != '\n')
                            p[length + i].stock = -1;
                    }
                    break;
                case 3:
                    printf("重新输入货品的进货价:");
                    scanf("%d", &p[length + i].purchase_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[length + i].purchase_price = -1;
                    while (p[length + i].purchase_price < 0)
                    {
                    PURCHASEER2:
                        printf("进货价不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的进货价:");
                        scanf("%d", &p[length + i].purchase_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[length + i].purchase_price = -1;
                    }
                    while (p[length + i].purchase_price > p[length + i].sale_price)
                    {
                        printf("进货价不能大于售价，请重新输入\n");
                        printf("重新输入货品的进货价:");
                        scanf("%d", &p[length + i].purchase_price);
                        buff = getchar();
                        if (buff != '\n')
                        {
                            p[length + i].purchase_price = -1;
                            goto PURCHASEER2;
                        }
                    }
                    break;
                case 4:
                    printf("重新输入货品的售价:");
                    scanf("%d", &p[length + i].sale_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[length + i].sale_price = -1;
                    while (p[length + i].sale_price < 0)
                    {
                    SALEER2:
                        printf("售价不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的售价:");
                        scanf("%d", &p[length + i].sale_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[length + i].sale_price = -1;
                    }
                    while (p[length + i].purchase_price > p[length + i].sale_price)
                    {
                        printf("售价不能小于进货价，请重新输入\n");
                        printf("重新输入货品的售价:");
                        scanf("%d", &p[length + i].sale_price);
                        buff = getchar();
                        if (buff != '\n')
                        {
                            p[length + i].sale_price = -1;
                            goto SALEER2;
                        }
                    }
                    break;
                }
                fflush(stdin);
                system("cls");
                printf("修改后数据如下\nEAN码:%lld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[length + i].EAN, p[length + i].name, p[length + i].stock, p[length + i].purchase_price, p[length + i].sale_price);
                system("pause");
                ch2 = ui_choice(notice3, freight_choice3, 2);
            }
        }
        if (mode == 1)
        {
            p[q].purchase_price = ((p[length + i].purchase_price * p[length + i].stock) + (p[q].purchase_price * p[q].stock)) / (p[q].stock + p[length + i].stock);
            p[q].stock += p[length + i].stock;
            p[q].sale_price = p[length + i].sale_price;
            init_freight(p + length + i);
            i--;
            m--;
        }
    }
    x = save_stock_data(p, &n);
}

#endif