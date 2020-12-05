#include<bits/stdc++.h>
using namespace std;
int T;
string s;
long long n,ans;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--)
	{
		cin>>s;
		n=s.size(),ans=0;
		if(n%2==0)
		    for(long long i=1;i<=n-2;i++)
			    i%2==0?ans+=n-i-1:ans+=(n-i-1)/2;
		else
		    for(long long i=1;i<=n-2;i++)
		        i%2==0?ans+=(n-i-1)/2:ans+=n-i-1;
		cout<<ans<<endl;
	}
	return 0;
}
