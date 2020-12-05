#include<bits/stdc++.h>
using namespace std;
set<long long>st;
int n,m,tmp;
vector<int>mp[55];
vector<pair<int,int> >ans;
bool cc(){
	long long ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<mp[i].size();j++){
			ans*=10;
			ans+=mp[i][j];
		}
		ans*=10;
	}
	int cnt=st.size();
	st.insert(ans);
	if(cnt==st.size()){
		return true;
	}
	return false;
}
void putans(){
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	exit(0);
}
void check(){
	for(int i=0;i<=n;i++){
		if(mp[i].size()!=m&&mp[i].size()!=0)
			return ;
		for(int j=1;j<mp[i].size();j++){
			if(mp[i][j]!=mp[i][0]){
				return ;
			}
		}
	}
	putans();
}
void dfs(int floor){
	check();
	if(floor==82000000){
		return;
	}
	if(cc()){
		return;
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==j||mp[j].size()==m){
				continue;
			}
			mp[j].push_back(mp[i][mp[i].size()-1]);
			mp[i].pop_back();
			ans.push_back(make_pair(i,j));
			dfs(floor+1);
			ans.pop_back();
			mp[i].push_back(mp[j][mp[j].size()-1]);
			mp[j].pop_back();
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&tmp);
			mp[i].push_back(tmp);
		}
	}
	dfs(0);
	return 0;
}

