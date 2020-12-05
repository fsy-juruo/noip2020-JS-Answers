#include<bits/stdc++.h>
#define int long long
#define bug cout<<"bug: "<<__LINE__<<endl
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=100005;

int head[maxn],ver[maxn<<1],nxt[maxn<<1],tot;

void add(int u,int v){
	tot++;
	ver[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}

struct node{
	int fz,fm;
}w[maxn];

node add(node a,node b){
	int fz=0,fm=0;
	if(a.fz==0 && a.fm==0){
//		bug;
		return b;
	}
	if(b.fz==0 && b.fm==0){
//		bug;
		return a;
	}
	fm=a.fm*b.fm;
	fz=a.fz*b.fm+a.fm*b.fz;
//	cout<<fz<<" "<<fm<<endl;
	for(int i=2;i<=(long long)sqrt(min(fz,fm));i++){
		while(fz%i==0 && fm%i==0){
			fz/=i;
			fm/=i;
		}
	}
//	cout<<fz<<" "<<fm<<endl;
	if(fz>fm && fz%fm==0){
		fz/=fm;
		fm/=fm;
	}
	else if(fz==fm){
		fz=1;
		fm=1;
	}
	else if(fz<fm && fm%fz==0){
//		bug;
		fm/=fz;
		fz/=fz;
	}
//	cout<<fz<<" "<<fm<<endl;
	return (node){fz,fm};
}

int n,m;
int deg[maxn],isout[maxn],outdeg[maxn];

node hj(node a){
	int fz=a.fz,fm=a.fm;
	for(int i=2;i<=(long long)sqrt(min(fz,fm));i++){
		while(fz%i==0 && fm%i==0){
			fz/=i;
			fm/=i;
		}
	}
//	cout<<fz<<" "<<fm<<endl;
	if(fz>fm && fz%fm==0){
		fz/=fm;
		fm/=fm;
	}
	else if(fz==fm){
		fz=1;
		fm=1;
	}
	else if(fz<fm && fm%fz==0){
//		bug;
		fm/=fz;
		fz/=fz;
	}
//	cout<<fz<<" "<<fm<<endl;
	return (node){fz,fm};	
}

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
//	int fz1,fm1,fz2,fm2;
//	cin>>fz1>>fm1>>fz2>>fm2;
//	node a=add((node){fz1,fm1},(node){fz2,fm2});
//	cout<<a.fz<<" "<<a.fm<<endl;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		w[i].fm=1,w[i].fz=1;
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		outdeg[i]=t;
		for(int j=1;j<=t;j++){
			int v;
			cin>>v;
			add(i,v);
			deg[v]++;
		}
		if(t==0){
			isout[i]=1;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		cout<<x<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<w[i].fz<<" "<<w[i].fm<<endl;
//		}
		node tadd;
		tadd.fz=w[x].fz;
		tadd.fm=w[x].fm*outdeg[x];
		for(int i=head[x];i;i=nxt[i]){
			int v=ver[i];
			w[v]=add(w[v],tadd);
			deg[v]--;
			if(deg[v]==0){
				q.push(v);
			}
		}
//		cout<<"after:"<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<w[i].fz<<" "<<w[i].fm<<endl;
//		}
		if(outdeg[x]==0){
			continue;
		}
		w[x].fz=0;
		w[x].fm=0;
	}
	for(int i=1;i<=n;i++){
		if(isout[i]==1){
			w[i]=hj(w[i]);
			cout<<w[i].fz<<" "<<w[i].fm<<endl;
		}
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

