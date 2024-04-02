#ifndef __AUTH_H__
#define __AUTH_H__
#include <stdio.h>
#include <stdlib.h>
#include "ui_terminal.h"
#include <conio.h>

char *input_password();

int auth()
{
    FILE *fp;
    fp = fopen("key.dat", "r");
    if (fp == NULL)
    {
    Label_empty:
        fp = fopen("key.dat", "w");
        if (fp == NULL)
        {
            system("cls");
            SetColor(4, 0);
            printf("���̶�д������������Ƿ�����ӦĿ¼�Ķ�дȨ�ޣ�\n");
            SetColor(15, 0);
            system("pause");
            return -1;
        }
        while (1)
        {
            system("cls");
            printf("��������Կ����Ӧ����128λ����\n");
            char *password = input_password();
            if (strlen(password) > 128)
            {
                printf("\n��Կ���Ȳ��ܳ���128λ��\n");
                Sleep(1000);
                continue;
            }
            else
            {
                char *sha = summonsha(password);
                fwrite(sha, sizeof(char), strlen(sha), fp);
                system("cls");
                printf("��Կ���óɹ���\n");
                Sleep(1000);
                fclose(fp);
                free(sha);
                return 200;
            }
        }
    }
    else
    {
        system("cls");
        char *key = (char *)malloc(sizeof(char) * 65);
        memset(key, 0, 65);
        fread(key, sizeof(char), 64, fp);
        if (feof(fp))
            goto Label_empty;
        fclose(fp);
        printf("��������Կ��\n");
        char *password = input_password();
        char *sha = summonsha(password);
        if (strcmp(sha, key) == 0)
        {
            free(sha);
            free(key);
            return 200;
        }
        else
        {
            free(sha);
            free(key);
            return -2;
        }
    }
}

char *input_password()
{
    char *password = (char *)malloc(sizeof(char) * 129);
    memset(password, 0, 129);
    int length = 0;
    char buff;
    while (1)
    {
        buff = _getch();
        if (buff == '\r')
        {
            if (length == 0)
            {
                printf("\a");
                continue;
            }
            password[length] = '\0';
            break;
        }
        else if (buff == '\b')
        {
            if (length > 0)
            {
                length--;
                printf("\b \b");
            }
            else
            {
                printf("\a");
            }
        }
        else
        {
            password[length] = buff;
            length++;
            printf("*");
        }
    }
    return password;
}

#endif