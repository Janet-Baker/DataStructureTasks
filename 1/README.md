# 单链表基本操作的实现 / 程序片段编程题 / 1. 单链表基本算法实现
## 【问题描述】

实现逆位序（头插法）创建单链表，遍历单链表，原地逆置单链表，删除指定元素共4个基本操作

## 【输入形式】

结点个数，结点序列，要删除的值

## 【输出形式】

创建后的单链表

逆置之后的单链表

删除指定元素之后的单链表

### 【样例输入1】
```
5 50 40 30 20 10 30
```
### 【样例输出1】
```
10 20 30 40 50

50 40 30 20 10

50 40 20 10
```
### 【样例说明1】
```
输入行的第一个5是元素个数，接着的50 40 30 20 10是5个元素的值，最后一个30是要删除结点的值

输出的第一行是创建后的单链表

输出的第二行是逆置后的单链表

输出的第三行是删除30之后的单链表（在逆置之后的基础上）
```


### 【样例输入2】
```
3 1 2 3 8
```
### 【样例输出2】
```
3 2 1

1 2 3

1 2 3
```
### 【样例说明2】
输入行的第一个3是元素个数，接着的1 2 3是3个元素的值，最后一个8是要删除结点的值

输出的第一行是创建后的单链表

输出的第二行是逆置后的单链表

输出的第三行是删除8之后的单链表（在逆置之后的基础上），但因为8不存在，实际上没有删除操作



### 【样例输入3】
```
1 5 5
```
### 【样例输出3】
```
5

5
```
### 【样例说明3】

输入行的第一个1是元素个数，接着的5是1个元素的值，最后一个5是要删除结点的值

输出的第一行是创建后的单链表

输出的第二行是逆置后的单链表

输出的第三行是删除5之后的单链表（在逆置之后的基础上），因为只有一个元素，且被删除，所以第3行为空



### 【样例输入4】
```
0 0
```
### 【样例输出4】
```

```
### 【样例说明4】

输入行的第一个0是元素个数，最后一个0是要删除结点的值

输出的第一行是创建后的单链表（空）

输出的第二行是逆置后的单链表（空）

输出的第三行是删除0之后的单链表（空）



整个程序逻辑，请阅读源代码更好理解。


```
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

}

//遍历单链表
void  Display(LinkList  L)
{

}//Traverse

/*  单链表原地逆置  */
void  Reverse(LinkList  L)
{

}//Reverse

/*单链表删除指定元素  */
void  DeleteElem(LinkList  L,int  e)
{

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
```