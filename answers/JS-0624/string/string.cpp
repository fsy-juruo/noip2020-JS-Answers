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
unsigned long long F(string s)
{
    map<char,unsigned long long> m;
    unsigned long long ans=0;
    for(unsigned long long i=0;i<s.size();++i)
        ++m[s[i]];
    for(map<char,unsigned long long>::iterator i=m.begin();i!=m.end();++i)
        if((i->second)%2)
            ++ans;
    return ans;
}
unsigned long long work(string s,unsigned long long i,unsigned long long f)
{
    unsigned long long ans=0;
    if(s.size()%i)
        return 0;
    string ab=s.substr(0,s.size()/i);
    for(unsigned long long j=1;j*ab.size()<s.size();++j)
        if(s.substr(j*ab.size(),ab.size())!=ab)
            return 0;
    map<char,unsigned long long> m;
    unsigned long long fa=0;
    for(unsigned long long j=0;j<ab.size()-1;++j)
    {
        ++m[ab[j]];
        if(m[ab[j]]%2)
            ++fa;
        else
            --fa;
        if(fa<=f)
            ++ans;
    }
    return ans;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T;
    read(T);
    while(T--)
    {
        string s;
        unsigned long long ans=0;
        cin>>s;
        for(unsigned long long i=1;i<s.size()-1;++i)
        {
            string c=s.substr(s.size()-i,i);
            unsigned long long f=F(c);
            for(unsigned long long j=1;j<=(s.size()-i)/2;++j)
                ans+=work(s.substr(0,s.size()-i),j,f);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
