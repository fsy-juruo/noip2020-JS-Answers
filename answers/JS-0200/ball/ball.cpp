#include <bits/stdc++.h>
using namespace std;
long long n,m,m1[25],m2[25],cnt,ans,tk,cnt2;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if(n==2)
	{
	for(int i=0;i<m;i++)
	cin>>m1[i];
	for(int i=0;i<m;i++)
	{
		cin>>m2[i];
		if(m2[i]==m1[m-1])
		{
			ans+=(i-cnt)*2+2;
			cnt++;
		}
	}
	ans+=m;
	cout<<ans<<endl;
	tk=m1[m-1];
	cout<<"1 3"<<endl;
	while(cnt>0)
	for(int i=m-1;i>=0;i--)
	{
		if(m2[i]!=0&&m2[i]!=tk)
		{
			cnt2++;
			cout<<"2 3"<<endl;
		}
		else if(m2[i]==tk)
		{
			cout<<"2 1"<<endl;
			while(cnt2>0)
			{
				cout<<"3 2"<<endl;
				cnt2--;
			}
			cout<<"1 3"<<endl;
			cnt--;
		}
	}
	for(int i=m-2;i>=0;i--)
	{
		if(m1[i]==tk)
		cout<<"1 3"<<endl;
		else
		cout<<"1 2"<<endl;
	}
}
else
cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
