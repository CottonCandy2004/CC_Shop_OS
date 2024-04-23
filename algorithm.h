#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "struct.h"

void sort_freight(freight *head,freight *tail)
{
    if(head>=tail) return;
    freight *p,*q=head+1;
    for(p=head+1;p!=tail+1;p++)
    {
        if(p->margins > head->margins)
        {
            freight temp=*p;
            *p=*q;
            *q=temp;
            q++;
        }
    }
    q--;
    freight temp=*head;
    *head=*q;
    *q=temp;
    sort_freight(head,q);
    sort_freight(q+1,tail);
    return;
}

char *summonsha(char *str_)
{
    FILE *fp, *buff;
    buff = fopen("sha", "w");
    fwrite(str_, 1, strlen(str_), buff);
    fclose(buff);
    fp = popen("certutil.exe -hashfile sha sha256", "r");
    char *buffer = (char *)malloc(1024);
    char *q=buffer;
    memset(buffer, 0, 1024);
    while (!feof(fp))
    fread(q++, 1, 1, fp);
    pclose(fp);
    char *p = strstr(buffer, "CertUtil");
    p--;
    *p='\0';
    p-=64;
    system("del sha");
    char *sha = (char *)malloc(65);
    strcpy(sha, p);
    free(buffer);
    return sha;
}
#endif