#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "ui_terminal.h"
#include "ui.h"
#include "stdio.h"
#include "vip.h"
#include "viplib.h"
#include "vip_show.h"
#include "freightlib.h"
#include "cleartool.h"
int main()
{
    struct vip *vip_data;
    freight *freight_data;
    int vip_length = 0, freight_length = 0, vip_search_id, freight_search_id,mode,num;
    unsigned long long phone_number, EAN;
    freight_data = (freight *)malloc(sizeof(freight) * 1000);
    vip_data = (struct vip *)malloc(sizeof(struct vip) * 1000);
    char buff;
    char *msg = (char *)malloc(sizeof(char) * 100);
    memset(msg, 0, 100);
    load_vip_data(vip_data, &vip_length);
    load_stock_data(freight_data, &freight_length);
    printf("欢迎使用超市收银系统\n");
    system("pause");
    system("cls");
    while (1)
    {
        mode = 1;
        printf("请输入会员的手机号码：（输入0为无会员）\n");
        scanf("%llu", &phone_number);
        buff = getchar();
        while (buff != '\n' || (phone_number > 0 && phone_number < 1e10) || phone_number >= 1e11 || phone_number < 0)
        {
            printf("输入的会员手机号码不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            system("cls");
            printf("请输入会员的手机号码：（输入0为无会员）\n");
            scanf("%llu", &phone_number);
            buff = getchar();
        }
        if (phone_number == 0)
        {
            mode = 0;
            printf("该顾客无会员\n");
            system("pause");
        }
        else
        {
            vip_search_id = is_in_list(vip_data, vip_length, phone_number);
            system("cls");
            if (vip_search_id == -1)
            {
                printf("该会员不存在，请确认输入是否正确，并重新输入\n");
                system("pause");
                system("cls");
                continue;
            }
            else
            {
                vip_msg(msg, vip_data, vip_search_id);
                printf("%s", msg);
                system("pause");
            }
        }
        system("cls");
        break;
    }
    while (1)
    {
        printf("请输入商品编号：（输入0退出并打印小票）\n");
        scanf("%llu", &EAN);
        buff = getchar();
        while (buff != '\n' || (EAN > 0 && EAN < 1e10) || EAN >= 1e11 || EAN < 0)
        {
            printf("输入的商品编号不合法，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            system("cls");
            printf("请输入商品编号：（输入0退出并打印小票）\n");
            scanf("%llu", &EAN);
            buff = getchar();
        }
        if (EAN==0)
        {
            printf("退出并打印小票\n");
            break;
        }
        freight_search_id=locating(freight_data,freight_length,EAN);
        if (freight_search_id==-1)
        {
            printf("该商品不存在，请确认输入是否正确，并重新输入\n");
            system("pause");
            system("cls");
            continue;
        }
        if (freight_data[freight_search_id].stock==0)
        {
            printf("该商品已售罄，请确认输入是否正确，并重新输入\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("请输入购买商品的数量：\n");
        scanf("%d",&num);
    }
}