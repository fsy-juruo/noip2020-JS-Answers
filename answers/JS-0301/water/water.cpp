#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int d,beginnode,endnode;
int endn[100010]={0};
int cnt=1;
long long g,G1,G2;

struct watr{
	int cntout[6];
	int cntn;
	long long water[2];
}node[100010];

queue<int> water;

long long gcd(long long a,long long b){
	if(a==0||b==0) return 1;
	if(a==b) return a;
	if(a<b){
		long long t=a;
		a=b;
		b=t;
	}
	return gcd(b,a-b);//gcd...maybe?I haven't learn this 
}

void check(int num){
	long long g0=gcd(node[num].water[0],node[num].water[1]);
	if(g0!=1){
		node[num].water[0]/=g0;
		node[num].water[1]/=g0;
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		if(d==0){
			endn[cnt]=i;
			cnt++;
		}
		node[i].cntn=d;
		for(int j=1;j<=d;j++){
			scanf("%d",&node[i].cntout[j]);
		}
		if(i<=m){
			node[i].water[0]=1;
			node[i].water[1]=1;
		}else{
			node[i].water[0]=0;
			node[i].water[1]=1;
		}
		water.push(i);
	}
	for(;water.empty()==false;){
		int beginnode=water.front();
		d=node[beginnode].cntn;
		if(d==0){
			water.pop();
			continue;
		}
		node[beginnode].water[1]*=d;
		for(int i=1;i<=d;i++){
			endnode=node[beginnode].cntout[i];
			g=gcd(node[beginnode].water[1],node[endnode].water[1]);
			G1=node[endnode].water[1]/g;
			G2=node[beginnode].water[1]/g;
			node[beginnode].water[0]=node[beginnode].water[0]*G1;
			node[endnode].water[0]=node[endnode].water[0]*G2;
			node[endnode].water[1]=node[endnode].water[1]*G2;
			node[endnode].water[0]+=node[beginnode].water[0];
			check(endnode);
//			water.push(endnode);
			node[beginnode].water[0]=node[beginnode].water[0]/G1;
		}
		node[beginnode].water[0]=0;
		node[beginnode].water[1]=1;
		water.pop();
	}
	for(int i=1;i<cnt;i++){
		printf("%lld %lld\n",node[endn[i]].water[0],node[endn[i]].water[1]);
	}
	return 0;
}

