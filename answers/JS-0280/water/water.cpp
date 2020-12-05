#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100005;
int n,m,in[maxn];
vector<int> v[maxn];
ll res[maxn][2];//0: fenzi 1:fenmu 
ll gcd(ll x,ll y)
{
	if(x>y) swap(x,y);
	if(y%x==0) return x;
	return gcd(y%x,x);
}
void cal(int x,int fa,int num)
{
//	if(num==0) cout<<"here"<<endl;
	ll a=res[x][1],b=res[x][0],c=1ll*res[fa][1]*num,d=res[fa][0];
	if(a==0&&b==0)
	{
		int fenmu=c;
		int fenzi=d;
	//	cout<<fenzi<<" "<<fenmu<<endl;
		int tmp=gcd(fenzi,fenmu);fenzi/=tmp;fenmu/=tmp;
		res[x][1]=fenmu;res[x][0]=fenzi;
	//	printf("x=%d fa=%d num=%d %d %d\n",x,fa,num,res[x][0],res[x][1]);
		return;
	}
	ll fenmu=a*c/gcd(a,c);
	ll fenzi=fenmu/a*b+fenmu/c*d;
	ll tmp=gcd(fenzi,fenmu);fenzi/=tmp;fenmu/=tmp;
	res[x][1]=fenmu;res[x][0]=fenzi;
//	printf("x=%d fa=%d %d %d\n",x,fa,res[x][0],res[x][1]);
}
queue<int> q;
void bfs(int s)
{
	q.push(s);
	while(!q.empty())
	{
	//	cout<<"here"<<endl;
		int x=q.front();q.pop();
	//	cout<<x<<endl;
		for(int i=0;i<v[x].size();i++)
		{
			cal(v[x][i],x,v[x].size());
			in[v[x][i]]--;
			if(in[v[x][i]]==0) q.push(v[x][i]);
		}
	}
}
void work1()
{
	
	for(int i=1;i<=m;i++)
	{
		bfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i].size())
		{
			printf("%lld %lld\n",res[i][0],res[i][1]);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) res[i][0]=res[i][1]=1;
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x;scanf("%d",&x);
			v[i].push_back(x);in[x]++;
		}
	}
	if(n<=100000) work1();
	return 0;
}
/*
5 2
1 3
1 3
2 4 5
0
0

4 1
2 2 3
1 4
1 4
0
*/
