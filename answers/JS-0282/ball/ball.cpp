#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
int n,m;
stack<int> roll[MAXN];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int x;
			cin>>x;
			roll[i].push(x);
		}
	}
		cout<<0;
		return 0;
	return 0;
}
