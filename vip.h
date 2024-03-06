#ifndef _VIP_
#define _VIP_

#include <stdio.h>
#include "vip_show.h"
#include "deregister.h"
#include "register.h"
#include "ui_terminal.h"
#include "viplib.h"
void vip_main()
{
    struct vip *vip_data = (struct vip *)malloc(sizeof(struct vip) * 1000);
    struct vip *vip_data_head = vip_data;
    int length = 0, changed = 0;
    int load_satus = load_vip_data(vip_data, &length);
    if (load_satus == -1)
        return;
    vip_data+=length;
    char *vip_choice[4] = {"1.注册新会员", "2.注销已有会员", "3.列出会员列表", "4.退出"};
    while (1)
    {
        int ch = ui_choice("会员管理", vip_choice, 4);
        if (ch == 0)
        {
            struct vip *vip = (struct vip *)malloc(sizeof(struct vip));
            int satus = register_vip(length, vip, vip_data_head);
            if (satus == 0)
            {
                vip->id=length+1;
                *vip_data = *vip;
                vip_data++;
                length++;
                free(vip);
                changed = 1;
            }
        }
        else if (ch == 1)
        {
            deregister(vip_data_head, length);
            length--;
            vip_data--;
            changed = 1;
        }
        else if (ch == 2)
        {
            show_vip(vip_data_head, length);
        }
        else if (ch == 3)
        {
            if (changed == 1)
            {
                char *save[2] = {"[N]不保存", "[Y]保存"};
                int result = ui_choice("存在未保存的更改，是否保存更改？", save, 2);
                if (result == 1)
                {
                    save_vip_data(vip_data_head, &length);
                    free(vip_data_head);
                }
            }
            return;
        }
        system("pause");
    }
}

#endif