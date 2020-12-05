#include <bits/stdc++.h>

using namespace std;

const int N=100005;

//int
//int
int n,m;
bool pai[N];
vector<int> G[N];
long long ansp[N],ansq[N];

void ADD(int x,long long p){
	if(ansp[x]==0){
		ansp[x]=1;
		ansq[x]=p;
	}else{//+1/p
		/*if(p>ansq[x]){
			int P=p;
			while(P%ansq[x]!=0){
				P+=p;
			}
			ansp[x]=P/p+ansp[x]*P/ansq[x];
			ansq[x]=P;
		}else{//1/6+1/12=2/12+1/12
			int P=ansq[x];
			while(P%p!=0){
				P+=ansq[x];
			}
			ansp[x]=P/p+ansp[x]*P/ansq[x];
			ansq[x]=P;
		}*/
		ansp[x]=ansp[x]*p+ansq[x];
		ansq[x]=ansq[x]*p;
		if(p<ansq[x]){
			for (int i=ansp[x];i>=2;i--){
				while(ansp[x]%i==0 && ansq[x]%i==0){
					ansp[x]=ansp[x]/i;
					ansq[x]=ansq[x]/i;
				}
			}
		}
	}
}

void dfs(int x,long long p){
	if(pai[x]==true){
		ADD(x,p);
		return;
	}
	for (int i=0;i<G[x].size();i++){
		dfs(G[x][i],p*G[x].size());
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a==0){
			pai[i]=true;
			continue;
		}
		for (int j=1;j<=a;j++){
			int y;
			scanf("%d",&y);
			G[i].push_back(y);
		}
	}
	for (int i=1;i<=m;++i){
		dfs(i,1);
	}
	for (int i=1;i<=n;++i){
		if(pai[i]==true){
			printf("%lld %lld\n",ansp[i],ansq[i]);
		}
	}
	//printf("%d",);
	return 0;
} 
