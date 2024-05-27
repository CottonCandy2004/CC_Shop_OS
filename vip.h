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
    vip_data += length;
    char *vip_choice[5] = {"1.ע���»�Ա", "2.ע�����л�Ա", "3.�г���Ա�б�", "4.��csv��������", "5.����"};
    while (1)
    {
        int ch = ui_choice("��Ա����", vip_choice, 5);
        if (ch == 0)
        {
            struct vip *vip = (struct vip *)malloc(sizeof(struct vip));
            int satus = register_vip(length, vip, vip_data_head);
            if (satus == 0)
            {
                if (length == 0)
                    vip->id = 1;
                else
                    vip->id = (vip_data - 1)->id + 1;
                *vip_data = *vip;
                vip_data++;
                length++;
                free(vip);
                changed = 1;
            }
        }
        else if (ch == 1)
        {
            int satus = deregister(vip_data_head, length);
            if (satus == 200)
            {
                length--;
                vip_data--;
                changed = 1;
            }
        }
        else if (ch == 2)
        {
            show_vip(vip_data_head, length);
        }
        else if (ch == 3)
        {
            char *choice[2] = {"��", "��"};
            switch (ui_choice("�ò�������������������ݣ��Ƿ������", choice, 2))
            {
            case 0:
                SetColor(4, 0);
                printf("��ȡ��\n");
                SetColor(15, 0);
                break;
            case 1:
                if (import_from_csv(vip_data_head, &length) == 0)
                {
                    vip_data = vip_data_head;
                    vip_data += length;
                    changed = 1;
                }
                break;
            }
        }
        else if (ch == 4)
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