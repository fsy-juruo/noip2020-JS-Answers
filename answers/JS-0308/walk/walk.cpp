#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
using namespace std;
ll n,k,w[12],a[6];
vector<pair<ll,ll> > vt;
ll solve(ll a1,ll a2,ll a3,ll a4,ll a5)
{
	a[0]=a1;
	a[1]=a2;
	a[2]=a3;
	a[3]=a4;
	a[4]=a5;
	ll i,j,ret=0;
	while(true)
	{
		for(i=0;i<n;i++)
		{
			ret++;
			a[vt[i].F]+=vt[i].S;
			for(j=0;j<k;j++)
			{
				if(a[j]>w[j]||a[j]<=0)
				{
					return ret;
				}
			}
		}
		if(a1==a[0]&&a2==a[1]&&a3==a[2]&&a4==a[3]&&a5==a[4])
		{
			puts("-1");
			exit(0);
		}
	}
	return ret;
}
void subtask2()
{
	ll a1,a2,a3,a4,a5,ans=0;
	for(a1=1;a1<=w[0];a1++)
	{
		if(k==1)
		{
			ans+=solve(a1,0,0,0,0);
			continue;
		}
		for(a2=1;a2<=w[1];a2++)
		{
			if(k==2)
			{
				ans+=solve(a1,a2,0,0,0);
				continue;
			}
			for(a3=1;a3<=w[2];a3++)
			{
				if(k==3)
				{
					ans+=solve(a1,a2,a3,0,0);
					continue;
				}
				for(a4=1;a4<=w[3];a4++)
				{
					if(k==4)
					{
						ans+=solve(a1,a2,a3,a4,0);
						continue;
					}
					for(a5=1;a5<=w[4];a5++)
					{
						ans+=solve(a1,a2,a3,a4,a5);
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ll i,c,d;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<k;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&c,&d);
		c--;
		vt.push_back(make_pair(c,d));
	}
	subtask2();
	return 0;
}
/*
1. file name
2. long long & int
3. array size
4. special cases
5. border
6. initialization
7. max&min value
8. big const->TLE
9. strange errors (/0,int->long long,iterator,unsigned long long...)
10. typo(n&m,=&-...)
*/
