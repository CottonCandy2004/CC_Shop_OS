#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
#include "freightlib.h"

int main()
{
    char *notice1 = "��ѡ�����Ĳ�����";
    char *notice2 = "��ѡ����Ҫ���������ѡ��";
    char *notice3 = "�Ƿ�����Ҫ���ĵ�ѡ�";
    char *choice1 = "1.ȷ����ȷ";
    char *choice2 = "2.��������";
    char *choice3 = "1.���";
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
    int n, i, q, ch, ch1, ch2,x;
    scanf("%d", &n);
    freight *p = (freight *)malloc(n * sizeof(freight));

    for (i = 0; i < n; i++)
    {
        q = 0;
        system("cls");
        printf("������\n��%d�ֻ�Ʒ�ı��:", (i + 1));
        scanf("%ld", &p[i].EAN);
        while (p[i].EAN < 0)
        {
            printf("�����Ų���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
            system("pause");
            printf("��Ʒ���:");
            scanf("%d", &p[i].EAN);
        }
        while (i > q)
        {
            if (p[i].EAN == p[q].EAN)
            {
                printf("��Ʒ�ı���ظ�����ȷ�������Ƿ���ȷ������������\n");
                system("pause");
                printf("����������\n");
                scanf("%ld", &p[i].EAN);
                q = -1;
            }
            q++;
        }
        printf("��Ʒ������:");
        scanf("%s", p[i].name);
        printf("��Ʒ�Ľ�������:");
        scanf("%d", &p[i].stock);
        while (p[i].stock < 0)
        {
            printf("������������Ϊ��������ȷ�������Ƿ���ȷ������������\n");
            system("pause");
            printf("��Ʒ�Ľ�������:");
            scanf("%d", &p[i].stock);
        }
        printf("��Ʒ�Ľ�����:");
        scanf("%d", &p[i].purchase_price);
        while (p[i].purchase_price < 0)
        {
            printf("�����۲���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
            system("pause");
            printf("��Ʒ�Ľ�����:");
            scanf("%d", &p[i].purchase_price);
        }
        printf("��Ʒ���ۼ�:");
        scanf("%d", &p[i].sale_price);
        while (p[i].sale_price < 0)
        {
            printf("�ۼ۲���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
            system("pause");
            printf("��Ʒ���ۼ�:");
            scanf("%d", &p[i].sale_price);
        }
        while (p[i].purchase_price > p[i].sale_price)
        {
            printf("�����۲��ܴ����ۼۣ�����������\n");
            printf("��Ʒ�Ľ�����:");
            scanf("%d", &p[i].purchase_price);
            printf("��Ʒ���ۼ�:");
            scanf("%d", &p[i].sale_price);
        }
        system("cls");
        printf("��ȷ�����������Ʒ��Ϣ\n");
        printf("���:%ld\n����:%s\n��������:%d\n������:%d\n�ۼ�:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
        system("pause");
        int result_colour = 0;
        ch = ui_choice(notice1, freight_choice1, 2);
        if (ch == 1)
        {
            ch2 = 0;
            for (; ch2 == 0;)
            {
                ch1 = ui_choice(notice2, freight_choice2, 5);
                switch (ch1)
                {
                case 0:
                    printf("�����������Ʒ�ı��\n");
                    scanf("%ld", &p[i].EAN);
                    while (p[i].EAN < 0)
                    {
                        printf("�����Ų���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
                        system("pause");
                        printf("��Ʒ�Ľ�������:");
                        scanf("%d", &p[i].EAN);
                    }
                    q = 0;
                    while (i > q)
                    {
                        if (p[i].EAN == p[q].EAN)
                        {
                            printf("��Ʒ�ı���ظ�����ȷ�������Ƿ���ȷ������������\n");
                            system("pause");
                            system("cls");
                            printf("����������:\n");
                            scanf("%ld", &p[i].EAN);
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
                    while (p[i].stock < 0)
                    {
                        printf("������������Ϊ��������ȷ�������Ƿ���ȷ������������\n");
                        system("pause");
                        printf("��Ʒ�Ľ�������:");
                        scanf("%d", &p[i].stock);
                    }
                    break;
                case 3:
                    printf("���������Ʒ�Ľ�����:");
                    scanf("%d", &p[i].purchase_price);
                    while (p[i].purchase_price < 0)
                    {
                        printf("�����۲���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
                        system("pause");
                        printf("��Ʒ�Ľ�����:");
                        scanf("%d", &p[i].purchase_price);
                    }
                    if (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("�����۲��ܴ����ۼۣ�����������\n");
                        printf("���������Ʒ�Ľ�����:");
                        scanf("%d", &p[i].purchase_price);
                    }
                    break;
                case 4:
                    printf("���������Ʒ���ۼ�:");
                    scanf("%d", &p[i].sale_price);
                    while (p[i].sale_price < 0)
                    {
                        printf("�ۼ۲���Ϊ��������ȷ�������Ƿ���ȷ������������\n");
                        system("pause");
                        printf("��Ʒ���ۼ�:");
                        scanf("%d", &p[i].sale_price);
                    }
                    if (p[i].purchase_price > p[i].sale_price)
                    {
                        printf("�ۼ۲���С�ڽ����ۣ�����������\n");
                        printf("���������Ʒ���ۼ�:");
                        scanf("%d", &p[i].sale_price);
                    }
                    break;
                }
                system("cls");
                printf("�޸ĺ���������\n���:%ld\n����:%s\n��������:%d\n������:%d\n�ۼ�:%d\n", p[i].EAN, p[i].name, p[i].stock, p[i].purchase_price, p[i].sale_price);
                system("pause");
                ch2 = ui_choice(notice3, freight_choice3, 2);
            }
        }
    }
    x=save_stock_data(p,&n);
}
