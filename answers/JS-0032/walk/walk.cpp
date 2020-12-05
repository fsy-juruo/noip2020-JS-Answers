#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long w[N],c[N],d[N],a[N],xa[N];
const long long mo=1e9+7;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=k;i++) cin>>w[i];
	for(long long i=1;i<=n;i++) cin>>c[i]>>d[i];
		long long dep=0,sum=1;
		for(long long i=1;i<=k;i++) sum*=w[i];
		for(long long i=1;i<=k;i++) a[i]=1;
//		cout<<sum<<endl;
		if(sum>1e8) 
		{
			cout<<-1<<endl;
			return 0;
		}
		for(long long i=1;i<=sum;i++)
		{
			for(long long j=1;j<=k;j++) xa[j]=a[j];
//			for(long long j=1;j<=k;j++) cout<<xa[j]<<" ";
//			cout<<endl;
			long long wei=1,num=0;
			while(1) 
			{
				dep++;
				dep=dep%mo;
				xa[c[wei]]+=d[wei];
				if(xa[c[wei]]>w[c[wei]]||xa[c[wei]]<1) break;
				wei++;
				if(wei>n) wei=1;
				num++;
				if(num>1e8+5) 
				{
					cout<<-1<<endl;
					return 0;
				}
			}
//			cout<<dep<<endl;
			long long j=1;
			a[j]++;
			while(a[j]>w[j]) 
			{
				a[j]=1;
				j++;
				a[j]++;
			} 
		}
		cout<<dep<<endl;
	return 0;
}

