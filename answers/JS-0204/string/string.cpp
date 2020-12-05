#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e3+100;
int t;
char ss[maxn];
int s[maxn];
int vis[30];
int stock[maxn][maxn];
int Find(int l,int r){
	if(stock[l][r]!=-1)return stock[l][r];
	int ret=0;
	memset(vis,0,sizeof(vis));
	for(int i=l;i<=r;i++)vis[s[i]]++;
	for(int i=1;i<=26;i++)if(vis[i]%2)ret++;
	return stock[l][r]=ret;
}

bool compare(int br,int st){
	for(int i=1;i<=br;i++){
		if(s[i]!=s[st+i-1])return 0;
	}
	return 1;
}

void init(){
	memset(stock,-1,sizeof(stock));
	int cnt1=0,cnt2=0;
	LL ans=0;
	memset(ss,0,sizeof(ss));
	scanf("%s",ss+1); 
	int n=strlen(ss+1);
	for(int i=1;i<=n;i++)s[i]=ss[i]-'a'+1;
	for(int br=2;br<=n;br++)
	for(int ar=1;ar<br;ar++){
		int al=1,bl=ar+1,cl;
		cnt1=Find(al,ar);
		for(int repeat=1;repeat*br+1<=n;repeat++){
			if(!compare(br,(repeat-1)*br+1))break;
			cl=repeat*br+1;
			cnt2=Find(cl,n);
			if(cnt1<=cnt2){
				ans++;
//				printf("%d %d   %d %d   %d\n",al,ar,bl,br,cl);
			}
		}
	}
	printf("%lld\n",ans);
	return;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--)init();
	return 0;
}
