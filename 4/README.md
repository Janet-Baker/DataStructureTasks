# 二叉树操作

## 【问题描述】

系统创建二叉树，需要你补充循环队列的入队和出队操作，并设计算法：

（1）用非递归算法输出二叉树的先序序列

（2）用非递归算法输出二叉树的中序序列

（3）用非递归算法输出二叉树的后序序列

（4）输出二叉树的全部结点个数

（5）输出二叉树的叶子结点个数

（6）输出二叉树的深度

（7）判断二叉树是否为完全二叉树

### 【样例输入1】

```
ABD##EG###C#F##
```

### 【样例输出1】

```
先序序列：ABDEGCF

中序序列：DBGEACF

后序序列：DGEBFCA

树的全部结点个数：7

叶子结点个数：3

二叉树的深度：4

二叉树是否为完全二叉树：否
```

### 【样例输入2】

```
ABD##E##CF##G##
```

### 【样例输出2】

```
先序序列：ABDECFG

中序序列：DBEAFCG

后序序列：DEBFGCA

树的全部结点个数：7

叶子结点个数：4

二叉树的深度：3

二叉树是否为完全二叉树：是
```

### 【样例输入3】

`#`

### 【样例输出3】

```
先序序列：

中序序列：

后序序列：

树的全部结点个数：0

叶子结点个数：0

二叉树的深度：0

二叉树是否为完全二叉树：是
```

## 【代码模板】

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define STACK_INIT_SIZE 100
typedef int Status;
typedef struct BiTNode{
	char	data;
	struct  BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

typedef struct SNode{
	BiTree ptr;
	int tag;
} StackNode;	//tag为后序遍历时的标志，先序和中序无用

typedef struct {
	StackNode *base;
	StackNode *top;	
    int stacksize;
}Stack;

Status InitStack(Stack &s)
{
	s.base = (StackNode *)malloc(STACK_INIT_SIZE * sizeof(StackNode));
	if(!s.base) exit(OVERFLOW);
	s.stacksize = STACK_INIT_SIZE;
	s.top = s.base;
	return OK;
}//InitStack

Status Push(Stack &s, StackNode p)
{
    if(s.top - s.base  >= s.stacksize ) return OVERFLOW;
    *s.top++ = p;
    return OK;
}//push

Status Pop(Stack &s, StackNode &p)
{
	 if(s.top == s.base ) return ERROR;
	 p = *(--s.top); 
	 return OK;    
}//pop

Status GetTop(Stack &s, StackNode &p)
{
	 if(s.top == s.base ) return ERROR;
	 p = *(s.top - 1); 
	 return OK;    
}//pop

Status StackEmpty(Stack s)
{	if(s.top == s.base ) return TRUE;
	else return FALSE;
}

//输入先序序列，创建二叉树
void CreateBiTree(BiTree &T)
{	char ch;
	scanf("%c",&ch);
	if (ch == '#') T = NULL;
	else
	{	T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//先序遍历二叉树的非递归算法
void PreOrderTraverse(BiTree T)
{   Stack S;
	BiTree p = T;
	StackNode s;

	InitStack(S);
        //这里插入你的代码







}

/* 中序遍历二叉树的非递归算法 */
void InOrderTraverse(BiTree T)
{       Stack S;
	BiTree p = T;
	StackNode s;

	InitStack(S);
        //这里插入你的代码







}

// 后序遍历二叉树的非递归算法 
// tag = 0 表示其左子树已被遍历
// tag = 1 表示其右子树已被遍历
void PostOrderTraverse(BiTree T)
{       Stack S;
	BiTree p = T;
	StackNode s;

	InitStack(S);
        //这里插入你的代码







}

int LeftCount(BiTree T)
{
//这里插入你的代码







}

int NodeCount(BiTree T)
{
//这里插入你的代码







}

int Depth (BiTree T )
{  
//这里插入你的代码







}

#define MAXQSIZE 100
typedef struct {
	BiTree *base;
	int front,rear;} SqQueue; //定义循环队列

void InitQueue(SqQueue &Q)
{	Q.base = (BiTree *)malloc(MAXQSIZE * sizeof(BiTree));
	Q.front = Q.rear = 0;
}

Status EnQueue(SqQueue &Q, BiTree e)
{	if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;	//队满
       //这里插入你的代码







	return OK;
}

Status DeQueue(SqQueue &Q, BiTree &e)
{	if(Q.rear == Q.front) return ERROR;	//队空
       //这里插入你的代码







	return OK;
}

Status QueueEmpty(SqQueue Q)
{	if(Q.rear == Q.front) return TRUE;
	else	return FALSE;
}

//利用层次遍历的算法，遍历过程中结点的孩子无论是否为空均入队，
//如果为完全二叉树，则遍历过程中，元素一定连续，否则中间会插入空指针
//若为完全二叉树，返回1，否则返回0
int LevelOrderTraverse(BiTree T)
{	
//这里插入你的代码







}

int main()
{	BiTree T;
	CreateBiTree(T);
	printf("先序序列：");
	PreOrderTraverse(T);
	
	printf("\n中序序列：");
	InOrderTraverse(T);

	printf("\n后序序列：");
	PostOrderTraverse(T);
	printf("\n");

	printf("\n树的全部结点个数：%d",NodeCount(T));
	
	printf("\n叶子结点个数：%d",LeftCount(T));
        
        printf("\n二叉树的深度：%d",Depth(T));

	printf("\n二叉树是否为完全二叉树：%s",(LevelOrderTraverse(T) == 1) ? "是" : "否");
        
        return 1;
}
```
