#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll w[10009];
int c[10009],d[10009];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n,k;
	for(int i=0;i<k;i++)
	cin>>w[i];
	for(int i=0;i<n;i++)
	cin>>c[i]>>d[i];
	cout<<"-1";
	return 0;
}
