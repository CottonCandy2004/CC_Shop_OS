#include <stdio.h>
#include "ui.h"
#include "register.h"
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

    //ע����Դ���
    struct vip *vip=NULL;
    vip=register_vip();
    printf("\n�յ��������ص����ݣ�\n�ṹ���ַ��%p\n���ݣ�\n%s\n", vip, vip->name);
    printf("%lld\n", vip->phone_number);
    free(vip);
    vip=NULL;
    system("pause");
    return 0;

}