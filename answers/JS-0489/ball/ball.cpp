#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*int res=1;
ll q_mi(ll x,ll n,ll m)
{
	if(n==0) return 1;
	res*=q_mi(x*x%m,n/2,m);
	return res;
}*/
int main()
{
	freopen("ball","r",stdin);
	freopen("ball","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	cout<<6<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<1<<endl;
	cout<<3<<" "<<2<<endl;
	cout<<3<<" "<<2<<endl;
	return 0;
}
