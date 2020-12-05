#include<bits/stdc++.h>
#define rep(a,b) for(int a=0;a<b;++a)
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define SEC second
#define FIR first
using namespace std;
const int MAXN=1e5+20;
vector<int> g[MAXN];//到达他的边
pair<LL,LL> wt[MAXN]; 
bool vis[MAXN];
int n,m;
int zz[MAXN];
LL my_gcd(LL A,LL B){
	if(B==0) return A;
	return my_gcd(B,A%B);
}
LL my_lcm(LL A,LL B){
	return A/my_gcd(A,B)*B;
}
void calc(int now){
	vis[now]=1;
	if(g[now].empty()){
		wt[now]=make_pair(1ll,1ll);
		return;
	}
	wt[now]=II(0ll,1ll);
	rep(i,g[now].size()){
		int pre=g[now][i];
		if(!vis[pre]) calc(pre);
		LL tmp=my_lcm(wt[now].SEC,wt[pre].SEC*zz[pre]);
		wt[now].FIR*=tmp/wt[now].SEC;
		wt[now].SEC=tmp;
		wt[now].FIR+=wt[pre].FIR*tmp/wt[pre].SEC/zz[pre];
		tmp=my_gcd(wt[now].FIR,wt[now].SEC);
		wt[now].FIR/=tmp;
		wt[now].SEC/=tmp;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		int d;
		scanf("%d",&d);
		zz[i]=d;
		rb(j,1,d){
			int ai;
			scanf("%d",&ai);
			g[ai].PB(i);
		}
	}	
	rb(i,1,n){
		if(!vis[i]){
			calc(i);
		}
	}
	rb(i,1,n){
		if(zz[i]==0){
			printf("%lld %lld\n",wt[i].FIR,wt[i].SEC);
		}
	}
	return 0;
}
/*

1. 数组大小是1倍还是2倍？
2. 有没有用long long
3. 特判有没有return 0
4. 需不需要特判
5. if的条件是否并列
6. vector ,函数返回值是否是long long
7. 有没有注意中途取模
8. dfn有没有错
9. 下标顺序有没有错

*/

