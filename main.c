#include <stdio.h>
#include "ui.h"
#include "register.h"
#include "deregister.h"
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

    // 注册测试代码
    // struct vip *vip = NULL;
    // vip = register_vip();
    // printf("\n收到函数传回的数据：\n结构体地址：%p\n内容：\n%s\n", vip, vip->name);
    // printf("%lld\n", vip->phone_number);
    // free(vip);
    // vip = NULL;
    // system("pause");

    // 注销测试代码
    struct vip vip_data[20] =
        {
            {1, 13100000000, "张三", {2020, 1, 1}, 100},
            {2, 13100000001, "李四", {2020, 1, 1}, 100},
            {3, 13100000002, "王五", {2020, 1, 1}, 100},
            {4, 13100000003, "赵六", {2020, 1, 1}, 100},
            {5, 13100000004, "孙七", {2020, 1, 1}, 100},
            {6, 13100000005, "周八", {2020, 1, 1}, 100},
            {7, 13100000006, "吴九", {2020, 1, 1}, 100},
            {8, 13100000007, "郑十", {2020, 1, 1}, 100},
            {9, 13100000008, "王十一", {2020, 1, 1}, 100},
            {10, 13100000009, "赵十二", {2020, 1, 1}, 100},
            {11, 13100000010, "孙十三", {2020, 1, 1}, 100},
            {12, 13100000011, "周十四", {2020, 1, 1}, 100},
            {13, 13100000012, "吴十五", {2020, 1, 1}, 100},
            {14, 13100000013, "郑十六", {2020, 1, 1}, 100},
            {15, 13100000014, "王十七", {2020, 1, 1}, 100},
            {16, 13100000015, "赵十七", {2020, 1, 1}, 100},
            {17, 13100000016, "孙十八", {2020, 1, 1}, 100},
            {18, 13100000017, "周十九", {2020, 1, 1}, 100},
            {19, 13100000018, "吴二十", {2020, 1, 1}, 100},
            {20, 13100000019, "郑二十", {2020, 1, 1}, 100}};
    deregister(vip_data, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n%lld\n%s\n%d-%d-%d\n%d\n", vip_data[i].id, vip_data[i].phone_number, vip_data[i].name, vip_data[i].last_consume_day.year, vip_data[i].last_consume_day.month, vip_data[i].last_consume_day.day, vip_data[i].total_consume);
    }
    system("pause");
    return 0;
}