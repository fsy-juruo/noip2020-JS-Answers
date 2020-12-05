#include <bits/stdc++.h>
using namespace std;

const int MAXN=1048576+5;
int as[30],cs[30],ajs,cjs,ajs_f[MAXN];
char c[MAXN];

struct ys{
    bool ud;
    vector<int> s;
    inline ys() : ud(0) {}
}y[MAXN];

namespace lzy
{
inline int rd()
{
    int tp(0);
    c[1]=getchar();
    for(;c[1]<'a'||c[1]>'z';c[1]=getchar());
    for(;c[tp+1]>='a'&&c[tp+1]<='z';c[tp+1]=getchar()) {
        ++tp;
    }
    return tp;
}

inline void qys(int x)
{
    if(y[x].ud)
        return;
    double sq(sqrt(x));
    for(int i=1;i<=sq;++i) {
        if(x%i==0) {
            if(i*i==x)
                y[x].s.push_back(i);
            else {
                y[x].s.push_back(i);
                y[x].s.push_back(x/i);
            }
        }
    }
    y[x].ud=1;
}

}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T,len,ans;
    scanf("%d",&T);
    for(int ti=1;ti<=T;++ti) {
        ans=0;
        len=lzy::rd();
        memset(as,0,sizeof(as));
        memset(ajs_f,-1,sizeof(ajs_f));
        memset(cs,0,sizeof(cs));
        ajs=cjs=0;
        for(int i=1;i<=len;++i)
            ++cs[c[i]-'a'];
        for(int i=0;i<26;++i)
            cjs+=(cs[i]%2==1);
        for(int i=1;i<len;++i) {
            --cs[c[i]-'a'];
            if(cs[c[i]-'a']%2==0)
                --cjs;
            else
                ++cjs;
            if(i==1)
                continue;
            lzy::qys(i);
            int size=y[i].s.size();
            for(int j=0;j<size;++j) {
                int times=i/y[i].s[j];
                bool ok=1;
                for(int k=times;k>=2;--k) {
                    for(int l=1;l<=y[i].s[j];++l) {
                        if(c[l]!=c[l+(k-1)*y[i].s[j]]) {
                            ok=0;
                            break;
                        }
                    }
                    if(!ok)
                        break;
                }
                if(!ok)
                    continue;
                for(int k=1;k<y[i].s[j];++k) {
                    if(ajs_f[k]==-1) {
                        ++as[c[k]-'a'];
                        if(as[c[k]-'a']%2==0)
                            --ajs;
                        else
                            ++ajs;
                        ajs_f[k]=ajs;
                        if(ajs<=cjs)
                            ++ans;
                    }
                    else if(ajs_f[k]<=cjs)
                        ++ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
