#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> gra[200005];
pair<int,int> ans[200005];
int gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return 1;
	return a%b==0?b:gcd(b,a%b);
}
pair<int,int> pluss(pair<int,int> a,pair<int,int> b){
	if(a.first==0)return b;
	if(b.first==0)return a;
	int gg=a.second/(int)(gcd(a.second,b.second))*b.second;
	pair<int,int> ret;
	ret.first=gg/a.second*a.first+gg/b.second*b.first;
	ret.second=gg;
	return make_pair(ret.first/gcd(ret.first,ret.second),ret.second/gcd(ret.first,ret.second));
}
pair<int,int> divide(pair<int,int> a,int b){
	return make_pair(a.first/gcd(a.first,b),a.second*(b/gcd(a.first,b)));
}
void dfs(int x){
	if(gra[x].size()==0)return ;
	for(int i=0;i<gra[x].size();i++){
		ans[gra[x][i]]=pluss(ans[gra[x][i]],divide(ans[x],gra[x].size()));
		dfs(gra[x][i]);
	}
	ans[x].first=0;
	ans[x].second=1;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int cnt[n+1];
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y;
			cin>>y;
			gra[i].push_back(y);
			cnt[y]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			ans[i].first=1;
			ans[i].second=1;
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(gra[i].size()==0){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
}

