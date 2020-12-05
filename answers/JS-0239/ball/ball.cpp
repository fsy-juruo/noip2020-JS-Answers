#include<bits/stdc++.h>
using namespace std;
int n,ans=100000000,m;
int ball[55][55],size[55];
vector<pair<int,int> >path;
bool ok(){
	for(int i=1;i<=n;i++){
		int c=ball[i][1];
		for(int j=1;j<=m;j++)		
			if(c!=ball[i][j])
				return 0;
	}
	return 1;		
}
void dfs(int x,int l,int k){
	if(!ball[x][0])
		return;
	if(ans<=k)
		return;
	if(ok()){
		ans=k;
		return;
	}	
	for(int i=1;i<=n+1;i++)
		if(i!=x&&i!=l&&size[i]<m){
			int given=ball[x][size[x]];
			ball[i][++size[i]]=ball[x][size[x]--];
			path.push_back(make_pair(x,i));
			dfs(i,x,k+1);
			ball[i][size[i]--]=0;
			ball[x][++size[x]]=given;
			path.pop_back();
		}		
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>ball[i][j];
		size[i]=m;		
	}
	for(int i=1;i<=n;i++)
		dfs(i,-1,0);	
	cout<<ans<<'\n';
	for(int i=0;i<path.size();i++)
		cout<<path[i].first<<' '<<path[i].second<<'\n';
	return 0;
}

