#ifndef _FREIGHT_H_
#define _FREIGHT_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"
#include "freighttool.h"

int fright_import()
{
    char *notice1 = "请选择您的操作：";
    char *notice2 = "请选择你要重新输入的选项";
    char *notice3 = "是否还有需要更改的选项？";
    char *notice4 = "货物的进货价不能大于售价打九折，请确认是否正确";
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
    int i = 0, q, ch, ch1, ch2,ch3, x, y, length = 0, mode;
    char buff;
    char *msg = (char *)malloc(sizeof(char) * 100);    
    freight *p = (freight *)malloc(1000 * sizeof(freight));
    y = load_stock_data(p, &length);
    while (1)
    {
        q = 0, mode = 0;
        system("cls");
        printf("请输入货品的EAN码:（输入0退出进货）");
        scanf("%llu", &p[length + i].EAN);
        buff = getchar();
        if (p[length + i].EAN == 0)
        {
            break;
        }
        while (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
        {
            printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品EAN码:");
            scanf("%llu", &p[length + i].EAN);
            buff = getchar();
        }
        while (length + i > q)
        {
            if (p[length + i].EAN == p[q].EAN)
            {
                printf("此商品已在库中\nEAN码:%llu\n名称:%s\n库存数量:%d\n进货价:%.2lf\n售价:%.2lf\n", p[q].EAN, p[q].name, p[q].stock, p[q].purchase_price, p[q].sale_price);
                mode = 1;
                break;
            }
            q++;
        }
        if (mode == 0)
        {
            printf("此商品为首次入库\n");
            printf("货品的名称:");
            scanf("%s", p[length + i].name);
        }
        fflush(stdin);
        printf("货品的进货数量:");
        scanf("%d", &p[length + i].stock);
        buff = getchar();
        while (p[length + i].stock < 0 || buff != '\n')
        {
            printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("货品的进货数量:");
            scanf("%d", &p[length + i].stock);
            buff = getchar();
        }
        while (1)
        {
            printf("货品的进货价:");
            scanf("%lf", &p[length + i].purchase_price);
            buff = getchar();
            while (p[length + i].purchase_price < 0 || buff != '\n')
            {
                printf("进货价不合法，请确认输入是否正确，并重新输入\n");
                fflush(stdin);
                system("pause");
                printf("货品的进货价:");
                scanf("%lf", &p[length + i].purchase_price);
                buff = getchar();
            }
            printf("货品的售价:");
            scanf("%lf", &p[length + i].sale_price);
            buff = getchar();
            while (p[length + i].sale_price < 0 || buff != '\n')
            {
                printf("售价不合法，请确认输入是否正确，并重新输入\n");
                fflush(stdin);
                system("pause");
                printf("货品的售价:");
                scanf("%lf", &p[length + i].sale_price);
                buff = getchar();
            }
            if (p[length + i].purchase_price > (0.9*p[length + i].sale_price))
            {
                printf("进货价不能大于售价打九折，请重新输入\n");
                continue;
            }
            break;
        }
        system("cls");
        freight_msg(msg,p,length + i);
        printf("%s",msg);
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
                    scanf("%llu", &p[length + i].EAN);
                    buff = getchar();
                    while (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
                    {
                        printf("货物EAN码不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("请重新输入货物的EAN码:");
                        scanf("%llu", &p[length + i].EAN);
                        buff = getchar();
                    }
                    q = 0;
                    while (length + i > q)
                    {
                        if (p[length + i].EAN == p[q].EAN)
                        {
                            printf("此商品已在库中\n");
                            mode = 1;
                            break;
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
                    while (p[length + i].stock < 0||buff != '\n')
                    {
                        printf("进货数量不合法，请确认输入是否正确，并重新输入\n");
                        fflush(stdin);
                        system("pause");
                        printf("货品的进货数量:");
                        scanf("%d", &p[length + i].stock);
                        buff = getchar();
                    }
                    break;
                case 3:
                    while (1)
                    {
                        printf("重新输入货品的进货价:");
                        scanf("%lf", &p[length + i].purchase_price);
                        buff = getchar();
                        while (p[length + i].purchase_price < 0 || buff != '\n')
                        {
                            printf("进货价不合法，请确认输入是否正确，并重新输入\n");
                            fflush(stdin);
                            system("pause");
                            printf("货品的进货价:");
                            scanf("%lf", &p[length + i].purchase_price);
                            buff = getchar();
                        }
                        if (p[length + i].purchase_price > (0.9*p[length + i].sale_price))
                        {
                            printf("进货价不能大于售价打九折，请重新输入\n");
                            continue;
                        }
                        break;
                    }
                    break;
                case 4:
                    while (1)
                    {
                        printf("重新输入货品的售价:");
                        scanf("%lf", &p[length + i].sale_price);
                        buff = getchar();
                        while (p[length + i].sale_price < 0||buff != '\n')
                        {
                            printf("售价不合法，请确认输入是否正确，并重新输入\n");
                            fflush(stdin);
                            system("pause");
                            printf("货品的售价:");
                            scanf("%lf", &p[length + i].sale_price);
                            buff = getchar();
                        }
                        if (p[length + i].purchase_price > (0.9*p[length + i].sale_price))
                        {
                            printf("打九折的售价不能小于进货价，请重新输入\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                fflush(stdin);
                system("cls");
                freight_msg(msg,p,length + i);
                printf("%s",msg);
                system("pause");
                ch2 = ui_choice(notice3, freight_choice3, 2);
            }
        }
        p[length + i].margins=0;
        if (mode == 1)
        {
            p[q].purchase_price = ((p[length + i].purchase_price * p[length + i].stock) + (p[q].purchase_price * p[q].stock)) / (p[q].stock + p[length + i].stock);
            p[q].stock += p[length + i].stock;
            p[q].sale_price = p[length + i].sale_price;
            p[q].margins+=p[length + i].margins;
            if (p[q].purchase_price>(0.9*p[q].sale_price))
            {
                ch3=ui_choice(notice4, freight_choice3, 2);
                if (ch3==1)
                {
                    while (1)
                    {
                        printf("重新输入货品的售价:");
                        scanf("%lf", &p[q].sale_price);
                        buff = getchar();
                        while (p[q].sale_price < 0||buff != '\n')
                        {
                            printf("售价不合法，请确认输入是否正确，并重新输入\n");
                            fflush(stdin);
                            system("pause");
                            printf("货品的售价:");
                            scanf("%lf", &p[q].sale_price);
                            buff = getchar();
                        }
                        if (p[q].purchase_price > (0.9*p[q].sale_price))
                        {
                            printf("打九折的售价不能小于进货价，请重新输入\n");
                            continue;
                        }
                        break;
                    }
                }
            }
            init_freight(p + length + i);
            i--;
        }
        i++;
    }
    length += i;
    x = save_stock_data(p, &length);
}

#endif