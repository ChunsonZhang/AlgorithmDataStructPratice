#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

#include "common.h"

struct SingleNode_t {
    SingleNode_t *next;
    int data;
};

struct SingleList_t {
    SingleNode_t  headNode;
    SingleNode_t* tail;
    int listSize;
};

struct NoHeadSingleList_t {
    SingleNode_t* head;
    SingleNode_t* tail;
    int listSize;
};

SingleNode_t* createSingleNode(int value);

SingleNode_t* createSingleNode(void);


SingleList_t*       createSingleList(int arry[], int length);
NoHeadSingleList_t* createNoheadSingleList(int arry[], int length);

void destroySingleList(SingleList_t* list);
void destroySingleList(NoHeadSingleList_t* list);

int singleListTailAppend(SingleList_t* list, SingleNode_t* node);
int singleListTailAppend(NoHeadSingleList_t* list, SingleNode_t* node);

int singleListHeadAppend(SingleList_t* list, SingleNode_t* node);
int singleListHeadAppend(NoHeadSingleList_t* list, SingleNode_t* node);

void showEachNodeOfSingleList(SingleList_t* list);
void showEachNodeOfSingleList(NoHeadSingleList_t* list);

int singleListInvert(SingleList_t* list);
int singleListInvert(NoHeadSingleList_t* list);


bool isEchoLinkList(SingleNode_t* head);

SingleNode_t* getLinkListMidNode1(SingleNode_t* head);
SingleNode_t* getLinkListMidNode2(SingleNode_t* head);
SingleNode_t* getLinkListMidPreNode(SingleNode_t* head);
SingleNode_t* getLinkListMidAfterNode(SingleNode_t* head);
SingleNode_t* testGetLinkListMidNode(SingleNode_t* head);


SingleNode_t* partitionLinkList(SingleNode_t* head, int partitionNum);
SingleNode_t* partitionLinkListUseArry(SingleNode_t* head, int num);
/* 单元测试用例 */
int getMidNodeTestCase(int arry[], int length);
int testEchoLinkList(int arry[], int length);
#endif