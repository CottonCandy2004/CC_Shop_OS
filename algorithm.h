#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "struct.h"

void sort_freight(freight *head,freight *tail)
{
    if(head==tail) return;
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

#endif