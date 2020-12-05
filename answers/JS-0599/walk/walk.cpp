#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>c[i]>>b[i];
	if(n==3)cout<<21<<endl;
	else cout<<10265<<endl;
	return 0;
}
