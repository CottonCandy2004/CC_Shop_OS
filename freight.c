#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "ui.h"
#include "struct.h"
#include "ui_terminal.h"
int main(){
    char *empty="";
    char *Error1="��δʵ��";
    char *notice1="��ѡ�����Ĳ�����";
    char *choice1="1.ȷ����ȷ";
    char *choice2="2.��������";
    char* choice[2]={choice1,choice2};
    char *result=empty;
    printf("������Ҫ���������ֻ�Ʒ��\n");
    int n,i,q,ch;
    scanf("%d",&n);
    freight *p=(freight *)malloc(n*sizeof(freight));
    for ( i = 0; i < n; i++)
    {
        for(ch=1;ch==1;){
            system("cls");
            printf("������\n��Ʒ�ı��:");
            scanf("%ld",&p[i].EAN);
            if(){
                printf("�ñ���Ѵ��ڣ�����������\n");
                getchar();
                continue;
            }
            getchar();
            printf("��Ʒ������:");
            scanf("%s",p[i].name);
            printf("��Ʒ�Ľ�������:");
            scanf("%d",&p[i].stock);
            printf("��Ʒ�Ľ�����:");
            scanf("%d",&p[i].purchase_price);
            printf("��Ʒ���ۼ�:");
            scanf("%d",&p[i].sale_price);
            while(p[i].purchase_price>p[i].sale_price)
            {
                printf("�����۲��ܴ����ۼۣ�����������\n");
                printf("��Ʒ�Ľ�����:");
                scanf("%d",&p[i].purchase_price);
                printf("��Ʒ���ۼ�:");
                scanf("%d",&p[i].sale_price);
            }
            system("cls");
            printf("��ȷ�����������Ʒ��Ϣ\n");
            printf("���:%ld\n����:%s\n��������:%d\n������:%d\n�ۼ�:%d\n",p[i].EAN,p[i].name,p[i].stock,p[i].purchase_price,p[i].sale_price);
            system("pause");
            int result_colour=0;
            ch=ui_choice(notice1,choice,2);
        }
    }
    
}    

