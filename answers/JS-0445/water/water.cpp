#include<bits/stdc++.h>
using namespace std;
#define int long long
struct{
	int to,next;
}edge[500010];
int E,V;
int head[100010];
int end[100010];
int eout[100010];
pair<int,int> am[100010];
const pair<int,int> zero=pair<int,int>(0,0);
void gcd(pair<int,int> &p){
	int a=p.first,b=p.second,r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	p.first/=b;
	p.second/=b;
}
pair<int,int> add(pair<int,int> a,pair<int,int> b){
	if(a==zero || b==zero){
		a.first+=b.first;
		a.second+=b.second;
		return a;
	}
	if((int)(log10(a.second))+(int)(log10(b.second))>=16 ||
	(int)(log10(a.first))+(int)(log10(b.second))>=16 ||
	(int)(log10(a.second))+(int)(log10(b.first))>=16){
		gcd(a);
		gcd(b);
	}
	pair<int,int> c;
	c.second=a.second*b.second;
	c.first=a.first*b.second+a.second*b.first;
	return c;
}
pair<int,int> divide(pair<int,int> a,int b){
	if((int)(log10(a.second))+(int)(log10(b))>=16)
		gcd(a);
	a.second*=b;
	return a;
}
void bfs(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int fr=q.front();
		q.pop();
		if(end[fr])
			continue;
		pair<int,int> curam=am[fr];
		am[fr]=zero;
		curam=divide(curam,eout[fr]);
		for(int cur=head[fr];cur!=-1;cur=edge[cur].next){
			am[edge[cur].to]=add(am[edge[cur].to],curam);
			q.push(edge[cur].to);
		}
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	V=n;
	for(int i=1;i<=n;i++)
		head[i]=-1;
	for(int i=1;i<=n;i++){
		int d;
		scanf("%lld",&d);
		eout[i]=d;
		if(d==0)
			end[i]=1;
		for(int j=1;j<=d;j++){
			int v;
			scanf("%lld",&v);
			E++;
			edge[E].to=v;
			edge[E].next=head[i];
			head[i]=E;
		}
	}
	for(int i=1;i<=m;i++){
		am[i].first=1;
		am[i].second=1;
		bfs(i);
	}
	for(int i=1;i<=V;i++)
		if(end[i]){
			gcd(am[i]);
			printf("%lld %lld\n",am[i].first,am[i].second);
		}
	return 0;
}
/*
5
1
3
2 3 5
2
4 5
2
5 4
0
0
*/
