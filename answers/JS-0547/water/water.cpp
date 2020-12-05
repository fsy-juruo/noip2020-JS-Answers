#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int n,m,d[N],f[N],cnt,head[N];
struct node{
	int to,next;
}edge[N*5];
struct ed{
	int p,q;
}ans[N];
queue<int>q;
void read(int &x){
	x=0; int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}
void add_edge(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void add(int x,int y){
	int pa=ans[x].p,qa=ans[x].q;
	int pb=ans[y].p,qb=ans[y].q;
	int k=d[x],g;
	g=gcd(pa*qb+k*pb*qa,k*qa*qb);
	ans[y]=(ed){(pa*qb+k*pb*qa)/g,(k*qa*qb)/g};
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;i++){
		read(d[i]);
		for(int j=1;j<=d[i];j++){
			int x; read(x);
			add_edge(i,x);
			f[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			q.push(i);
			ans[i].p=1; ans[i].q=1;
		}
		else ans[i].q=1;
	}
	while(!q.empty()){
		int tmp=q.front(); q.pop();
		for(int i=head[tmp];i;i=edge[i].next){
			int y=edge[i].to;
			f[y]--;
			add(tmp,y);
			if(!f[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!d[i]) printf("%I64d %I64d\n",ans[i].p,ans[i].q);
	return 0;
}
