#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c[N];
int a[N],b[N];
int  v[N];
int n;
int ans[N];
int read()
{
	int x=0,y=1; char ch=getchar();
	while(ch>'9' || ch<'0') {if(ch=='-') y=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*y;
}
int main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(v,0,sizeof(v));
	memset(c,0,sizeof(c));
    int t;
    t=read();
    while(t--)
    {
    	string s;
    	cin>>s;
    	int n=sizeof(s)+1;
    	int ans=0;
    	for(int i=1;i<=n-2;i++)
    	{
    		if(i%2==1) ans+=n-i-1;
    		if(i%2==0) ans+=(n-i-1)/2;
		}
    	cout<<ans;
	}
	return 0;
}
