#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int nxt[N+5],cnt[N+5],f[27][N+3];
int n,T;
string st;
void kmp()
{
	memset(nxt,0,sizeof(nxt));
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&st[i]!=st[j+1]) j=nxt[j];
		if(st[i]==st[j+1]) ++j;
		nxt[i]=j;
	}
}
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		ans=0;
		cin>>st;
		n=st.size();
		st='*'+st;
		kmp();
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int t=st[i]-97;
			cnt[t]++;
			if(cnt[t]&1) ++sum;
			else --sum;
			for(int j=0;j!=27;j++) f[j][i]=f[j][i-1];
			++f[sum][i];
		}
		memset(cnt,0,sizeof(cnt));
		sum=0;
		for(int i=n;i>=3;i--)
		{
			int t=st[i]-97;
			cnt[t]++;
			if(cnt[t]&1) ++sum;
			else --sum;
			int j=i-1,len,pos=0,tmp=0;
			while(1)
			{
				len=i-1-j;
				if(len>=2&&(i-1)%len==0)
				{
					for(int k=0;k<=sum;k++) ans+=(long long)f[k][len-1];
				}
				if(!j) break;
				j=nxt[j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

