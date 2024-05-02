#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
int main()
{
    char *notice1 = "请选择您的操作：";
    char *notice2 = "请选择你要重新输入的选项";
    char *notice3 = "是否还有需要更改的选项？";
    char *choice1 = "1.确认正确";
    char *choice2 = "2.重新输入";
    char *choice3 = "1.编号";
    char *choice4 = "2.名称";
    char *choice5 = "3.进货数量";
    char *choice6 = "4.进货价";
    char *choice7 = "5.售价";
    char *choice8 = "Y.是";
    char *choice9 = "N.否";
    char *choice0[5] = {choice3, choice4, choice5, choice6, choice7};
    char *choice00[2] = {choice8, choice9};
    char *choice[2] = {choice1, choice2};
    printf("请问您要引进多少种货品？\n");
    int n, i, q, ch, ch1, ch2;
    scanf("%d", &n);
    freight *p = (freight *)malloc(n * sizeof(freight));
    for (i = 0; i < n; i++)
    {
        q = 0;
        system("cls");
        printf("请输入\n第%d种货品的编号:", (i + 1));
        scanf("%ld", &p[i].EAN);
        while (p[i].EAN < 0)
        {
            printf("货物编号不能为负数，请确认输入是否正确，并重新输入\n");
            system("pause");
            printf("货品的进货数量:");
            scanf("%d", &p[i].EAN);
        }
        while (i > q)
        {
            if (p[i].EAN == p[q].EAN)
            {
                printf("货品的编号重复，请确认输入是否正确，并重新输入\n");
                system("pause");
                printf("重新输入编号\n");
                scanf("%ld", &p[i].EAN);
                q = -1;
            }
            q++;
        }
        printf("货品的名称:");
        scanf("%s", p[i].name);
        printf("货品的进货数量:");
        scanf("%d", &p[i].stock);
        while (p[i].stock < 0)
        {
            printf("进货数量不能为负数，请确认输入是否正确，并重新输入\n");
            system("pause");
            printf("货品的进货数量:");
            scanf("%d", &p[i].stock);
        }
        printf("货品的进货价:");
        scanf("%d", &p[i].purchase_price);
        while (p[i].purchase_price < 0)
        {
            printf("进货价不能为负数，请确认输入是否正确，并重新输入\n");
            system("pause");
            printf("货品的进货价:");
            scanf("%d", &p[i].purchase_price);
        }
        printf("货品的售价:");
        scanf("%d", &p[i].sale_price);
        while (p[i].sale_price < 0)
        {
            printf("售价不能为负数，请确认输入是否正确，并重新输入\n");
            system("pause");
            printf("货品的售价:");
            scanf("%d", &p[i].sale_price);
        }
        while (p[i].purchase_price > p[i].sale_price)
        {
            printf("进货价不能大于售价，请重新输入\n");
            printf("货品的进货价:");
            scanf("%d", &p[i].purchase_price);
            printf("货品的售价:");
            scanf("%d", &p[i].sale_price);
        }
        system("cls");
        printf("请确认您输入的商品信息\n");
        printf("编号:%ld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
        system("pause");
        int result_colour = 0;
        ch = ui_choice(notice1, choice, 2);
        if (ch == 1)
        {
            ch2 = 0;
            for (; ch2 == 0;)
            {
                ch1 = ui_choice(notice2, choice0, 5);
                switch (ch1)
                {
                case 0:
                    printf("请重新输入货品的编号\n");
                    scanf("%ld", &p[i].EAN);
                    while (p[i].EAN < 0)
                    {
                        printf("货物编号不能为负数，请确认输入是否正确，并重新输入\n");
                        system("pause");
                        printf("货品的进货数量:");
                        scanf("%d", &p[i].EAN);
                    }
                    q = 0;
                    while (i > q)
                    {
                        if (p[i].EAN == p[q].EAN)
                        {
                            printf("货品的编号重复，请确认输入是否正确，并重新输入\n");
                            system("pause");
                            system("cls");
                            printf("重新输入编号:\n");
                            scanf("%ld", &p[i].EAN);
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
                    while (p[i].stock < 0)
                    {
                        printf("进货数量不能为负数，请确认输入是否正确，并重新输入\n");
                        system("pause");
                        printf("货品的进货数量:");
                        scanf("%d", &p[i].stock);
                    }
                    break;
                case 3:
                    printf("重新输入货品的进货价:");
                    scanf("%d", &p[i].purchase_price);
                    while (p[i].purchase_price < 0)
                    {
                        printf("进货价不能为负数，请确认输入是否正确，并重新输入\n");
                        system("pause");
                        printf("货品的进货价:");
                        scanf("%d", &p[i].purchase_price);
                    }
                    if (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("进货价不能大于售价，请重新输入\n");
                        printf("重新输入货品的进货价:");
                        scanf("%d", &p[i].purchase_price);
                    }
                    break;
                case 4:
                    printf("重新输入货品的售价:");
                    scanf("%d", &p[i].sale_price);
                    while (p[i].sale_price < 0)
                    {
                        printf("售价不能为负数，请确认输入是否正确，并重新输入\n");
                        system("pause");
                        printf("货品的售价:");
                        scanf("%d", &p[i].sale_price);
                    }
                    if (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("售价不能小于进货价，请重新输入\n");
                        printf("重新输入货品的售价:");
                        scanf("%d", &p[i].sale_price);
                    }
                    break;
                }
                system("cls");
                printf("修改后数据如下\n编号:%ld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
                system("pause");
                ch2 = ui_choice(notice3, choice00, 2);
            }
        }
    }
}
