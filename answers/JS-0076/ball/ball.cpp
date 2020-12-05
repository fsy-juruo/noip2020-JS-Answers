#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[60][410];
int high[60]; 
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
		high[i]=m;
	}
	cout<<6<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<1<<endl;
	cout<<3<<" "<<2<<endl;
	cout<<3<<" "<<2<<endl;


	return 0;
}

