#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF 2147483647
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=1055555;
const LL bas=1145141;
const LL mod1=1e9+9;
const LL mod2=998244353;
char c[Maxn];
int n,pre[Maxn],suf[Maxn],cnt[27],cur,PS[Maxn][27];
LL Ha1[Maxn],Ha2[Maxn],pw1[Maxn],pw2[Maxn];
void _init(){
	pw1[0]=pw2[0]=1;
	for (int i=1;i<Maxn;i++){
		pw1[i]=pw1[i-1]*bas%mod1;
		pw2[i]=pw2[i-1]*bas%mod2;
	}
}
LL GH(int l,int r){
	LL H1=(l==0)?Ha1[r]:((Ha1[r]-Ha1[l-1]*pw1[r-l+1])%mod1);
	if (H1<0) H1+=mod1;
	LL H2=(l==0)?Ha2[r]:((Ha2[r]-Ha2[l-1]*pw2[r-l+1])%mod2);
	if (H2<0) H2+=mod2;
	return H1*mod2+H2;
}
void mian(){
	scanf("%s",c);n=strlen(c);
	memset(cnt,0,sizeof(cnt));cur=0;
	for (int i=0;i<n;i++){
		cur-=cnt[c[i]-'a'];cnt[c[i]-'a']^=1;cur+=cnt[c[i]-'a'];
		pre[i]=cur;
	}
	memset(cnt,0,sizeof(cnt));cur=0;
	for (int i=n-1;i>=0;i--){
		cur-=cnt[c[i]-'a'];cnt[c[i]-'a']^=1;cur+=cnt[c[i]-'a'];
		suf[i]=cur;
	}
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<n;i++){
		cnt[pre[i]]++;
		PS[i][0]=cnt[0];
		for (int j=1;j<26;j++) PS[i][j]=PS[i][j-1]+cnt[j];
	}
	LL H1=0,H2=0;
	for (int i=0;i<n;i++){
		H1=(H1*bas+c[i])%mod1;H2=(H2*bas+c[i])%mod2;
		Ha1[i]=H1,Ha2[i]=H2;
	}
	LL ans=0;
	for (int l=2;l<=n;l++){
		int lo=1,hi=n/l+1;
		while (hi-lo>1){
			int mid=lo+hi>>1;
			if (GH(0,l*(mid-1)-1)==GH(l,l*mid-1)){
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		int C1=suf[l*lo],C2=suf[l*(lo-1)];
		int V1=(lo+1)/2,V2=lo-V1;
		if (l*lo==n) V1--;
		ans+=1ll*V1*PS[l-2][C1];
		ans+=1ll*V2*PS[l-2][C2];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	_init();
	int T=read();
	while (T--){
		mian();
	}
}
