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
    char *notice1 = "��ѡ�����Ĳ�����";
    char *notice2 = "��ѡ����Ҫ���������ѡ��";
    char *notice3 = "�Ƿ�����Ҫ���ĵ�ѡ�";
    char *choice1 = "1.ȷ����ȷ";
    char *choice2 = "2.��������";
    char *choice3 = "1.EAN��";
    char *choice4 = "2.����";
    char *choice5 = "3.��������";
    char *choice6 = "4.������";
    char *choice7 = "5.�ۼ�";
    char *choice8 = "Y.��";
    char *choice9 = "N.��";
    char *freight_choice1[2] = {choice1, choice2};
    char *freight_choice2[5] = {choice3, choice4, choice5, choice6, choice7};
    char *freight_choice3[2] = {choice8, choice9};
    int i = 1, q, ch, ch1, ch2, x, y, length = 0, mode;
    char buff;
    freight *p = (freight *)malloc(1000 * sizeof(freight));
    y = load_stock_data(p, &length);
    while (1)
    {
        q = 0, mode = 0;
        system("cls");
        printf("�������Ʒ��EAN��:������0�˳�������");
        scanf("%llu", &p[length + i].EAN);
        buff = getchar();
        if (p[length + i].EAN == 0)
        {
            break;
        }
        while (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
        {
            printf("����EAN�벻�Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��ƷEAN��:");
            scanf("%llu", &p[length + i].EAN);
            buff = getchar();
        }
        while (length + i > q)
        {
            if (p[length + i].EAN == p[q].EAN)
            {
                printf("����Ʒ���ڿ���\n��Ʒ����Ϊ%s\n", p[q].name);
                mode = 1;
                break;
            }
            q++;
        }
        if (mode == 0)
        {
            printf("����ƷΪ�״����\n");
            printf("��Ʒ������:");
            scanf("%s", p[length + i].name);
        }
        fflush(stdin);
        printf("��Ʒ�Ľ�������:");
        scanf("%d", &p[length + i].stock);
        buff = getchar();
        while (p[length + i].stock < 0 || buff != '\n')
        {
            printf("�����������Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��Ʒ�Ľ�������:");
            scanf("%d", &p[length + i].stock);
            buff = getchar();
        }
        while (1)
        {
            printf("��Ʒ�Ľ�����:");
            scanf("%lf", &p[length + i].purchase_price);
            buff = getchar();
            while (p[length + i].purchase_price < 0 || buff != '\n')
            {
                printf("�����۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                printf("��Ʒ�Ľ�����:");
                scanf("%lf", &p[length + i].purchase_price);
                buff = getchar();
            }
            printf("��Ʒ���ۼ�:");
            scanf("%lf", &p[length + i].sale_price);
            buff = getchar();
            while (p[length + i].sale_price < 0 || buff != '\n')
            {
                printf("�ۼ۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                fflush(stdin);
                system("pause");
                printf("��Ʒ���ۼ�:");
                scanf("%lf", &p[length + i].sale_price);
                buff = getchar();
            }
            if (p[length + i].purchase_price > p[length + i].sale_price)
            {
                printf("�����۲��ܴ����ۼۣ�����������\n");
                continue;
            }
            break;
        }
        system("cls");
        printf("��ȷ�����������Ʒ��Ϣ\n");
        printf("EAN:%llu\n����:%s\n��������:%d\n������:%.2lf\n�ۼ�:%.2lf\n", p[length + i].EAN, p[length + i].name, p[length + i].stock, p[length + i].purchase_price, p[length + i].sale_price);
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
                    printf("�����������Ʒ��EAN��\n");
                    scanf("%llu", &p[length + i].EAN);
                    buff = getchar();
                    while (buff != '\n' || p[length + i].EAN < 1e12 || p[length + i].EAN >= 1e13)
                    {
                        printf("����EAN�벻�Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��������������EAN��:");
                        scanf("%llu", &p[length + i].EAN);
                        buff = getchar();
                    }
                    q = 0;
                    while (length + i > q)
                    {
                        if (p[length + i].EAN == p[q].EAN)
                        {
                            printf("����Ʒ���ڿ���\n");
                            mode = 1;
                            break;
                        }
                        q++;
                    }
                    if (mode == 0)
                    {
                        printf("����ƷΪ�״����\n");
                    }
                    break;
                case 1:
                    printf("���������Ʒ������:");
                    scanf("%s", p[length + i].name);
                    break;
                case 2:
                    printf("���������Ʒ�Ľ�������:");
                    scanf("%d", &p[length + i].stock);
                    buff = getchar();
                    while (p[length + i].stock < 0||buff != '\n')
                    {
                        printf("�����������Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��Ʒ�Ľ�������:");
                        scanf("%d", &p[length + i].stock);
                        buff = getchar();
                    }
                    break;
                case 3:
                    while (1)
                    {
                        printf("���������Ʒ�Ľ�����:");
                        scanf("%lf", &p[length + i].purchase_price);
                        buff = getchar();
                        while (p[length + i].purchase_price < 0 || buff != '\n')
                        {
                            printf("�����۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                            fflush(stdin);
                            system("pause");
                            printf("��Ʒ�Ľ�����:");
                            scanf("%lf", &p[length + i].purchase_price);
                            buff = getchar();
                        }
                        if (p[length + i].purchase_price > p[length + i].sale_price)
                        {
                            printf("�����۲��ܴ����ۼۣ�����������\n");
                            continue;
                        }
                        break;
                    }
                    break;
                case 4:
                    while (1)
                    {
                        printf("���������Ʒ���ۼ�:");
                        scanf("%lf", &p[length + i].sale_price);
                        buff = getchar();
                        while (p[length + i].sale_price < 0||buff != '\n')
                        {
                            printf("�ۼ۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                            fflush(stdin);
                            system("pause");
                            printf("��Ʒ���ۼ�:");
                            scanf("%lf", &p[length + i].sale_price);
                            buff = getchar();
                        }
                        if (p[length + i].purchase_price > p[length + i].sale_price)
                        {
                            printf("�ۼ۲���С�ڽ����ۣ�����������\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                fflush(stdin);
                system("cls");
                printf("�޸ĺ���������\nEAN��:%llu\n����:%s\n��������:%d\n������:%.2lf\n�ۼ�:%.2lf\n", p[length + i].EAN, p[length + i].name, p[length + i].stock, p[length + i].purchase_price, p[length + i].sale_price);
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
        }
        i++;
    }
    length += i;
    x = save_stock_data(p, &length);
}

#endif