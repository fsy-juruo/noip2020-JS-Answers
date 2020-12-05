#include<bits/stdc++.h>
#define bug cout<<"bug"<<__LINE__<<endl
using namespace std;
const int maxn=1005;
int n,m;
long long tot;
int mp[505][505];
vector<int> vec[maxn];
vector<pair<int,int> > ans;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*f;
}
pair<int,int> find(int color){
	for(int i=1;i<=n;i++){
		if(i==color) continue;
		for(int j=m-1;j>=0;j--){
			if(vec[i][j]==color) return make_pair(i,j);
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
//	cin.tie(0);cout.tie(0);
//	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			vec[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			if(vec[i][j]!=i){
				pair<int,int> aim=find(i);
				int now_i=aim.first;
				int now_j=aim.second;
				if(j>=now_j){
					for(int k=m-1;k>=now_j;k--){
						ans.push_back(make_pair(now_i,n+1));
						tot++;
						vec[n+1].push_back(vec[now_i][vec[now_i].size()-1]);
						vec[now_i].pop_back();
					}
					for(int k=m-1;k>=j;k--){
						ans.push_back(make_pair(i,now_i));
						tot++;
						vec[now_i].push_back(vec[i][vec[i].size()-1]);
						vec[i].pop_back();
					}
					ans.push_back(make_pair(n+1,i));
					tot++;
					vec[i].push_back(vec[n+1][vec[n+1].size()-1]);
					vec[n+1].pop_back();
					ans.push_back(make_pair(now_i,n+1));
					tot++;
					vec[n+1].push_back(vec[now_i][vec[now_i].size()-1]);
					vec[now_i].pop_back();
					for(int k=m-1;k>j;k--){
						ans.push_back(make_pair(now_i,i));
						tot++;
						vec[i].push_back(vec[now_i][vec[now_i].size()-1]);
						vec[now_i].pop_back();
					}
					for(int k=m-1;k>=now_j;k--){
						ans.push_back(make_pair(n+1,now_i));
						tot++;
						vec[now_i].push_back(vec[n+1][vec[n+1].size()-1]);
						vec[n+1].pop_back();
					}
				}
				else if(j<now_j){
					for(int k=m-1;k>=j;k--){
						ans.push_back(make_pair(i,n+1));
						tot++;
						vec[n+1].push_back(vec[i][vec[i].size()-1]);
						vec[i].pop_back();
					}
					for(int k=m-1;k>=now_j;k--){
						ans.push_back(make_pair(now_i,i));
						tot++;
						vec[i].push_back(vec[now_i][vec[now_i].size()-1]);
						vec[now_i].pop_back();
					}
					ans.push_back(make_pair(n+1,now_i));
					tot++;
					vec[now_i].push_back(vec[n+1][vec[n+1].size()-1]);
					vec[n+1].pop_back();
					ans.push_back(make_pair(i,n+1));
					tot++;
					vec[n+1].push_back(vec[i][vec[i].size()-1]);
					vec[i].pop_back();
					for(int k=m-1;k>now_j;k--){
						ans.push_back(make_pair(i,now_i));
						tot++;
						vec[now_i].push_back(vec[i][vec[i].size()-1]);
						vec[i].pop_back();
					}
					for(int k=m-1;k>=j;k--){
						ans.push_back(make_pair(n+1,i));
						tot++;
						vec[i].push_back(vec[n+1][vec[n+1].size()-1]);
						vec[n+1].pop_back();
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++){
//			cout<<vec[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<tot<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2





*/
