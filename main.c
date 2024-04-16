#include <stdio.h>
#include "ui.h"
#include <stdlib.h>
#include "struct.h"
#include "vip.h"
#include "auth.h"
#include "stock.h"

int main()
{
    int status = auth();
    while (status != 200)
    {
        if (status == -2)
        {
            SetColor(4, 0);
            printf(" X\n�����������������\n");
            Sleep(1000);
            SetColor(15, 0);
        }
        if (status == -1)
            return 0;
        status = auth();
    }
    char *empty = "";
    char *Error1 = "��δʵ��";
    char *notice1 = "��ѡ�����Ĳ�����";
    char *choice1 = "1.��Ա����";
    char *choice2 = "2.�������";
    char *choice3 = "3.�˳�";
    char *choice[3] = {choice1, choice2, choice3};
    char *result = empty;
    int result_colour = 0;
    while (1)
    {
        int ch=ui_choice(notice1, choice, 3);
        if (ch == 0)
        {
            vip_main();
        }
        else if (ch == 1)
        {
            stock_main();
        }
        else if (ch == 2)
        {
            exit(0);
        }
    }
    system("pause");
    return 0;
}