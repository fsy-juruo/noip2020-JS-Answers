#include<bits/stdc++.h>
#define LL long long
#define MAXN 100010
using namespace std;

template<typename T> void read(T &x){
	char ch=getchar(); x=0; T f=0;
	for (;!isdigit(ch);ch=getchar()) f|=ch=='-';
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	x=f?-x:x;
}

int n,m,tot;
int edge[MAXN][6];
LL a[MAXN][2],ans[MAXN];
int h[MAXN];
bool vis[MAXN];
queue<int> q;

LL gys(LL x,LL y){
	if (x==0) return y;
	if (x==1) return 1;
	return gys(y%x,x);
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<=n;++i){
		read(edge[i][0]);
		if (edge[i][0]==0) ans[++tot]=i;
		for (int j=1;j<=edge[i][0];++j){
			read(edge[i][j]);
			int x=edge[i][j];
			h[x]++;
		}
	}
	for (int i=1;i<=m;++i){
		q.push(i);
		a[i][0]=a[i][1]=1;
	}
	memset(vis,0,sizeof(vis));
	while (!q.empty()){
		int now=q.front();
		q.pop();
		if (h[now]){
			q.push(now);
			continue;
		}
		LL fenzi=a[now][0],fenmu=a[now][1]*edge[now][0];
		for (int i=1;i<=edge[now][0];++i){
			int ver=edge[now][i];
			if (!vis[ver]) q.push(ver),vis[ver]=1;
			if (h[ver]>0) h[ver]--;
			if (a[ver][0]==0){
				a[ver][0]=fenzi;
				a[ver][1]=fenmu;
			}else{
				a[ver][0]=a[ver][0]*fenmu+fenzi*a[ver][1];
				a[ver][1]=a[ver][1]*fenmu;
				LL MOD=gys(a[ver][0],a[ver][1]);
				a[ver][0]/=MOD,	a[ver][1]/=MOD;
			}
		}
	}
	
	for (int i=1;i<=tot;++i){
		int MOD=gys(a[ans[i]][0],a[ans[i]][1]);
		a[ans[i]][0]/=MOD,	a[ans[i]][1]/=MOD;
		printf("%lld %lld\n",a[ans[i]][0],a[ans[i]][1]);
	}
	return 0;
}

