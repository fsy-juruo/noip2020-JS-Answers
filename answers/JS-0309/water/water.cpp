#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
/* int 够不够，要不要long long?
	数组开得够不够？
	*/ 
using namespace std;
template<typename T>
inline void in(T &x)
{
	x=0;
	char c=getchar();
	bool fu=0;
	while(c<'0'||c>'9'){if(c=='-')fu=1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x=fu?-x:x;
}
template<typename T>
inline T Abs(T x){return x<0?-x:x;}
template<typename T>
inline void chmax(T &x,T y){x=x>y?x:y;}
template<typename T>
inline void chmin(T &x,T y){x=x<y?x:y;}
//need long long
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
struct frac
{
	ll son,mom;
	frac(ll _son=0,ll _mom=1):son(_son),mom(_mom){}
};
frac operator + (const frac &x,const frac &y)
{
	frac ret;
	ll g=gcd(x.mom,y.mom);
	ret.mom=x.mom/g*y.mom;
	ret.son=(ret.mom/x.mom)*x.son+(ret.mom/y.mom)*y.son;
	if(ret.son==0)return frac(0,1);
	g=gcd(ret.son,ret.mom);
	ret.son/=g;
	ret.mom/=g;
	return ret;
}
frac calc(frac x,ll d)
{
	ll g=gcd(x.son,d);
	x.son/=g,d/=g;
	x.mom*=d;
	return x;
}
int n,m,deg[N],q[N];
frac val[N];
vector<int> v[N];
bool Out[N];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	in(n);in(m);
	
	memset(deg,0,sizeof(deg));
	for(int i=1;i<=n;++i)
	{
		int t;
		in(t);
		if(!t)Out[i]=1;
		for(int j=0;j<t;++j)
		{
			int to;
			in(to);
			++deg[to];
			v[i].pb(to);
		}
	}
	int fr=0,bk=0;
	for(int i=1;i<=n;++i)
	if(!deg[i])q[bk++]=i,val[i]=frac(1,1);
	while(fr<bk)
	{
		int from=q[fr++],sz=v[from].size();
		if(!sz)continue;
		frac Add=calc(val[from],sz);
		for(int i=0;i<v[from].size();++i)
		{
			int to=v[from][i];
			val[to]=val[to]+Add;
			--deg[to];
			if(!deg[to])q[bk++]=to;
		}
	}
	for(int i=1;i<=n;++i)
	if(Out[i])
	printf("%lld %lld\n",val[i].son,val[i].mom);
	return 0;
}
