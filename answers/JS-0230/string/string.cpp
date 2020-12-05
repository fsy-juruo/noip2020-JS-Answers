#include<bits/stdc++.h>
#include<stdint.h>
#define FILEIO(x) do{freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);}while(0)
using namespace std;
template<typename T>
void ri(T&x)
{
	x=0;
	int neg=1;
	char c=getchar();
	for (;!(isdigit(c)||c=='-');c=getchar());
	if (c=='-') neg=-1,c=getchar();
	for (;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=neg;
}
#ifdef MYDBG
#define DEBUG(x) cerr<<#x<<":"<<x<<" "
#define DEBUGL(x) cerr<<#x<<":"<<x<<endl
#else
#define DEBUG(x)
#define DEBUGL(x)
#endif
#define ZEROMEM(x) memset(x,0,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef unsigned long long ull;
const ull P=257;
const int MAXN=1.5e6;
char s[MAXN];
ull base[MAXN],hs[MAXN];
vector<ull> xBase[3000];
int cnt[MAXN][26];
vector<int> v[26];
ull qpow(ull a,ull b)
{
    return (b&1)?qpow(a*a,b>>1)*a:qpow(a*a,b>>1);
}
void solve()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    bool allSame=1;
    for (int i=1;i<=n;i++)
        allSame&=s[i]==s[1];
    ZEROMEM(cnt);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<26;j++)
            cnt[i][j]=cnt[i-1][j];
        cnt[i][s[i]-'a']++;
        hs[i]=hs[i-1]*P+s[i]-'a';
    }
    for (int i=0;i<26;i++)
        v[i].clear();
    for (int i=1;i<=n;i++)
    {
        int p=0;
        for (int j=0;j<26;j++)
                p+=cnt[i][j]&1;
        v[p].push_back(i);
    }
    int cntC[128];
    ZEROMEM(cntC);
    ll ans=0;
    for (int i=n;i>2;i--)
    {
        cntC[s[i]]++;
        int p=0;
        for (int j='a';j<='z';j++)
            p+=cntC[j]&1;
        for (int c=0;c<=p;c++)
        {
            ans+=lower_bound(ALL(v[c]),i-1)-v[c].begin();
            //fprintf(stderr,"%lld %d %d\n",ans,c,i);
        }
        for (int j=2;j*j<=i;j++)
        {
            if ((i-1)%j!=0) continue;
            int tj=(i-1)/j;
            bool flg=1;
            ull t=0;
            //flg&=hs[j]*xBase[j][tj]==hs[i-1];
            if (!allSame)
            for (int k=1;k<=tj&&flg;k++)
            {
                t=t*base[j]+hs[j];
                flg&=t==hs[k*j];
            }
            if (flg)
                for (int c=0;c<=p;c++)
                    ans+=lower_bound(ALL(v[c]),j)-v[c].begin();
            if (j==tj) continue;
            flg=1;
            t=0;
            if (!allSame)
            for (int k=1;k<=j&&flg;k++)
            {
                t=t*base[tj]+hs[tj];
                flg&=t==hs[k*tj];
            }
            if (flg)
                for (int c=0;c<=p;c++)
                    ans+=lower_bound(ALL(v[c]),tj)-v[c].begin();

        }
    }
    printf("%lld\n",ans);
}
int main()
{
	FILEIO("string");
	base[0]=1;
	for (int i=1;i<MAXN;i++)
        base[i]=base[i-1]*P;
    /*for (int i=2;i<=1200;i++)
    {
        xBase[i].push_back(1);
        xBase[i].reserve(MAXN/i+1);
        for (int j=1;j<=MAXN/i;j++)
            xBase[i].push_back(xBase[i][xBase[i].size()-1]*base[i]+1);
    }*/
	int T;
    scanf("%d",&T);
    while(T--) solve();
    //while(1);
	return 0;
}
