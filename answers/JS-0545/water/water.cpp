#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	gcd(b,a%b);
}



int n,m;
vector<int> nei[100005];
vector<int> wor[100005];
void dfs(int x,ll val){
	if(nei[x].size()==0){
		wor[x].push_back(val);
	}
	for(int i=0;i<nei[x].size();i++){
		dfs(nei[x][i],val*ll(nei[x].size()));
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t==0){
			continue;
		}
		for(int j=0;j<t;j++){
			int a;
			scanf("%d",&a);
			a--;
			nei[i].push_back(a);
		}
	}
	for(int i=0;i<m;i++){
		dfs(i,1);
	}
	for(int j=0;j<n;j++){
		if(wor[j].size()!=0){
			ll a=1,b=0;
			for(int i=0;i<wor[j].size();i++){
				a=wor[j][i]*a/gcd(wor[j][i],a);
			}
			for(int i=0;i<wor[j].size();i++){
				b+=a/wor[j][i];
			}
			//printf("%d %d\n",b,a);
			ll c=gcd(a,b);
			a/=c;
			b/=c;
			printf("%lld %lld\n",b,a);
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
