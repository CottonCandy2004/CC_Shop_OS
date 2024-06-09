#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "ui_terminal.h"
#include "ui.h"
#include "vip.h"
#include "viplib.h"
#include "vip_show.h"
#include "freightlib.h"
#include "cleartool.h"
#include "registertool.h"
int casher()
{
    struct vip *vip_data;
    freight *freight_data;
    receipts *receipts_data;
    int vip_length = 0, freight_length = 0, vip_search_id, freight_search_id, mode, num, i = 0, n = 0, m = 0, ch0, receipts_length = 0, x, discount = 1;
    double sum_price;
    unsigned long long phone_number, EAN;
    char *register_notice = "请问您是否要继续使用收银台？";
    char *choice1 = "[Y]继续";
    char *choice2 = "[N]退出";
    char *register_choice[2] = {choice1, choice2};
    freight_data = (freight *)malloc(sizeof(freight) * 1000);
    vip_data = (struct vip *)malloc(sizeof(struct vip) * 1000);
    receipts_data = (receipts *)malloc(sizeof(receipts) * 1000);
    memset(receipts_data, 0, sizeof(receipts) * 1000);
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
        while (1)
        {
            mode = 1;
            discount = 1;
            memset(receipts_data, 0, sizeof(receipts) * 1000);
            memset(msg, 0, 100);
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
                    fflush(stdin);
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
            break;
        }
        while (1)
        {
            system("cls");
            i = 0, n = 0, m = 0;
            printf("请输入商品编号：（输入0退出并打印小票）\n");
            scanf("%llu", &EAN);
            m = i;
            for (n = 0; i > n; n++)
            {
                if (EAN == receipts_data[n].EAN)
                {
                    m = n;
                    i--;
                }
            }
            buff = getchar();
            while (buff != '\n' || (EAN > 0 && EAN < 1e12) || EAN >= 1e13 || EAN < 0)
            {
                printf("输入的商品编号不合法，请确认输入是否正确，并重新输入\n");
                fflush(stdin);
                system("pause");
                system("cls");
                printf("请输入商品编号：（输入0退出并打印小票）\n");
                scanf("%llu", &EAN);
                buff = getchar();
            }
            if (EAN == 0)
            {
                printf("退出并打印小票\n");
                break;
            }
            freight_search_id = locating(freight_data, freight_length, EAN);
            system("cls");
            if (freight_search_id == -1)
            {
                printf("该商品不存在，请确认输入是否正确，并重新输入\n");
                fflush(stdin);
                system("pause");
                system("cls");
                continue;
            }
            if (freight_data[freight_search_id].stock == 0)
            {
                printf("该商品已售罄，请确认输入是否正确，并重新输入\n");
                fflush(stdin);
                system("pause");
                system("cls");
                continue;
            }
            while (1)
            {
                printf("请输入购买商品的数量：（输入0可重新输入EAN）\n");
                scanf("%d", &num);
                if (num > freight_data[freight_search_id].stock)
                {
                    printf("该商品库存不足，请确认输入是否正确，并重新输入\n");
                    fflush(stdin);
                    system("pause");
                    system("cls");
                    continue;
                }
                if (num < 0)
                {
                    printf("输入的商品数量不合法，请确认输入是否正确，并重新输入\n");
                    fflush(stdin);
                    system("pause");
                    system("cls");
                    continue;
                }
                if (num == 0)
                {
                    i--;
                    break;
                }
                freight_data[freight_search_id].stock -= num;
                receipts_data[m].unit_price = freight_data[freight_search_id].sale_price;
                receipts_data[m].discount_price = freight_data[freight_search_id].sale_price;
                receipts_data[m].EAN = freight_data[freight_search_id].EAN;
                strcpy(receipts_data[m].name, freight_data[freight_search_id].name);
                receipts_data[m].num += num;
                if (mode == 1)
                {
                    timesearch(vip_data, vip_search_id);
                    Discount_calculation(receipts_data, vip_data, vip_search_id,m);
                }
                freight_data[freight_search_id].margins += ((receipts_data[m].discount_price - freight_data[freight_search_id].purchase_price) * num);
                receipts_data[m].sum_price = (receipts_data[m].num * receipts_data[m].discount_price);
                break;
            }
            i++;
        }
        sum_price = fresum(receipts_data, &receipts_length);
        receipts_vip(receipts_data, receipts_length, sum_price);
        double pay;
        printf("应收：%.2f\n实付：", sum_price);
        scanf("%lf", &pay);
        buff = getchar();
        while (pay < 0 || buff != '\n'||pay<sum_price)
        {
            printf("实付不合法或小于应收，请确认输入是否正确，并重新输入\n");
            fflush(stdin);
            system("pause");
            printf("实付:");
            scanf("%lf", &pay);
            buff = getchar();
        }
        printf("找零：%.2f", (pay - sum_price));
        system("pause");
        if (mode == 1)
        {
            vip_data[vip_search_id].total_consume += sum_price;
            timeput(vip_data, vip_search_id);
        }
        ch0 = ui_choice(register_notice, register_choice, 2);
        if (ch0 == 1)
        {
            break;
        }
    }
    save_vip_data(vip_data, &vip_length);
    silent_save_stock_data(freight_data, &freight_length);
    free(vip_data);
    free(freight_data);
    free(receipts_data);
}