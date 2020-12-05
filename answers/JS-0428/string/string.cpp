#include<bits/stdc++.h>
using namespace std;
const int N=100010;
string s[N];
long long f(int n,int m)
{
	if(n<m) return 1;
	else if(m==1) return 1;
	else if(n==1)return m;
	return f(n-1,m-1)+m*f(n-1,m);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cout<<f(s[i].size(),3)<<endl;
	return 0;
}
