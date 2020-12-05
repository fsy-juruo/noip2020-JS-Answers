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
void read(T& x)
{
    x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); x = x * 10 + (c ^ 48), c = getchar());
}

int n, m;
int sta[52][410];
std::stack <int> st[52];

int main()
{
#ifdef submit
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
#endif
    read(n); read(m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x = 0;
            read(x);
            ++sta[i][x];
            st[i].push(x);
        }
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        
    }
    else
    {
        
    }
    return 0;
}

