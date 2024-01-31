#include <stdio.h>
#include "ui.h"
#include "register.h"
#include <stdlib.h>
#include "struct.h"
int main()
{
    // ui测试代码
    // char *empty="";
    // char *Error1="尚未实现";
    // char *notice1="请选择您的操作：";
    // char *choice1="1.会员管理";
    // char *choice2="2.货物管理";
    // char *choice3="3.退出";
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
    //         printf("退出\n");
    //         exit(0);
    //     }
    // }

    //注册测试代码
    struct vip *vip=NULL;
    vip=register_vip();
    printf("\n收到函数传回的数据：\n结构体地址：%p\n内容：\n%s\n", vip, vip->name);
    printf("%lld\n", vip->phone_number);
    free(vip);
    vip=NULL;
    system("pause");
    return 0;

}