#include <bits/stdc++.h>

using namespace std;
const int maxn=30;
int n;string s;
int aj,cj,cnta[maxn],cntc[maxn];
void work1()
{
	int ans=0;
	memset(cnta,0,sizeof(cnta));
	memset(cntc,0,sizeof(cntc));
	aj=cj=0;
	int len=s.size();
	s='#'+s;
	for(int i=1;i<=len;i++)// 1-i
	{
		cnta[s[i]-'a']++;
		if(cnta[s[i]-'a']%2==1) aj++;
		else aj--;
		memset(cntc,0,sizeof(cntc));cj=0;
		for(int j=len;j>i+1;j--)//j-len
		{
			cntc[s[j]-'a']++;	
			if(cntc[s[j]-'a']%2==1) cj++;
			else cj--;
		//	printf("i=%d j=%d aj=%d cj=%d\n",i,j,aj,cj);
			if(aj>cj) continue;
			for(int k=i+1;k<=j-1;k++)//i+1-k
			{
				int now=1;int flag=1;
				if((j-k-1)%k!=0) 
				{
				//	printf("cant i=%d j=%d k=%d\n",i,j,k);
					flag=0;continue;
				}
				for(int t=k+1;t<=j-1;t++)
				{
					if(s[t]!=s[now]) 
					{
						flag=0;
						break;
					}
					now++;if(now>k) now=1;
				}
				if(flag&&now==1)
				{
					ans++;
				//	printf("i=%d j=%d k=%d now=%d\n",i,j,k,now);	
				} 
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s.size()<=1005) work1();
	}
	return 0;
}
