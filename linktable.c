#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
/*create a new linklist*/
LinkList* createLinkList()
{
    LinkList *p_list=(LinkList*)malloc(sizeof(LinkList*));
    if(p_list==NULL)
    {
        printf("CREATE LINKLIST ERROR!\n");
        exit(0);
    }else
    {
        p_list->head=NULL;
        p_list->tail=NULL;
        p_list->size=0;
        return p_list;
    }

}
/*destroy the existed linklist*/
int destroyLinkList(LinkList *pLinkList)
{
    if(pLinkList==NULL)
    {
         printf("destory fails. linklist is not exsit!\n");
         exit(0);
    }
    while(pLinkList->head != NULL)
    {
        LinkListNode *p=pLinkList->head;
        pLinkList->head = pLinkList->head->pNext;
        free(p);
        pLinkList->size -= 1;
    }
        pLinkList->tail = NULL;
        free(pLinkList);
    return 1;
}
/*add a node to a linklist*/
int addLinkListNode(LinkList *pLinkList, LinkListNode *pLinkListNode)
{
    if(pLinkListNode == NULL){
        printf("add linklist node ERROR!\n");
        exit(0);
    }
    if(pLinkList->head == NULL)
    {
        pLinkList->head = pLinkListNode;
        pLinkList->tail = pLinkListNode;
    }else
    {
        pLinkList->tail->pNext = pLinkListNode;
        pLinkList->tail = pLinkListNode;
        pLinkList->tail->pNext = NULL;
    }

    pLinkList->size += 1;
    return 1;
}
/*remove a node from the linklist*/
int delLinkListNode(LinkList *pLinkList, LinkListNode *pLinkListNode)
{
    if (pLinkList == NULL || pLinkListNode == NULL)
    {
        return 0;
    }
    // handler head == pLinkListNode:
    if (pLinkList->head == pLinkListNode)
    {
        pLinkList->head = pLinkList->head->pNext;
        pLinkList->size -= 1;
        if (pLinkList->size == 0)
        {
            pLinkList->tail = NULL;
        }
        return 1;
    }
    LinkListNode* ptr = pLinkList->head;
    while (ptr != NULL)
    {
        if (ptr->pNext == pLinkListNode)
        {
            ptr->pNext = ptr->pNext->pNext;
            pLinkList->size -= 1;
            if (pLinkList->size == 0)
            {
                pLinkList->tail = NULL;
            }
            return 1;
        }
        ptr = ptr->pNext;
    }
    return 0;
}
/*get the head of the linklist*/
LinkListNode* getLinkListHead(const LinkList *pLinkList)
{
    if (pLinkList == NULL || pLinkList->head == NULL)
    {
        return NULL;
    }
    return pLinkList->head;
}
/*get next node of the parameter node*/
LinkListNode* getNextLinkListNode(const LinkList *pLinkList, const LinkListNode *pLinkListNode)
{
    if (pLinkList == NULL || pLinkListNode == NULL)
    {
        return NULL;
    }
    LinkListNode* ptr = pLinkList->head;
    while (ptr != NULL)
    {
        if (ptr == pLinkListNode)
        {
            return ptr->pNext;
        }
        ptr = ptr->pNext;
    }
    return NULL;
}
