#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> a[3];
int a1[1000],a2[1000];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int b;
			cin>>b;
			a[i].push(b);
		}
	int ans=0,k=0;
	for(int i=0;i<m;i++)
	{
		if(a[1].top()==2)
		{
			a1[ans]=2;
			a2[ans]=3;
			a[1].pop();
			a[2].push(2);
		}
		else
		{
			a1[ans]=2;
			a2[ans]=1;
			a[1].pop();
			a[0].push(1);
			k++;
		}
		ans++;
	}
	for(int i=0;i<m+k;i++)
	{
		if(a[0].top()==2)
		{
			a1[ans]=1;
			a2[ans]=3;
			a[0].pop();
			a[2].push(2);
		}
		else
		{
			a1[ans]=1;
			a2[ans]=2;
			a[0].pop();
			a[1].push(1);
		}
		ans++;
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
		cout<<a1[i]<<' '<<a2[i]<<endl;
 	return 0;
}

