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
    printf("������Ҫ���������ֻ�Ʒ��\n");
    int n = -1, i, q, ch, ch1, ch2, x;
    scanf("%d", &n);
    char buff = getchar();
    if (buff != '\n')
        n = -1;
    while (n < 0)
    {
        printf("���벻�Ϸ�������������\n");
        fflush(stdin);
        system("pause");
        printf("������Ҫ���������ֻ�Ʒ��\n");
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
        printf("������\n��%d�ֻ�Ʒ��EAN��:", (i + 1));
        scanf("%lld", &p[i].EAN);
        buff = getchar();
        if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
            p[i].EAN = 0;
        while (p[i].EAN <= 0)
        {
        EANER:
            printf("����EAN�벻�Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��ƷEAN��:");
            scanf("%lld", &p[i].EAN);
            buff = getchar();
            if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                p[i].EAN = 0;
        }
        while (i > q)
        {
            if (p[i].EAN == p[q].EAN)
            {
                printf("��Ʒ��EAN���ظ�����ȷ�������Ƿ���ȷ������������\n");
                system("pause");
                printf("��������EAN��\n");
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
        printf("��Ʒ������:");
        scanf("%s", p[i].name);
        fflush(stdin);
        printf("��Ʒ�Ľ�������:");
        scanf("%d", &p[i].stock);
        buff = getchar();
        if (buff != '\n')
            p[i].stock = -1;
        while (p[i].stock < 0)
        {
            printf("�����������Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��Ʒ�Ľ�������:");
            scanf("%d", &p[i].stock);
            buff = getchar();
            if (buff != '\n')
                p[i].stock = -1;
        }
        printf("��Ʒ�Ľ�����:");
        scanf("%d", &p[i].purchase_price);
        buff = getchar();
        if (buff != '\n')
            p[i].purchase_price = -1;
        while (p[i].purchase_price < 0)
        {
        PURCHASEER:
            printf("�����۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��Ʒ�Ľ�����:");
            scanf("%d", &p[i].purchase_price);
            buff = getchar();
            if (buff != '\n')
                p[i].purchase_price = -1;
        }
        printf("��Ʒ���ۼ�:");
        scanf("%d", &p[i].sale_price);
        buff = getchar();
        if (buff != '\n')
            p[i].sale_price = -1;
        while (p[i].sale_price < 0)
        {
        SALEER:
            printf("�ۼ۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
            fflush(stdin);
            system("pause");
            printf("��Ʒ���ۼ�:");
            scanf("%d", &p[i].sale_price);
            buff = getchar();
            if (buff != '\n')
                p[i].sale_price = -1;
        }
        while (p[i].purchase_price > p[i].sale_price)
        {
            printf("�����۲��ܴ����ۼۣ�����������\n");
            printf("��Ʒ�Ľ�����:");
            scanf("%d", &p[i].purchase_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[i].purchase_price = -1;
                goto PURCHASEER;
            }
            printf("��Ʒ���ۼ�:");
            scanf("%d", &p[i].sale_price);
            buff = getchar();
            if (buff != '\n')
            {
                p[i].sale_price = -1;
                goto SALEER;
            }
        }
        system("cls");
        printf("��ȷ�����������Ʒ��Ϣ\n");
        printf("EAN:%lld\n����:%s\n��������:%d\n������:%d\n�ۼ�:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
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
                    scanf("%lld", &p[i].EAN);
                    buff = getchar();
                    if (buff != '\n' || p[i].EAN < 1e12 || p[i].EAN >= 1e13)
                        p[i].EAN = 0;
                    while (p[i].EAN <= 0)
                    {
                    EAN2ER:
                        printf("����EAN�벻�Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��������������EAN��:");
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
                            printf("��Ʒ��EAN���ظ�����ȷ�������Ƿ���ȷ������������\n");
                            system("pause");
                            system("cls");
                            printf("��������EAN��:\n");
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
                    printf("���������Ʒ������:");
                    scanf("%s", p[i].name);
                    break;
                case 2:
                    printf("���������Ʒ�Ľ�������:");
                    scanf("%d", &p[i].stock);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].stock = -1;
                    while (p[i].stock < 0)
                    {
                        printf("�����������Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��Ʒ�Ľ�������:");
                        scanf("%d", &p[i].stock);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].stock = -1;
                    }
                    break;
                case 3:
                    printf("���������Ʒ�Ľ�����:");
                    scanf("%d", &p[i].purchase_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].purchase_price = -1;
                    while (p[i].purchase_price < 0)
                    {
                    PURCHASEER2:
                        printf("�����۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��Ʒ�Ľ�����:");
                        scanf("%d", &p[i].purchase_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].purchase_price = -1;
                    }
                    while (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("�����۲��ܴ����ۼۣ�����������\n");
                        printf("���������Ʒ�Ľ�����:");
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
                    printf("���������Ʒ���ۼ�:");
                    scanf("%d", &p[i].sale_price);
                    buff = getchar();
                    if (buff != '\n')
                        p[i].sale_price = -1;
                    while (p[i].sale_price < 0)
                    {
                    SALEER2:
                        printf("�ۼ۲��Ϸ�����ȷ�������Ƿ���ȷ������������\n");
                        fflush(stdin);
                        system("pause");
                        printf("��Ʒ���ۼ�:");
                        scanf("%d", &p[i].sale_price);
                        buff = getchar();
                        if (buff != '\n')
                            p[i].sale_price = -1;
                    }
                    while (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("�ۼ۲���С�ڽ����ۣ�����������\n");
                        printf("���������Ʒ���ۼ�:");
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
                printf("�޸ĺ���������\nEAN��:%lld\n����:%s\n��������:%d\n������:%d\n�ۼ�:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
                system("pause");
                ch2 = ui_choice(notice3, freight_choice3, 2);
            }
        }
    }
    x = save_stock_data(p, &n);
}

#endif