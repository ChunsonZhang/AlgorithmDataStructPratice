#include "doublyList.h"

DoublyNode_t* createDoublyNode(void)
{
    DoublyNode_t* node = (DoublyNode_t*)malloc(sizeof(DoublyNode_t));
    if (node) {
        node->data = 0;
        node->next = NULL;
        node->pre = NULL;
    }
    return node;
}


DoublyNode_t* createDoublyNode(int value)
{
    DoublyNode_t* node = (DoublyNode_t*)malloc(sizeof(DoublyNode_t));
    if (node) {
        node->data = value;
        node->next = NULL;
        node->pre = NULL;
    }
    return node;
}


void initDoublyList(DoublyList_t* list)
{
    if (list == NULL) {
        return;
    }
    list->tail = &(list->headNode);
    list->listSize = 0;
    list->headNode.data = 0;
    list->headNode.next = NULL;
    list->headNode.pre = NULL;
}


DoublyList_t* createDoublyList(int arry[], int length)
{
    DoublyList_t* list = (DoublyList_t*)malloc(sizeof(DoublyList_t));
    if (list == NULL) {
        return NULL;
    }
    initDoublyList(list);

    size_t i = 0;
    for (; i < length; i++) {
        DoublyNode_t* newNode = createDoublyNode(arry[i]);
        if (!newNode) {
            printf("create new node failed.\n");
            break;
        }
         doublyListTailAppend(list, newNode);
    }

    if (i != length) {
        destroyDoublyList(list);
        list = NULL;
    }
    return list;
}



void showEachNodeOfDoublyList(DoublyList_t* list)
{
    if (!list) return;
    DoublyNode_t* ptr = list->headNode.next;

    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void deleteDoublyLinkNode(DoublyNode_t* node)
{
    DoublyNode_t* preNode = node->pre;
    preNode->next = node->next;
    if(preNode->next){
        preNode->next->pre = preNode;
    }
    free(node);
}


void doubleListPopLastNode(DoublyList_t* list, DoublyNode_t *node)
{
    if (node) {
        memcpy(node, list->tail, sizeof(DoublyNode_t));
        node->pre = NULL;
        node->next = NULL;
    }

    /* 到达头结点了 */
    if (list->tail->pre == NULL) {
        return;
    }

    list->tail = list->tail->pre;
    list->listSize--;
    free(list->tail->next);
    list->tail->next = NULL;    
}


void destroyDoublyList(DoublyList_t* list)
{
    if (!list) return;

    while (list->headNode.next) {
        deleteDoublyLinkNode(list->headNode.next);
        // list->listSize--;
    }

    // while (list->tail != (&list->headNode)) {
    //     doubleListPopLastNode(list, NULL);
    // }

    free(list);
}


/*
 * @tail：最后一个节点的地址
 * @node：需要插入的节点
 * @retValue：完成后节点插入之后返回的新的尾节点的地址
 * 如果tail是空，那么返回的尾节点也是空
 * 如果node是空，那么返回的尾节点还是原来的tail的值
 */ 
int doublyListTailAppend(DoublyList_t* list, DoublyNode_t* node)
{
    if (list == NULL || list->tail == NULL) {
        return -1;
    }

    list->tail->next = node;
    node->pre = list->tail;

    list->tail = node;
    list->listSize++;
    return 0;
}


int doublyListHeadAppend(DoublyList_t* list, DoublyNode_t* node)
{
    if (list == NULL || node == NULL) {
        return -1;
    }

    node->next = list->headNode.next;
    node->next->pre = node;

    node->pre = &(list->headNode);
    list->headNode.next = node;

    list->listSize++;

    if (node->next == NULL) {
        list->tail = node;
    }
    return 0;
}


int doublyListInvert(DoublyList_t* list)
{
    if (!list) return -1;

    DoublyNode_t* tmpNodePtr = list->headNode.next;
    list->headNode.next = NULL;
    list->listSize = 0;
    list->tail = &(list->headNode);

    DoublyNode_t* nextNode = NULL;
    while (tmpNodePtr) {
        nextNode = tmpNodePtr->next;
        doublyListHeadAppend(list, tmpNodePtr);
        tmpNodePtr = nextNode;
    }
    return 0;
}
