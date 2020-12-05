#include<bits/stdc++.h>
using namespace std;
int n,m;
long long d[100005];
int a[100005][6];
long long p[100005];
long long q[100005];
vector<long long> v;
typedef long long ll;
inline long long gcd(long long n,long long m)
{
	if(m==0)
	{
		return n;
	}
	else
	{
		return gcd(m,n%m);
	}
}
inline long long lcm(long long n,long long m)
{
	return n/gcd(n,m)*m;
}
inline pair<long long,long long> add(long long a1,long long a2,long long b1,long long b2)
{
	if(a1==0&&a2==0)
	{
		return make_pair(b1,b2);
	}
	if(b1==0&&b2==0)
	{
		return make_pair(a1,a2);
	}
	long long U=0,D=0;
	long long L=lcm(a2,b2);
	U+=L/a2*a1;
	U+=L/b2*b1;
	D=L;
	long long G=gcd(D,U);
	return make_pair(U/G,D/G);
}
inline pair<long long,long long> div(long long a1,long long a2,long long d)
{
	if(a1==0&&a2==0)
	{
		return make_pair(0,0);
	}
	long long G=gcd(a1,d);
	long long U=a1/G;
	long long D=d/G*a2;
	return make_pair(U,D);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	/*
	ll a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	pair<ll,ll>P=add(a1,a2,b1,b2);
	cout<<P.first<<" "<<P.second<<endl;
	*/
	cin>>n>>m;
//	/*
//	cout<<n<<m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
		if(d[i]==0)
		{
			v.push_back(i);
//			cout<<i<<endl;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(d[i]==0)continue;
		for(int j=1;j<=d[i];j++)
		{
			int aa=a[i][j];//cout<<aa<<endl;
			pair<long long,long long> P=add(1,d[i],p[aa],q[aa]);
			p[aa]=P.first;
			q[aa]=P.second;
		}
	}
//	cout<<p[4]<<" "<<q[4]<<endl;
	for(int i=m+1;i<=n;i++)
	{
		if(d[i]==0)continue;
		pair<long long,long long> P=div(p[i],q[i],d[i]);
//		cout<<P.first<<" "<<P.second<<endl;
		for(int j=1;j<=d[i];j++)
		{
			int aa=a[i][j];
			pair<long long,long long> PP=add(P.first,P.second,p[aa],q[aa]);
			p[aa]=PP.first;
			q[aa]=PP.second;
		}
//		cout<<p[4]<<" "<<q[4]<<endl;
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<p[v[i]]<<" "<<q[v[i]]<<endl;
	}
//	*/
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
