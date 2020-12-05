#include<bits/stdc++.h>

using namespace std;

#define ll long long;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pii pair<int,int>

const int INF=1e9+7;
void mov(int now,int c){
	for(int i=v[now].size()-1;i>=0;i--){
		int cc=v[now][i];
		if(cc==c){
			k++;
			x[k]=now;
			y[k]=n+1;
			v[now].pop_back();
			v[n+1].push_back(c);
		}
		else{
			bool flag=0;
			rep(j,n){
				if(j==now)continue;
				if(v[j].size()==m)continue;
				k++;
				x[k]=now;
				y[k]=j;
				v[now].pop_back();
				v[j].push_back(cc);
				flag=1;
				break;
			}
			if(!flag){
				
			}
		}
	}
}
void go(int c){
	int goal=col[c];
	mov(goal,c);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	rep(i,n)rep(i,m){
		int t;
		cin>>t;
		v[i].push_back(t);
	}
	rep(i,n){
		bool flag=0;
		rep0(j,m){
			int now=v[i][j];
			if(vis[v[i][j]])continue;
			vis[v[i][j]]=1;
			col[v[i][j]]=i;
			flag=1;
		}
		if(!flag){
			int j=1;
			while(vis[j])j++;
			col[j]=i;
		}
	}
	rep(i,n)go(i);
	return 0;
}
