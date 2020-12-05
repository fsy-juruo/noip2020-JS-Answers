#include<bits/stdc++.h>
using namespace std;
bool g[1005][1005];
int w[1005][3];
int n,m;
void yue(int y){
	int n=w[y][1],m=w[y][2],t,shu;
	while(1){
		if(m%n==0){
			shu=n;
			break;
		}
		else{
			t=m%n;
			m=n;
			n=t;
		}
	}
	w[y][1]/=n;
	w[y][2]/=n;
}
void jia(int a,int b){
	if(w[a][1]==0||w[a][2]==0){
		w[a][1]=w[b][1];
		w[a][2]=w[b][2];
	}
	else{
		int gbs=max(w[a][2],w[b][2]);
		int miner=min(w[a][2],w[b][2]);
		while(gbs%miner) gbs+=gbs;
		w[a][1]=(gbs/w[a][2])*w[a][1];
		w[a][2]=gbs;
		w[b][1]=(gbs/w[b][2])*w[b][1];
		w[b][2]=gbs;
		w[a][1]+=w[b][1];
	}
}
void liu(int x){
	int chu=0;
	for(int i=1;i<=n;i++)
		if(g[x][i]) chu++;
	w[x][2]=w[x][2]*chu;
	for(int i=1;i<=n;i++)
		if(g[x][i]){
			jia(i,x);
			if(w[i][0]!=7) liu(i);
		}
}
int main(){
	freopen("water1.in","r",stdin);
	freopen("water1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,d;i<=m;i++){
		scanf("%d",&d);
		for(int j=1,a;j<=d;j++){
			scanf("%d",&a);
			g[i][a]=true;
		}
			w[i][1]=1;
			w[i][2]=1;
	}
	for(int i=m+1,d;i<=n;i++){
		scanf("%d",&d);
		if(!d){
			w[i][0]=7;
			continue;
		}
		else for(int j=1,a;j<=d;j++){
			scanf("%d",&a);
			g[i][a]=true;
		}
	}
	for(int i=1;i<=m;i++) liu(i);
	for(int i=1;i<=n;i++)
		if(w[i][0]==7){
			yue(i);
			printf("%d %d\n",w[i][1],w[i][2]);
		} 
	return 0;
}
