#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
int n,m,k,x,y;
queue<int>qu;
int sz[100086];
vector<int>ed[100086],lst;
bool inqu[100086];
ll son[100086],mon[100086];
void add(int to,ll s,ll mo){
	ll anss=son[to];
	ll ansm=mon[to];
	if(son[to]==0){
		anss=s;
		ansm=mo;
	}else{
		anss*=mo;
		ansm*=mo;
		s*=mon[to];
		mo*=mon[to];
		anss+=s;
	}
	while(anss%2==0&&ansm%2==0)anss/=2,ansm/=2;
	while(anss%3==0&&ansm%3==0)anss/=3,ansm/=3;
	while(anss%5==0&&ansm%5==0)anss/=5,ansm/=5;
	son[to]=anss;
	mon[to]=ansm;
		
}
void bfs(){
	while(!qu.empty())qu.pop();
	memset(inqu,false,sizeof(inqu));
	for(int i=1;i<=m;i++){
		qu.push(i);
		son[i]=mon[i]=1;
		inqu[i]=true;
	}
	while(!qu.empty()){
		int rt=qu.front();
		for(int i=0;i<sz[rt];i++){
			int to=ed[rt][i];
			if(!inqu[to]){
				inqu[to]=true;
				qu.push(to);
				add(to,son[rt],mon[rt]*sz[rt]);
			}else{
				add(to,son[rt],mon[rt]*sz[rt]);
			}
		}
		qu.pop();
		if(sz[rt]!=0){
			mon[rt]=1;
			son[rt]=0;
		}
		inqu[rt]=false;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&y);
			ed[i].pb(y);
		}
		if(k==0)lst.pb(i);
	}
	for(int i=1;i<=n;i++)sz[i]=ed[i].size();
	bfs();
	int p=lst.size();
	for(int i=0;i<p;i++){
		printf("%lld %lld\n",son[lst[i]],mon[lst[i]]);
	}
}
/*
5 1
3 2 3 5
2 4 5
2 4 5
0
0
*/
