#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector <int > a[100005];
int q[1000005],h,r;
int n,m,tot;
int d[100005],e[100005],ansp[100005],ansq[100005],vis[100005];
void add(int x,int pp,int qq){
	int ppp=ansp[x]*qq+pp*ansq[x],qqq=qq*ansq[x];
	int t=min(ppp,qqq);
	for(int i=t;i>=1;i--){
		if(ppp%i==0 && qqq%i==0){
			ansp[x]=ppp/i;ansq[x]=qqq/i;
			break;
		}
	}
//	ansp[x]=ppp;ansq[x]=qqq;
}
void put(int x,int y){
	int t=min(x,y);
	for(int i=t;i>1;i--){
		if(x%i==0 && y%i==0){
			cout<<x/i<<' '<<y/i<<'\n';
			break;
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]==0) e[++tot]=i;
		for(int j=1;j<=d[i];j++){
			int x;
			cin>>x;
			a[i].push_back(x);
		}
		ansq[i]=1;
	}
	for(int i=1;i<=m;i++){
		vis[i]==1;
		r++;
		q[r]=i;
		ansp[i]=1;
	}
	h=1;
	while(r>=h){
		if(d[q[h]]!=0){
				int w;
			if(ansp[q[h]]%d[q[h]]==0){
				ansp[q[h]]=ansp[q[h]]/d[q[h]];
				w=ansq[q[h]];
			}
			else w=ansq[q[h]]*d[q[h]];
			for(int i=0;i<a[q[h]].size();i++){
				int v=a[q[h]][i];
				if(vis[v]==0){r++;q[r]=v;vis[v]=1;}
				add(v,ansp[q[h]],w);
			}
			ansp[q[h]]=0;
			ansq[q[h]]=1;
		}
		vis[q[h]]=0;
		h++;
	}
	for(int i=1;i<=tot;i++){
//		put(ansp[e[i]],ansq[e[i]]);
		cout<<ansp[e[i]]<<' '<<ansq[e[i]]<<'\n';
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
