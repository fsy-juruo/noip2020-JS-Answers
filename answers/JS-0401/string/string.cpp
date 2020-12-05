#include<bits/stdc++.h>
using namespace std;
const int p=99991;
int T,vis[35],n,summ[10007],ans,base[10007],h[10007];
int ans1,ans2;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
	    cin>>s;
		ans=0;
		n=s.size();
		for(int i=n;i>=1;i--)
		s[i]=s[i-1];
		base[0]=1;
		for(int i=1;i<=n;i++)
		base[i]=(base[i-1]*97)%p;
		for(int i=1;i<=n;i++)
		{
			h[i]=(h[i-1]*97)%p+s[i];
			h[i]%=p;
		}
		for(int i=1;i<=n-1;i++)
		 for(int j=1;j<=(n-1)/i;j++)
		 {
		 	if((h[j*i]+p-(h[j*i-i]*base[i])%p)%p!=h[i]) continue;
		 	for(int k=1;k<i;k++)
		 	{
		 		ans1=0;ans2=0;
		 		memset(vis,0,sizeof(vis));
		 		for(int l=1;l<=k;l++)
		 		vis[s[l]-'a'+1]++;
		 		for(int l=1;l<=26;l++)
		 		if(vis[l]&1)
		 		ans1++;
		 		memset(vis,0,sizeof(vis));
		 		for(int l=i*j+1;l<=n;l++)
		 		vis[s[l]-'a'+1]++;
		 		for(int v=1;v<=26;v++)
		 		if(vis[v]&1)
		 		ans2++;
		 		if(ans1<=ans2)
		 		ans++;
			 }
		 }
		 cout<<ans<<endl;
	}
	return 0;
}
