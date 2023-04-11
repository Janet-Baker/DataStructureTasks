# 判断回文
## 【问题描述】

假设正读和反读都相同的序列为回文，例如"abba"和"abcba"是回文，而"abcde"则不是。

判断以@为结束符的序列是否为回文

## 【输入形式】

字符串

## 【输出形式】

是回文输出Yes！不是回文输出No！

### 【样例输入1】
```
abcba
```
### 【样例输出1】
```
Yes!
```
### 【样例输入2】
```
a
```
### 【样例输出2】
```
Yes!
```
### 【样例输入3】
```
abc
```
### 【样例输出3】
```
No!
```
### 【样例输入4】
```
abccba
```
### 【样例输出4】
```
Yes!
```
## 代码模板

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







}//push

Status Pop(Stack &s, char &x) {
//这里写入出栈代码，出栈成功返回OK，失败返回ERROR



}//pop


int Judge(Stack &a, char *s) {
    //这里写入代码，判断回文，若是回文返回OK，若不是回文，返回ERROR；





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

```
