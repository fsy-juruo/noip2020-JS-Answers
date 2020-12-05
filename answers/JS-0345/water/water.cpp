//t1 water
//by feng jiu li
#include<bits/stdc++.h>
using namespace std;
long long n,m,d[100007][7],fenzi[100007],fenmu[100007],k[100007];
long long gcd(long long x,long long y)
{
	if (x%y==0) return y;
	else return gcd(y,x%y);
}
int main()
{
	//zuo ti bu yi
	//gei dian fen ba
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		{
			fenmu[i]=1;
			scanf("%lld",&k[i]);
			for (int j=1;j<=k[i];++j)
				{
					scanf("%lld",&d[i][j]);
				}
		}
	for (int i=1;i<=m;++i) fenzi[i]=1;
	for (int i=1;i<=n;++i)
		{
			long long fz=fenzi[i],fm=fenmu[i]*k[i];
			//cout<<endl<<fz<<"/"<<fm<<endl<<endl;
			for (int j=1;j<=k[i];++j)
				{				
					//cout<<fenzi[d[i][j]]<<"/"<<fenmu[d[i][j]]<<endl;
					fenzi[d[i][j]]=fenzi[d[i][j]]*(fm/gcd(fm,fenmu[d[i][j]]))+fz*(fenmu[d[i][j]]/gcd(fm,fenmu[d[i][j]]));
					fenmu[d[i][j]]=fenmu[d[i][j]]*fm/gcd(fm,fenmu[d[i][j]]);
					fenzi[j]/=gcd(fenzi[d[i][j]],fenmu[d[i][j]]);
					fenmu[j]/=gcd(fenzi[d[i][j]],fenmu[d[i][j]]);
					//cout<<fenzi[d[i][j]]<<"/"<<fenmu[d[i][j]]<<endl;
				}
		}
	for (int i=1;i<=n;++i)
		{
			if (k[i]==0)
				{
					printf("%lld %lld\n",fenzi[i]/gcd(fenzi[i],fenmu[i]),fenmu[i]/gcd(fenzi[i],fenmu[i]));
				}
		}
	return 0;
}
