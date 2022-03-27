#include "singleList.h"

/*********************************************************/

SingleNode_t* createSingleNode(void)
{
    SingleNode_t* node = (SingleNode_t*)malloc(sizeof(SingleNode_t));
    if (node) {
        node->data = 0;
        node->next = NULL;
    }
    return node;
}


SingleNode_t* createSingleNode(int value)
{
    SingleNode_t* node = (SingleNode_t*)malloc(sizeof(SingleNode_t));
    if (node) {
        node->data = value;
        node->next = NULL;
    }
    return node;
}


/*********************************************************/

void initSingleList(SingleList_t* list)
{
    if (list == NULL) {
        return;
    }
    list->tail = &(list->headNode);
    list->listSize = 0;
    list->headNode.data = 0;
    list->headNode.next = NULL;
}


void initSingleList(NoHeadSingleList_t* list)
{
    if (list == NULL) {
        return;
    }
    list->head = NULL;
    list->tail = NULL;
    list->listSize = 0;
}


/*********************************************************/

SingleList_t* createSingleList(int arry[], int length)
{
    if (length <= 0) {
        return NULL;
    }
    
    SingleList_t* list = (SingleList_t*)malloc(sizeof(SingleList_t));
    if (list == NULL) {
        return NULL;
    }
    initSingleList(list);

    size_t i = 0;
    for (; i < length; i++) {
        SingleNode_t* newNode = createSingleNode(arry[i]);
        if (!newNode) {
            printf("create new node failed.\n");
            break;
        }
         singleListTailAppend(list, newNode);
    }

    if (i != length) {
        destroySingleList(list);
        list = NULL;
    }
    return list;
}


NoHeadSingleList_t* createNoheadSingleList(int arry[], int length)
{
    if (length <= 0) {
        return NULL;
    }

    NoHeadSingleList_t* list = (NoHeadSingleList_t*)malloc(sizeof(SingleList_t));
    if (list == NULL) {
        return NULL;
    }
    initSingleList(list);

    size_t i = 0;
    for (; i < length; i++) {
        SingleNode_t* newNode = createSingleNode(arry[i]);
        if (!newNode) {
            printf("create new node failed.\n");
            break;
        }
        singleListTailAppend(list, newNode);
    }

    if (i != length) {
        destroySingleList(list);
        list = NULL;
    }
    return list;
}


/*********************************************************/

void showEachNodeOfSingleList(SingleList_t* list)
{
    if (!list) return;
    SingleNode_t* ptr = list->headNode.next;

    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void showEachNodeOfSingleList(NoHeadSingleList_t* list)
{
    if (!list) return;
    SingleNode_t* ptr = list->head;

    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


/*********************************************************/

void deleteSingleLinkNode(SingleNode_t* node, SingleNode_t* preNode)
{
    preNode->next = node->next;
    free(node);
}

 
/*
 * 这种写法实际上是把下一个节点的内容填到当前节点，
 * 然后释放掉下一个节点
 * 这种写法会带来一个问题是，如果节点本身是某种数据的一部分，
 * 需要靠当前节点的地址加上一定的偏移位置得到完整数据的地址
 * 那么这种快速删除的方法并没有释放掉当前节点的地址，只是把该节点的值复制成下一个节点的值
 * 根据当前节点地址加上偏移找到完整数据的地址仍然是原来节点的数据，而不是下一个节点的数据
 */ 
void quickDeleOneNode(SingleNode_t* node)
{
    SingleNode_t* nextNode = node->next;
    if (nextNode) {
        node->next = nextNode->next;
        node->data = nextNode->data;
        free(nextNode);
    } else {
        free(node);
    }
}


/*********************************************************/

void destroySingleList(SingleList_t* list)
{
    if (!list) return;

    while (list->headNode.next) {
        deleteSingleLinkNode(list->headNode.next, &(list->headNode));
        // list->listSize--;
    }

    free(list);
}


void destroySingleList(NoHeadSingleList_t* list)
{
    if (!list || !list->head) return;

    while (list->head->next) {
        deleteSingleLinkNode(list->head->next, list->head);
    }
    free(list->head);
    free(list);
}


/*********************************************************/

int singleListTailAppend(SingleList_t* list, SingleNode_t* node)
{
    if (list == NULL || list->tail == NULL) {
        return -1;
    }

    list->tail->next = node;
    list->tail = node;
    list->listSize++;
    return 0;
}


int singleListTailAppend(NoHeadSingleList_t* list, SingleNode_t* node)
{
    if (list == NULL) {
        return -1;
    }

    if(list->tail) {
        list->tail->next = node;
        list->tail = node;
    } else {
        list->tail = node;
        list->head = node;
    }
    list->listSize++;
    return 0;
}


/*********************************************************/

int singleListHeadAppend(SingleList_t* list, SingleNode_t* node)
{
    if (list == NULL || node == NULL) {
        return -1;
    }

    node->next = list->headNode.next;
    list->headNode.next = node;
    list->listSize++;

    if (node->next == NULL) {
        list->tail = node;
    }
    return 0;
}


int singleListHeadAppend(NoHeadSingleList_t* list, SingleNode_t* node)
{
    if (list == NULL || node == NULL) {
        return -1;
    }

    node->next = list->head;
    list->head = node;
    list->listSize++;
    if (list->head->next == NULL) {
        list->tail = node;
    }
    return 0;
}


/*********************************************************/

int singleListInvert(SingleList_t* list)
{
    if (!list) return -1;

    SingleNode_t* tmpNodePtr = list->headNode.next;
    list->headNode.next = NULL;
    list->listSize = 0;
    list->tail = &(list->headNode);

    SingleNode_t* nextNode = NULL;
    while (tmpNodePtr) {
        nextNode = tmpNodePtr->next;
        singleListHeadAppend(list, tmpNodePtr);
        tmpNodePtr = nextNode;
    }
    return 0;
}


int singleListInvert(NoHeadSingleList_t* list)
{
    if (!list) return -1;

    SingleNode_t* tmpNodePtr = list->head;    
    list->head = NULL;
    list->listSize = 0;
    list->tail = NULL;

    SingleNode_t* nextNode = NULL;
    while (tmpNodePtr) {
        nextNode = tmpNodePtr->next;
        singleListHeadAppend(list, tmpNodePtr);
        tmpNodePtr = nextNode;
    }

    return 0;
}


SingleNode_t* singleListInvert(SingleNode_t* head)
{
    SingleNode_t* newHead = NULL;
    SingleNode_t* nextNode;
    SingleNode_t* tmp = head;
    while(tmp) {
        nextNode = tmp->next;       //记录旧链表当前节点下一个节点

        tmp->next = newHead;        //将当前节点与下一个节点断开，
                                    //断开后将当前节点作为头部介入到新链表中

        newHead = tmp;              //新链表头部指向新加入的头结点

        tmp = nextNode;             //将当前节点指向旧链表的头结点
    }

    return newHead;
}


/*********************************************************/

/*
 * 判断链表是否是回显链表
 */ 
bool isEchoLinkList(SingleNode_t* head)
{
    bool result = true;
    if (!head) return false;

    SingleNode_t* leftEndNode = getLinkListMidNode1(head);
    
    //链表只有一个节点的情况
    if (leftEndNode->next == NULL) {
        return true;
    }

    SingleNode_t* rightStartNode = leftEndNode->next;
    leftEndNode->next = NULL;

    /*将右边的链表翻转 */
    SingleNode_t* newHead = NULL;
    SingleNode_t* nextNode = NULL;
    while(rightStartNode) {
        nextNode = rightStartNode->next;
        rightStartNode->next = newHead;
        newHead = rightStartNode;
        rightStartNode = nextNode;
    }
    rightStartNode = newHead;

    /* 比较两段链表是否一致 */
    SingleNode_t *p1 = head;
    SingleNode_t *p2 = rightStartNode;
    while (p1 && p2) {
        if (p1->data != p2->data) {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    /* 再次翻转恢复原来的链表 */
    newHead = NULL;
    nextNode = NULL;
    while(rightStartNode) {
        nextNode = rightStartNode->next;
        rightStartNode->next = newHead;
        newHead = rightStartNode;
        rightStartNode = nextNode;
    }
    leftEndNode->next = newHead;

    return result;
}

/*********************************************************/

SingleNode_t* getLinkListLoopNode(SingleNode_t* head)
{
    if (!head) return NULL;
    SingleNode_t* p1 = head;
    SingleNode_t* p2 = head;

    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;

        if (p1 == p2) {
            break;
        }
    }

    if (p2 == NULL || p2->next == NULL) return NULL;
    
    p2 = head;
    while (p2 != p1) {
        p2 = p2->next;
        p1 = p1->next;
    }
    
    return p2;
}

/*
 *
 * 
 */
SingleNode_t* getNoloopLinkListCrossNode(
    SingleNode_t* head1, 
    SingleNode_t* head2, 
    SingleNode_t* endNode)
{
    if (head1 == NULL || head2 == NULL) return NULL;

    SingleNode_t* endNode1 = NULL;
    SingleNode_t* endNode2 = NULL;
    
    /* 遍历两个链表，找到链表最后一个节点以及两个链表的长度 */
    SingleNode_t* p1 = head1;
    int lengthDiff = 0;
    while (p1) {
        endNode1 = p1;
        lengthDiff++;
        p1 = p1->next;
    }
    
    SingleNode_t* p2 = head2;
    int length2 = 0;
    while (p2) {
        endNode2 = p2;
        lengthDiff--;
        p2 = p2->next;
    }

    /* 如果最后一个节点不相等，那说明不相交 */
    if (endNode1 != endNode2) return NULL;

    /* p1设置为长链表的表头, p2设置为短链表的表头 */
    p1 = (lengthDiff>0) ? head1 : head2;
    p2 = (p1!=head1) ? head1 : head2;
    if (lengthDiff < 0) {
        lengthDiff = -lengthDiff;
    }

    /* 长链表要先走多出的长度，保证两个链表相交前的长度一致 */
    for (int i = 0; i < lengthDiff; i++) {        
        p1 = p1->next;
    }

    // 两个指针相遇就是相交的位置
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p1;
}


SingleNode_t* getloopLinkListCrossNode(
    SingleNode_t* head1, 
    SingleNode_t* head2,
    SingleNode_t* loop1,
    SingleNode_t* loop2
    )
{

    //环交点相等的情况的
    if (loop1 == loop2) {
        return getNoloopLinkListCrossNode(head1, head2, loop2);
    }

    // 环交点不一样的时候，相交在环内的时候
    SingleNode_t* p1 = loop1->next;
    while (p1 != loop1) {
        if (p1 == loop2) {
            return loop2;
        }
        p1 = p1->next;
    }
    
    return NULL;
}


SingleNode_t* getLinkListCrossNode(SingleNode_t* head1, SingleNode_t* head2)
{
    if (head1 == NULL || head2 == NULL) return NULL;

    SingleNode_t* loopNode1 = getLinkListLoopNode(head1);
    SingleNode_t* loopNode2 = getLinkListLoopNode(head2);

    // 两个都无环
    if (!loopNode1 && !loopNode2) {
        return getNoloopLinkListCrossNode(head1, head2, NULL);
    }

    // 两个都有环
    if (loopNode1 && loopNode2) {
        return getloopLinkListCrossNode(head1, head2, loopNode1, loopNode2);
    }

    return NULL;
}



/*********************************************************/

/*
 * 奇数长度的链表返回中间的节点
 * 偶数长度的链表返回中间前的一个节点
 * 实现方法：快指针提前一步
 */
SingleNode_t* getLinkListMidNode1(SingleNode_t* head)
{
    if (head == NULL) return NULL;

    SingleNode_t* p1 = head;
    SingleNode_t* p2 = head->next ;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}


/*
 * 奇数长度的链表返回中间的节点
 * 偶数长度的链表返回中间的后一个节点
 * 实现方法：快指针提前一步
 */
SingleNode_t* getLinkListMidNode2(SingleNode_t* head)
{
    if (head == NULL) return NULL;

    SingleNode_t* p1 = head;
    SingleNode_t* p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}


/*
 * 不管链表长度为奇偶都返回链表中间的前一个节点
 * 实现方法：快指针提前2步
 */
SingleNode_t* getLinkListMidPreNode(SingleNode_t* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    SingleNode_t* p1 = head;
    SingleNode_t* p2 = head->next->next ;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}


/*
 * 不管链表长度为奇偶都返回链表中间的前一个节点
 * 实现方法：慢指针提前一步
 */
SingleNode_t* getLinkListMidAfterNode(SingleNode_t* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    SingleNode_t* p1 = head->next;
    SingleNode_t* p2 = head;
    while (p2->next && p2->next->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}


/*********************************************************/

SingleNode_t* partitionLinkList(SingleNode_t* head, int partitionNum)
{
    SingleNode_t* smallHead = NULL;
    SingleNode_t* smallTail = NULL;
    SingleNode_t* equalHead = NULL;
    SingleNode_t* equalTail = NULL;
    SingleNode_t* bigHead   = NULL;
    SingleNode_t* bigTail   = NULL;
    while (head) {
        if (head->data < partitionNum) {
            if(!smallTail) {
                smallHead = head;
                smallTail = head;
            } else {
                smallTail->next = head;
                smallTail = head;
            }
            head = head->next;
            smallTail->next = NULL;
        } else if (head->data == partitionNum) {
            if (!equalTail) {
                equalTail = head;
                equalHead = head;
            } else {
                equalTail->next = head;
                equalTail = head;
            }
            head = head->next;
            equalTail->next = NULL;
        } else {
            if (!bigTail) {
                bigTail = head;
                bigHead = head;
            } else {
                bigTail->next = head;
                bigTail = head;
            }
            head = head->next;
            bigTail->next = NULL;
        }
    }
    

    if (smallHead) {
        smallTail->next = equalHead ? equalHead : bigHead;
        if (equalHead) {
            equalTail->next = bigHead;
        }
        return smallHead;
    }

    if (equalHead) {
        equalTail->next = bigHead;
        return equalHead;
    }

    return bigHead;
}


void arryPartition(SingleNode_t* arry[], int length, int num)
{
    int i = 0;
    int leftIndex = 0;
    int rightIndex = length -1;
    while (i <= rightIndex) {
        if (arry[i]->data < num) {
            swapNumber(arry[i], arry[leftIndex]);
            leftIndex++;
            i++;
        } else if (arry[i]->data == num) {
            i++;
        } else {
            swapNumber(arry[i], arry[rightIndex]);
            rightIndex--;
        }
    }
}


SingleNode_t* partitionLinkListUseArry(SingleNode_t* head, int num)
{
    std::vector<SingleNode_t*> vec;
    while (head) {
        vec.push_back(head);
        head = head->next;
    }

    SingleNode_t **arry = new SingleNode_t*[vec.size()];
    for (int i = 0; i < vec.size(); i++) {
        arry[i] = vec[i];
    }
    arryPartition(arry, vec.size(), num);
    
    size_t i;
    for (i = 0; i < vec.size()-1; i++) {
        arry[i]->next = arry[i+1];
    }
    arry[i]->next = NULL;
    head = arry[0];
    delete [] arry;
    return head;
}


/*********************************************************/

/*
 * offset == 0: 打印中间前一个
 * offset == 1: 打印中间或者中间前一个节点
 * offset == 2: 打印中间或者中间后面一个
 * offset == 3: 打印中间后面一个
 */
SingleNode_t* testGetLinkListMidNode(SingleNode_t* head, int offset)
{
    if (!head) return NULL;

    SingleNode_t* p = head;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }

    if (length == 1) {
        return head;
    }

    p = head;
    for (int i = 1; i < (length+offset)/2; i++) {
        p = p->next;
    }
    return p;
}


/*********************************************************/
/*接口测试*/
/*********************************************************/

int getMidNodeTestCase(int arry[], int length)
{
    if (length <= 0) return 0;

    std::cout << "list length: " << length << std::endl;
    NoHeadSingleList_t* list = createNoheadSingleList(arry, length);
    // showEachNodeOfSingleList(list);

    std::cout << "Pre: " 
        << getLinkListMidPreNode(list->head)->data << ",";
    std::cout << testGetLinkListMidNode(list->head, 0)->data 
        << std::endl;

    if(testGetLinkListMidNode(list->head, 0) 
    != getLinkListMidPreNode(list->head)) {
        std::cout << "test failed.\n" << std::endl;
        return -1;
    }

    std::cout << "Mid&Pre: " 
        << getLinkListMidNode1(list->head)->data << ",";
    std::cout << testGetLinkListMidNode(list->head, 1)->data 
        << std::endl;
    if(getLinkListMidNode1(list->head) 
    != testGetLinkListMidNode(list->head,1)) {
        std::cout << "test failed.\n" << std::endl;
        return -1;
    }

    std::cout << "Mid&After: " 
        << getLinkListMidNode2(list->head)->data << ",";
    std::cout << testGetLinkListMidNode(list->head, 2)->data 
        << std::endl;
    if(getLinkListMidNode2(list->head) 
    != testGetLinkListMidNode(list->head,2)) {
        std::cout << "test failed.\n" << std::endl;
        return -1;
    }
    
    std::cout << "After " 
        << getLinkListMidAfterNode(list->head)->data << ",";
    std::cout << testGetLinkListMidNode(list->head, 3)->data 
        << std::endl;
    if(getLinkListMidAfterNode(list->head) 
    != testGetLinkListMidNode(list->head,3)) {
        std::cout << "test failed.\n" << std::endl;
        return -1;
    }
    return 0;
}


void invertSingleListTest(int arry[], int length)
{
    SingleList_t*   maxQueue = createSingleList(arry, length);
    NoHeadSingleList_t* noHeadmaxQueue = createNoheadSingleList(arry, length);
    if (!maxQueue) {
        fprintf(stderr, "create link list failed.\n");
        return;
    }

    showEachNodeOfSingleList(maxQueue);
    showEachNodeOfSingleList(noHeadmaxQueue);
    
    singleListInvert(maxQueue);
    singleListInvert(noHeadmaxQueue);

    showEachNodeOfSingleList(maxQueue);
    showEachNodeOfSingleList(noHeadmaxQueue);
}


int testEchoLinkList(int arry[], int length)
{
    NoHeadSingleList_t* list = createNoheadSingleList(arry, length);
    showEachNodeOfSingleList(list);
    std::cout << isEchoLinkList(list->head) << std::endl;
    showEachNodeOfSingleList(list);
    return 0;
}