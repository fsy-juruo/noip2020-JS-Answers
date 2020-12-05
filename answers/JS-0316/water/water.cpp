#include<bits/stdc++.h>
#define r register
using namespace std;
int n,m,d,a,head[100001],cnt,zl[100001];
inline int read(){
	r int w=1,x=0; r char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}return w*x;
}
struct node{
	int to,next;
}e[500001];
struct score{
	long long fm,fz;
}wt[100001];
inline void add(r int x,r int y){
	e[++cnt].to=y; e[cnt].next=head[x]; head[x]=cnt;
}
inline int mygcd(r int x,r int y){
	if(x%y==0) return y;
	return mygcd(y,x%y);
}
inline void work(r int k,r int kfm){
	int kgcd=mygcd(wt[k].fm,kfm);
	wt[k].fz=wt[k].fz*kfm/kgcd+wt[k].fm/kgcd;
	wt[k].fm*=kfm/kgcd;
	kgcd=mygcd(wt[k].fm,wt[k].fz);
	wt[k].fm/=kgcd; wt[k].fz/=kgcd;
}
inline void dfs(r int k,r int kfm){
	kfm*=zl[k];
	for(r int i=head[k];i;i=e[i].next){
		if(zl[e[i].to]) dfs(e[i].to,kfm);
		else work(e[i].to,kfm);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
	n=read(); m=read();
	for(r int i=1;i<=n;i++){
		zl[i]=read();
		if(!zl[i]) wt[i].fm=1;
		for(r int j=1;j<=zl[i];j++){
			a=read();
			add(i,a);
		}
	}
	for(r int i=1;i<=m;i++)
		dfs(i,1);
	for(r int i=m+1;i<=n;i++)
		if(!zl[i]) cout<<wt[i].fz<<" "<<wt[i].fm<<endl;
	return 0;
}
