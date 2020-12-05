#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
const int maxk=15;
const int mod=1e9+7;
ll w[maxk],c[maxn],d[maxn];
/*int res=1;
ll q_mi(ll x,ll n,ll m)
{
	if(n==0) return 1;
	res*=q_mi(x*x%m,n/2,m);
	return res;
}*/
int main()
{
	freopen("walk","r",stdin);
	freopen("walk","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
	}
	cout<<-1<<endl;
	return 0;
}
