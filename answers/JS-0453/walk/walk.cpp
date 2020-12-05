#include<bits/stdc++.h>
using namespace std;
int st[101],n,k,w[101],loc[101000],ste[100010],f[100010],pl[1010];
long long sec=1,tot;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	pl[1]=1;
	for (int i=1;i<=k;i++)
	{
		cin>>w[i];
		sec*=w[i];
		pl[i+1]=sec;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>loc[i]>>ste[i];
	}
	for (int i=1;i<=sec;i++)
	{
		int lo=i,f=0;
		while (f==0)
		for (int j=1;j<=n;j++)
		{
			tot++;
			lo+=pl[loc[j]]*ste[j];
			if (lo>sec||lo<1)
			{
				f=1;
				break;
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
