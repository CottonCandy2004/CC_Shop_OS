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
    char *vip_choice[4] = {"1.ע���»�Ա", "2.ע�����л�Ա", "3.�г���Ա�б�", "4.�˳�"};
    while (1)
    {
        int ch = ui_choice("��Ա����", vip_choice, 4);
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
                char *save[2] = {"[N]������", "[Y]����"};
                int result = ui_choice("����δ����ĸ��ģ��Ƿ񱣴���ģ�", save, 2);
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