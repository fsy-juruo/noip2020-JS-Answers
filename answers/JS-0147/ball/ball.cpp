#include<bits/stdc++.h>
using namespace std;
int n,m,ans1[1000010],ans2[1000010],tot;
vector<int>zhu[60];
void work()
{
	int t;
	for(int i=0;i<zhu[1].size();++i)
	if(zhu[1][i]!=1)
	{
		t=i;
		break;
	}
}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch^'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		int x;
		zhu[i].push_back(x);
	}
	if(n==2)work();
	return 0;
}
