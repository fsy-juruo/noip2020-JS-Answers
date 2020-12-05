#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mod=1000000007;
const int inf=2147483647;
int n,k;
int w[500005],c[500005],d[500005];
int tn[11];
int mx[11],mn[11];
ll k_1[100005];
/*
struct zb
{
	ll a[11];
	int k;
	zb()
	{
		for(int i=0;i<=10;i++)
			a[i]=0;
	}
	zb(int K)
	{
		k=K;
		for(int i=0;i<k;i++)
			a[i]=1;
	}
	zb operator+(const zb &b)const
	{
		zb c;
		c.k=max(k,b.k);
		for(int i=0;i<c.k;i++)
		{
			c.a[i]=a[i]+b.a[i];
		}
		return c;
	}
};
*/
//map<zb,int> mp;
void Check()
{
	for(int i=0;i<n;i++)
	{
		tn[c[i]]+=d[i];
		mx[c[i]]=max(mx[c[i]],tn[c[i]]);
		mn[c[i]]=min(mn[c[i]],tn[c[i]]);
	}
}
inline bool ok(int z,int i)
{
	return z<=w[i] && z>0;
}
inline bool stil(int a[])
{
	for(int i=0;i<k;i++)
	{
		if(a[i]+mn[i]<=0 || a[i]+mx[i]>w[i]) return false;
	}
	return true;
}
ll run(int a[])
{
	ll ans=0;
	//if(mp[a[]]>0) ;
	while(stil(a))
	{
		for(int i=0;i<k;i++)
			a[i]+=tn[i];
		ans=(ans+n)%mod;
	}
	for(int i=0;i<n;i++)
	{
		if(!ok(a[c[i]]+d[i],c[i]))
		{
			ans+=i+1;
			break;
		}
		a[c[i]]+=d[i];
	}
	return ans%mod;
}
int solv(int x,int a[])
{
	ll ans=0;
	if(x==k) 
	{
		for(int i=0;i<k;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		//cout<<run(a)<<endl;
		return run(a);
	}
	for(int i=1;i<=w[x];i++)
	{
		a[x]=i;
		ans=(ans+solv(x+1,a))%mod;
	}
	return ans;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
	{
		cin>>c[i]>>d[i];
		c[i]--;
	}
	Check();
	bool cant=1;
	for(int i=0;i<k;i++)
	{
		if(mx[i]-mn[i]>=w[i] || tn[i]!=0)
		{
			cant=0;
			break;
		}
	}
	if(cant) 
	{
		cout<<"-1"<<endl;
		return 0;
	}
	//if(k==1) k1();
	int a[11];
	cout<<solv(0,a)<<endl;
	return 0;
}


