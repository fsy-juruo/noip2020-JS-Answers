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

long long mod = 1e9 + 7;

using std::cin;
using std::cout;
using std::endl;

template <class T>
void read(T& x)
{
    T flag = x = 0;
    char c = getchar();
    for (; !isdigit(c); flag |= c == '-', c = getchar());
    for (; isdigit(c); x = x * 10 + (c ^ 48), c = getchar());
    flag ? x = -x : x;
}

template <class T>
T min(T x, T y)
{
    return x < y ? x : y;
}

struct Data
{
    int t, id; // 第 d 维, t = ±1, 是某天的第 id 个操作 
    
    Data(int t = 0, int id = 0): t(t), id(id) { }
};

int n, k, damn;
int w[20], c[1000010], d[1000010];
long long f[12][1000010];
long long ans;
std::vector <Data> op[12];

namespace bruteforce
{
    int g[12]; // 第 i 维的初值 
    
    void check()
    {
        long long r = 1ll << 62;
        for (int i = 1; i <= k; ++i)
        {
            r = min(r, f[i][g[i]]);
        }
        if (r == 1ll << 62)
        {
            damn = 1;
        }
        else
        {
            (ans += r) %= mod;
        }
    }
    
    void dfs(int x)
    {
        if (x > k)
        {
            check();
            return;
        }
        for (int i = 1; i <= w[x]; ++i)
        {
            g[x] = i;
            dfs(x + 1); 
        }
    }
    int main()
    {
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 1; j <= w[i]; ++j) // 第 i 维在初始值为 j 的时候最早挂掉的步数 
            {
                int _j = j, fail = 0;
                long long steps = 0, lst = 0;
                //  判断 -1: 该维在成功走完一遍后留在原地
                
                for (int l = 0, liml = op[i].size(); l < liml; ++l)
                {
                    Data x = op[i][l];
                    if (_j + x.t > w[i] || _j + x.t == 0)
                    {
                        fail = 1;
                        break;
                    }
                    else
                    {
                        _j += x.t;
                    }
                }
                if (_j == j && !fail)
                {
                    f[i][j] = 1ll << 62;
                    continue;
                }
                // 正常操作 
                _j = j;
                for (bool fin = 0; !fin; )
                {
                    for (int l = 0, liml = op[i].size(); l < liml; ++l)
                    {
                        Data x = op[i][l];
                        steps += (x.id == lst) ? n : ((n + x.id - lst) % n);
                        if (_j + x.t > w[i] || _j + x.t == 0)
                        {
                            fin = 1;
                            break;
                        }
                        else
                        {
                            _j += x.t;
                            lst = x.id;
                        }
                    }
                }
                f[i][j] = steps;
            }
        }
        
//        for (int i = 1; i <= k; ++i)
//        {
//            for (int j = 1; j <= w[i]; ++j)
//            {
//                cout << "f[" << i << "][" << j << "]: " << f[i][j] << endl;
//            }
//        }
        dfs(1);
        if (damn)
            cout << -1 << endl;
        else
            cout << ans % mod << endl;
        return 0;
    }
}

int main()
{
#ifdef submit
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
#endif
    read(n); read(k);
    for (int i = 1; i <= k; ++i)
    {
        read(w[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        read(c[i]);
        read(d[i]);
        op[c[i]].push_back(Data(d[i], i));
    }
    //if (n <= 100)
        bruteforce::main();
    return 0;
}

