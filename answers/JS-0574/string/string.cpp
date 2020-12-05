#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
template <typename T> inline T chkmax(T&x,T y){return (x=(x>y?x:y));}
template <typename T >inline T chkmin(T&x,T y){return (x=(x<y?x:y));}
template <typename T> inline void read(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
	while(ch>=48&&ch<=57){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	x*=f;
}
const int N=1005;
string s;int n;
int f[200];
int l[N],r[N];
string s1[N];
int dp[N],su[N];
void solve()
{
	rep(i,0,n)
	l[0]=r[n-1]=1;
	f[s[0]]++;
	s1[0]="";
	s1[0]=s1[0]+s[0];
	_rep(i,1,n)
	s1[i]=s1[i-1]+s[i];
	_rep(i,1,n)
	{
		f[s[i]]++;
		if(f[s[i]]%2==0)
		l[i]=l[i-1]-1;
		else l[i]=l[i-1]+1;
	}
	rep(i,'a','z')
	f[i]=0;
	f[s[n-1]]++;
	Rep(i,n-2,0)
	{
		f[s[i]]++;
		if(f[s[i]]%2==0)
		r[i]=r[i+1]-1;
		else r[i]=r[i+1]+1;
	}
	rep(i,'a','z')
	f[i]=0;
	_rep(i,0,n)dp[i]=i,su[i]=1;
	_rep(i,1,n)
	{
		Rep(j,i-1,0)
		if(s1[j]+s1[dp[j]]==s1[i])
		{
			dp[i]=dp[j];
			su[i]=su[j]+1;
			break;
		}
	}
//	rep(i,0,n-1)printf("%d ",l[i]);printf("\n");
//	Rep(i,n-1,0)printf("%d ",r[i]);printf("\n");
//	printf("\n");
//	rep(i,0,n-1)printf("%d %d\n",dp[i],su[i]);
//	printf("\n");
	int ans=0;
	Rep(i,n-1,2)
	{
		rep(j,0,i-2)
		if(l[j]<=r[i])
		{
			rep(k,1,su[i-1])
			if(su[i-1]%k==0&&(dp[i-1]+1)*k-1>j)
			ans++;//,cout<<j+1<<' '<<n-i<<endl;;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		cin>>s;
		n=s.size();
		solve();
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/

