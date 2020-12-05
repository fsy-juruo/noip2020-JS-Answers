#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,x,sta,l,r;
int qq[111111];
struct edge
{
int to,nxt;
}a[2000111];
int hd[100011]={},tot=0;
struct vvv
{
ll p,q;
}val[100011];
int sz[100011]={};
inline int read()
{
int x=0;char ch=getchar();
while(ch>'9'||ch<'0')ch=getchar();
while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();
return x;
}
inline void addedge(int x,int y)
{a[++tot].to=y;a[tot].nxt=hd[x];hd[x]=tot;}
int gcdit(ll x,ll y)
{
if(x<y)x^=y,y^=x,x^=y;
if(x%y==0)return y;
else return gcdit(y,x%y);
}
inline vvv addit(vvv x,vvv y)
{
vvv tt;
tt.q=x.q*y.q;
tt.p=x.p*y.q+y.p*x.q;
ll tmpt=gcdit(tt.q,tt.p);
tt.q/=tmpt;tt.p/=tmpt;
return tt;
}
vvv dfs(int x)
{

//printf("%d\n",x);

if(val[x].p)return val[x];

//printf("tp:%lld tq:%lld\n",tmp.p,tmp.q);

for(int i=hd[x];i;i=a[i].nxt)
{
vvv tmp=dfs(a[i].to);
tmp.q*=sz[a[i].to];
val[x]=addit(val[x],tmp);
}
return val[x];
}
/*inline void bfs()
{
l=r=1;
qq[l]=sta;
while(l<=r)
	{
	vvv tmp;
	x=qq[l];
	
	printf("l:%d x:%d xp:%lld xq:%lld\n",l,x,val[x].p,val[x].q);
	
	tmp.p=val[x].p;
	tmp.q=val[x].q*sz[x];
	
	printf("tp:%lld tq:%lld\n",tmp.p,tmp.q);
	
	for(int i=hd[x];i;i=a[i].nxt)
		{
		qq[++r]=a[i].to;
		val[a[i].to]=addit(val[a[i].to],tmp);
		
		printf("top:%lld toq:%lld\n",val[a[i].to].p,val[a[i].to].q);
		
		}
	++l;
	}
}*/
int main()
{
freopen("water.in","r",stdin);
freopen("water.out","w",stdout);
n=read();m=read();
sta=n+1;
val[sta].p=m;
val[sta].q=1;
sz[sta]=m;
for(int i=1;i<=m;++i)
addedge(i,sta);
for(int i=1;i<=n;++i)
	{
	sz[i]=read();
	val[i].q=1;val[i].p=0;
	for(int j=1;j<=sz[i];++j)
		{
		x=read();
		addedge(x,i);
		}
	}
//bfs();
for(int i=1;i<=n;++i)
if(!sz[i])
{
vvv ttt=dfs(i);
cout<<ttt.p<<" "<<ttt.q<<endl;
}
return 0;
}

