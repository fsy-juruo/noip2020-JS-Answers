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
unsigned long long n,m,depth;
vector<vector<unsigned long long> > bal;
vector<pair<unsigned long long,unsigned long long> > mov;
map<vector<vector<unsigned long long> >,unsigned long long> s;
bool dfs(unsigned long long k)
{
    if(k>depth)
        return false;
    if(s.count(bal)!=0&&s[bal]<k)
        return false;
    s[bal]=k;
    bool f=true;
    for(unsigned long long i=1;i<=n+1;++i)
        if(!bal[i].empty()&&bal[i]!=vector<unsigned long long>(m,bal[i].back()))
        {
            f=false;
            break;
        }
    if(f)
    {
        cout<<k<<'\n';
        for(unsigned long long i=0;i<mov.size();++i)
            cout<<mov[i].first<<' '<<mov[i].second<<'\n';
        return true;
    }
    for(unsigned long long i=1;i<=n+1;++i)
    {
        if(bal[i].empty())
            continue;
        for(unsigned long long j=1;j<=n+1;++j)
        {
            if(j==i||bal[j].size()==m)
                continue;
            bal[j].push_back(bal[i].back());
            bal[i].pop_back();
            mov.push_back(make_pair(i,j));
            if(dfs(k+1))
                return true;
            mov.pop_back();
            bal[i].push_back(bal[j].back());
            bal[j].pop_back();
        }
    }
    return false;
}
int main()
{
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    read(n);
    read(m);
    bal.resize(n+2);
    for(unsigned long long i=1;i<=n;++i)
        for(unsigned long long x,j=1;j<=m;++j)
        {
            read(x);
            bal[i].push_back(x);
        }
    depth=1;
    while(!dfs(0)&&depth<=820000)
        ++depth;
    return 0;
}
