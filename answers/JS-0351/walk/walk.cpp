#include <bits/stdc++.h>
#define ll long long
#define re register
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int maxn=5e5+5;
const int maxm=10+5;
const ll mod=1e9+7;
int n,m,orig[maxm],a[maxm],c[maxn],d[maxn];
ll w[maxn],ans;
bool judge(){
	for(re int i=1;i<=m;i++){
		if(a[i]!=orig[i]) return false;
	}
	return true;
}
bool check(){
	for(re int i=1;i<=m;i++){
		if(a[i]<=0 || a[i]>w[i]) return true;
	}
	return false;
}
void print(){
	printf("*************\n");
	for(re int i=1;i<=m;i++) printf("%d ",a[i]);
	printf("%lld\n",ans);
	printf("*************\n");
}
void init(){
	for(re int i=1;i<=m;i++) a[i]=orig[i];
}
void calculate(){
	int tmp=0;
	init();
	while(1){
		++tmp;
		a[c[tmp]]+=d[tmp];
		ans=(ans+1)%mod;
		if(a[c[tmp]]<=0 || a[c[tmp]]>w[c[tmp]]) break;
		if(tmp==n){
			if(judge()){
				cout<<-1<<endl;
				exit(0);
			}
			tmp=0;
		} 
	}
	//print();
}
void dfs(int step){
	if(step==m+1){
		calculate();
		return;
	}
	for(re int i=1;i<=w[step];i++){
		orig[step]=a[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(re int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
