#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T&x){
	x=0;
	int flg=1;
	char ch=getchar();
	while((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if(ch=='-') ch=getchar(),flg=-1;
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=flg;
}
long long w[110];
const int N=5e5+10;
long long md=1e9+7;
int c[N],d[N];
const int MM=1e6+10;
long long t1[21][MM],t2[21][MM];
int s=0;
int n,k;
set<pair<int,int> >ss;
void dfs(int kk,int dep,long long x,int dlt,long long sum){
	if(ss.find(make_pair(dlt,dep))!=ss.end()) return;
	ss.insert(make_pair(dlt,dep));
	
	if(dep>n) dep=1;
	if(c[dep]!=kk) dfs(kk,dep+1,x,dlt,(sum+1)%md);
	else{
		dlt+=d[dep];
		if(dlt>x) {
			s++;return;
		}
		if(dlt<-x) {
			s++;return;
		}
		if(dlt>0)  t1[kk][dlt]=min(t1[kk][dlt],sum%md);
		else if(dlt<0) t2[kk][-dlt]=min(sum%md,t2[kk][-dlt]);
		dfs(kk,dep+1,x,dlt,(sum+1)%md);
	}
}
long long ans[110];
long long ret=0;
void dfss(int dep){
	if(dep>k){
		long long rettt=0x3f;
		for(int i=1;i<=k;i++){
			rettt=min(rettt,ans[i]);
		}
		if(rettt==0x3f){
			puts("-1");exit(0);
		}
		ret=(ret+rettt)%md;
		return;
	}
	for(int i=1;i<=w[dep];i++){
		ans[dep]=min(t1[dep][w[dep]-i+1],t2[dep][i]);
		dfss(dep+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(t1,0x3f,sizeof t1);
	memset(t2,0x3f,sizeof t2);
	read(n),read(k);
	long long maxx=0;
	for(int i=1;i<=k;i++)read(w[i]),maxx=max(maxx,w[i]);
	for(int i=1;i<=n;i++){
		read(c[i]);read(d[i]);
	}
	if(maxx>100000) {
		puts("-1");return 0;
	}
	for(int i=1;i<=k;i++){
		ss.clear();
		dfs(i,1,w[i],0,1);
	}
	dfss(1);
	printf("%lld\n",ret%md);
	return 0;
}

