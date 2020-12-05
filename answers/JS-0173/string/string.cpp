#include <bits/stdc++.h>
using namespace std;

const int maxn=1010,p=29,MOD=1e9+7;

int q,n,cntpre[maxn][30],cntsuf[maxn][30],prec[maxn],sufc[maxn],ans;
long long hsh[maxn];
string s;

inline long long pw(int a)
{
	long long ret=1,pp=p;
	while(a>0)
	{
		if(a&1) ret=ret*pp%MOD;
		pp=pp*pp%MOD;
		a>>=1;
	}
	
	return ret;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>q;
	while(q--)
	{
		memset(cntpre,0,sizeof(cntpre));
		memset(cntsuf,0,sizeof(cntsuf));
		memset(prec,0,sizeof(prec));
		memset(sufc,0,sizeof(sufc));
		memset(hsh,0,sizeof(hsh));
		ans=0;
		
		cin>>s;
		n=s.size();
		
		hsh[0]=s[0]-'a';
		for(int i=1;i<n;i++) hsh[i]=(hsh[i-1]*p%MOD+s[i]-'a')%MOD;
		
		cntpre[0][s[0]-'a']++;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<26;j++) cntpre[i][j]=cntpre[i-1][j];
			cntpre[i][s[i]-'a']++;
		}
		for(int i=0;i<n;i++) for(int j=0;j<26;j++) if(cntpre[i][j]&1) prec[i]++;
		
		cntsuf[n-1][s[n-1]-'a']++;
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<26;j++) cntsuf[i][j]=cntsuf[i+1][j];
			cntsuf[i][s[i]-'a']++;
		}
		for(int i=n-1;i>=0;i--) for(int j=0;j<26;j++) if(cntsuf[i][j]&1) sufc[i]++;
		
		for(int suf=1;suf+2<=n;suf++)
		{
			int m=n-suf;
			
			for(int i=2;i<=m;i++) if((m%i)==0)
			{
				bool ok=1;
				for(int j=i*2;j<=m;j+=i) if((hsh[j-1]-hsh[j-1-i]*pw(i)%MOD+MOD)%MOD!=hsh[i-1])
				{
					ok=0;
					break;
				}
				
				if(!ok) continue;
				
				for(int j=0;j<i-1;j++) if(prec[j]<=sufc[m]) ans++;
			}
		}
		
		cout<<ans<<endl;
	}

	return 0;
}

