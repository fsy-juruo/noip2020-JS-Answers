//water 8:37-
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int n,m,numout,num;
bool in[MAXN];
int may(int p,int q){
	if(q>p) p^=q,q^=p,p^=q;
	int u=p%q;
	while(u!=0){
		p=q;
		q=u;
		u=p%q;
	}
	return q;
}
queue<int> que;
struct node{
	int q,p;
	//  q
	// ---
	//  p
	node(){
		q=0;
		p=1;
	}
	void y(){
		int u=may(p,q);
		if(u==1) return ;
		p/=u;
		q/=u;
		return ;
	}
	void in(int a,int b){
		p=b;
		q=a;
		y();
		return ;
	}
	void pl(node b){
		if(p==b.p){
			q+=b.q;
			y();
			return ;
		}
		//system("pause");
		int u=p*b.p/may(p,b.p);
		
		q=q*u/p+b.q*u/b.p;
		p=u;
		y();
		return ;
	}
	void pr(){
		y();
		printf("%d %d\n",q,p);
		return ;
	}
}point[MAXN],flow;
vector<int> g[MAXN];
void rush(int p){
	if(g[p][0]==0){
		/*
		printf("rush(%d):",p);
		point[p].pr();
		*/
		return ;
	}
	flow.in(point[p].q,point[p].p*g[p][0]);
	/*
	printf("rush(%d):",p);
	flow.pr();
	*/
	for(int i=1;i<g[p].size();i++) point[g[p][i]].pl(flow);
	for(int i=1;i<g[p].size();i++) if(!in[g[p][i]]) in[g[p][i]]=true,que.push(g[p][i]);
	point[p].q=0;
	return ;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int c;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		g[i].push_back(num);
		if(num==0){
			numout++;
			continue;
		}
		for(int j=1;j<=num;j++){
			scanf("%d",&c);
			g[i].push_back(c);
		}
	}
	for(int i=1;i<=m;i++) point[i].in(1,1),que.push(i),in[i]=true;
	while(!que.empty()){
		if(point[que.front()].q!=0) rush(que.front());
		que.pop();
	}
	for(int i=1;i<=n;i++) if(g[i][0]==0) printf("%d %d\n",point[i].q,point[i].p);
	return 0;
}
