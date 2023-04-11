# 稀疏矩阵相加

## 【问题描述】

若将稀疏矩阵A的非零元以行序为主存储在一维数组data中，并用二维数组bitmap表示A中的相应元素是否为零元素，

    例如：A = {（15,0,0,22）（0,-6,0,0）（91,0,0,0）} 

    可用   data = （15,22,-6,91）和 bitmap = {（1,0,0,1）（0,1,0,0）（1,0,0,0）}表示。

试写一算法，实现矩阵相加的运算，分析时间复杂度。

---

分析：两矩阵A和B相加的结果是一矩阵C，其元素Cij有三种情况；
```
（1）Cij=Aij（Bij =0）；（2）Cij=Bij（Aij =0）；（3）Cij=Aij+Bij 。
```
在情况（3）下，要看结果是否为0，C矩阵只有非零元素


## 【输入形式】

无，在main()函数自动为矩阵A、B赋值

## 【输出形式】

输出相加后的矩阵C

## 【样例输入】

main()函数自动完成输入，
```
矩阵A：
{
{0,1,0,3,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,-3,5}
};

矩阵B：
{
{0,-1,2,3,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,3,10}
};
```
## 【样例输出】
```
(1,3,2)(1,4,6)(4,5,15)
```
## 【样例说明】

main函数自动输出矩阵C的非零元，（行，列，值）。

## 代码模板

```c++
//要求：若将稀疏矩阵A的非零元以行序为主存储在一维数组V中，并用二维数组B表示A中的相应元素是否为零元素，
//      例如：A= {（15,0,0,22）（0,-6,0,0）（91,0,0,0）} 可用
//      V = （15,22,-6,91）和 B = {（1,0,0,1）（0,1,0,0）（1,0,0,0）}表示。
//      试写一算法，实现矩阵相加的运算，分析时间复杂度。

//分析：两矩阵A和B相加的结果是一矩阵C，其元素Cij有三种情况；
//（1）Cij=Aij（Bij =0）；（2）Cij=Bij（Aij =0）；（3）Cij=Aij+Bij 。
//在（3）种情况下，要看结果是否为0，C矩阵只有非零元素

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
#define MAXSIZE 100

typedef struct { 
	int data[MAXSIZE+1]; 
	int bitmap[MAXSIZE+1][MAXSIZE+1];		//位图表示相应位是否为非零元
	int mu,nu;
} TSMatrix;

void TSMatrixAdd(TSMatrix A, TSMatrix B, TSMatrix &C)
{ 
//这里输入你的代码






  

}//TSMatrixAdd 

int main()
{ 
/*
  int a[4][5] = {	                {0,1,0,3,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,-3,5} };
  int b[4][5] = {	                {0,-1,2,3,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,3,10} };
 */
  int i,j,k = 1;
  TSMatrix A,B,C;
  A.mu = 4; A.nu = 5;
  B.mu = 4; B.nu = 5;
  //矩阵A赋值
  for (i = 1; i <= A.mu; i++)
	  for (j = 1; j <= A.nu; j++)
		  A.bitmap[i][j] = 0;
  A.data[1] = 1;  A.data[2] = 3;  A.data[3] = -3;  A.data[4] = 5;
  A.bitmap[1][2] = 1;A.bitmap[1][4] = 1;A.bitmap[4][4] = 1;A.bitmap[4][5] = 1;

  //矩阵B赋值
   for (i = 1; i <= B.mu; i++)
	  for (j = 1; j <= B.nu; j++)
		  B.bitmap[i][j] = 0;
  B.data[1] = -1;  B.data[2] = 2;  B.data[3] = 3;  B.data[4] = 3;  B.data[5] = 10;
  B.bitmap[1][2] = 1;B.bitmap[1][3] = 1;B.bitmap[1][4] = 1;B.bitmap[4][4] = 1;B.bitmap[4][5] = 1;

  TSMatrixAdd(A,B,C);
  
  //输出矩阵C
  for (i = 1; i <= C.mu; i++)
	  for (j = 1; j <= C.nu; j++)
		if (C.bitmap[i][j]) printf("(%d,%d,%d)",i,j,C.data[k++]);
  printf("\n");
  return 1; 
}

//(1,3,2)(1,4,6)(4,5,15)

```
