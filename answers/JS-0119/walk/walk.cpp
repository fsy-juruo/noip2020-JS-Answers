#include<bits/stdc++.h>
#define rep(a,b) for(int a=0;a<b;++a)
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define PB(a) push_back(a)
using namespace std;
const int MOD=1e9+7;
int n,k;
const int MAXN=500000+20;
int c[MAXN],d[MAXN];
int w[11];
void erro(){
	cout<<-1<<endl;
	exit(0);
}
vector<int> v;
LL calc(){
	vector<int> tmp=v;
	rb(i,1,1000){
		int is=i%n;
		if(is==0) is=n;
		tmp[c[is]]+=d[is];
		if(tmp[c[is]]<=0)
			return i;
		if(tmp[c[is]]>w[c[is]])
			return i;
	}
	erro();
	return 1;
}
LL rest=0;
void dfs(int now){
	if(now>k){
		rest+=calc();
		return ;
	}
	rb(i,1,w[now]){
		v.PB(i);
		dfs(now+1);
		v.pop_back();
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	rb(i,1,k) scanf("%d",&w[i]);
	rb(i,1,n){
		scanf("%d%d",&c[i],&d[i]);
	}
	dfs(1);
	cout<<rest<<endl;
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

