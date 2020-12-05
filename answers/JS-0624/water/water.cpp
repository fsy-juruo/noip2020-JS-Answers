#include<bits/stdc++.h>
using namespace std;
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
template<typename T>
T gcd(T a,T b)
{
    T c;
    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
struct fs
{
    unsigned long long a,b;
    fs()
    {
        a=0;
        b=1;
    }
    fs(unsigned long long m,unsigned long long n)
    {
        a=m;
        b=n;
    }
    void yf()
    {
        unsigned long long g=gcd(a,b);
        a/=g;
        b/=g;
    }
    void jf(fs x)
    {
        unsigned long long i=a,j=b;
        a*=x.b;
        b*=x.b;
        x.a*=j;
        x.b*=j;
        a+=x.a;
        yf();
    }
    void cf(unsigned long long x)
    {
        b*=x;
        yf();
    }
    void write()
    {
        yf();
        cout<<a<<' '<<b<<'\n';
    }
};
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    unsigned long long n,m;
    read(n);
    read(m);
    vector<vector<unsigned long long> > v(n+1);
    vector<fs> w(n+1);
    vector<bool> in(n+1,true);
    for(unsigned long long d,i=1;i<=n;++i)
    {
        read(d);
        for(unsigned long long a,j=1;j<=d;++j)
        {
            read(a);
            v[i].push_back(a);
            in[a]=false;
        }
    }
    for(unsigned long long i=1;i<=n;++i)
        if(in[i])
            w[i]=fs(1,1);
    bool t=true;
    while(t)
    {
        t=false;
        for(unsigned long long i=1;i<=n;++i)
            if(!v[i].empty()&&w[i].a!=0)
            {
                t=true;
                w[i].cf(v[i].size());
                for(unsigned long long j=0;j<v[i].size();++j)
                    w[v[i][j]].jf(w[i]);
                w[i].a=0;
                w[i].b=1;
            }
    }
    for(unsigned long long i=1;i<=n;++i)
        if(v[i].empty())
            w[i].write();
    return 0;
}
