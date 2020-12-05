#include<bits/stdc++.h>
#define MAXN 500005
#define MOD 1000000007
typedef long long ll;
using namespace std;
int _max(int a,int b)	{return a>b?a:b;}
int _min(int a,int b)	{return a<b?a:b;}
template <typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for  (;!isdigit(c);c=getchar())	if  (c=='-')	x=-x;
	for  (;isdigit(c);a=a*10+c-48,c=getchar());a*=x;
}
struct qwq{
	int wd;
} px[10000007];
struct zb{
	int num[10];
} xy[MAXN],jdz,xz;
int w[15];
int c[MAXN],d[MAXN];
int zy[15];
int nxt[MAXN];
int N,K;
long long ans=0;
int cs[10][1000005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(N),read(K);
	for  (int i=0;i<K;i++)
		read(w[i]);
	int tot=0;
	for  (int i=1;i<=N;i++)
		{
			read(c[i]),read(d[i]);
			c[i]--;
			xy[i]=xy[i-1];
			xy[i].num[c[i]]+=d[i];
			int zz=xy[i].num[c[i]];
			jdz.num[c[i]]=_max(jdz.num[c[i]],abs(zz));
			nxt[i]=i+1;
			if  (zz>0)
				{	
					if  (zz>w[c[i]])	break;
					if  (cs[c[i]][w[c[i]]+1-zz]==0)
						{
							cs[c[i]][w[c[i]]+1-zz]=i;
							tot++;
							px[tot].wd=c[i];
						}
				}
			if  (zz<0)
				{
					if  (-zz>w[c[i]])	break;
					if  (cs[c[i]][-zz]==0)
						{
							cs[c[i]][-zz]=i;
							tot++;
							px[tot].wd=c[i];
						}
				}
		}
	nxt[N]=1;
	bool flag=true;
	for  (int i=0;i<K;i++)
		if  (xy[N].num[c[K]])	flag=false;
	if  (flag)
		{
			for  (int i=0;i<K;i++)
				if  (jdz.num[i]>=w[i])	flag=false;
			if  (flag)
				{
					cout<<-1<<endl;
					return 0;
				}
		}
		
	int qwq=N;
	xz=xy[N];
	for  (int i=N+1;;i++)
		{
				qwq=nxt[qwq];
			int cc=c[qwq],dd=d[qwq];
			xz.num[cc]+=dd;
			int zz=xz.num[cc];
			if  (zz>0)
				{	
					if  (zz>w[cc])	break;
					if  (cs[cc][w[cc]+1-zz]==0)
						{
								cs[cc][w[cc]+1-zz]=i;
								tot++;
								px[tot].wd=cc;
						}
				}
			if  (zz<0)
				{
					if  (-zz>w[cc])	break;
					if  (cs[cc][-zz]==0)
						{
							cs[cc][-zz]=i;
							tot++;
							px[tot].wd=cc;
						}
				}
		}
	
	for  (int i=1;i<=tot;i++)
		{
			ll qwq=1;
			for  (int j=0;j<K;j++)
				if  (j!=px[i].wd)
					qwq=qwq*w[j]%MOD;
			w[px[i].wd]--;
			qwq=qwq*i%MOD;
			ans=(ans+qwq)%MOD;
			if  (w[px[i].wd]==0)	break;
		}
	cout<<ans<<endl;
	return 0;
}

