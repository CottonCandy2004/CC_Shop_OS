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
    int n = -1, i, q, ch, ch1, ch2, x;
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
    freight *p = (freight *)malloc(n * sizeof(freight));
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        q = 0;
        system("cls");
        printf("请输入\n第%d种货品的EAN码:", (i + 1));
        scanf("%lld", &p[i].EAN);
        buff = getchar();
        if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
            p[i].EAN = 0;
        while (p[i].EAN <= 0)
        {
        EANER:
            printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品EAN码:");
            scanf("%lld", &p[i].EAN);
            buff = getchar();
            if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                p[i].EAN = 0;
        }
        while (i > q)
        {
            if (p[i].EAN == p[q].EAN)
            {
                printf("货品的EAN码重复，请确认输入是否正确，并重新输入\n");
                system("pause");
                printf("重新输入EAN码\n");
                scanf("%lld", &p[i].EAN);
                buff = getchar();
                if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                {
                    p[i].EAN = 0;
                    goto EANER;
                }
                q = -1;
            }
            q++;
        }
        printf("货品的名称:");
        scanf("%s", p[i].name);
        fflush(stdin);
        printf("货品的进货数量:");
        scanf("%d", &p[i].stock);
        buff = getchar();
        if (buff != '\n')
            p[i].stock = -1;
        while (p[i].stock < 0)
        {
            printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的进货数量:");
            scanf("%d", &p[i].stock);
            buff = getchar();
            if (buff != '\n')
                p[i].stock = -1;
        }
        printf("货品的进货价:");
        scanf("%d", &p[i].purchase_price);
        buff = getchar();
        if (buff != '\n')
            p[i].purchase_price = -1;
        while (p[i].purchase_price < 0)
        {
        PURCHASEER:
            printf("进货价不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的进货价:");
            scanf("%d", &p[i].purchase_price);
            buff = getchar();
            if (buff != '\n')
                p[i].purchase_price = -1;
        }
        printf("货品的售价:");
        scanf("%d", &p[i].sale_price);
        buff = getchar();
        if (buff != '\n')
            p[i].sale_price = -1;
        while (p[i].sale_price < 0)
        {
        SALEER:
            printf("售价不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的售价:");
            scanf("%d", &p[i].sale_price);
            buff = getchar();
            if (buff != '\n')
                p[i].sale_price = -1;
        }
        while (p[i].purchase_price > p[i].sale_price)
        {
            printf("进货价不能大于售价，请重新输入\n");
            printf("货品的进货价:");
            scanf("%d", &p[i].purchase_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[i].purchase_price = -1;
                goto PURCHASEER;
            }
            printf("货品的售价:");
            scanf("%d", &p[i].sale_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[i].sale_price = -1;
                goto SALEER;
            }
        }
        system("cls");
        printf("请确认您输入的商品信息\n");
        printf("EAN:%lld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
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
                    scanf("%lld", &p[i].EAN);
                    buff = getchar();
                    if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                        p[i].EAN = 0;
                    while (p[i].EAN <= 0)
                    {
                    EAN2ER:
                        printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("请重新输入货物的EAN码:");
                        scanf("%lld", &p[i].EAN);
                        buff = getchar();
                        if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                            p[i].EAN = 0;
                    }
                    q = 0;
                    while (i > q)
                    {
                        if (p[i].EAN == p[q].EAN)
                        {
                            printf("货品的EAN码重复，请确认输入是否正确，并重新输入\n");
                            system("pause");
                            system("cls");
                            printf("重新输入EAN码:\n");
                            scanf("%lld", &p[i].EAN);
                            buff = getchar();
                            if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                            {
                                p[i].EAN = 0;
                                goto EAN2ER;
                            }
                            q = -1;
                        }
                        q++;
                    }
                    break;
                case 1:
                    printf("重新输入货品的名称:");
                    scanf("%s", p[i].name);
                    break;
                case 2:
                    printf("重新输入货品的进货数量:");
                    scanf("%d", &p[i].stock);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].stock = -1;
                    while (p[i].stock < 0)
                    {
                        printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的进货数量:");
                        scanf("%d", &p[i].stock);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].stock = -1;
                    }
                    break;
                case 3:
                    printf("重新输入货品的进货价:");
                    scanf("%d", &p[i].purchase_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].purchase_price = -1;
                    while (p[i].purchase_price < 0)
                    {
                    PURCHASEER2:
                        printf("进货价不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的进货价:");
                        scanf("%d", &p[i].purchase_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].purchase_price = -1;
                    }
                    while (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("进货价不能大于售价，请重新输入\n");
                        printf("重新输入货品的进货价:");
                        scanf("%d", &p[i].purchase_price);
                        buff = getchar();
                        if (buff != '\n')
                        {
                            p[i].purchase_price = -1;
                            goto PURCHASEER2;
                        }
                    }
                    break;
                case 4:
                    printf("重新输入货品的售价:");
                    scanf("%d", &p[i].sale_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].sale_price = -1;
                    while (p[i].sale_price < 0)
                    {
                    SALEER2:
                        printf("售价不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的售价:");
                        scanf("%d", &p[i].sale_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].sale_price = -1;
                    }
                    while (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("售价不能小于进货价，请重新输入\n");
                        printf("重新输入货品的售价:");
                        scanf("%d", &p[i].sale_price);
                        buff = getchar();
                        if (buff != '\n')
                        {
                            p[i].sale_price = -1;
                            goto SALEER2;
                        }
                    }
                    break;
                }
                fflush(stdin);
                system("cls");
                printf("修改后数据如下\nEAN码:%lld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
                system("pause");
                ch2 = ui_choice(notice3, freight_choice3, 2);
            }
        }
    }
    x = save_stock_data(p, &n);
}

#endif