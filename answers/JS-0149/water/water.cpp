#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[100001],fz[100001],fm[100001];
int a[100001][6];
void dfs(int s){
	if(f[s]){
		long long g=fm[s]*f[s],j=fz[s],v=__gcd(g,j);
		g/=v;
		j/=v;
		fm[s]=0;
		fz[s]=0;
		for(int i=1;i<=f[s];i++){
			if(fm[a[s][i]]==0){
				fm[a[s][i]]=g;
				fz[a[s][i]]=j;
			}
			else{
				v=__gcd(g,fm[a[s][i]]);
				v=g*fm[a[s][i]]/v;
				fz[a[s][i]]=v/fm[a[s][i]]*fz[a[s][i]]+v/g*j;
				fm[a[s][i]]=v;
				v=__gcd(fm[a[s][i]],fz[a[s][i]]);
				fm[a[s][i]]/=v;
				fz[a[s][i]]/=v;
			}
			dfs(a[s][i]);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		for(int j=1;j<=f[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		if(fm[i]==0){
			fm[i]++;
			fz[i]++;
		}
		else{
			fz[i]+=fm[i];
		}
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			cout<<fz[i]<<' '<<fm[i]<<endl;
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0 0
*/
