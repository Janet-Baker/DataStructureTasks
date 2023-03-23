/*  逆位序（头插法）创建单链表，遍历单链表，原地逆置单链表，删除指定元素  */
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>
#include  <stddef.h>
#define  TRUE  1
#define  FALSE  0
#define  OK  1
#define  ERROR  0
#define  INFEASIBLE  -1
#define  OVERFLOW  -2
#define  LIST_INIT_SIZE  100
#define  STACK_INIT_SIZE  100
typedef  int  Status;


/*  链表结点定义  */
typedef  struct  LNode{
        int  data;
        struct  LNode  *next;
}LNode,  *LinkList;

/*  逆位序创建单链表  */
void  CreateList(LinkList  &L,  int  n)
{
    LinkList p;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

//遍历单链表
void  Display(LinkList  L)
{
    LinkList p = L->next;
    while (p != NULL) {
        if (p->next != NULL) {
            printf("%d ", p->data);
        } else {
            printf("%d", p->data);
        }
        p = p->next;
    }
}//Traverse

/*  单链表原地逆置  */
void  Reverse(LinkList  L)
{
    LinkList p, q;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
}//Reverse

/*单链表删除指定元素  */
void  DeleteElem(LinkList  L,int  e)
{
    LinkList p, q;
    p = L;
    while (p->next != NULL) {
        if (p->next->data == e) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else
            p = p->next;
    }
}//DeleteElem


Status  main()
{
        LinkList  L;
        int  n,e;

                scanf("%d",&n);

                CreateList(L,  n);//创建单链表
                Display(L);                //遍历单链表

                Reverse(L);            //逆置
                printf("\n");
                Display(L);              //遍历

                scanf("%d",&e);  //读入待删除元素
                DeleteElem(L,e);
                printf("\n");
                Display(L);

        return  OK;
}
