#include<bits/stdc++.h>
using namespace std;
int test,n,z[1111111],l,r,p,suf[1111111],num[33],cnt,pre[33],cur;
char s[1111111];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);
		l=1;r=0;
		for (int i=1;i<n;i++)
		{
			if (r<i)
			{
				z[i]=0;
				while(z[i]+i<n)
				{
					if (s[z[i]]!=s[z[i]+i]) break;
					z[i]++;
				}
				l=i;r=i+z[i]-1;
				continue;
			}
			p=i-l;
			if (z[p]<r-l-p+1) z[i]=z[p];
			else
			{
				z[i]=r-l-p+1;
				while(z[i]+i<n)
				{
					if (s[z[i]]!=s[z[i]+i]) break;
					z[i]++;
				}
				l=i;r=i+z[i]-1;
			}
		}
		memset(num,0,sizeof(num));
		cnt=0;
		for (int i=n-1;i>=0;i--)
		{
			num[s[i]-'a']++;
			if (num[s[i]-'a']&1) cnt++;
			else cnt--;
			suf[i]=cnt; 
		}
		memset(num,0,sizeof(num));
		memset(pre,0,sizeof(pre));
		cnt=0;ans=0;
		for (int i=1;i<n-1;i++)
		{
			num[s[i-1]-'a']++;
			if (num[s[i-1]-'a']&1) cnt++;
			else cnt--;
			for (int j=cnt;j<26;j++) pre[j]++;
			cur=i+1;
			while(cur<n)
			{
				ans+=pre[suf[cur]];
				if (z[cur]<i+1) break;
				cur+=(i+1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
