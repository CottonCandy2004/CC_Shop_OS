#ifndef ui_h
#define ui_h
#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui_terminal.h"

void flush(char *notice, char **arr, int length, int *choice);
void result_attach(char *result, int *result_colour, char *notice, char **arr, int length, int *choice);
int ui_re_choice(char *notice, char **arr, int length, char *result, int result_colour);
void orginize_input(int *choice, int *satus, const int *length);
int ui_choice(char *notice, char **arr, int length);

void flush(char *notice, char **arr, int length, int *choice)
{
    system("cls");
    if (DEBUG_MODE)
    {
        SetColor(14, 0);
        printf("===RUNNING IN DEBUG MODE,AUTH WILL SKIPPED===\n");
        SetColor(15, 0);
    }
    SetColor(15, 0);
    printf("%s\n", notice);
    for (int i = 0; i < length; i++)
    {
        if (i == *choice)
        {
            SetColor(0, 15);
            printf("%s\n", arr[i]);
            SetColor(15, 0);
        }
        else
        {
            printf("%s\n", arr[i]);
        }
    }
}

void result_attach(char *result, int *result_colour, char *notice, char **arr, int length, int *choice)
{
    flush(notice, arr, length, choice);
    SetColor(*result_colour, 0);
    printf("\n%s\n", result);
}

int ui_re_choice(char *notice, char **arr, int length, char *result, int result_colour)
{
    HideConsoleCursor();
    int choice = 0, satus = 0;
    while (1)
    {
        result_attach(result, &result_colour, notice, arr, length, &choice);
        orginize_input(&choice, &satus, &length);
        if (satus == 1)
        {
            return choice;
        }
    }
}

void orginize_input(int *choice, int *satus, const int *length)
{
    int key = getch();
    if (key == 224)
    {
        switch (getch())
        {
        case 72:
            (*choice)--;
            if (*choice < 0)
            {
                printf("\a");
                *choice = 0;
            }
            break;
        case 80:
            (*choice)++;
            if (*choice > (*length) - 1)
            {
                printf("\a");
                *choice = (*length) - 1;
            }
            break;
        default:
            printf("\a");
            break;
        }
    }
    else
    {
        switch (key)
        {
        case 'w':
            (*choice)--;
            if (*choice < 0)
            {
                printf("\a");
                *choice = 0;
            }
            break;
        case 's':
            (*choice)++;
            if (*choice > (*length) - 1)
            {
                printf("\a");
                *choice = (*length) - 1;
            }
            break;
        default:
            if (key == '\r')
            {
                *satus = 1;
            }
            else
            {
                printf("\a");
            }
            break;
        }
    }
}

int ui_choice(char *notice, char **arr, int length)
{
    HideConsoleCursor();
    int choice = 0, satus = 0;
    while (1)
    {
        fflush(stdin);
        flush(notice, arr, length, &choice);
        orginize_input(&choice, &satus, &length);
        if (satus == 1)
        {
            system("cls");
            return choice;
        }
    }
}
#endif
