#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int bs[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>bs[i][j];
	if(n==1)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==2)
	{
		int jz[n+1],cx[n+1],tr[m+1],s=1;
		for(int i=1;i<=n;i++)
			jz[i]=bs[i][1];
		for(int i=1;i<=n;i++)
		{
			cx[i]=1;
			while(bs[i][cx[i]]==jz[i])cx[i]++;
		}
		cout<<2*((m-cx[1]+1)+(m-cx[2]+1))<<endl;
		for(int i=m;i>=cx[1];i--)
		{
			tr[s]=bs[1][i];
			cout<<"1 3"<<endl;
			s++;
		}
		for(int i=m;i>=cx[2];i--)
		{
			tr[s]=bs[2][i];
			cout<<"2 3"<<endl;
			s++;
		}
		for(int i=s-1;i>=1;i--)
		{
			if(tr[i]==jz[1])
				cout<<"3 1"<<endl;
			else
				cout<<"3 2"<<endl;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

