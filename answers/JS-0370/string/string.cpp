#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const ull BASE=149;
const int MAXN=(1<<20)+5;
const int ALPHA=26+2;
char s[MAXN];
int n,cnt[ALPHA],suf[MAXN],pre[MAXN],t[ALPHA];
ull pw[MAXN],hs[MAXN];
void add(int x,int v){x++;for(int i=x;i<=27;i+=(i&(-i))) t[i]+=v;}
int query(int x){x++;int ret=0;for(int i=x;i;i-=(i&(-i))) ret+=t[i];return ret;}
void clear(){
	memset(cnt,0,sizeof(cnt));
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	memset(hs,0,sizeof(hs));
	memset(t,0,sizeof(t));
}
ull gethash(int l,int r){
	return hs[r]-hs[l-1]*pw[r-l+1];
}
void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	clear();
	for(int i=n;i;i--){
		suf[i]=suf[i+1];
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1) suf[i]++;
		else suf[i]--;
//		printf("%d %d\n",i,suf[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1) pre[i]++;
		else pre[i]--;
//		printf("%d %d\n",i,pre[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++) hs[i]=hs[i-1]*BASE+s[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j+=i){
			if(j!=i&&gethash(j-i+1,j)!=hs[i]) break;
			ans+=query(suf[j+1]);
		}
		add(pre[i],1);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	pw[0]=1;for(int i=1;i<MAXN;i++) pw[i]=pw[i-1]*BASE;
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
