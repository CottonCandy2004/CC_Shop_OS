#include <stdio.h>
#include "ui.h"
#include "register.h"
#include "deregister.h"
#include <stdlib.h>
#include "struct.h"
int main()
{
    // ui���Դ���
    // char *empty="";
    // char *Error1="��δʵ��";
    // char *notice1="��ѡ�����Ĳ�����";
    // char *choice1="1.��Ա����";
    // char *choice2="2.�������";
    // char *choice3="3.�˳�";
    // char* choice[3]={choice1,choice2,choice3};
    // char *result=empty;
    // int result_colour=0;
    // int ch=ui_choice(notice1,choice,3);
    // while(1)
    // {
    //     if(ch==0)
    //     {
    //         result=Error1;
    //         result_colour=4;
    //         ch=ui_re_choice(notice1,choice,3,result,&result_colour);
    //     }
    //     else if(ch==1)
    //     {
    //         result=Error1;
    //         result_colour=4;
    //         ch=ui_re_choice(notice1,choice,3,result,&result_colour);
    //     }
    //     else if(ch==2)
    //     {
    //         printf("�˳�\n");
    //         exit(0);
    //     }
    // }

    // ע����Դ���
    // struct vip *vip = NULL;
    // vip = register_vip();
    // printf("\n�յ��������ص����ݣ�\n�ṹ���ַ��%p\n���ݣ�\n%s\n", vip, vip->name);
    // printf("%lld\n", vip->phone_number);
    // free(vip);
    // vip = NULL;
    // system("pause");

    // ע�����Դ���
    struct vip vip_data[20] =
        {
            {1, 13100000000, "����", {2020, 1, 1}, 100},
            {2, 13100000001, "����", {2020, 1, 1}, 100},
            {3, 13100000002, "����", {2020, 1, 1}, 100},
            {4, 13100000003, "����", {2020, 1, 1}, 100},
            {5, 13100000004, "����", {2020, 1, 1}, 100},
            {6, 13100000005, "�ܰ�", {2020, 1, 1}, 100},
            {7, 13100000006, "���", {2020, 1, 1}, 100},
            {8, 13100000007, "֣ʮ", {2020, 1, 1}, 100},
            {9, 13100000008, "��ʮһ", {2020, 1, 1}, 100},
            {10, 13100000009, "��ʮ��", {2020, 1, 1}, 100},
            {11, 13100000010, "��ʮ��", {2020, 1, 1}, 100},
            {12, 13100000011, "��ʮ��", {2020, 1, 1}, 100},
            {13, 13100000012, "��ʮ��", {2020, 1, 1}, 100},
            {14, 13100000013, "֣ʮ��", {2020, 1, 1}, 100},
            {15, 13100000014, "��ʮ��", {2020, 1, 1}, 100},
            {16, 13100000015, "��ʮ��", {2020, 1, 1}, 100},
            {17, 13100000016, "��ʮ��", {2020, 1, 1}, 100},
            {18, 13100000017, "��ʮ��", {2020, 1, 1}, 100},
            {19, 13100000018, "���ʮ", {2020, 1, 1}, 100},
            {20, 13100000019, "֣��ʮ", {2020, 1, 1}, 100}};
    deregister(vip_data, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n%lld\n%s\n%d-%d-%d\n%d\n", vip_data[i].id, vip_data[i].phone_number, vip_data[i].name, vip_data[i].last_consume_day.year, vip_data[i].last_consume_day.month, vip_data[i].last_consume_day.day, vip_data[i].total_consume);
    }
    system("pause");
    return 0;
}