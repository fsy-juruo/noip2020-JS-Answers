#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct V{
   long long p,q;
};
struct Node{
	int x,y;
};
V sl[N];//每个节点的水量 
vector<int>g[N];//存图 
int in[N];//记录入度判断接收口，入度为0的都是接收口
int n,m; 
void init(){
	int i;
	for(i=1;i<=n;i++){
		sl[i].q=1;
	}//水量初始化
	return; 
}
int gcd(long long a,long long b){
	if(a%b==0)return b;
	gcd(b,a%b);
}
void js(int t,long long p1,long long q1){
	sl[t].p=sl[t].p*q1+p1*sl[t].q;
	sl[t].q=sl[t].q*q1;
	int x=gcd(max(sl[t].p,sl[t].q),min(sl[t].p,sl[t].q));
	sl[t].p/=x;
	sl[t].q/=x;
}
void search(int t,long long p1,long long q1){
	if(g[t].size()==0)return;
	sl[t].p=0;sl[t].q=1;//水都流走了 
	int x=g[t].size(),i;
	for(i=0;i<x;i++){
		int y=g[t][i];
		js(y,p1,q1*x);
		search(y,p1,q1*x); 
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int i;
	init();
	for(i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		if(t==0)continue;
		for(int j=1;j<=t;j++){
			int x;
			scanf("%d",&x);
			g[i].push_back(x);
			in[x]++;
		}
	}
	for(i=1;i<=n;i++){
		if(in[i]==0){
			search(i,1,1);
		}
	}
	for(i=1;i<=n;i++){
		if(g[i].size()==0){
			cout<<sl[i].p<<" "<<sl[i].q<<endl;
		}
	}
	return 0;
}
