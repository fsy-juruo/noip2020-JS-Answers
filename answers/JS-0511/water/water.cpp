#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
};
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
node Plus(node x,node y)
{
	node ans;
	ans.b=x.b*y.b;
	ans.a=x.a*y.b+x.b*y.a;
	long long GCD=gcd(ans.b,ans.a);
	ans.b/=GCD,ans.a/=GCD;
	return ans;
}
node multi(node x,node y)
{
	node ans;
	ans.a=x.a*y.a;
	ans.b=x.b*y.b;
	long long GCD=gcd(ans.b,ans.a);
	ans.b/=GCD,ans.a/=GCD;
	return ans;
}
int n,m;bool v[100005];
vector<int> a[100005];
node val[100005];
int rd[100005];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;//cout<<gcd(n,m);
	for(int i=1;i<=n;i++)
	{val[i].a=0;val[i].b=1;
		int s,t;scanf("%d",&s);
		for(int j=0;j<s;j++)
		{
			scanf("%d",&t);
			a[i].push_back(t);rd[t]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=m;i++){
		q.push(i);val[i].a=1;}
	while(!q.empty())
	{
		int f=q.front();
		q.pop();if(a[f].size()==0)continue;
		node xx;xx.a=1;xx.b=a[f].size();
		xx=multi(xx,val[f]);
		for(int i=0;i<a[f].size();i++)
		{
			int u=a[f][i];//if(u==10)printf("%d{%lld/%lld+%lld/%lld=%lld/%lld\n",f,val[u].a,val[u].b,xx.a,xx.b,Plus(val[u],xx).a,Plus(val[u],xx).b);
			val[u]=Plus(val[u],xx);
			rd[u]--;
			//if(v[u])continue;v[u]=1;
			if(rd[u]==0)
			q.push(u);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].size()==0)
		{
			printf("%lld %lld\n",val[i].a,val[i].b);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
