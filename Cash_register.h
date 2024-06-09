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
    char *register_notice = "�������Ƿ�Ҫ����ʹ������̨��";
    char *choice1 = "[Y]����";
    char *choice2 = "[N]�˳�";
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
    printf("��ӭʹ�ó�������ϵͳ\n");
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
            printf("�������Ա���ֻ����룺������0Ϊ�޻�Ա��\n");
            scanf("%llu", &phone_number);
            buff = getchar();
            while (buff != '\n' || (phone_number > 0 && phone_number < 1e10) || phone_number >= 1e11 || phone_number < 0)
            {
                printf("����Ļ�Ա�ֻ����벻�Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                system("cls");
                printf("�������Ա���ֻ����룺������0Ϊ�޻�Ա��\n");
                scanf("%llu", &phone_number);
                buff = getchar();
            }
            if (phone_number == 0)
            {
                mode = 0;
                printf("�ù˿��޻�Ա\n");
                system("pause");
            }
            else
            {
                vip_search_id = is_in_list(vip_data, vip_length, phone_number);
                system("cls");
                if (vip_search_id == -1)
                {
                    printf("�û�Ա�����ڣ���ȷ�������Ƿ���ȷ������������\n");
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
            printf("��������Ʒ��ţ�������0�˳�����ӡСƱ��\n");
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
                printf("�������Ʒ��Ų��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                system("cls");
                printf("��������Ʒ��ţ�������0�˳�����ӡСƱ��\n");
                scanf("%llu", &EAN);
                buff = getchar();
            }
            if (EAN == 0)
            {
                printf("�˳�����ӡСƱ\n");
                break;
            }
            freight_search_id = locating(freight_data, freight_length, EAN);
            system("cls");
            if (freight_search_id == -1)
            {
                printf("����Ʒ�����ڣ���ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                system("cls");
                continue;
            }
            if (freight_data[freight_search_id].stock == 0)
            {
                printf("����Ʒ����������ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                system("cls");
                continue;
            }
            while (1)
            {
                printf("�����빺����Ʒ��������������0����������EAN��\n");
                scanf("%d", &num);
                if (num > freight_data[freight_search_id].stock)
                {
                    printf("����Ʒ��治�㣬��ȷ�������Ƿ���ȷ������������\n");
                    fflush(stdin);
                    system("pause");
                    system("cls");
                    continue;
                }
                if (num < 0)
                {
                    printf("�������Ʒ�������Ϸ�����ȷ�������Ƿ���ȷ������������\n");
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
        printf("Ӧ�գ�%.2f\nʵ����", sum_price);
        scanf("%lf", &pay);
        buff = getchar();
        while (pay < 0 || buff != '\n'||pay<sum_price)
        {
            printf("ʵ�����Ϸ���С��Ӧ�գ���ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("ʵ��:");
            scanf("%lf", &pay);
            buff = getchar();
        }
        printf("���㣺%.2f", (pay - sum_price));
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