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

const long long mod = 1e9 + 7;

using std::cin;
using std::cout;
using std::endl;

int T, len, cntEq;
int eq[1048586], f[1048586], finv[1048586], app[30]; // f[i]: s[0 .. i] 的 F 值, finv[i]: s[i .. len - 1] 的 F 值 
long long ans;
long long hash[1010][1010];
std::string s;

void work(int x, int y) // AB = s[0 .. x - 1], C = s[y .. len - 1]
{
    if (x == 1 || y == len)
        return;
//    cout << s.substr(0, x) << " " << s.substr(y, len - y) << endl;
    for (int i = 0; i < x - 1; ++i) // A = s[0 .. i]
    {
        if (f[i] <= finv[y])
            ++ans;
    }
}

int main()
{
#ifdef submit
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (cin >> T; T; --T)
    {
        cin >> s;
        
        // init start
        
        len = s.length();
        char fst = s[0], lst = s[len - 1];
        memset(app, 0, sizeof app);
        app[fst - 'a'] = f[0] = 1;
        ans = 0;
        // init end
        
        for (int i = 1; i < len; ++i)
        {
            char x = s[i];
            ++app[x - 'a'];
            if (app[x - 'a'] & 1) // 曾经出现过偶数次，变为奇数次 
            {
                f[i] = f[i - 1] + 1;
            }
            else // 曾经出现过奇数次，变为偶数次 
            {
                f[i] = f[i - 1] - 1;
            }
        }
        
        memset(app, 0, sizeof app);
        app[lst - 'a'] = finv[len - 1] = 1;
        for (int i = len - 2; ~i; --i)
        {
            char x = s[i];
            ++app[x - 'a'];
            if (app[x - 'a'] & 1)
            {
                finv[i] = finv[i + 1] + 1;
            }
            else
            {
                finv[i] = finv[i + 1] - 1;
            }
        }
        
        for (int i = 0; i < len; ++i)
        {
            long long h = 0;
            for (int j = 0; i + j < len; ++j)
            {
                h = (h + s[i + j] - 'a' + 7ll) * 37ll % mod * 41ll % mod * 1145141ll % mod;
                hash[i][j + 1] = h;
            }
        }
        
        // init end
        
        for (int i = 1; i < len; ++i) // 截取 s[0 .. i] 作为 AB 
        {
            int lAB = i + 1;
            for (int j = 1, lim = len / lAB; j <= lim; ++j) // 重复 j 次 
            {
                if (hash[0][lAB] == hash[(j - 1) * lAB][lAB])
                {
                    // C = s[C .. len - 1]
                    work(lAB, (j - 1) * lAB + lAB);
                }
                else
                {
                    break;
                }
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}

