#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1e9+7;
template<typename T>
void read(T &n)
{
    n=0;
    int tag=1;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-')
            tag=-tag;
        c=getchar();
    }
    while(isdigit(c))
    {
        n=n*10+c-'0';
        c=getchar();
    }
    n*=tag;
    return;
}
unsigned long long n,k,ans;
vector<unsigned long long> a,w,c,d;
void work()
{
    if(ans==-1)
        return;
    vector<unsigned long long> s=a;
    bool f=true;
    while(f)
    {
        for(unsigned long long i=1;i<=n;++i)
        {
            s[c[i]]+=d[i];
            ++ans;
            ans%=mod;
            if(s[c[i]]>w[c[i]]||s[c[i]]==0)
            {
                f=false;
                break;
            }
        }
        if(s==a)
        {
            f=false;
            ans=-1;
        }
    }
    return;
}
void dfs(unsigned long long x)
{
    for(unsigned long long i=1;i<=w[x];++i)
    {
        a[x]=i;
        if(x==k)
        {
            work();
            if(ans==-1)
                break;
        }
        else
        {
            dfs(x+1);
            if(ans==-1)
                break;
        }
    }
    return;
}
int main()
{
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    read(n);
    read(k);
    a.resize(k+1);
    w.resize(k+1);
    c.resize(n+1);
    d.resize(n+1);
    for(unsigned long long i=1;i<=k;++i)
        read(w[i]);
    for(unsigned long long i=1;i<=n;++i)
        read(c[i]),read(d[i]);
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
