#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sum=0,fh=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') fh=-1; ch=getchar();}
	while(isdigit(ch)){if(sum==214748364&&fh==-1&&ch=='8'){sum=-2147483638; fh=1;} else sum=sum*10+ch-'0'; ch=getchar();}
	return sum*fh;
}
inline void write(int x){
	if(x==0){putchar('0');return ;}stack<char>s;
	if(x==INT_MIN){s.push('8');x=-214748364;}
	if(x<0)putchar('-');x=abs(x);
	while(x){s.push(char(x%10+'0')); x/=10;}
	while(!s.empty()){putchar(s.top()); s.pop();}
}
struct node{
	long long a1,a2;
};
const int MAXN=100010;
vector<int> g[MAXN],a,b;
node ans[MAXN];
bool h[MAXN];
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
node yf(node l)
{
	int f=gcd(l.a1,l.a2);
	if(f!=1)
	{
		l.a1/=f;
		l.a2/=f;
	}
	return l;
}
node Plus(node x,node y)
{
	node l;
//	cout<<y.a1<<' '<<y.a2<<endl;
	if(x.a2<y.a2)
	{
		swap(x.a1,y.a1);
		swap(x.a2,y.a2);
	}
	if(x.a2==y.a2)
	{
		l.a1=x.a1+y.a1;
		l.a2=x.a2;
	}
	else
	{
		l.a2=x.a2*y.a2/gcd(x.a2,y.a2);
		l.a1=(l.a2/x.a2)*x.a1+(l.a2/y.a2)*y.a1;
	}
	return yf(l);
}
void dfs(node s,int u)
{
	if(g[u].size()==0)
	{
		ans[u]=Plus(ans[u],s);
		return ;
	}
	node sum=s;
	sum.a2*=g[u].size();
//	cout<<u<<' '<<g[u].size()<<endl;
	sum=yf(sum);
	for(int i=0;i<g[u].size();i++)
	{
		dfs(sum,g[u][i]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int len=read();
		if(len==0)
		{
			b.push_back(i);
			ans[i].a1=0;
			ans[i].a2=1;
		}
		for(int j=1;j<=len;j++)
		{
			int x=read();
			g[i].push_back(x);
			h[x]=true;
		}
	}
	for(int i=1;i<=n;i++)
		if(h[i]==false)
			a.push_back(i);
	for(int i=0;i<m;i++)
	{
		node l;
		l.a1=1;l.a2=1;
		dfs(l,a[i]);
//		cout<<'*';
	}
	for(int i=0;i<b.size();i++)
	{
		write(ans[b[i]].a1);
		putchar(' ');
		write(ans[b[i]].a2);
		putchar('\n');
	}
	return 0;
}
