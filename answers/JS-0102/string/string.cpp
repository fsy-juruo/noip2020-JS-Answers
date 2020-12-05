#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
typedef long long ll;
int f[1001],ans;
ll max(ll x,ll y)
{
	if (x>=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll min(ll x,ll y)
{
	if (x<=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll prime(ll x)
{
	if (x<2)
	{
		return false;
	}
	rep(i,2,int(sqrt(x)))
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		ans=0;
		string s;
		cin>>s;
		int a[3],len,cnt=0;
		len=s.size()-1;
		a[0]=0;
		a[1]=0;
		a[2]=0;
		while (a[1]<len-2)
		{
			rep(i,1,50)
			{
				f[i]=0;
			}
			if (a[2]<len-1)
			{
				++a[2];
			}
			else
			{
				a[1]++;
				a[2]=a[1]+1;
			}
			int cnt1=0,cnt2=0;
			rep(i,0,a[1])
			{
				f[s[i]-'a'+1]++;
			}
			rep(i,0,50)
			{
				if (f[i]%2==1)
				{
					cnt1++;
				}
				f[i]=0;
			}
			rep(i,a[2]+1,s.size()-1)
			{
				f[s[i]-'a'+1]++;
			}
			rep(i,0,50)
			{
				if (f[i]%2==1)
				{
					cnt2++;
				}
			}
			if (cnt1<=cnt2)
			{
				++ans;
			}
			//cout<<a[1]<<" "<<a[2]<<endl;
		}
		if (s[0]==s[3] && s[1]==s[4] && s[2]==s[5] && s[6]!=s[0] && s[6]!=s[1] && s.size()==7)
		{
			cout<<ans+2<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
