#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//#define bug cerr<<">>>"<<__LINE__<<endl
//#define int long long
const int maxn=1048586;
char S[maxn];
int len,T[maxn],F[maxn],SF[28][maxn];
inline void initF(){
	int cnt[26]; memset(cnt,0,sizeof cnt);
	for(int i=1;i<=len;++i){
		cnt[S[i-1]-'a']^=1;
		if(cnt[S[i-1]-'a']) F[i]=F[i-1]+1;
		else F[i]=F[i-1]-1;
		for(int j=0;j<F[i];++j)
			SF[j][i]=SF[j][i-1];
		for(int j=F[i];j<=26;++j)
			SF[j][i]=SF[j][i-1]+1;
//		cerr<<i<<':'<<F[i]<<endl;
	}
}
inline bool eql(const char* a,const char* b,int l){
	for(int i=0;i<l;++i)
		if(a[i]!=b[i]) return 0;
	return 1;
}
inline void initT(){
	for(int i=1;i<=len;++i)
		T[i]=i;
	for(int i=1;i<=len>>1;++i)
		if(T[i]==i)
			for(int j=i+i;j<=len;j+=i)
				if(eql(S,S+j-i,i)) T[j]=i;
				else break;
//	for(int i=1;i<=len;++i) cerr<<i<<':'<<T[i]<<endl;
}
int calc(int pos,int FC){
	int rp=pos/T[pos],ans=0,i;
	for(i=1;i*i<rp;++i)
		if(rp%i==0)
			ans+=SF[FC][i*T[pos]-1]+SF[FC][rp/i*T[pos]-1];
	if(i*i==rp) ans+=SF[FC][i*T[pos]-1];
//	cerr<<pos<<' '<<T[pos]<<' '<<FC<<' '<<ans<<endl;
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",S);
		len=strlen(S);
		initF();
/*		for(int i=0;i<=26;++i){
			for(int j=0;j<=len;++j)
				cerr<<SF[i][j]<<' ';
			cerr<<endl;
		}*/
		initT();
		int cnt[26],FC=0,ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=len-1;i>=2;--i){
			cnt[S[i]-'a']^=1;
			if(cnt[S[i]-'a']) ++FC;
			else --FC;
			int d=calc(i,FC);
//			cerr<<d<<endl;
			ans+=d;
		}
		printf("%d\n",ans);
	}
}
