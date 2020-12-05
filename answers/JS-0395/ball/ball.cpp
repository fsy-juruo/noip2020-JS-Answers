#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][405],num[55][55],co[55],ul[55],ans1[820005],ans2[820005],cnt,size[405];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		cin>>a[i][j];
		num[i][a[i][j]]++;
	}
	for(int i=1;i<=n;++i){
		int maxn=-1,maxi=0;
		for(int j=1;j<=n;++j){
			if(num[j][i]>maxn&&!ul[j]) maxn=num[j][i],maxi=j;
		}
		co[i]=maxi;
		ul[maxi]=1;
	}
	for(int i=1;i<=n;++i) size[i]=m;
	//for(int i=1;i<=n;++i) cout<<co[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		int l=co[i],tot=0;
		int sb=size[l];//cout<<sb<<endl;
		for(int j=sb;j>=1;--j){
			//cout<<j<<":"<<a[l][j]<<endl;
			if(a[l][j]!=i){
				tot++;
				int ch=n+1,u=co[a[l][j]];
				for(int k=1;k<=sb-j;++k) ans1[++cnt]=l,ans2[cnt]=ch;
				ans1[++cnt]=l,ans2[cnt]=u;
				for(int k=1;k<=sb-j;++k) ans1[++cnt]=ch,ans2[cnt]=l;a[u][m+tot]=a[l][j];
				a[l][j]=a[l][j+1],a[l][m-tot+1]=0;
				size[l]--,size[u]++;
			}
		}
		//for(int i=1;i<=n;++i) cout<<size[i]<<" ";cout<<endl;
		//for(int j=m-tot+1;j<=m;++j) a[l][j]=0;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i) cout<<ans1[i]<<" "<<ans2[i]<<endl;
	return 0;
}
