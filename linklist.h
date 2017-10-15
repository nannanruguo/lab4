#include "linktable.h"
/* data struct */
typedef struct DataNode
{
    LinkListNode* next;
    char* cmd;
    char* desc;
    void(*handler)();
} tDataNode;
/* show all cmd */
int ShowAllCmd(LinkList* head);
