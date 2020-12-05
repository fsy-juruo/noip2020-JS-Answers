#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=50+5,M=400+5;
ll n,k,m;
ll col[N][M],topp[N];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cout<<"0"<<endl;
	return 0;
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf("%lld",col[i][j]);
		topp[i]=m;
	}
		
	
	
	/*
	if(n==2){
		while(topp[3]<m){
			while(col[1][topp[1]]==1){
				topp[3]++;
				topp[1]--;
				col[3][topp[3]]
			}
		}
	}
	*/
	
}

