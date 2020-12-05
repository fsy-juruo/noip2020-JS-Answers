#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;

struct Node{
	int to,nxt;
}E[N*2];
int H[N],tot;
void add(int u,int v){
	tot++;
	E[tot].to=v;
	E[tot].nxt=H[u];
	H[u]=tot;
}
queue<int> Q;
int ind[N];
ll gcd(ll a,ll b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
struct node{
	ll fz,fm;
}wat[N];
node ad(node a,node b){
	node p;
	p.fz=a.fz*b.fm+b.fz*a.fm;
	p.fm=a.fm*b.fm;
	int t=gcd(p.fz,p.fm);
	p.fz/=t;p.fm/=t;
	return p;
}
ll nn[N];
ll out[N],tt;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)wat[i].fm=1,wat[i].fz=0;
	for(int i=1;i<=n;i++){
		if(i<=m){
			Q.push(i);
			wat[i].fz=1;
			wat[i].fm=1;
		}
		ll k;
		cin>>k;
		nn[i]=k;
		if(k==0){
			out[++tt]=i;
		}
		for(int j=1;j<=k;j++){
			int u;
			cin>>u;
			add(i,u);
			ind[u]++;
		}
	}
	while(!Q.empty()){
		int p=Q.front();Q.pop();
		if(nn[p]==0)continue;
		wat[p].fm*=nn[p];
		for(int i=H[p];i!=0;i=E[i].nxt){
			int v=E[i].to;
			wat[v]=ad(wat[v],wat[p]);
			ind[v]--;
			if(ind[v]==0)Q.push(v);
		}
//		cout<<p;
	}
	for(int i=1;i<=tt;i++){
		cout<<wat[out[i]].fz<<' '<<wat[out[i]].fm<<endl;
	}
	return 0;
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0


*/
