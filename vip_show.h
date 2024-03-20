#ifndef _VIP_SHOW_
#define _VIP_SHOW_

#include "struct.h"
#include <stdio.h>
#include "ui_terminal.h"
void show_vip(struct vip *vip,int length)
{
    system("cls");
    SetColor(3,0);
    printf("��ע��Ļ�Ա��Ϣ���£�\n��Ա���\t��Ա�ֻ���\t��Ա����\t�ϴ���������\t�ۼ����Ѷ�\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t\t%lld\t%s\t\t%d��%d��%d��\t��%lf\n",vip[i].id,vip[i].phone_number,vip[i].name,vip[i].last_consume_day.year,vip[i].last_consume_day.month,vip[i].last_consume_day.day,vip[i].total_consume);
    }
    return;
}

#endif