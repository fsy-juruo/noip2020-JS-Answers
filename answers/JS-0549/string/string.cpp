#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
string s;
ll len;
ll ans;
void ftry(ll y,ll n)
{
	for(ll i=1; i<=n-1; i++)
	{
		for(ll j=0; j<=y; j++)
		{
			if(s[i*(y+1)+j]!=s[j])
			{
				return;
			}
		}
	}

	//¼ÆËãF(C)
	ll mc[2000];
	memset(mc,0,sizeof(mc));
	ll mccnt=0;
	for(ll i=y+1; i<len; i++)
	{
		mc[(ll)s[i]]++;
	}

	for(ll i=0; i<=200; i++)
	{
		if(mc[i]%2==1)
		{
			mccnt++;
		}
	}
	ll mx[2000];
	memset(mx,0,sizeof(mx));
	ll mxcnt=0;
	for(ll x=0; x<y; x++)
	{
		mx[(ll)s[x]]++;
		if(mx[(ll)s[x]]%2==0)
		{
			mxcnt--;
		}
		else
		{
			mxcnt++;
		}
		if(mxcnt<=mccnt)
		{
			ans++;
			//cout<<ans<<" "<<x<<" "<<y<<" "<<n<<endl;
		}
	}
}
long long solve()
{
	for(ll y=1; y<=len-2; y++)
	{
		for(ll n=1; n<=(len-1)/(y+1); n++)
		{
			ftry(y,n);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(ll i=1; i<=T; i++)
	{
		cin>>s;
		len=s.size();
		ans=0;
		cout<<solve()<<endl;
	}
	return 0;
}
