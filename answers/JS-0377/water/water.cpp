#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> ans[100010];
int d[100010];
long long zdgys(long long a,long long b){
	if(b==0ll)
	return a;
	return zdgys(b,a%b);
}
pair<long long,long long> fsjf(pair<long long,long long> a,pair<long long,long long> b){
	long long x=a.second,y=b.second;
	long long zzdgys=zdgys(x,y);
	pair<long long,long long> res;
	res.first=a.first*(y/zzdgys)+b.first*(x/zzdgys);
	x/=zzdgys;
	zzdgys=zdgys(x,res.first);
	x/=zzdgys;
	res.first/=zzdgys;
	zzdgys=zdgys(y,res.first);
	y/=zzdgys;
	res.first/=zzdgys;
	res.second=x*y;
	return res;
}
int n,m;
vector<int> v[100010],e[100010];
void dfs(int x){
	if(ans[x].second!=-1)
	return;
	ans[x].first=0;
	ans[x].second=1;
	for(int i=0;i<(int)(e[x].size());i++){
		dfs(e[x][i]);
		pair<long long,long long> now=ans[e[x][i]];
		now.second*=d[e[x][i]]/zdgys(now.first,d[e[x][i]]);
		now.first/=zdgys(now.first,d[e[x][i]]);
		ans[x]=fsjf(ans[x],now);
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
		for(int j=0;j<d[i];j++){
			int x;
			cin>>x;
			x--;
			v[i].push_back(x);
			e[x].push_back(i);
		}
	}
	for(int i=0;i<n;i++)
	ans[i].second=-1;
	for(int i=0;i<m;i++){
		ans[i].first=1;
		ans[i].second=1;
	}
	for(int i=0;i<n;i++){
		if(d[i]==0)
		dfs(i);
	}
	for(int i=0;i<n;i++){
		if(d[i]==0)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}
