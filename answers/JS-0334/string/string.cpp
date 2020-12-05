#include <bits/stdc++.h>
#define ll long long
using namespace std;

int l[2000010],r[2000010],num[30],sum[30];
char s[2000010];
unsigned int h[2000010],pw[2000010];

inline unsigned int calc(int l,int r)
{
	return h[r]-(h[l-1]*pw[r-l+1]);
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int n=strlen(s);
		h[0]=0;pw[0]=1;
		for(int i=1;i<=n;i++){
			h[i]=37*h[i-1]+(s[i-1]-'a'+1);
			pw[i]=37*pw[i-1];
		}
		int cnt=0;
		for(int i=1;i<=26;i++) num[i]=0;
		for(int i=1;i<=n;i++){
			num[s[i-1]-'a'+1]++;
			if(num[s[i-1]-'a'+1]&1) cnt++;
			else cnt--;
			l[i]=cnt;
		}
		cnt=0;
		for(int i=1;i<=26;i++) num[i]=0;
		for(int i=n;i>=1;i--){
			num[s[i-1]-'a'+1]++;
			if(num[s[i-1]-'a'+1]&1) cnt++;
			else cnt--;
			r[i]=cnt;
		}
		for(int i=0;i<=26;i++) sum[i]=0;
		ll ans=0ll;
		for(int i=2;i<=n-1;i++){
			for(int j=l[i-1];j<=26;j++) sum[j]++;
			int now=i;
			unsigned int val=calc(1,i);
			ans+=(ll)sum[r[now+1]];
			while(now+i<=n-1){
				if(calc(now+1,now+i)==val){
					now+=i;
					ans+=(ll)sum[r[now+1]];
				}
				else break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
