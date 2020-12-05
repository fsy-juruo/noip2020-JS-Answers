#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<20)+10;
const unsigned long long base=191;
int T,fr[maxn],en[maxn],cnt[26];
string s;
unsigned long long ans,hash[maxn],jc[maxn]={1};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(fr,0,sizeof(fr));
		memset(en,0,sizeof(en));
		ans=0;
		cin>>s;
		int len=s.size();
		s=' '+s;
		for(int i=1;i<=len;++i)
		{
			jc[i]=1ull*base*jc[i-1];
			hash[i]=1ull*hash[i-1]*base+s[i]-'a';
		}
		for(int i=1;i<=len;++i)
		{
			fr[i]+=fr[i-1];
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2)fr[i]++;
			else fr[i]--;
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=len;i>=1;--i)
		{
			en[i]+=en[i+1];
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2)en[i]++;
			else en[i]--;
		}
		for(int ll=1;ll<=len-2;++ll)
		{
			int mc=en[len-ll+1];//C中出现奇数次的字符数量
			for(int i=1;len-ll>=i*2;++i)
			{
				if((len-ll)%i)continue;
				int lenab=(len-ll)/i;//AB总长度
				unsigned long long ha=1ull*hash[lenab];
				bool f=true;
				for(int j=2;j<=i;++j)
				{
					if((1ull*hash[j*lenab]-1ull*hash[(j-1)*lenab]*jc[lenab])!=ha)
					{
						f=false;
						break;
					}
				}
				if(f==false)continue;
				for(int j=1;j<lenab;++j)
				{
					if(fr[j]>mc)continue;
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
