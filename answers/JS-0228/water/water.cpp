#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main ( ){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	int c[n];
	int fenzi[n];
	int fenmu[n];
	fenzi[1]=1;
	fenmu[1]=1;
	for(int i=2;i<=n;i++)
	{
		fenzi[i]=0;
		fenmu[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int q;
		scanf("%lld",&q);
		if(q!=0){
			int b[q];
			for(int j=1;j<=q;j++)
			{
				cin>>b[j];
				fenzi[b[j]]*=q*fenmu[i];
				fenzi[b[j]]+=fenmu[b[j]]*fenzi[i];
				fenmu[b[j]]*=q*fenmu[i];
			}
		}
		else{
			c[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1){
			for(int j=2;j<=17;j++)
			{
				int f=0;
				while(f==0){
					if(fenzi[i]%j==0&&fenmu[i]%j==0){fenzi[i]=fenzi[i]/j;fenmu[i]=fenmu[i]/j;}
					else f=1;
				}    
			}
		printf("%lld %lld\n",fenzi[i],fenmu[i]);
		}
	}
	return 0;
}
