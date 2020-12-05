#include<bits/stdc++.h>
using namespace std;
int n,len,ans;
string s;
void dfs(int k)
{
	for(int i=2;i*2<=k;i++)
	{
		if(k%i)continue;
		for(int j=1;j<i;j++)
		{
			if(j%2<=(len-k)%2)ans++;
		}
	}
	for(int j=1;j<k;j++)
	{
		if(j%2<=(len-k)%2)ans++;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		len=s.size();
		for(int i=2;i<len;i++)
		{
			dfs(i);
		}
	}
	printf("%d",ans);
	return 0;
}

