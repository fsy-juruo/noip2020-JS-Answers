#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main ( )
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s.length()%2!=0)
		{
			cout<<((s.length()-3)/2*3+1)*((s.length()-1)/2)/2+1;
		}
		else{
			cout<<((s.length()-4)/2*3+2)*((s.length()-2)/2)/2+1;
		}            
	}
}
