#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
//rp++!
int n,k;
int w[15];
int c[500005],d[500005];
int ans;
using namespace std;
void dfs(vector<int> x){
	vector<int> y;
	for(int i=0;i<(int)x.size();i++) y.pb(x[i]);
	int cnt=0;
	int i;
	for(i=1;i<=n;i++){
		y[c[i]-1]+=d[i];
		cnt++;
		if(y[c[i]-1]<1 || y[c[i]-1]>w[c[i]]) break;
	}
	if(i==n+1){
		bool flag=1;
		for(int j=0;j<(int)x.size();j++)
			if(x[j]!=y[j])
				flag=0;
		if(flag==1){
			puts("-1");
			exit(0);
		}
		else{
			flag=1;
			while(flag){
				for(int j=1;j<=n;j++){
					y[c[j]-1]+=d[j];
					cnt++;
					if(y[c[j]-1]<1 || y[c[j]-1]>w[c[j]]){
						flag=0;
						break;
					}
				}
			}
		}	
	}
	ans+=cnt;
	bool fin=1;
	for(int i=0;i<(int)x.size();i++)
		if(x[i]!=w[i+1]) fin=0;
	if(fin) return;
	for(int i=0;i<(int)x.size();i++)
		if(x[i]<w[i+1]){
			x[i]++;
			break;
		}
		else
			x[i]=1;
	dfs(x);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	//remember to use freopen!
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&c[i],&d[i]);
	if(n>1000) puts("-1");
	vector<int> now;
	for(int i=1;i<=k;i++) now.pb(1);
	dfs(now);
	printf("%d\n",ans);
	return 0;
}
//remember to use long long or unsigned long long
//remember to clear the...array?
//remember to read problems carefully
//think carefully before writing
/*
3 2
3 3
1 1
2 -1
1 1
*/
