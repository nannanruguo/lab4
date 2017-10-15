#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linktable.h"
#include "string.h"
/* CMD functions */
void help();
void hello();
void pwd();
void add();
void sub();
void quit();
/* normal functions */
int init_menu();
tDataNode* search_cmd(LinkList* head, char* cmd);
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
LinkList* head = NULL;
/* menu program */
int main()
{
    /* cmd line begins */
    init_menu(&head);
    char cmd[CMD_MAX_LEN];
    while (1)
    {    
        printf("Input a cmd (input help for command help) >");
        scanf("%s", cmd);
        tDataNode* p = search_cmd(head, cmd);
        if (p == NULL)
        {
            printf("This is wrong cmd!\n");
            ShowAllCmd(head);
            continue;
        }
        if (p->handler != NULL)
        {
            p->handler();
        }
    }
    return 0;
}
/* CMD functions */
void help()
{
    ShowAllCmd(head);

}
void hello()
{
    printf("Hello,I am glad to meet you here.\n");
}
void add()
{
    int a,b,c;
    printf("input a and b: ");
    scanf("%d %d",&a,&b);
    c=a+b;
    printf("result is %d\n",c);
}
void sub()
{
    int a,b,c;
    printf("input a and b: ");
    scanf("%d %d",&a,&b);
    c=a-b;
    printf("result is %d\n",c);
}
void quit()
{
    exit(0);
}
/* normal functions */
int init_menu(LinkList** pp_table)
{
    *pp_table = createLinkList();

    tDataNode* node = (tDataNode*)malloc(sizeof(tDataNode));
    node->cmd = "help";
    node->desc = "show this help list.";
    node->handler = help;
    addLinkListNode(*pp_table, (LinkListNode*)node);
    node = (tDataNode*)malloc(sizeof(tDataNode));
    node->cmd = "hello";
    node->desc = "say hello to you.";
    node->handler = hello;
    addLinkListNode(*pp_table, (LinkListNode*)node);
    node = (tDataNode*)malloc(sizeof(tDataNode));
    node->cmd = "add";
    node->desc = "a + b";
    node->handler = add;
    addLinkListNode(*pp_table, (LinkListNode*)node);
    node = (tDataNode*)malloc(sizeof(tDataNode));
    node->cmd = "sub";
    node->desc = "a - b";
    node->handler = sub;
    addLinkListNode(*pp_table, (LinkListNode*)node);
    node = (tDataNode*)malloc(sizeof(tDataNode));
    node->cmd = "quit";
    node->desc = "exit cmd";
    node->handler = quit;
    addLinkListNode(*pp_table, (LinkListNode*)node);
    return 0;
}
tDataNode* search_cmd(LinkList* linklist, char* cmd)
{
    tDataNode* ptr_node = (tDataNode*)getLinkListHead(linklist);
    while (ptr_node != NULL)
    {
        if (strcmp(ptr_node->cmd, cmd) == 0)
        {
            return ptr_node;
        }
        ptr_node = (tDataNode*)getNextLinkListNode(linklist, (LinkListNode*)ptr_node);
    }
    return NULL;
}
