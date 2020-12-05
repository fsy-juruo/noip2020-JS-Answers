#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long p;
	long long q;
}water[100010];
vector<int> inof[1000010];
vector<int> outof[1000010];
int n,m,d,x,cnt,num,init[100010],a[100010],outit[100010];
queue<int> q;
long long gcd(long long y,long long z){
	if(y%z==0) return z;
	else return gcd(z,y%z);
}
Node add(Node g,Node h){
	//g=g+h;
	Node ans;
	long long k=gcd(g.q,h.q);
	long long tmp1=g.q/k;
	long long tmp2=h.q/k;
	ans.p=g.p*tmp2+h.p*tmp1;
	ans.q=tmp1*tmp2*k;
	k=gcd(ans.p,ans.q);
	ans.p=ans.p/k;
	ans.q=ans.q/k;
	return ans;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		water[i].p=0;
		water[i].q=1;
		scanf("%d",&d);
		if(d==0){
			outit[++num]=i;
		}
		for(int j=1;j<=d;j++){
			scanf("%d",&x);
			outof[i].push_back(x);
			inof[x].push_back(i);
			init[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		water[i].p=1;
		water[i].q=1;
	}
	//sort
	for(int i=1;i<=n;i++){
		if(init[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		a[++cnt]=u;
		for(int i=0;i<outof[u].size();i++){
			int v=outof[u][i];
			init[v]--;
			if(init[v]==0){
				q.push(v);
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		int now=a[i];
		for(int j=0;j<outof[now].size();j++){
			int to=outof[now][j];
			Node tmp=water[now];
			tmp.q*=outof[now].size();
			water[to]=add(water[to],tmp);
		}
	}
	for(int i=1;i<=num;i++){
		printf("%lld %lld\n",water[outit[i]].p,water[outit[i]].q);
	}
	return 0;
}

