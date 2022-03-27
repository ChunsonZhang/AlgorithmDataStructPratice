#ifndef _DOUBLY_LIST_H_
#define _DOUBLY_LIST_H_

#include "common.h"

struct DoublyNode_t {
    DoublyNode_t *next;
    DoublyNode_t *pre;
    int data;
};

struct DoublyList_t {
    DoublyNode_t  headNode;
    DoublyNode_t* tail;
    int listSize;
};


DoublyNode_t* createDoublyNode(int value);

DoublyNode_t* createDoublyNode(void);


DoublyList_t* createDoublyList(int arry[], int length);

void destroyDoublyList(DoublyList_t* list);

int doublyListTailAppend(DoublyList_t* list, DoublyNode_t* node);

int doublyListHeadAppend(DoublyList_t* list, DoublyNode_t* node);

void showEachNodeOfDoublyList(DoublyList_t* list);

int doublyListInvert(DoublyList_t* list);



#endif
