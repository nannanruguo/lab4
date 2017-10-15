#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
int ShowAllCmd(LinkList* head)
{
        tDataNode* p = (tDataNode*)getLinkListHead(head);
    printf("*************Menu List************\n");
    while(p != NULL)
    {
            printf("%s -- %s\n", p->cmd, p->desc);
        p = (tDataNode*)getNextLinkListNode(head, (LinkListNode*)p);
    }
        printf("*************Menu End*************\n");
    return 1;
}
