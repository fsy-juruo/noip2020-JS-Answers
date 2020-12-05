#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,k;
const int Maxn=5e5+5;
const int mod=1e9+7;
const int Maxk=11;
int w[Maxk],c[Maxn],d[Maxn];
vector<int>v(20);
int ans;
void solve() {
	vector<int>at;
	at=v;
	int step=1;
	while(1) {
		ans++;
		if(ans>=mod)ans-=mod;
		at[c[step]]+=d[step];
		if(at[c[step]]<1||at[c[step]]>w[c[step]])break;
		if(step==n&&at==v){
			printf("-1\n");
			exit(0);
		}
		step++;
		if(step>n)step-=n;
	}
}
void dfs(int i,vector<int>&v) {
	if(i>k) {
		solve();
		return;
	}
	for(int j=1; j<=w[i]; j++) {
		v[i]=j;
		dfs(i+1,v);
	}
}
void type_1() {
	dfs(1,v);
	printf("%d\n",ans);
}
//int pre[Maxn];
//void type_2(){
//	for(int i=1;i<=n;i++){
//		pre[i]=pre[i-1]+d[i];
//	}
//	int mins=*min_element(pre+1,pre+n+1);
//	int maxs=*max_element(pre+1,pre+n+1);
//	
//	
//	for(int i=1;i<=n;i++){
//		int preans=0;
//		v[1]=i;
//		vector<int>at=v;
//		if(pre[n]==0&&(i-mins>=1&&i+maxs<=w[1])){
//			printf("-1\n");
//			exit(0);
//		}
//		int step;
//		if(pre[n]>0){
//			step=(w[1]-i-maxs)%pre[n];
//			preans=((ll)ans+(ll)step*n)%mod;
//		}else{
//			step=(i-abs(mins))%pre[n];
//			preans=((ll)ans+(ll)step*n)%mod;
//		}
//		
//		step=1;
//		while(1) {
//			preans++;
//			if(preans>=mod)ans-=mod;
//			at[c[step]]+=d[step];
//			if(at[c[step]]<1||at[c[step]]>w[c[step]])break;
//			if(step==n&&at==v){
//				printf("-1\n");
//				exit(0);
//			}
//			step++;
//			if(step>n)step-=n;
//		}
//		printf("%d\n",preans);
//		ans+=preans;
//	}
//}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	ll Maxw=1;
	bool tp1=true;
	for(int i=1; i<=k; i++) {
		scanf("%d",&w[i]);
		Maxw*=w[i];
		if(Maxw>1e6)tp1=false;
	}
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&c[i],&d[i]);
	}
	if(tp1) {
		type_1();
		return 0;
	}
	return 0;
}
