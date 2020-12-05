#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{
	if(y==0ll)return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	return x*y/gcd(x,y);
}
pair<ll,ll>p(ll a,ll b)
{
	ll num=gcd(a,b);
	a/=num;
	b/=num;
	return make_pair(a,b);
}
pair<ll,ll>add(ll a1,ll b1,ll a2,ll b2)
{
	ll num=lcm(b1,b2);
	a1*=(num/b1);
	a2*=(num/b2);
	return p(a1+a2,num);
}
int n,m;
vector<int>v[100100];
ll s[100100];
ll cnt1[100100],cnt2[100100];
void dfs(int x)
{
	if(s[x]==0ll)return;
	pair<ll,ll>p1=p(cnt1[x],cnt2[x]*s[x]);
	for(int i=0;i<v[x].size();i++)
	{
		pair<ll,ll>p2=add(p1.first,p1.second,cnt1[v[x][i]],cnt2[v[x][i]]);
		cnt1[v[x][i]]=p2.first;
		cnt2[v[x][i]]=p2.second;
		dfs(v[x][i]);
	}
	cnt1[x]=0ll;
	cnt2[x]=1ll;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i];j++)
		{
			int u;
			cin>>u;
			u--;
			v[i].push_back(u);
		 } 
	}
	for(int i=0;i<n;i++)
	{
		cnt1[i]=0ll;
		cnt2[i]=1ll;
	}
	for(int i=0;i<m;i++)
	{
		cnt1[i]=1ll;
		dfs(i);
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==0ll)
		{
			cout<<cnt1[i]<<" "<<cnt2[i]<<endl; 
		}
	}
	return 0;
}



