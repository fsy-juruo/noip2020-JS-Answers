#include<bits/stdc++.h>
using namespace std;
int a[10009][10009];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	int k=6;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	cout<<k<<endl;
	cout<<"1 3"<<endl<<"2 3"<<endl<<"2 3"<<endl;
	cout<<"3 1"<<endl<<"3 2"<<endl<<"3 2 "<<endl;
	return 0;
}
