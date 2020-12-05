#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define fi first
#define se second
#define x0 xasdsajldk
#define x1 xklasjdklsa
#define y0 ysjaldksla
#define y1 yaklsdnwad
const int INF=0x3f3f3f3f,N=1e5+5,K=10+5;
int n,k;
pll bu[N];
ll s[N][K];
ll mx[K];
ll mn[K];
ll w[K];
ll a[K],b[K];
void slove1()
{
	int i,j;
	for(i=1;i<=k;i++)
		a[i]=1;
	//a[k]=0;
	ll ans=0;
	while(!a[0])
	{
		int j=k;
		while(a[j]==w[j])
		{
			a[j]=1;
			j--;
		}
		a[j]++;
		
//		for(i=1;i<=k;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		
		for(i=1;i<=k;i++)
			b[i]=a[i];
		
		while(1)
		{
			bool f1;
			for(j=1;j<=n;j++)
			{
				ans++;
				f1=1;
				b[bu[j].fi]+=bu[j].se;
				if(b[bu[j].fi]<1||b[bu[j].fi]>w[bu[j].fi])
				{
					f1=0;
					break;
				}					
				
			}
			if(!f1)
			{
				break;
			}
			bool f=1;
			for(i=1;i<=k;i++)
			{
				if(b[i]!=a[i]) f=0;
			}
			if(f)
			{
				cout<<-1<<endl;
				return;
			}
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i,j;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&bu[i].fi,&bu[i].se);
		for(j=1;j<=k;j++)
		{
			if(j==bu[i].fi)
			{
				s[i][j]=s[i-1][j]+bu[i].se;
			}
			else
				s[i][j]=s[i-1][j];
		}
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			mx[j]=max(mx[j],s[i][j]);
			mn[j]=min(mn[j],s[i][j]);
		}
	}
	
//	for(i=1;i<=k;i++)
//	{
//		cout<<mx[i]<<" ";
//	}
//	cout<<endl;
//	
//	for(i=1;i<=k;i++)
//	{
//		cout<<mn[i]<<" ";
//	}
//	cout<<endl;
//	cout<<endl;
	if(n<=100)
	{
		slove1();
	}
	return 0;

}
/*
4 2
5 5
1 1
2 1
2 -1
1 -1
*/
