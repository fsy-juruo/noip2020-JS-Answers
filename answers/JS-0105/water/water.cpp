#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	ll f=0;
	for(;isdigit(c);c=getchar())f=f*10+(c-'0');
	return f;
}
int n,m;
vector<int> ed[101010];
vector<pair<int,ll> > ans;
ll gcd(ll p,ll q){
	if(q==0)return p;
	return gcd(q,p%q);
}
void dfs(int x,ll q){
	if(ed[x].size()==0)ans.push_back(make_pair(x,q));
	else for(int i=0;i<ed[x].size();i++) dfs(ed[x][i],q*ed[x].size());
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k=read();
		for(int j=0;j<k;j++)ed[i].push_back(read()-1);
	}
	for(int i=0;i<m;i++)dfs(i,1);
	sort(ans.begin(),ans.end());
	ll p=1,q=ans[0].second;
	for(int i=1;i<ans.size();i++){
		if(ans[i].first==ans[i-1].first){
			ll qq=q;
			q=q/gcd(qq,ans[i].second)*ans[i].second;
			p=q/qq*p+q/ans[i].second;
		}else{
			cout<<p/gcd(p,q)<<' '<<q/gcd(p,q)<<endl;
			p=1;q=ans[i].second;
		}
	}
	cout<<p/gcd(p,q)<<' '<<q/gcd(p,q)<<endl;
	return 0;
}
