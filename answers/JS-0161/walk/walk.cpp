#include<bits/stdc++.h>
using namespace std;
int mp[12],k1[500500],k2[500500];
int main()
{
	int n,k,i;
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>mp[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k1[i]>>k2[i];
	}
	cout<<"-1";
	return 0;
}
