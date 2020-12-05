#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
const long long inf=0x3f3f3f3f;
const long long mod=1e9+7;
long long w[maxn],c[maxn],d[maxn],b[maxn],tw[maxn],ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=k;i++)
		cin>>w[i];
	for(long long i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	for(long long i=1;i<=k;i++)
		b[i]=1;
	while(b[0]==0)
	{
//		for(long long i=1;i<=k;i++)
//			cout<<b[i]<<" ";
//		cout<<endl;
		for(long long i=1;i<=k;i++)
			tw[i]=b[i];
		long long flag=0;
		while(1)
		{
			for(long long i=1;i<=n;i++)
			{
				tw[c[i]]+=d[i];
				ans++;
				if(ans>=mod)
					ans-=mod;
				if(tw[c[i]]>w[c[i]]||tw[c[i]]==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
			int gege=0;
			for(int i=1;i<=k;i++)
			{
				if(tw[i]!=b[i])
				{
					gege=1;
					break;
				}
			}
			if(gege==0)
			{
				cout<<"-1"<<"\n";
				return 0;
			}
//			for(long long i=1;i<=k;i++)
//				cout<<tw[i]<<" ";
//			cout<<endl;
		}
		b[k]++;
		for(long long i=k;i>=1;i--)
		{
			if(b[i]>w[i])
			{
				b[i]=1;
				b[i-1]++;
			}
		}
	}
	if(ans>=mod)
		ans-=mod;
	cout<<ans<<endl;
	return 0;
}
/*
3 2
3 3
1 1 
2 -1
1 1

21
*/
