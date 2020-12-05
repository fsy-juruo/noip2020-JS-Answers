#include<bits/stdc++.h>
using namespace std;
#define fgx cerr<<"------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define pii pair<LL,LL>
#define mpt make_pair
#define fr first
#define sc second
inline int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-1;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
#define M 2000010
int n,nowd; char ch[M]; LL ans;
int Z[M],T[520],sm[520],cnt[520],pre[M],suf[M];
inline void ins(int x){
	T[x]++,sm[0]=T[0];
	for(int i=1;i<=26;i++) sm[i]=sm[i-1]+T[i];
}
inline void solve(){
	scanf("%s",ch+1),n=strlen(ch+1);
	int mxr=0,mid=0; Z[1]=n;
	for(int i=2;i<=n;i++){
		if(i<=mxr) Z[i]=min(Z[i-mid+1],mxr-i+1); else Z[i]=0;
		while(i+Z[i]<=n&&ch[Z[i]+i]==ch[Z[i]+1]) Z[i]++;
		if(i+Z[i]-1>mxr) mxr=i+Z[i]-1,mid=i;
	}
	memset(cnt,0,sizeof(cnt)),nowd=0;
	for(int i=1,x;i<=n;i++){
		x=ch[i]-'a',cnt[x]++;
		if(cnt[x]&1) nowd++; else --nowd;
		pre[i]=nowd;
	}
	memset(cnt,0,sizeof(cnt)),nowd=0;
	for(int i=n,x;i;--i){
		x=ch[i]-'a',cnt[x]++;
		if(cnt[x]&1) nowd++; else --nowd;
		suf[i]=nowd;
	}
	memset(T,0,sizeof(T)),ins(pre[1]),ans=0ll;
	for(int i=2;i<=n;i++){
		if(i<n) ans+=(LL)sm[suf[i+1]];
		for(int j=(i<<1);j<=n;j+=i){
			if(Z[j-i+1]<i) break;
			if(j<n) ans+=(LL)sm[suf[j+1]];
		}
		ins(pre[i]);
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}
