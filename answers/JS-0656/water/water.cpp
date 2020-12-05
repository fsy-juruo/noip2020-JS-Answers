#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
queue<pair<int,pair<int,int> > > q;
pair<int,int> ns[100010];
int rd[100010];
int n,m;
pair<int,int> yf(pair<int,int> x){
	int a=x.first;
	int b=x.second;
	int t=__gcd(a,b);
	return make_pair(a/t,b/t);
}
pair<int,int> pls(pair<int,int> a,pair<int,int> b){
	if(a.first==0)
		return b;
	if(b.first==0)
		return a;
	int ap=a.first;
	int aq=a.second;
	int bp=b.first;
	int bq=b.second;
	int sq=aq*bq/__gcd(aq,bq);
	int sp=ap*(sq/aq)+bp*(sq/bq);
	return yf(make_pair(sp,sq));
}
void bfs(){
	int cn,cs,cp,cq,tn;
	for(int i=1;i<=m;i++)
		ns[i]=make_pair(1,1);
	for(int i=1;i<=n;i++)
		if(!rd[i])	
			q.push(make_pair(i,ns[i]));
	while(!q.empty()){
		cn=q.front().first;
		cs=g[cn][0];
		cp=q.front().second.first;
		cq=q.front().second.second;
		q.pop();
		for(int i=1;i<=cs;i++){
			tn=g[cn][i];
			ns[tn]=pls(ns[tn],yf(make_pair(cp,cq*cs)));
			rd[tn]--;
			if(!rd[tn])
				q.push(make_pair(tn,ns[tn]));
		}
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		g[i].push_back(x);
		for(int j=1;j<=g[i][0];j++){
			cin>>x;
			g[i].push_back(x);
			rd[x]++;
		}
	}
	bfs();
	for(int i=1;i<=n;i++)
		if(!g[i][0])
			cout<<ns[i].first<<' '<<ns[i].second<<"\n";
	return 0;
}
