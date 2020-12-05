#include <bits/stdc++.h>
using namespace std;
const int N=100005;
map<char,int>cnt[2];
char s[N],a[N],b[N],c[N];
char ch;
int T,sleng,la,lb,lmax,imax,ans;

bool chk1()
{
	int na=0,nb=0;
	for(int cha='a';cha<='z';cha++)
	  if(cnt[0][cha]%2==1) na++;
	for(int chb='a';chb<='z';chb++)
	  if(cnt[1][chb]%2==1) nb++;
	return na<=nb;
}

bool chk2(int i)
{
	for(int j=2;j<=i;j++)
	{
		int loopt=(la+lb)*(j-1),u;
		for(u=loopt+1;u<=loopt+la;u++)
		  if(s[u]!=a[u-loopt]) return false;
		for(u=loopt+la+1;u<=loopt+la+lb;u++)
		  if(s[u]!=b[u-loopt-la]) return false;
	}
	return true;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		sleng=ans=0;
		while((ch=getchar())!='\n')
		  s[++sleng]=ch;
		imax=(sleng-1)>>1;
		for(int i=1;i<=imax;i++)
		{
			lmax=(sleng-1)/i-1;
			for(la=1;la<=lmax;la++)
			{
				cnt[0].clear();
				int u;
				for(u=1;u<=la;u++)
				  a[u]=s[u],cnt[0][a[u]]++;
				for(lb=1;lb<=lmax&&la+lb<sleng;lb++)
				{
					cnt[1].clear();
					int loops=(la+lb)*i;
					if(loops>=sleng) continue;
					for(u=la+1;u<=la+lb;u++)
					  b[u-la]=s[u];
					for(u=loops+1;u<=sleng;u++)
					  c[u-loops]=s[u],cnt[1][c[u-loops]]++;
					ans+=(chk1()&chk2(i));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
