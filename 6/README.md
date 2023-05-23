# 安排课程表

## Description

学生需要修读完所有的课程才能毕业，这些课程之间有先导关系（比如要修读数据结构，必须先修读程序设计思想方法）。假设任意一门课程可以在任何一个学期给满足条件的学生选修，且学生每个学期可以选修的课程数不限。先给出一些课程与课程之间的关系，求能够修完所有课程的最少学期数。

为简化题目，约定：假设有n门课程，则这n门课程的编号分别为：1,2，……n。

数据保证不会出现环和自环（即总是可以合法地修完所有的课程，不会出现类似“1->1”或是“1->2->3->1”的情况）

（提示：如果你没有很好的思路，请仔细看P360开始的“拓扑排序”部分内容。）

## Input Format

第1行：`n m` //正整数n ，代表课程的数量。非负整数m代表要给出几个先导关系。

第2行到第1+m行: `a b` //每行两个整数：代表要选修编号为a的课程，必须先修读编号为b的课程。

## Output Format

一个整数，即修完所有课程的最少学期数。

## Sample Input1

```
5 4
1 2
2 3
3 4
4 5
```

## Sample Output1

```
5
```

## Sample Input2

```
6 0
```

## Sample Output2

```
1
```

## Sample Input3

```
6 3
1 2
1 3
4 1
```

## Sample Output3

```
3
```

## Limits

0<n<=10000 0<=m<=100000

数据保证合法

## 代码模板

> 没有提供代码模板。
 
## BING AI 提供的答案

你好，这道题目是一道典型的拓扑排序问题。拓扑排序是根据有向图中的偏序关系，对图中的节点进行排序。对于这道题目而言，排课老师的任务是：根据课程之间的先修关系，每个学期合理安排课程，保证每门课的先修课都必须安排在这门课的前面。¹²

这道题目可以使用拓扑排序算法来解决。具体来说，我们可以使用一个队列来存储所有入度为0的节点，然后每次从队列中取出一个节点，并将其所有的后继节点的入度减1。如果某个后继节点的入度变为0，则将其加入到队列中。当队列为空时，如果图中还有节点的入度不为0，则说明图中存在环，即无法完成拓扑排序；否则，所有节点都已经被访问过了，且没有环，即可以完成拓扑排序。²³

你可以参考以下代码实现：

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    d[b] ++ ;
}

int topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q.push(i);

    int res = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        res ++ ;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0) q.push(j);
        }
    }

    return res;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
    }

    printf("%d\n", topsort());

    return 0;
}
```

希望能够帮到你！如果你还有其他问题，请随时问我哦！😊

源: 与必应的对话， 2023/5/23
(1) 基础-7：拓扑排序 - 简书. https://www.jianshu.com/p/0b92b442dca7.
(2) 图文详解面试常考算法 —— 拓扑排序 - 知乎 - 知乎专栏. https://zhuanlan.zhihu.com/p/135094687.
(3) Leetcode --- 课程表问题（拓扑排序） - 简书. https://www.jianshu.com/p/0c8241d2a005.
(4) LeetCode 207 课程表（拓扑排序） - 知乎 - 知乎专栏. https://zhuanlan.zhihu.com/p/408887993.