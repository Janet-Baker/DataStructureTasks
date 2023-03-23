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

typedef struct {
    int *base;
    int *top;
    int stacksize;
} Stack;

Status InitStack(Stack &s) {
    s.base = (int *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!s.base) exit(OVERFLOW);
    s.stacksize = STACK_INIT_SIZE;
    s.top = s.base;
    return OK;
}//InitStack

Status Push(Stack &s, char x) {
//这里写入入栈代码，入栈成功返回OK，失败返回ERROR；
    if (s.top - s.base >= s.stacksize) {
        s.base = (int *) realloc(s.base, (s.stacksize + STACK_INIT_SIZE) * sizeof(int));
        if (!s.base) exit(OVERFLOW);
        s.top = s.base + s.stacksize;
        s.stacksize += STACK_INIT_SIZE;
    }
    *s.top++ = x;
    return OK;
}//push

Status Pop(Stack &s, char &x) {
//这里写入出栈代码，出栈成功返回OK，失败返回ERROR
    if (s.top == s.base) return ERROR;
    x = *(--s.top);
    return OK;
}//pop


int Judge(Stack &a, char *s) {
    //这里写入代码，判断回文，若是回文返回OK，若不是回文，返回ERROR；
    int i, len = strlen(s), halfm, halfl;
    if (len == 1) return OK;
    halfm = len / 2;
    if (len % 2 == 0) halfl = halfm;
    else halfl = len / 2 + 1;
    for (i = 0; i < halfm; i++) {
        Push(a, s[i]);
    }
    for (i = halfl; i < len; i++) {
        char x;
        Pop(a, x);
        if (s[i] != x) return ERROR;
    }
    return OK;
}//Judge

int main() {
    char s[65530];
    Stack S;
    InitStack(S);

    //printf("Please Input the s:");
    scanf("%s", s);

    printf("\n");

    if (Judge(S, s) == OK)
        printf("Yes!\n");
    else
        printf("No!\n");
    return 1;
}
