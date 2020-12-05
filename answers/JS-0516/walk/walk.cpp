#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int MAX_N=1e5+10;

int N,K;
int w[MAX_N],c[MAX_N],d[MAX_N];
int pos[MAX_N],now[MAX_N];

int ans=0;

void getval(){
	for(int i=0;i<K;i++) now[i]=pos[i];
	int day=0,res=0;
	while(true){
		now[c[day]]+=d[day]; res++;
		if(now[c[day]]<1||now[c[day]]>w[c[day]]) break;
		day=(day+1)%N;
	}
	ans+=res;
//	for(int i=0;i<K;i++) cout<<pos[i]<<" "; cout<<endl;
//	cout<<res<<endl;
}

void getans(){
//	for(int i=0;i<K;i++) cout<<pos[i]<<" "; cout<<endl;
	getval();
	for(int i=K-1;i>=0;i--){
		pos[i]++;
		if(pos[i]>w[i]){
			if(i==0) return;
			pos[i]=1;
		}
		else break;
	}
	getans();
}

void solve1(){
	for(int i=0;i<K;i++) pos[i]=1;
	getans();
	printf("%d\n",ans);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++) scanf("%d",&w[i]);
	for(int i=0;i<N;i++) scanf("%d%d",&c[i],&d[i]),c[i]--;
	if(N<=100){
		solve1();
		return 0;
	}
}
