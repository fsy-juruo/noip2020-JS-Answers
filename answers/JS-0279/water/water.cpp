#include<bits/stdc++.h>
#define ull unsigned long long
#define F first
#define S second
using namespace std;
int n,m;
int d[100010],v[100010][7];
int deg[100010],s[100010];
ull dp[100010];
ull inf=604661760000000000ull;
ull GCD(ull x,ull y){
	if(y==0)
		return x;
	return GCD(y,x%y);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			scanf("%d",&v[i][j]);
			deg[v[i][j]]++;
		}
	}
	int cnt=1;
	for(int i=1;i<=n;i++)
		if(deg[i]==0){
			s[cnt]=i;
			cnt++;
		}
	for(int i=1;i<=n;i++){
		int p=s[i];
		for(int j=1;j<=d[p];j++){
			deg[v[p][j]]--;
			if(deg[v[p][j]]==0){
				s[cnt]=v[p][j];
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		dp[i]=inf;
	for(int i=1;i<=n;i++){
		int p=s[i];
		for(int j=1;j<=d[p];j++)
			dp[v[p][j]]+=dp[p]/d[p];
	}
	for(int i=1;i<=n;i++)
		if(d[i]==0){
			ull x=dp[i],y=inf;
			ull g=GCD(x,y);
			cout<<x/g<<" "<<y/g<<endl;
		}
	return 0;
}
