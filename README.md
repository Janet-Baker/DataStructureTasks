# 大连理工大学 《数据结构》课程作业

1. 单链表基本操作的实现
2. 判断回文
3. 稀疏矩阵相加
4. 二叉树操作
5. 在有向图的邻接表存储结构上实现：输出某顶点出发的所有长度等于k的简单路径
6. 安排课程表
7. 统计结果排序

---

1. 单链表基本操作的实现

实现逆位序（头插法）创建单链表，遍历单链表，原地逆置单链表，删除指定元素共4个基本操作

2. 判断回文

假设正读和反读都相同的序列为回文，例如"abba"和"abcba"是回文，而"abcde"则不是。
判断以@为结束符的序列是否为回文

3. 稀疏矩阵相加

若将稀疏矩阵A的非零元以行序为主存储在一维数组data中，并用二维数组bitmap表示A中的相应元素是否为零元素。
试写一算法，实现矩阵相加的运算，分析时间复杂度。

4. 二叉树操作

练习循环队列、堆栈及二叉树的各种基本操作

系统创建二叉树，需要你补充循环队列的入队和出队操作，并设计算法：

>1. 用非递归算法输出二叉树的先序序列
>2. 用非递归算法输出二叉树的中序序列
>3. 用非递归算法输出二叉树的后序序列
>4. 输出二叉树的全部结点个数
>5. 输出二叉树的叶子结点个数
>6. 输出二叉树的深度
>7. 判断二叉树是否为完全二叉树

5. 在有向图的邻接表存储结构上实现：输出某顶点出发的所有长度等于k的简单路径

使用深度优先遍历的思想，利用邻接表存储结构，对给定的有向图，找出从指定结点v出发，长度为k的所有简单路径（包括简单回路）的数量。

6. 安排课程表

给出一些课程与课程之间的关系，求能够修完所有课程的最少学期数。

7. 统计结果排序

现在统计出来一个文件中字符的字频，已经将统计结果存放在一个数组中，并且数组中的统计结果已经按照字母序排好序。
请将数组中的统计结果，按照字频排序，要求相同字频下的字母序不能被打乱。
