#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return flag?x:~(x-1);
}
void fre()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}
int n,m,cnt,head[100001],in[100001],d[100001];
pair<int,int> val[100001];
struct node{
	int to,next;
} edge[500001];
queue<int> q;
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
pair<int,int> jia(pair<int,int> x,pair<int,int> y)
{
	int g=x.second*y.second/gcd(x.second,y.second);
//	cout<<x.second<<" "<<y.second<<endl;
//	cout<<"g "<<g<<endl;
	int fir=x.first*(g/x.second);
	fir+=y.first*(g/y.second);
//	cout<<fir<<endl;
	return make_pair(fir,g);
}
signed main()
{
	fre();
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
		for(int l=1;l<=d[i];l++)
		{
			int x=read();
			add(i,x);
			in[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(i<=m)
		{
			val[i]=make_pair(1,1);
			q.push(i);
		}
		else
			val[i]=make_pair(0,1);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
//		cout<<"f "<<f<<endl;
		if(d[f]==0)
			continue;
		pair<int,int> ff;
		int g=gcd(val[f].first,val[f].second);
		ff.first=val[f].first/g;
		ff.second=val[f].second/g*d[f];
		val[f]=make_pair(0,0);
		for(int i=head[f];i;i=edge[i].next)
		{
			val[edge[i].to]=jia(val[edge[i].to],ff);
			in[edge[i].to]--;
//			cout<<val[edge[i].to].first<<" "<<val[edge[i].to].second<<endl;
			if(in[edge[i].to]==0)
				q.push(edge[i].to);
		}
	}
//	cout<<"ans"<<endl;
	for(int i=1;i<=n;i++)
		if(val[i].second!=0)
		{
			int g=gcd(val[i].first,val[i].second);
			cout<<val[i].first/g<<" "<<val[i].second/g<<endl;
		}
	return 0;
}
