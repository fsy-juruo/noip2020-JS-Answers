#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long w[52][500]={0};
int size[52];
int mb[52];
int ans1[820001],ans2[820001];
void yb(int a,int b){
	if(size[a]==b){
		if(size[w[a][b]]<=m-1) {
			size[w[a][b]]++;
			w[w[a][b]][size[w[a][b]]]=w[a][b];
			size[a]--;
			ans++;
			ans1[ans]=a,ans2[ans]=w[a][b];
		}
		else{
			size[n+1]++;
			w[n+1][size[n+1]]=w[a][b];
			size[a]--;
			ans++;
			ans1[ans]=a,ans2[ans]=n+1;
		}
	}
	else{
		yb(a,b+1);
		yb(a,b);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=51;i++) size[i]=m;
	size[n+1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>w[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=size[i];j++){
			if(w[i][j]!=i)
				yb(i,j);
		}
	}
	while(size[n+1]>=1){
		ans++;
		ans1[ans]=n+1;
		ans2[ans]=w[n+1][size[n+1]];
		size[w[n+1][size[n+1]]]++;
		w[w[n+1][size[n+1]]][size[w[n+1][size[n+1]]]]=w[n+1][size[n+1]];
		size[n+1]--;
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	return 0;
}
