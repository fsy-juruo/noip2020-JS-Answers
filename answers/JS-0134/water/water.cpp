#include<bits/stdc++.h>
using namespace std;

int out[100010][10];
bool is_end[100010];
int n,m;
struct answer
{
	long long p,q;
}ans[100010];

inline void start(){

	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}

inline long long read(){

	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

inline long long gcd(long long a,long long b){

	if(a<b) swap(a,b);
	if(b==0) return a;
	return gcd(b,a%b);
}

inline void plus1(long long a,long long b,long long id){

	long long x=ans[id].p,y=ans[id].q;
	long long t=gcd(b,y);
	long long c=a*y/t+x*b/t,d=b*y/t;
	t=gcd(c,d);
	c=c/t;
	d=d/t;
	ans[id].p=c;
	ans[id].q=d;
}

inline void dfs(int s,long long v)
{
	//cout<<s<<" "<<v<<endl;
	if(is_end[s])
	{
		plus1(1,v,s);
		return;
	}
	v=v*out[s][0];
	for(int i=1;i<=out[s][0];i++) dfs(out[s][i],v);
	return;
}

int main()
{
	start();
	n=read(); m=read();
	for(int i=1;i<=n;i++)
	{
		int d;
		d=read();
		out[i][0]=d;
		if(d==0) 
		{
			is_end[i]=1;
			ans[i].p=0;
			ans[i].q=1;
		}
		for(int j=1;j<=d;j++) out[i][j]=read();
	}
	for(int i=1;i<=m;i++) dfs(i,1);
	for(int i=1;i<=n;i++) 
	{
		
		if(is_end[i]) 
		{
			cout<<ans[i].p<<" "<<ans[i].q<<endl;
		}
	}
	return 0;
}

//gcd¿Õ¼äÓÅ»¯ 
