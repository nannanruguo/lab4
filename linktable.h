#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
typedef struct LinkListNode
{
    struct LinkListNode *pNext;
} LinkListNode;
typedef struct LinkList
{
    LinkListNode *head;
    LinkListNode *tail;
    int size;
} LinkList;
/*create a new linklist*/
LinkList* createLinkList();
/*destroy the existed linklist*/
int destroyLinkList(LinkList *pLinkList);

/*add a node to a linklist*/
int addLinkListNode(LinkList *pLinkList, LinkListNode *pLinkListNode);

/*remove a node from the linklist*/
int delLinkListNode(LinkList *pLinkList, LinkListNode *pLinkListNode);

/*get the head of the linklist*/
LinkListNode* getLinkListHead(const LinkList *pLinkList);

/*get next node of the parameter node*/
LinkListNode* getNextLinkListNode(const LinkList *pLinkList, const LinkListNode *pLinkListNode);
#endif
