#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define pq priority_queue
#define ff first
#define ss second
#define isnum(c) (('0'<=c)&&(c<='9'))
#define isch(c) (('a'<=c)&&(c<='z'))
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN=1.1e6+10,INF=2e9+7,MOD1=1e9+7,MOD2=1e9+9,BASE=541;
char s[MAXN];
int hash1[MAXN],hash2[MAXN],p1[MAXN],p2[MAXN],pre[MAXN][30],nail[MAXN],N;
ll ans=0;
inline void read(int &a)
{
	char c=getchar();
	bool f=0;
	a=0;
	while(!isnum(c))
	{
		f|=(c=='-');
		c=getchar();
	}
	while(isnum(c))
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return;
}
inline void init()
{
	p1[0]=1;
	p2[0]=1;
	_for(i,1,MAXN)
	{
		p1[i]=(ll)p1[i-1]*BASE%MOD1;
		p2[i]=(ll)p2[i-1]*BASE%MOD2;
	}
	return;
}
pii gethash(int l,int r)
{
	 pii ret;
	 ret.ff=(ll)((ll)hash1[r]-hash1[l-1]+MOD1)%MOD1;
	 ret.ss=(ll)((ll)hash2[r]-hash2[l-1]+MOD2)%MOD2;
	 return ret;
}
inline void input()
{
	scanf("%s",&s[1]);
	_for(i,1,MAXN)
		if(!isch(s[i]))
		{
			N=i-1;
			break;
		}
	return;
}
inline void solve()
{
	ans=0;
	int sum[30],num;
	memset(sum,0,sizeof(sum));
	_for(i,1,N+1)
	{
		sum[s[i]-'a']++;
		num=0;
		_for(j,0,30)
			if(sum[j]%2)
				num++;
		_for(j,0,30)
			pre[i][j]=pre[i-1][j];
		_for(j,num,30)
			pre[i][j]++;
	}
	memset(sum,0,sizeof(sum));
	for(int i=N;i>=1;i--)
	{
		sum[s[i]-'a']++;
		num=0;
		_for(j,0,30)
			if(sum[j]%2)
				num++;
		nail[i]=num;
	}
	_for(i,1,N+1)
	{
		hash1[i]=(ll)((ll)s[i]-'a'+(ll)hash1[i-1]*BASE%MOD1)%MOD1;
		hash2[i]=(ll)((ll)s[i]-'a'+(ll)hash2[i-1]*BASE%MOD2)%MOD2;
	}
	pii h0,h1;
	int r,r0;
	_for(len,2,N)
	{
		r0=1+len-1;
		h0=gethash(1,r0);
		ans+=pre[r0-1][nail[r0+1]];
		for(int l=1+len;l+len-1<N;l+=len)
		{
			r=l+len-1;
			h1=gethash(l,r);
			h0.ff=(ll)h0.ff*p1[len]%MOD1;
			h0.ss=(ll)h0.ss*p2[len]%MOD2;
			if(h0!=h1)
				break;
			ans+=pre[r0-1][nail[r+1]];
		}
	}
	return;
}
inline void print()
{
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	init();
	_for(i,0,T)
	{
		input();
		solve();
		print();
	}
	return 0;
}
