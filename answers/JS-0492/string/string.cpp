#include <bits/stdc++.h>
#define re register
typedef long long ll;
using namespace std;
const int MAXN=(1<<20)+10;
int T,num[MAXN][26];
ll ans;
string s,sa,sb,sc;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ll ans=0;
		cin>>s;
		for(re int i=0;i<26;i++)
			num[0][i]=0;
		for(re int i=0;i<s.size();i++)
		{
			for(re int j=0;j<26;j++)
			{
				if(i)
					num[i][j]=num[i-1][j];
				num[i][j]+=((s[i]-'a')==j);
			}
		}
		for(re int i=0;i<s.size()-2;i++)
		{
			for(re int j=i+1;j<s.size()-1;j++)
			{
				string sab=s.substr(0,j+1);
				sa=s.substr(0,i+1),sb=s.substr(i+1,j-i);
				int pos=0,cnta=0;
				for(int k=0;k<26;k++)
					if(num[i][k]&1)
						cnta++;
				while(pos+sab.size()<s.size() && s.find(sab,pos)==pos)
				{
					int cntc=0;
					pos=s.find(sab,pos)+sab.size();
					for(int k=0;k<26;k++)
						if((num[s.size()-1][k]-num[pos-1][k])&1)
							cntc++;
					if(cnta<=cntc)
						ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
