#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ull long long
int n,m;
int flag=0;
int a[55][411]={};
int h[55]={};
struct mmmm
{
int x,y;
}st[820011];
int top=0;
map<ull,ull> mp;
ull calcit()
{
ull tmp=0;
for(int i=1;i<=n+1;++i)
{
for(int j=1;j<=h[i];++j)
tmp=tmp*m+a[i][j];
tmp*=n;
}
return tmp;
}
bool check()
{
for(int i=1;i<=n+1;++i)
{
if(h[i]!=m&&h[i]!=0)return 0;
for(int j=1;j<=h[i];++j)

if(a[i][j]!=a[i][1])return 0;
}
return 1;
}
void dfs(int dep)
{
if(check()){flag=1;cout<<dep-1<<endl;return;}
if(dep>820000)return;
for(int i=1;i<=n+1;++i)
if(h[i]>0)
for(int j=1+n;j>=1;--j)
if(i!=j&&h[j]<m)
	{
	
//	printf("i:%d h[i]:%d j:%d h[j]:%d dep:%d\n",i,h[i],j,h[j],dep);
	
	a[j][h[j]+1]=a[i][h[i]];
	++h[j];--h[i];
	ull tmp=calcit();
	if(mp.find(tmp)==mp.end())
		{
		mp[tmp]=1;
		dfs(dep+1);
		
		if(flag){st[++top].x=i;st[top].y=j;return;}
		
		}
	a[i][h[i]+1]=a[j][h[j]];
	--h[j];++h[i];
	}
}
int main()
{
freopen("ball.in","r",stdin);
freopen("ball.out","w",stdout);
scanf("%d%d",&n,&m);
for(int i=1;i<=n;++i)
{
for(int j=1;j<=m;++j)
scanf("%d",&a[i][j]);
h[i]=m;
}
dfs(1);
while(top)
{
cout<<st[top].x<<" "<<st[top].y<<endl;
--top;
}
return 0;
}

