#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
const int maxn=1e5+100,maxk=20; 
const int maxw=1e5+100;
struct node{
	int c,d;
}step[maxn];
LL ans;
struct all{
	LL wei[maxk],maxl[maxk],maxr[maxk];
};
all cir;
int w[maxk];
int n,k;
LL sp[maxk][maxw];
vector<int> times[maxk];
LL dfs1(int wd,int zb){
	if(sp[wd][zb]!=-1)return sp[wd][zb];
	if(zb+cir.maxl[wd]<1||zb+cir.maxr[wd]>w[wd]){
		int f=times[wd].size(),g=zb;
		for(int i=0;i<f;i++){
			g+=step[times[wd][i]].d;
			if(g<1||g>w[wd])return sp[wd][zb]=times[wd][i];
		}
	}
	if(cir.wei[wd]==0)return sp[wd][zb]=LONG_LONG_MAX/2-114514;
	return sp[wd][zb]=dfs1(wd,zb+cir.wei[wd])+n;
}

LL dfs2(int wd,int zb,LL minn){
	LL ret=0;
	if(wd==0){
		for(int i=1;i<=w[1];i++)ret+=dfs2(1,i,minn);
		return ret;
	}
	minn=min(sp[wd][zb],minn);
	if(wd==k)return minn;
	for(int i=1;i<=w[wd+1];i++)ret+=dfs2(wd+1,i,minn);
	return ret;
}

void sub30(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=w[i];j++)dfs1(i,j);
	}
	printf("%lld",dfs2(0,0,LONG_LONG_MAX/2-114514));
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(sp,-1,sizeof(sp));
	read(n);read(k);
	for(int i=1;i<=k;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(step[i].c);
		read(step[i].d);
		cir.wei[step[i].c]+=step[i].d;
		if(cir.maxl[step[i].c]+step[i].d<cir.maxl[step[i].c])cir.maxl[step[i].c]=cir.maxl[step[i].c]+step[i].d;
		if(cir.maxr[step[i].c]+step[i].d>cir.maxr[step[i].c])cir.maxr[step[i].c]=cir.maxr[step[i].c]+step[i].d;
		times[step[i].c].push_back(i);
	}
	sub30();
	return 0;
	
}
