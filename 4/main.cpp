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

// 二叉树的二叉链表结点结构定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 栈的结点
typedef struct SNode {
    BiTree ptr;
    //tag为后序遍历时的标志，先序和中序无用
    int tag = 0;
} StackNode;

// 栈的属性（头尾、长度）定义
typedef struct {
    StackNode *base;
    StackNode *top;
    int stacksize;
} Stack;

// InitStack 初始化栈
Status InitStack(Stack &s) {
    s.base = (StackNode *) malloc(STACK_INIT_SIZE * sizeof(StackNode));
    if (!s.base) exit(OVERFLOW);
    s.stacksize = STACK_INIT_SIZE;
    s.top = s.base;
    return OK;
}//InitStack

// Push 入栈
Status Push(Stack &s, StackNode p) {
    if (s.top - s.base >= s.stacksize) return OVERFLOW;
    *s.top++ = p;
    return OK;
}//push

// Pop 出栈
Status Pop(Stack &s, StackNode &p) {
    if (s.top == s.base) return ERROR;
    p = *(--s.top);
    return OK;
}//pop

// GetTop 取栈顶元素
Status GetTop(Stack &s, StackNode &p) {
    if (s.top == s.base) return ERROR;
    p = *(s.top - 1);
    return OK;
}//pop

// StackEmpty 判断栈是否为空
Status StackEmpty(Stack s) {
    if (s.top == s.base) return TRUE;
    else return FALSE;
}

// 输入先序序列，创建二叉树
// 二叉树以链式存储
void CreateBiTree(BiTree &T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        T = NULL;
    } else {
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//先序遍历二叉树的非递归算法
void PreOrderTraverse(BiTree T) {
    Stack S;
    BiTree p = T;
    StackNode s;
    InitStack(S);
    //这里插入你的代码
    while (p || !StackEmpty(S)) {
        if (p) {
            printf("%c", p->data);
            s.ptr = p;
            Push(S, s);
            p = p->lchild;
        } else {
            Pop(S, s);
            p = s.ptr;
            p = p->rchild;
        }
    }
    free(S.base);
}

// 中序遍历二叉树的非递归算法
void InOrderTraverse(BiTree T) {
    Stack S;
    BiTree p = T;
    StackNode s;
    InitStack(S);
    //这里插入你的代码
    while (p || !StackEmpty(S)) {
        if (p) {
            s.ptr = p;
            Push(S, s);
            p = p->lchild;
        } else {
            Pop(S, s);
            p = s.ptr;
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    free(S.base);
}

/* 后序遍历二叉树的非递归算法
 tag = 0 表示其左子树已被遍历
 tag = 1 表示其右子树已被遍历 */
void PostOrderTraverse(BiTree T) {
    Stack S;
    BiTree p = T;
    StackNode s;

    InitStack(S);
    //这里插入你的代码
    while (p || !StackEmpty(S)) {
        if (p) {
            s.ptr = p;
            s.tag = 0;
            Push(S, s);
            p = p->lchild;
        } else {
            GetTop(S, s);
            if (s.tag == 0) {
                Pop(S, s);
                s.tag = 1;
                Push(S, s);
                p = s.ptr->rchild;
            } else {
                Pop(S, s);
                p = s.ptr;
                printf("%c", p->data);
                p = NULL;
            }
        }
    }
    free(S.base);
}

// 叶子结点个数
int LeftCount(BiTree T) {
//这里插入你的代码
    int count = 0;
    BiTree p = T;
    StackNode s;
    Stack S;
    InitStack(S);
    while (p || !StackEmpty(S)) {
        if (p) {
            s.ptr = p;
            Push(S, s);
            p = p->lchild;
        } else {
            Pop(S, s);
            p = s.ptr;
            if (p->lchild == NULL && p->rchild == NULL) {
                count++;
            }
            p = p->rchild;
        }
    }
    free(S.base);
    return count;
}

// 树的全部结点个数
int NodeCount(BiTree T) {
//这里插入你的代码
    int count = 0;
    BiTree p = T;
    StackNode s;
    Stack S;
    InitStack(S);
    while (p || !StackEmpty(S)) {
        if (p) {
            count++;
            s.ptr = p;
            Push(S, s);
            p = p->lchild;
        } else {
            Pop(S, s);
            p = s.ptr;
            p = p->rchild;
        }
    }
    free(S.base);
    return count;
}

// 二叉树的深度
int Depth(BiTree T) {
//这里插入你的代码
    int depth = 0;
    int maxdepth = 0;
    Stack S;
    BiTree p = T;
    StackNode s;
    InitStack(S);
    while (p || !StackEmpty(S)) {
        if (p) {
            depth++;
            s.ptr = p;
            s.tag = 0;
            Push(S, s);
            p = p->lchild;
        } else {
            GetTop(S, s);
            if (s.tag == 0) {
                Pop(S, s);
                s.tag = 1;
                Push(S, s);
                p = s.ptr->rchild;
            } else {
                depth--;
                Pop(S, s);
                p = s.ptr;
                p = NULL;
            }
        }
        if (depth > maxdepth) {
            maxdepth = depth;
        }
    }
    free(S.base);
    return maxdepth;
}

#define MAXQSIZE 100
typedef struct {
    BiTree *base;
    int front, rear;
} SqQueue; //定义循环队列

void InitQueue(SqQueue &Q) {
    Q.base = (BiTree *) malloc(MAXQSIZE * sizeof(BiTree));
    if (!Q.base) {
        exit(OVERFLOW);
    } else {
        Q.front = Q.rear = 0;
    }
}

// 加入队列
Status EnQueue(SqQueue &Q, BiTree e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;    //队满
    //这里插入你的代码
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

// 出队
Status DeQueue(SqQueue &Q, BiTree &e) {
    if (Q.rear == Q.front) return ERROR;    //队空
    //这里插入你的代码
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front) return TRUE;
    else return FALSE;
}

/*利用层次遍历的算法，遍历过程中结点的孩子无论是否为空均入队，
  如果为完全二叉树，则遍历过程中，元素一定连续，否则中间会插入空指针
  若为完全二叉树，返回1，否则返回0 */
int LevelOrderTraverse(BiTree T) {
//这里插入你的代码
    SqQueue Q;
    InitQueue(Q);
    BiTree p = T;
    if (p == NULL) {
        return 1;
    }
    EnQueue(Q, p);
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        if (p != NULL) {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        } else {
            while (!QueueEmpty(Q)) {
                DeQueue(Q, p);
                if (p != NULL) {
                    return 0;
                }
            }
        }
    }
    free(Q.base);
    return 1;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("先序序列：");
    PreOrderTraverse(T);

    printf("\n中序序列：");
    InOrderTraverse(T);

    printf("\n后序序列：");
    PostOrderTraverse(T);
    printf("\n");

    printf("\n树的全部结点个数：%d", NodeCount(T));

    printf("\n叶子结点个数：%d", LeftCount(T));

    printf("\n二叉树的深度：%d", Depth(T));

    printf("\n二叉树是否为完全二叉树：%s", (LevelOrderTraverse(T) == 1) ? "是" : "否");

    return 1;
}
