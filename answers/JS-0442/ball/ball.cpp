#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[25];
int b[25];
int step1[100005],step2[100005];
int ans;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	while(1)
	{
		bool flag=false;
		for(int i=1;i<=m;i++)
			if(a[i]!=1)
			{
				flag=true;
				break;
			}
		if(!flag)
		{
			cout<<ans<<endl;
			for(int i=1;i<=ans;i++)
				cout<<step1[i]<<" "<<step2[i]<<endl;
			return 0;
		}
		int s1=0,s2=0;
		bool flag2=false;
		for(int i=m;i>=1;i--)
		{
			if(a[i]!=2) break;
			ans++;
			step1[ans]=1;
			step2[ans]=3;
			a[i]=0;
			s1++;
		}
		for(int i=m;i>=1;i--)
		{
			if(b[i]!=2) break;
			ans++;
			step1[ans]=2;
			step2[ans]=3;
			b[i]=0;
			s2++;
		}
		int t1=m-s1;
		int t2=m-s2;
		if(flag2==false)
		{
			for(int i=t2;i>=1;i--)
			{
				if(b[i]!=1||t1==m) break;
				ans++;
				step1[ans]=2;
				step2[ans]=1;
				t1++;
				t2--;
				a[t1]=1;
				b[i]=0;
			}
			flag2=true;
		}
		else
		{
			for(int i=t1;i>=1;i--)
			{
				if(a[i]!=1||t2==m) break;
				ans++;
				step1[ans]=1;
				step2[ans]=2;
				t2++;
				t1--;
				b[t2]=1;
				a[i]=0;
			}
			flag2=false;
		}
		for(int i=t1+1;i<=m;i++)
		{
			ans++;
			step1[ans]=3;
			step2[ans]=1;
			a[i]=2;
		}
		for(int i=t2+1;i<=m;i++)
		{
			ans++;
			step1[ans]=3;
			step2[ans]=2;
			b[i]=2;
		}
	}
	return 0;
}
