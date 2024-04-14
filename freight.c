#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
int main(){
    char *empty="";
    char *Error1="尚未实现";
    char *notice1="请选择您的操作：";
    char *choice1="1.确认正确";
    char *choice2="2.重新输入";
    char* choice[2]={choice1,choice2};
    char *result=empty;
    printf("请问您要引进多少种货品？\n");
    int n,i,q,ch;
    scanf("%d",&n);
    freight *p=(freight *)malloc(n*sizeof(freight));
    for ( i = 0; i < n; i++)
    {
        for(ch=1;ch==1;){
            system("cls");
            printf("请输入\n货品的编号:");
            scanf("%ld",&p[i].EAN);
            if(){
                printf("该编号已存在，请重新输入\n");
                getchar();
                continue;
            }
            getchar();
            printf("货品的名称:");
            scanf("%s",p[i].name);
            printf("货品的进货数量:");
            scanf("%d",&p[i].stock);
            printf("货品的进货价:");
            scanf("%d",&p[i].purchase_price);
            printf("货品的售价:");
            scanf("%d",&p[i].sale_price);
            while(p[i].purchase_price>p[i].sale_price)
            {
                printf("进货价不能大于售价，请重新输入\n");
                printf("货品的进货价:");
                scanf("%d",&p[i].purchase_price);
                printf("货品的售价:");
                scanf("%d",&p[i].sale_price);
            }
            system("cls");
            printf("请确认您输入的商品信息\n");
            printf("编号:%ld\n名称:%s\n进货数量:%d\n进货价:%d\n售价:%d\n",p[i].EAN,p[i].name,p[i].stock,p[i].purchase_price,p[i].sale_price);
            system("pause");
            int result_colour=0;
            ch=ui_choice(notice1,choice,2);
        }
    }
    
}    

