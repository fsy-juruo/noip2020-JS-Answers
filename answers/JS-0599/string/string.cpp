#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cishu[100],tot[100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T; string s;
	cin>>T;
	while(T--)
	{
		memset(cishu,0,sizeof(cishu));
		memset(tot,0,sizeof(tot));
		ll ans=0;
		cin>>s;ll len=s.size(); //cout<<len<<endl;
		if(len<=100){
		for(int i=len-1;i>=2;--i)
		{
			ll jishu=0;
			cishu[int(s[i])-96]++;
			if(cishu[int(s[i])-96]%2!=0)jishu++;
			else jishu--;
			for(int j=0;j<=i-1;++j)
			{	
				memset(tot,0,sizeof(tot));
				ans++;
				ll ajishu=0;
			
				tot[int(s[j])-96]++;
				if(tot[int(s[j])-96]%2!=0)ajishu++;
				else ajishu--;
				
				if(ajishu>jishu)ans--;
			}
		}
		cout<<ans;
		continue;}
		else{
		
		for(int i=1;i<=len-2;++i)
		{
			ll l=len-i;ll oushu=(l-1)/2;
			if(i%2==0)
			{
				ans+=(oushu);
			}
			else {
				
				if(i*2<len){
					ans+=(l-1);
				}
				else ans+=(l-1);
			}
		}
		printf("%lld\n",ans);}
	}
	return 0;
}
