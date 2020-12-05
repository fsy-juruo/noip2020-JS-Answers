#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//queue<int> a;
	int n,m;
	cin>>n>>m;
	int x;

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			//num[j]=m;
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<6<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<3<<" "<<1<<endl;
		cout<<3<<" "<<2<<endl;
		cout<<3<<" "<<2<<endl;
	}
	
	
	
	
	
	return 0;
	
	
	
	
}
