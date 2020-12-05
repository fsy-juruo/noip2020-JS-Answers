#include<cstdio>
#define N 100005
using namespace std;
int n,k,ans;
int a[15],b[N],w[15],c[N],d[N];
int g(int x){
	if(x+1>n) return 1;
	return x+1;
}
void dfs2(int x,int p){
	b[c[p]]+=d[p];
	if(b[c[p]]<1||b[c[p]]>w[c[p]]) {
		ans+=x;
		return;
	}
	dfs2(x+1,g(p));
}
void dfs1(int x){
	if(x==k+1) {
		for(int i=1;i<=k;i++) b[i]=a[i];
		dfs2(1,1);
		return;
	}
	for(int i=1;i<=w[x];i++) {
		a[x]=i;
		dfs1(x+1);
	}
}
void work1(){
	int f=0,num;
	int vis[N];
	while(1){
		f++;
		if(f==1e8) ans=-1;
		num+=d[g(f)];
		if(num<0){
			if(!vis[-1*num]) vis[-1*num]=1,ans+=f;
		}
		else {
			if(!vis[w[1]-num+1]) vis[w[1]-num+1]=1,ans+=f;
		}
	}
}
void work2(){
	int f=0,num1,num2;
	int vis[5005][5005];
	while(1){
		f++;
		if(f==1e8) ans=-1;
		if(g(f)&1){
			num1+=d[1];
			if(num1<0){
			  if(!vis[-1*num1][num2]) vis[-1*num1][num2]=1,ans+=f;
			}
			else {
				if(!vis[w[1]-num1+1][num2]) vis[w[1]-num1+1][num2]=1,ans+=f;
			}
		}
		else {
			num2+=d[2];
			if(num2<0){
				if(!vis[num1][-1*num2]) vis[num1][-1*num2]=1,ans+=f;
			}
			else {
				if(!vis[num1][w[2]-num2+1]) vis[num1][w[2]-num2+1]=1,ans+=f;
			}
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	if(k==1&&n>5) work1();
	else if(k==2&&n>5) work2();
	else dfs1(1);
	printf("%d\n",ans);
	return 0;
}
