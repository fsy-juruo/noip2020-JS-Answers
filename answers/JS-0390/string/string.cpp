#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int read(){
	char c=getchar();
	int s=0,f=1;
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int readu(){
	char c=getchar();
	int s=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s;
}

ll readll(){
	char c=getchar();
	ll s=0ll,f=1ll;
	while (c<'0' || c>'9'){if (c=='-') f=-1ll;c=getchar();}
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s*f;
}

ll readull(){
	char c=getchar();
	ll s=0ll;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s;
}

const int MAXINT=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;
const int MAXN=2000005;

int n;
string s;
int cnt[30],pref[MAXN],suff[MAXN],ans=0;

void solve1(){
	memset(cnt,0,sizeof(cnt));
	memset(suff,0,sizeof(suff));
	memset(pref,0,sizeof(pref));
//		cout<<s;
	for (register int i=n;i>=1;--i){
		int x=s[i]-'a'+1;
		cnt[x]++;
		if (cnt[x]%2==1){
			suff[i]=suff[i+1]+1;
		}
		else{
			suff[i]=suff[i+1]-1;
		}
	}
	memset(cnt,0,sizeof(cnt));
	for (register int i=1;i<=n;++i){
		int x=s[i]-'a'+1;
		cnt[x]++;
		if (cnt[x]%2==1){
			pref[i]=pref[i-1]+1;
		}
		else{
			pref[i]=pref[i-1]-1;
		}
	}
	memset(cnt,0,sizeof(cnt));
	/*
	for (register int i=1;i<=n;++i){
		printf("%d ",pref[i]);
	}
	printf("\n");
	for (register int i=1;i<=n;++i){
		printf("%d ",suff[i]);
	}
	printf("\n");
	*/
	ans=0;
	for (register int i=1;i<=n;++i){
		if (i>1){
			cnt[pref[i-1]]++;
		}
		int j=i,sum=0;
		/*
		for (register int i=0;i<=26;++i){
			printf("%d ",cnt[i]);
		}
		*/
		for (register int k=0;k<=suff[j];++k){
			sum+=cnt[k];
		}
		j++;
		while (j<=n){
			if (suff[j]==suff[j-1]+1){
				sum+=cnt[suff[j]];
			}
			else{
				sum-=cnt[suff[j-1]];
			}
//				printf("[%d,%d]",j,sum);
			if (j%i==1){
				ans+=sum;
			}
			if (s[j]!=s[(j-1)%i+1]) break;
			++j;
		}
//			printf("\n");
	}
	printf("%d\n",ans);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=readu();
	while (T--){
		cin>>s;
		n=s.length();
		s="0"+s;
//		if (n<=1000){
			solve1();
//		}
	}
	return 0;
}

