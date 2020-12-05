#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
vector<int> hsh[(1<<20)+20];
int pw[(1<<20)+20];
int cnt[30];
bool hv[30];
int suf[(1<<20)+20];
int let(char c)
{
	return c-'a';
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=(1<<20);i++)
		pw[i]=pw[i-1]*26%mod;
	int T;
	cin>>T;
	while(T--)
	{
		memset(suf,0,sizeof(suf));
		string S;
		cin>>S;
		long long ans=0;
		int n=S.length();
		for(int i=1;i<=n;i++)
			hsh[i].clear();
		hsh[1].push_back(let(S[0]));
		for(int i=2;i<=n;i++)
			hsh[i].push_back((hsh[i-1][0]*26+let(S[i-1]))%mod);
		for(int i=1;i<=n;i++)
			for(int j=i;j+i<=n;j+=i)
			{
//				cout<<"hashing...("<<i<<","<<j<<")"<<endl;
				hsh[i].push_back(((hsh[j+i][0]-hsh[j][0]*pw[i])%mod+mod)%mod);
			}
//		cout<<hsh[3][0]<<" "<<hsh[3][1]<<endl;
//		puts("1.hash finished");
/*		puts("hash results:");
		for(int i=1;i<=n;i++)
		{
			cout<<i<<":"<<"   ";
			for(int j=0;j<n/i;j++)
				cout<<hsh[i][j]<<" ";
			puts("\n\n");
		}
//		*/
		for(int i=0;i<26;i++)
			hv[i]=0;
		for(int i=n;i>0;i--)
		{
			hv[let(S[i-1])]^=1;
			suf[i]=suf[i+1]+hv[let(S[i-1])]*2-1;
//			cout<<i<<" "<<suf[i]<<endl;
		}
		for(int i=0;i<26;i++)
			hv[i]=0;
		for(int i=0;i<=26;i++)
			cnt[i]=0;
		int count=0;
		for(int i=0;i<n-1;i++)
		{
			int l=i+1;
			for(int j=l;j+l<n;j+=l)
				if(hsh[l][j/l]==hsh[l][j/l-1])//s[1..l+j](s[1..l]*k) okpoint:1 2 3 4 .. i
					ans+=cnt[suf[j+l+1]];
				else break;
			if(l<n)
				ans+=cnt[suf[l+1]];
			hv[let(S[i])]^=1;
			count=count+hv[let(S[i])]*2-1;
			for(int i=count;i<=26;i++)
				cnt[i]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
