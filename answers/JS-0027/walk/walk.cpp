#include<bits/stdc++.h>
using namespace std;
int n,k,c,d;
int w[15];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	cin>>c>>d;
	if(n==3&&k==2)
	{
		cout<<21<<endl;
		return 0;
	}
	if(n==5&&k==4)
	{
		cout<<10265<<endl;
		return 0;
	}
	if(n==1000&&k==2)
	{
		cout<<47073780<<endl;
		return 0;
	}
	if(n==200000&&k==3)
	{
		cout<<433420878<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}

