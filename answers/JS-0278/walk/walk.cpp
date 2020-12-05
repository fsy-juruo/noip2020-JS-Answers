#include<bits/stdc++.h>
using namespace std;

const int N=100000+3;
const int inf=0x7fffffff;
const int mo=1e9+7;
struct node{int step,di;}ci[13][N];int s[N];
int w[15],ans[13][13];

int sum[N],n,k;
int work(int wd,int zb)
{
	int cnt=0;int l=inf;int r=0;
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=s[wd];i++)
	{ 
	    sum[i]=sum[i-1]+ci[wd][i].di;
	    l=min(l,sum[i]);r=max(r,sum[i]);
	    if(zb+sum[i]<1||zb+sum[i]>w[wd]) 
		   return ci[wd][i].step;
	}
	if(sum[s[wd]]==0) return -1;
	if(l<0) l=abs(l);else l=1;
	if(r==sum[s[wd]]) r=1; 
	while(zb+sum[s[wd]]>=l&&zb+sum[s[wd]]<=w[wd]-r+1) 
	     zb+=sum[s[wd]],cnt+=n;
	for(int i=1;i<=s[wd];i++)
	    if(zb+sum[i]<1||zb+sum[i]>w[wd]) 
		   return cnt+ci[wd][i].step;
}

int tot,q[15];bool no;int mm;
void dfs(int dep)
{
	if(dep>k) 
	{
		int minn=inf;
		for(int i=1;i<=k;i++)
		    if(ans[i][q[i]]!=-1)
			minn=min(minn,ans[i][q[i]]);
		if(minn==inf) {no=1;return ;}
		tot=(tot+minn)%mo;return ;
	}
	for(int i=1;i<=w[dep];i++)
	{
		q[dep]=i;
		dfs(dep+1);
		if(no) return ;
	}
	return ;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i) scanf("%d",&w[i]);
	for(int i=1,x,y;i<=n;++i)
	{
	    scanf("%d%d",&x,&y);
	    s[x]++;
	    ci[x][s[x]].di=y;
	    ci[x][s[x]].step=i;
    }
    for(int i=1;i<=k;i++)
       for(int j=1;j<=w[i];j++)
         ans[i][j]=work(i,j);
    dfs(1);
    if(no) printf("-1");
	else printf("%d",tot);
	return 0;
}
