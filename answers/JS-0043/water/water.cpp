#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

#define submit

using std::cin;
using std::cout;
using std::endl;

template <class T>
T gcd(T x, T y)
{
    return y ? gcd(y, x % y) : x;
}

template <class T>
void read(T& x)
{
    x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); x = x * 10 + (c ^ 48), c = getchar());
}

struct Edge
{
    int v, nxt;
    Edge(int v = 0, int nxt = 0): v(v), nxt(nxt) { }
};

int n, m, cntOut, cntEdge;
int inDeg[500020], outDeg[500020], out[500020], head[500020];
Edge edge[500020];

struct Number
{
    long long p, q; // p / q
    Number(long long p = 0, long long q = 1): p(p), q(q) { }
    
    const Number operator+(const Number ano) const
    {
        long long fm = q * ano.q, fz = p * ano.q + q * ano.p, d = gcd(fm, fz);
        fm /= d; fz /= d;
        return Number(fz, fm);
    }
    
    Number cut(long long x)
    {
        q *= x;
        long long d = gcd(p, q);
        p /= d; q /= d;
        return Number(p, q);
    }
    
    void print()
    {
        printf("%lld %lld\n", p, q);
    }
};
Number num[500020];

void addEdge(int u, int v)
{
    edge[++cntEdge] = Edge(v, head[u]); head[u] = cntEdge; ++inDeg[v];
}

void dfs(int x)
{
    if (outDeg[x] == 0)
        return;
    Number add = num[x].cut(outDeg[x]);
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int y = edge[i].v;
        num[y] = num[y] + add;
        dfs(y);
    }
    num[x] = Number(0, 1);
}

int main()
{
#ifdef submit
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
#endif
    read(n); read(m);
    for (int i = 1; i <= n; ++i)
    {
        read(outDeg[i]);
        if (outDeg[i] == 0)
        {
            out[++cntOut] = i;
        }
        else
        {
            for (int j = 1; j <= outDeg[i]; ++j)
            {
                int x = 0;
                read(x);
                addEdge(i, x);
            }
        }
    }

//    for (int i = 1; i <= n; ++i)
//    {
//        cout << i << " " << inDeg[i] << " " << outDeg[i] << endl;
//    }

    for (int i = 1; i <= n; ++i)
    {
        if (inDeg[i])
            continue;
        num[i] = Number(1, 1);
        dfs(i);
//        cout << "Water flows from " << i << endl;
//        for (int j = 1; j <= n; ++j)
//            cout << j << " ", num[j].print();
//        cout << endl;
    }
    for (int i = 1; i <= cntOut; ++i)
    {
        num[out[i]].print();
    }
    return 0;
}

