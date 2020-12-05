#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 500005
using namespace std;
typedef long long ll;
int n,m,d[MAXN],output[MAXN];
int deg[MAXN],head[MAXN],ver[MAXM<<1],nxt[MAXM<<1],tot;
ll p[MAXN],q[MAXN];

void AddEdge(int x,int y){
	++deg[y],ver[tot]=y,nxt[tot]=head[x],head[x]=tot++;
}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(nxt,-1,sizeof(nxt));
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>d[i];
		for(int j=0,a;j<d[i];++j)
			cin>>a,AddEdge(i,a);
		if(!d[i]) output[++output[0]]=i;
	}
	queue<int> que;
	for(int i=1;i<=m;++i)
		p[i]=q[i]=1,que.push(i);
	while(!que.empty()){
		int nod=que.front(); que.pop();
		for(int i=head[nod];~i;i=nxt[i]){
			int to=ver[i];
			ll a=p[nod]/gcd(p[nod],d[nod]);
			ll b=d[nod]/gcd(p[nod],d[nod])*q[nod];
			if(!(p[to]+q[to])) p[to]=a,q[to]=b;
			else {
				ll c=q[to]/gcd(b,q[to])*a+b/gcd(b,q[to])*p[to];
				ll d=b/gcd(b,q[to])*q[to];
				ll e=gcd(c,d);
				p[to]=c/e,q[to]=d/e;
			}
			if(--deg[to]==0) que.push(to);
		}
	}
	for(int i=1;i<=output[0];++i)
		cout<<p[output[i]]<<' '<<q[output[i]]<<endl;
	return 0;
}
