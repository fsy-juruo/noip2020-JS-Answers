#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)
#define pb push_back
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vii;

int a[53][503],n,m;
queue<pii> q;

void change(pii x,pii y){
	if(x.se<y.se)swap(x,y);
	for(int i=1;i<=x.se;++i){
		q.push(mp(x.fi,n+1));
	}
	for(int i=1;i<=y.se;++i){
		q.push(mp(y.fi,x.fi));
	}
	q.push(mp(n+1,y.fi));
	q.push(mp(x.fi,n+1));
	for(int i=1;i<y.se;++i){
		q.push(mp(x.fi,y.fi));
	}
	for(int i=1;i<=x.se;++i){
		q.push(mp(n+1,x.fi));
	}
	swap(a[x.fi][x.se],a[y.fi][y.se]);
}

pii fnd(int p){
	for(int i=p+1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]==p)
				return mp(i,j);
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][m-j+1]);
	
	for(int i=1;i<=n;++i){
		int cur=m;
		while(cur>=1){
			while(a[i][cur]==i)--cur;
			if(cur<1)break;
			pii p=fnd(i);
//			printf("%d %d : %d %d\n",i,cur,p.fi,p.se);
			change(mp(i,cur),p);
//			printf("%d !\n",q.size());
			--cur;
		}
//		return 0;
	}
	printf("%d\n",q.size());
//	return 0;
	while(!q.empty()){
		printf("%d %d\n",q.front().fi,q.front().se);
		q.pop();
	}
	return 0;
}



