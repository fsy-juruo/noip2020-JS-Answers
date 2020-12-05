//freopen unenabled.
#include<bits/stdc++.h>
using namespace std;
int n,m,t1,t2,rt;
vector<int> to[100001];
pair<int,int> sol[100001];
bool ala[100001]; //true -> outPoint
bool directed[100001];
int GCD(int a,int b) { //calc gcd
	int c;
	while(a%b!=0) {
		c=a%b;
		a=b;
		b=c;
	}
	return min(a,b);
}
pair<int, int> fracAdd(int a,int b,int c,int d) { //calc a/b + c/d with gcd. Don't worry.
	int above = a*d+b*c;
	int below = b*d;
	//cerr<<"above,below="<<above<<","<<below<<endl;
	int f = GCD(above,below);
	//cerr<<"f="<<f<<endl;
	above /= f;
	below /= f;
	pair<int, int> l;
	l.first = above;
	l.second = below;
	return l;
}
void dfs(int p) {
	//cerr<<"I Running on pt "<<p<<endl;
	if(ala[p]) {
		return;
	}
	//cerr<<"II Running on pt "<<p<<endl;
	int towards = to[p].size();
	for(int i=0;i<towards;i++) {
		//cerr<<"III Running on pt "<<p<<endl;
		sol[to[p][i]] = fracAdd(sol[p].first,sol[p].second*towards,sol[to[p][i]].first,sol[to[p][i]].second);
		dfs(to[p][i]);
	}
	sol[p]=make_pair(0,1);
	return;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>t1;
		if(t1==0) ala[i]=true;
		for(int j=1;j<=t1;j++) {
			cin>>t2;
			directed[t2]=true;
			to[i].push_back(t2);
		}
	}
	for(int i=1;i<=n;i++) {
		sol[i].second=1;
		if(i<=m) sol[i].first += sol[i].second;
	}
	//cerr<<"OK1"<<endl;
	for(int i=1;i<=n;i++) {
		//cerr<<"OK2 on pt "<<i<<endl;
		if(!directed[i]) { 
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++) {
		if(ala[i]) cout<<sol[i].first<<" "<<sol[i].second<<endl;
	}
	return 0;
}
