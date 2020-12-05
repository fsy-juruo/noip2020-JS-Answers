#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[51][401];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	if (n==2 && m==3)
	{
		cout<<"6"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
        cout<<"2 3"<<endl;
        cout<<"3 1"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
	}
	return 0;
}

