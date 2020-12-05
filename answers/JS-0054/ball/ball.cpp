#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define N 53
#define M 407
#define F first
#define S second
#define random(x) (rand()%(x))
#define INF 0x3f3f3f3f
int n,m,st[N][M],tp[N],col[N][M];
vii ls,res;
set<int> kc;
inline int kcq(){
	return (*kc.begin());
}
inline int kch(){
	return (*kc.rbegin());
}
inline void dfs(int n){
	if(n==1) return;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			++col[st[i][j]][j];
			col[st[i][j]][0]+=j;
			
		}
	}
	int mn=INF,u,cnt=0,f,nq,nh;
	for(int i=1;i<=n;++i){
		if(col[i][0]==0) continue;
		f=1;
		for(int j=1;j<=m;++j){
			cnt+=col[i][j];
			if(cnt<j){
				f=0;break;
			}
		}
		if(f&&col[i][1]<mn){
			mn=col[i][0];
			u=i;
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(st[i][j]==u){
				ls.push_back(ii(i,j));
			}
		}
	}
	for(int i=0;i<ls.size();++i){
		//printf("%d %d\n",ls[i].F,ls[i].S);
		while(tp[ls[i].F]<ls[i].S){
			nq=kcq();nh=kch();
			if(nq==ls[i].F){
				res.push_back(ii(ls[i].F,nh));
				st[nh][--tp[nh]]=st[ls[i].F][tp[ls[i].F]];
				++tp[ls[i].F];
				set<int>::iterator it=kc.end();--it;
				kc.erase(it);
				
				kc.insert(ls[i].F);
			}else{
				res.push_back(ii(ls[i].F,nq));
				st[nq][--tp[nq]]=st[ls[i].F][tp[ls[i].F]];
				++tp[ls[i].F];
				kc.erase(kc.begin());
				kc.insert(ls[i].F);
			}
		}
		res.push_back(ii(ls[i].F,n+1));
		++tp[ls[i].F];
		kc.insert(ls[i].F);
		/*
		for(set<int>::iterator it=kc.begin();it!=kc.end();++it){
			printf("%d ",*it);
		}
		puts("");
		*/
	}
	
	while(!kc.empty()){
		nq=kcq();
		if(nq==n) break;
		res.push_back(ii(n,nq));
		st[nq][--tp[nq]]=st[n][tp[n]];
		++tp[n];
		kc.erase(kc.begin());
	}
	//printf("%d\n",res.size());
	kc.clear();
	ls.clear();
	dfs(n-1);
}
int main(){
	
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		tp[i]=1;
		for(int j=m;j;--j){
			scanf("%d",st[i]+j);
		}
	}
	dfs(n);
	printf("%d\n",res.size());
	for(int i=0;i<res.size();++i){
		printf("%d %d\n",res[i].F,res[i].S);
	}
	return 0;
}
