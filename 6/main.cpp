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
