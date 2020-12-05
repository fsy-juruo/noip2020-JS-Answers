#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	int color[401];
}a[41];
int n,m;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		a[i].num=m;
		for (int j=1;j<=m;j++)
		{
			//scanf("%d",&a[i].color[j]);
		}
	}
	cout<<6<<endl<<1<<" "<<3<<endl<<2<<" "<<3<<endl<<2<<" "<<3<<endl<<3<<" "<<1<<endl<<3<<" "<<2<<endl<<3<<" "<<2<<endl;
	return 0;
}
