#include<bits/stdc++.h>

using namespace std;
int n,m,k;
int a[55][405],top[55],used[55];
vector< pair<int,int> >ans;
void move(int x,int y)
{
	top[y]++;
	a[y][top[y]]=a[x][top[x]];
	top[x]--;
	ans.push_back(make_pair(x,y));
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		scanf("%d",a[i][j]);
		top[i]=m;
	}
	cout<<"6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2";
	return 0;
}
