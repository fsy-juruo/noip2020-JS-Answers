#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;
int n,m;
const int N=100010;
const int M=1000010;
int c;
int point[N];//the point point to line
int to[M];//line point to y
int nex[M];//line points to line
void addEdge(int x, int y){
	++c;
	to[c]=y;
	nex[c]=point[x];
	point[x]=c;
}
long long gcd(long long a,long long b){
	if(b==0)return a;
	int  r=a%b;
	a=b,b=r;
	return gcd(a,b);
}
long long num[N]={0};
bool isOut[N];
pair<long long,long long> q[N];
bool vis[N];
pair<int,int> Add(pair<long long,long long> a, pair<long long,long long> b){
	long long up=a.first*b.second+a.second*b.first;
	long long down=a.second*b.second;
	long long g=gcd(up,down);
	up/=g;
	down/=g;
	return make_pair(up,down);
}
pair<int,int> Chu(pair<long long,long long> a, long long b){
	long long g=gcd(a.first,b);
	b/=g;
	a.first/=g;
	long long qw=a.second*b;
	return make_pair(a.first,qw);
}
void bfs(int x){
	queue<int> p;
	p.push(x);
	vis[x]=true;
	while(!p.empty()){
		int now=p.front();
		//cout<<"now "<<now<<endl;
		p.pop();
		for(int i=point[now];i;i=nex[i]){
			int j=to[i];
			pair<long long,long long> tt=Chu(q[now],num[now]);
			pair<long long,long long>tmp=q[j];
			//cout<<"tmp "<<" "<<tmp.first<<"/"<<tmp.second<<endl;;
			q[j]=Add(tt,tmp);
			//cout<<"j "<<j<<" "<<q[j].first<<"/"<<q[j].second<<endl;;
			if(!vis[j])p.push(j);
			vis[j]=true;
		}
		if(num[now]){q[now].first=0;q[now].second=1;}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=tmp;j++){
			int a;
			cin>>a;
			isOut[a]=true;
			addEdge(i,a);
			
		}
		num[i]=tmp;
	}
	for(int i=1;i<=n;i++){
		if(!isOut[i]){
			q[i].first=1;
		}
	}
	for(int i=1;i<=n;i++){
		q[i].second=1;
	}
	for(int i=1;i<=n;i++){
		if(!isOut[i]&&!vis[i]){
			bfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(num[i]==0){
			cout<<q[i].first<<" "<<q[i].second<<endl;;
		}
	}
	return 0;
}
