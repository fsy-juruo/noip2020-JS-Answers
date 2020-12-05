#include<bits/stdc++.h>
#define int long long
//#define mo
using namespace std;
int read(){
	int num=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar(); }
	while(isdigit(c)){num=num*10+c-'0'; c=getchar(); }
	return num*f;
}
int n,m,x[100005];
int head[100005],tot;
int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
struct node{
	int to,nxt;
}edge[1000005];
struct fenshu{
	int a,b;
}ans[100005];
void add(int x,int y){
	edge[++tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}
void up(int k,int a,int b){
	ans[k].a=ans[k].a*b+ans[k].b*a;
	ans[k].b=ans[k].b*b;
	int g=gcd(ans[k].a,ans[k].b);
	ans[k].a/=g;
	ans[k].b/=g;
}
void dfs(int k,int a,int b){
	if (x[k]==0) 
	{
		up(k,a,b);
		return;
	}
	for(int i=head[k];i;i=edge[i].nxt)
	{
		int y=edge[i].to;
		dfs(y,a,x[k]*b);
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		for(int j=1;j<=x[i];j++)
		{
			int a=read();
			add(i,a);
		}
	}
	for(int i=1;i<=n;i++)
		if (x[i]==0) ans[i].b=1;
	for(int i=1;i<=m;i++) dfs(i,1,1);
	for(int i=1;i<=n;i++)
		if (x[i]==0) 
		{
			int g=gcd(ans[i].a,ans[i].b);
			cout<<ans[i].a/g<<" "<<ans[i].b/g<<'\n';
		}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
