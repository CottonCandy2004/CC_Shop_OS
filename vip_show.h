#ifndef _VIP_SHOW_
#define _VIP_SHOW_

#include "struct.h"
#include <stdio.h>
#include "ui_terminal.h"
void show_vip(struct vip *vip,int length)
{
    system("cls");
    SetColor(3,0);
    printf("已注册的会员信息如下：\n会员编号\t会员手机号\t会员姓名\t上次消费日期\t累计消费额\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t\t%lld\t%s\t\t%d年%d月%d日\t￥%lf\n",vip[i].id,vip[i].phone_number,vip[i].name,vip[i].last_consume_day.year,vip[i].last_consume_day.month,vip[i].last_consume_day.day,vip[i].total_consume);
    }
    return;
}

#endif