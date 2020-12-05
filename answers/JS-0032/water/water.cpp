#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
const int M=1e3+5;
int d[N],a[N][15],sum[1025][1025],num[N];
int n,m;
struct hh
{
	int z;
	int m;
};
hh ans;
int gcd(int n,int m) 
{
	int r;
	while(m!=0) 
	{
		r=n%m;
		n=m;
		m=r;
	}
	return n;
}
hh add(hh a,hh b) 
{
	int f=a.m*b.m/gcd(a.m,b.m);
	int abei=f/a.m;
	int bbei=f/b.m;
	a.m=f;
	a.z=a.z*abei+b.z*bbei;
//	cout<<a.z<<" "<<a.m<<endl;
	return a;
}
hh dfs(int i)
{
	hh s;
	s.z=0;
	s.m=1;
	if(i<=m) 
	{
		s.m=d[1];
		s.z=1;
		return s;
	}
	for(long long k=1;k<=num[i];k++) 
	{
//		cout<<sum[i][k]<<" ";
		s=add(s,dfs(sum[i][k]));	
	}
	if(d[i]!=0) s.m*=d[i];
	return s;	
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>d[i];
		for(long long j=1;j<=d[i];j++) 
		{
			cin>>a[i][j];
			sum[a[i][j]][++num[a[i][j]]]=i;
		}
	}
	for(long long i=1;i<=n;i++) 
	{
		if(d[i]==0) 
		{
			ans.z =0,ans.m=1;
			hh lans=dfs(i);
			long long zui=gcd(lans.z,lans.m);
			cout<<lans.z/zui<<" "<<lans.m/zui<<endl;
		}
	}
	return 0;
}

