# 统计结果排序

## 【问题描述】

现在统计出来一个文件中字符的字频，已经将统计结果存放在一个数组中，并且数组中的统计结果已经按照字母序排好序。

请将数组中的统计结果，按照字频排序，要求相同字频下的字母序不能被打乱。


## 【输入形式】

一个数组

注：数组中存放的是一个结构体
```c++
typedef struct{

    KeyType character;

    int count;

}
```
## 【输出形式】

有序的数组

## 【样例输入】
```
a4 b4 c4 d4 e3 f73 g73 r1 q1 z53
```
## 【样例输出】
```
f73 g73 z53 a4 b4 c4 d4 e3 r1 q1
```
## 【样例说明】

a4：字符a出现了4次

f73：字符f出现了73次



经过排序后，在相同字频下，字母的顺序没有被打乱



## 【评分标准】

实现函数sort

## 代码模板

请补全`merge`和`Sort`函数

```cpp
#include<iostream>

using  namespace  std;
#define  MaxSize  20
typedef  char  KeyType;

typedef  struct  {
//字母
KeyType  character;
//字频
int  count;

}  RedType;

void  merge(RedType  SR[],  RedType  TR[],  int  i,  int  m,  int  n)  {

}

void  Sort(RedType  SR[],  RedType  TR1[],  int  s,  int  t)  {

}

int  main()  {
//统计结果，已经按字母序排好序
RedType  SR[MaxSize];
//按照字频排序后的结果
RedType  TR1[MaxSize];

        string  data;
        int  i  =  0;

        //读取输入
        while  (i  <  MaxSize  &&  cin  >>  data)  {
                SR[i].character  =  data[0];
                SR[i++].count  =  stoi(data.substr(1,  data.length()));

                if  (cin.get()  ==  '\n')  {
                        break;
                }
        }

        //排序
        Sort(SR,  TR1,  0,  i  -  1);

        //打印排序后的结果
        for  (int  j  =  0;  j  <  i;  ++j)  {
                cout  <<  TR1[j].character  <<  TR1[j].count  <<  "  ";
        }
}
```

## 由 Bing AI 提供的答案

你可以使用快速排序算法来对一个数组按照字频排序。具体来说，你可以使用一个结构体数组，其中每个结构体包含一个字符和它出现的次数。然后，你可以使用快速排序算法对这个结构体数组进行排序，以便按照字频从高到低的顺序排列。如果有多个字符具有相同的字频，则你可以按照字母序将它们排序。这里是一个C++的代码模板，其中包含了merge和Sort函数的实现。¹

```c++
#include <iostream>

using namespace std;
#define MaxSize 20
typedef char KeyType;

typedef struct {
 //字母
 KeyType character;
 //字频
 int count;
} RedType;

void merge(RedType SR[], RedType TR[], int i, int m, int n) {
    int j = m + 1; //第二个有序区间的起始位置
    int k = i; //TR中当前记录的位置

    while (i <= m && j <= n) {
        if (SR[i].count > SR[j].count || (SR[i].count == SR[j].count && SR[i].character < SR[j].character)) {
            TR[k++] = SR[i++];
        } else {
            TR[k++] = SR[j++];
        }
    }

    while (i <= m) {
        TR[k++] = SR[i++];
    }

    while (j <= n) {
        TR[k++] = SR[j++];
    }
}

void Sort(RedType SR[], RedType TR1[], int s, int t) {
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        RedType TR2[MaxSize];
        int m = (s + t) / 2;
        Sort(SR, TR2, s, m);
        Sort(SR, TR2, m + 1, t);
        merge(TR2, TR1, s, m, t);
    }
}

int main() {
 //统计结果，已经按字母序排好序
 RedType SR[MaxSize];
 //按照字频排序后的结果
 RedType TR1[MaxSize];

 string data;
 int i = 0;

 //读取输入
 while (i < MaxSize && cin >> data) {
 SR[i].character = data[0];
 SR[i++].count = stoi(data.substr(1, data.length()));

 if (cin.get() == '\n') {
 break;
 }
 }

 //排序
 Sort(SR, TR1, 0, i - 1);

 //打印排序后的结果
 for (int j = 0; j < i; ++j) {
 cout << TR1[j].character << TR1[j].count << " ";
 }
}
```
希望这可以帮到你！如果你有任何其他问题，请随时问我。

源: 与必应的对话， 2023/5/23
(1) python词频统计并按词频排序 - CSDN博客. https://blog.csdn.net/m0_51566872/article/details/121192614.
(2) Array.prototype.sort() - JavaScript | MDN - MDN Web Docs. https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/sort.
(3) JavaScript 数组排序 - w3school 在线教程. https://www.w3school.com.cn/js/js_array_sort.asp.
(4) Java中Arrays.sort()的三种常用用法（自定义排序规则）_arrays.sort定义排序规则_请叫我算术嘉的博客-CSDN博客. https://blog.csdn.net/ssjdoudou/article/details/107886461.