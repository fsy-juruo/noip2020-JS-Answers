#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define int long long

int n,k,w[15],c[MAXN],d[MAXN];
int start[15];
int cur[15];
const int mod=1e9+7;
int sum[15];

int calc_force()
{
	int ret=0;
	while (1)
	{
		for (int i=1;i<=n;i++)
		{
			cur[c[i]]+=d[i];
			ret=(ret+1)%mod;
		//	cout<<ret<<endl;
			if (cur[c[i]]>w[c[i]]||cur[c[i]]<=0) return ret;
		//	for (int j=1;j<=k;j++) cout<<cur[k]<<' ';
		//	cout<<endl;
		}
	}
	return 19260817;
}

void force()
{
	int ans=0;
	for (int i=1;i<=k;i++) start[i]=1;
	while (1) 
	{
		for (int j=1;j<=k;j++) cur[j]=start[j];
		ans=(ans+calc_force())%mod;
	//	cout<<calc_force()<<endl;
		start[1]++;
		int ttt=1;
		while (ttt<=k&&start[ttt]>w[ttt]) {start[ttt]=1;start[++ttt]++;}
	//	for (int j=1;j<=k;j++) cout<<start[j]<<' ';
	//	cout<<endl;
		if (ttt>k) break;
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>w[i];
	bool flag=true;
	for (int i=1;i<=n;i++) {cin>>c[i]>>d[i];sum[c[i]]+=d[i];if (sum[c[i]]>=w[c[i]]||sum[c[i]]<=(-w[c[i]])) flag=false;}
	for (int i=1;i<=k;i++) if (sum[i]!=0) flag=false;
	if (flag){cout<<-1<<endl;return 0;}
	if (n<=100) force();
	return 0;
}

