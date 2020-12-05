#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,k,ans=0;
int flag=0;
int lim[11];
struct walkit
{
int c,d;
}a[500011];
struct nowwhat
{
int x[11];
}st;
bool insz(nowwhat p)
{
for(int i=1;i<=k;++i)
if(p.x[i]<1||p.x[i]>lim[i])return 0;
return 1;
}
bool equ(nowwhat a,nowwhat b)
{
for(int i=1;i<=k;++i)
if(a.x[i]!=b.x[i])return 0;
return 1;
}
void dfs(nowwhat p)
{
int tot=0,e=0;
while(1)
	{
	++tot;e%=n;++e;
	p.x[a[e].c]+=a[e].d;
	if(!insz(p))break;
	if(equ(p,st)){flag=1;break;}
	}
ans+=tot;
ans%=mo;
}
void outerdfs(int dep)
{
if(dep>k){dfs(st);return;}
for(int i=1;i<=lim[dep];++i)
	{
	if(flag)return;
	st.x[dep]=i,outerdfs(dep+1);
	}
}
int main()
{
freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
scanf("%d%d",&n,&k);
for(int i=1;i<=k;++i)
scanf("%d",&lim[i]);
for(int i=1;i<=n;++i)
scanf("%d%d",&a[i].c,&a[i].d);
outerdfs(1);
cout<<ans<<endl;
return 0;
}

