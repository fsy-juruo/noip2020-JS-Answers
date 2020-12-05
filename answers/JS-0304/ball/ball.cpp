#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int ac[52][20001],a[52][20001];
int yc[52],y2[52];
int x[52][2];
void count(int x){
	while(yc[x]!=0){
		if(ac[x][yc[x]]<x){
			ac[ac[x][yc[x]]][++yc[ac[x][yc[x]]]]=ac[x][yc[x]];
//			cout<<x<<" "<<a[x][y[x]]<<'\n';
		}
		else{
			ac[ac[x][yc[x]]+1][++yc[ac[x][yc[x]]+1]]=ac[x][yc[x]];
//			cout<<x<<" "<<a[x][y[x]]+1<<'\n';
		}
		yc[x]--;
		cnt++;
	}
}
void solve(int x){
	while(y2[x]!=0){
		if(a[x][y2[x]]<x){
			a[a[x][y2[x]]][++y2[a[x][y2[x]]]]=a[x][y2[x]];
			cout<<x<<" "<<a[x][y2[x]]<<'\n';
		}
		else{
			a[a[x][y2[x]]+1][++y2[a[x][y2[x]]+1]]=a[x][y2[x]];
			cout<<x<<" "<<a[x][y2[x]]+1<<'\n';
		}
		y2[x]--;
	}
}
int main(){
  	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		yc[i]=m,y2[i]=m;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			ac[i][j]=a[i][j];
		}
//		x[i][a[i][1]]=1;
//		for(int j=2;j<=m;j++){
//			if(a[i][j]==a[i][j-1])
//				x[i][a[i][1]]++;
//		}
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		count(i);
		ans+=cnt;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		solve(i);
	}
//	for(int i=1;i<=n+1;i++){
//		for(int j=1;j<=y2[i];j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
