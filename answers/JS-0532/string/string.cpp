#include<bits/stdc++.h>
#define ll long long
#define N 1048600
using namespace std;
int T,n,nxt[N],f[N][27];
//vector<int> v[26];
vector<int> fac[N];
char s[N];
ll ans;
struct edge{
	int to,nxt;
}e[14698400];
int head[N],cnte;
inline void add(register int u,register int v){
	e[++cnte]=(edge){v,head[u]},head[u]=cnte;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=1048576;++i)
		for(register int j=i;j<=1048576;j+=i)
			add(j,i);
//	cerr<<cnte<<endl;
//			fac[j].push_back(i);
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1),ans=0;
//		for(register int i=1;i<=n;++i) cerr<<s[i];
//		puts("");
		for(register int i=2,p=0;i<=n;++i){
			while(p&&s[p+1]!=s[i]) p=nxt[p];
			if(s[p+1]==s[i]) ++p;
			nxt[i]=p;
//			for(register int j=1;j<=nxt[i];++j)
//				if(s[j]!=s[i-nxt[i]+j])
//					cerr<<"233"<<endl;
		}	
//		for(register int i=1;i<=n;++i)
//			printf("%d ",nxt[i]);
//		puts("");
		int cnts[26],cur=0; for(register int i=0;i<26;++i) cnts[i]=0;
		for(register int i=1;i<=n;++i){
			++cnts[s[i]-'a'];
			if(cnts[s[i]-'a']%2==0) --cur; else ++cur;
			for(register int j=0;j<cur;++j) f[i][j]=f[i-1][j];
			for(register int j=cur;j<=26;++j) f[i][j]=f[i-1][j]+1;
		}
		cur=0; for(register int i=0;i<26;++i) cnts[i]=0;
		for(register int i=n;i>=3;--i){
			++cnts[s[i]-'a'];
			if(cnts[s[i]-'a']%2==0) --cur; else ++cur;
			int len,cntl;
			if(nxt[i-1]*2<i-1) len=i-1,cntl=1;
			else {
				len=(i-1)-nxt[i-1];
				cntl=(i-1)/len;
				if(cntl*len!=i-1)
					len=i-1,cntl=1;
//				assert(cntl*len==i-1);
			}
//			for(register int j=1;j<=30&&j<=cntl;++j)
//				if(cntl%j==0){
//					ans+=1ll*f[len*j-1][cur];
//				}
//			for(register int j=0;j<(int)fac[cntl].size();++j){
//				int tmp=len*fac[cntl][j]-1;
//				ans+=1ll*f[tmp][cur];
//			}
			for(register int j=head[cntl];j;j=e[j].nxt){
				int tmp=len*e[j].to-1;
				ans+=1ll*f[tmp][cur];
			}
//			cerr<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

