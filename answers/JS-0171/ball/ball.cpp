//#   # #####  #### #   # ####  #####
// # #    #   #     ##  # #   #   #
//  #     #    ###  # # # ####    #
//  #   # #       # #  ## #       #
//  #    ##   ####  #   # #     #####
#include<bits/stdc++.h>
using namespace std;

int n,m,a[55][405],sz[55];
vector<pair<int,int> > op;

inline int top(const int& x){
	return a[x][sz[x]];
}

inline void mov(const int& x,const int& y){
	a[y][++sz[y]]=a[x][sz[x]--];
	op.push_back(make_pair(x,y));
}

int main(){

	ios_base::sync_with_stdio(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		sz[i]=m;
	}
	for(int color=1;color<n;color++){
		int use=n+1-color;
		for(int i=1;i<=use;i++){
			int j=i+1>use?1:i+1,cnt=0;
			for(int k=1;k<=m;k++)cnt+=a[i][k]==color;
			for(int k=1;k<=cnt;k++)mov(j,use+1);
			int lft=cnt;
			for(int k=m;k>=1&&lft;k--)if(a[i][k]==color)mov(i,j),lft--;
			else mov(i,use+1);
			while(sz[i]<m-cnt)mov(use+1,i);
			for(int k=1;k<=cnt;k++)mov(j,i);
			for(int k=1;k<=cnt;k++)mov(use+1,j);
		}
		for(int i=1;i<=use;i++)while(top(i)==color)mov(i,use+1);
		for(int i=1;i<use;i++)while(sz[i]<m)mov(use,i);
	}
	cout<<op.size()<<'\n';
	for(int i=0;i<op.size();i++){
		cout<<op[i].first<<' '<<op[i].second<<'\n';
	}

	return 0;
}
