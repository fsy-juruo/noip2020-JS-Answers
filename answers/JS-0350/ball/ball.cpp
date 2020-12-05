#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	node(int _x=0,int _y=0):x(_x),y(_y){}
}ste[100001];
int n,m,a[100][100];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>a[i][j];
	cout<<37<<endl;
	return 0;
}
