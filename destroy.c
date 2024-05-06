#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"
#include "destroytool.h"
int main()
{
    char* destroy_notice1="请您最后确认是否销毁此商品。";
    char* choice1="[Y]是";
    char* choice2="[N]否";
    char* destroy_choice[2]={choice1, choice2};
    int load_satus, length = 0, n, i, serch_id,ch1,x;
    unsigned long long EAN;
    freight *p;
    p = (freight *)malloc(sizeof(freight) * 1000);
    load_satus = load_stock_data(p, &length);
    if (load_satus == -1)
    {
        return -1;
    }
    printf("请问您想要销毁多少种货品：");
    ShowConsoleCursor();
    scanf("%d", &n);
    char buff = getchar();
    if (buff != '\n')
        n = -1;
    while (n < 0)
    {
        printf("输入不合法，请重新输入\n");
        fflush(stdin);
        system("pause");
        system("cls");
        printf("请问您要销毁多少种货品？\n");
        ShowConsoleCursor();
        scanf("%d", &n);
        char buff = getchar();
        if (buff != '\n')
            n = -1;
    }
    for (i = 0; i < n; i++)
    {
        system("cls");
        printf("请输入想要销毁商品的EAN：");
        ShowConsoleCursor();
        scanf("%lld", &EAN);
        while (EAN < 1e12 || EAN >= 1e13)
        {
            printf("输入不合法，请重新输入\n");
            fflush(stdin);
            system("pause");
            system("cls");
            printf("请输入想要销毁商品的EAN：");
            ShowConsoleCursor();
            scanf("%lld", &EAN);
        }
        serch_id = locating(p, length, EAN);
        Sleep(1000);
        if (serch_id == -1)
        {
            system("cls");
            SetColor(4, 0);
            printf("商品不存在，请重新输入！\n");
            SetColor(15, 0);
            fflush(stdin);
            system("pause");
            i--;
            continue;
        }
        else
        {
            system("cls");
            printf("您要销毁的商品信息如下：\n");
            printf("EAN码:%lld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n", p[serch_id].EAN, p[serch_id].name, p[serch_id].stock, p[serch_id].purchase_price, p[serch_id].sale_price);
            system("pause");
            ch1=ui_choice(destroy_notice1, destroy_choice, 2);
            if (ch1==0)
            {
                del_freight(p,&length,serch_id);
                system("cls");
                SetColor(10, 0);
                printf("销毁成功！\n");
                SetColor(15, 0);
                fflush(stdin);
            }
            else{
                printf("已经取消此操作\n");
                i--;
                continue;
            }
        }
    }
    x = silent_save_stock_data(p, &length);
}
