#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace lzy
{
template <typename T> inline void rd(T &x)
{
    x=0;
    int f(1);
    char c(getchar());
    for(;c<'0'||c>'9';c=getchar())
        if(c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=x*10+c-'0';
    x*=f;
}

char s[25];
template <typename T> inline void wt(T x)
{
    int tp(0);
    while(x) {
        s[tp++]=x%10+'0';
        x/=10;
    }
    for(int i=tp-1;i>=0;--i)
        putchar(s[i]);
}

inline ll gcd(ll x,ll y)
{
    if(x==0||y==0)
        return 1;
    ll z=x%y;
    while(z!=0)
    {
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}

inline ll gbs(ll x,ll y){return (x*y)/gcd(x,y);}
}

const int MAXN=100000+5;

struct fs{
    ll p,q;
    inline void yf()
    {
        ll g(lzy::gcd(p,q));
        p/=g;
        q/=g;
    }
    inline fs(){}
    inline fs(int _p,int _q) : p(_p),q(_q) {}
    inline fs(fs _p,int _q) : p(_p.p),q(_p.q*_q) {}
    inline void operator+=(fs _y)
    {
        ll _p,_q(lzy::gbs(q,_y.q)),g;
        _p=_q/q*p+_q/_y.q*_y.p;
        g=lzy::gcd(_p,_q);
        p=_p/g;
        q=_q/g;
    }
};

struct node{
    bool is_out;
    fs w;
    vector<int> to;
}a[MAXN];

int main()
{
    int n,m,di,ai;
    queue<int> que;
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    lzy::rd(n);
    lzy::rd(m);
    for(int i=0;i<n;++i) {
        lzy::rd(di);
        a[i].is_out=(di==0);
        if(i<m) {
            a[i].w=fs(1,1);
            que.push(i);
        }
        else
            a[i].w=fs(0,1);
        for(int j=0;j<di;++j) {
            lzy::rd(ai);
            a[i].to.push_back(ai-1);
        }
    }
    while(!que.empty()) {
        int x(que.front()),size;
        que.pop();
        if(a[x].is_out)
            continue;
        fs w_val;
        size=a[x].to.size();
        w_val=fs(a[x].w,size);
        w_val.yf();
        for(int i=0;i<size;++i) {
            a[a[x].to[i]].w+=w_val;
            que.push(a[x].to[i]);
        }
        a[x].w=fs(0,1);
    }
    for(int i=0;i<n;++i) {
        if(a[i].is_out) {
            lzy::wt(a[i].w.p);
            putchar(' ');
            lzy::wt(a[i].w.q);
            putchar('\n');
        }
    }
    return 0;
}
