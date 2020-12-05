#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int N=1.1e6;
const LL MOD=152141314;

int Tc,n;
string s;
LL ha[N],po[N];
vector<pii> good;
bool is1[30],is2[30];
int a1[N],a2[N],sum1[N][30];
LL ans;

LL get_hash(int x,int y)
{
	return (ha[y]-ha[x-1]*po[y-x+1]%MOD+MOD)%MOD;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&Tc);
	while(Tc--)
	{
		char c=getchar(); s="#";
		while('a'>c || 'z'<c) c=getchar();
		while('a'<=c && c<='z') s+=c,c=getchar();
		n=s.size()-1; ans=0;
		memset(ha,0,sizeof(ha));
		memset(po,0,sizeof(po));
		good.clear();
		memset(is1,0,sizeof(is1));
		memset(a1,0,sizeof(a1));
		memset(sum1,0,sizeof(sum1));
		memset(is2,0,sizeof(is2));
		memset(a2,0,sizeof(a2));
		
		for(int i=1;i<=n;i++)
			ha[i]=(ha[i-1]*31+s[i]-'a'+1)%MOD;
		po[0]=1;
		for(int i=1;i<=n;i++)
			po[i]=po[i-1]*31%MOD;
		for(int i=2;i<=n;i++)
		for(int j=1;j+i<=n;j+=i)
			if(get_hash(1,i)==get_hash(j,j+i-1)) good.pb(mp(i,j+i));
			else break;
		
		for(int i=1;i<=n;i++)
		{
			if(!is1[s[i]-'a']) a1[i]=a1[i-1]+1;
			else a1[i]=a1[i-1]-1;
			is1[s[i]-'a']^=1;
			for(int j=0;j<=25;j++)
				sum1[i][j]=sum1[i-1][j]+(a1[i]==j);
		}
		for(int i=n;i>=1;i--)
		{
			if(!is2[s[i]-'a']) a2[i]=a2[i+1]+1;
			else a2[i]=a2[i+1]-1;
			is2[s[i]-'a']^=1;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=25;j++)
			sum1[i][j]+=sum1[i][j-1];
		
		for(int i=0;i<good.size();i++)
		{
			int l=good[i].first-1,r=good[i].second;
			ans+=sum1[l][a2[r]];
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
