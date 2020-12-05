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

1. �����С��1������2����
2. ��û����long long
3. ������û��return 0
4. �費��Ҫ����
5. if�������Ƿ���
6. vector ,��������ֵ�Ƿ���long long
7. ��û��ע����;ȡģ
8. dfn��û�д�
9. �±�˳����û�д�

*/

