#include<bits/stdc++.h>
using namespace std;
const int N = 410;
typedef pair<int,int> pii;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)
#define pb push_back

int col[55][N];
int cnt[55];
int n,m;

vector<pii> ans;

inline void put_top(int x,int y){
	assert(cnt[x] > 0); assert(cnt[y] < m);
	ans.pb(pii(x,y));
	col[y][++cnt[y]] = col[x][cnt[x]--];
}

inline int other(int x,int y){
	if(x != n-1 && y != n-1)return n-1;
	if(x != n && y != n)return n;
	return n+1;
}

inline void div_top(int curi,int tari,int num,int use){
	assert(cnt[use] == 0);
	int sz = 0;
	int j = m;
	while(j > 0 && col[tari][j] == num)--j;
	sz = m-j;
	if(sz == 0)return ;
	
	int prepos;
	nfr(j,m,1)if(col[curi][j] != num)prepos = j;
	
	nfr(j,m,prepos)put_top(curi,use);
	fr(j,1,sz)put_top(tari,curi);
	nfr(j,m-prepos+1,1){
		if(col[use][j] != num && cnt[tari] < m){
			put_top(use,tari);
		} else put_top(use,curi);
	}
	assert(cnt[use] == 0);
	return ;
}

inline void solve(){
	fr(i,1,n-2){
		//solve pillar (i+1)
		int numi = 0;
		int prepos;
		nfr(j,m,1)if(col[i+1][j] == i)++numi,prepos = j;
		if(numi > 0){
			//use i+2 pillar
			fr(j,1,numi)put_top(i+2,n+1);
			nfr(j,m,prepos){
				if(col[i+1][j] == i)put_top(i+1,i+2);
				else put_top(i+1,n+1);
			}
			nfr(j,m,prepos)put_top(n+1,i+1);
			div_top(i,i+2,i,n+1);
			fr(j,1,numi)put_top(i+2,n+1);
			fr(j,1,numi)put_top(i+1,i+2);
			fr(j,1,numi)put_top(n+1,i+1);
		}
		
	/*	cerr << i << endl;
		fr(i,1,n)
		fr(j,1,m)cerr << col[i][j] << (j == m ? '\n' : ' ');*/
		int curuse = n+1;
		fr(k,i+2,n+1){
			if(k == curuse)continue ;
			//these pillars use i+1 pillar
			numi = 0;
			int prepos;
			nfr(j,m,1)if(col[k][j] == i)++numi,prepos = j;
			if(numi == 0)continue ;
			fr(j,1,numi)put_top(i+1,curuse);
			nfr(j,m,prepos){
				if(col[k][j] == i)put_top(k,i+1);
				else put_top(k,curuse);
			}
			if(prepos > m/2){
				nfr(j,m,prepos)put_top(curuse,k);
				div_top(i,i+1,i,curuse);
			} else {
				nfr(j,prepos-1,1)put_top(k,curuse);
				curuse = k;
				div_top(i,i+1,i,curuse);
			}
		}
		if(curuse != n+1){
			fr(j,1,m)put_top(n+1,curuse);
		}
	}
	// n-1 and n
	int curi = n-1,curj = n;
	int numi = 0;
	fr(j,1,m)if(col[n-1][j] == n)++numi;
	
//	cerr << ans.size() << endl;
	
	fr(i,1,numi){
		int ps1,ps2;
		fr(j,1,m)if(col[curi][j] == n)ps1 = j;
		fr(j,1,m)if(col[curj][j] == n-1)ps2 = j;
		if(ps1 <= m/2){
			int p = other(curi,curj);
			fr(j,1,m)put_top(curi,p);
			ps1 = m+1-ps1; curi = p;
		}
		if(ps2 <= m/2){
			int p = other(curi,curj);
			fr(j,1,m)put_top(curj,p);
			ps2 = m+1-ps2; curj = p;
		}
		int p = other(curi,curj);
		nfr(j,m,ps2+1)put_top(curj,p);
		nfr(j,m,ps1)put_top(curi,p);
		put_top(curj,curi);
		put_top(p,curj);
		fr(j,ps1+1,m)put_top(p,curi);
		fr(j,ps2+1,m)put_top(p,curj);
	}
	return ;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	fr(i,1,n)
		fr(j,1,m)scanf("%d",&col[i][j]);
	fr(i,1,n)cnt[i] = m;
	cnt[n+1] = 0;
	solve();
		
	printf("%d\n",ans.size());
	fr(i,0,(int)ans.size()-1){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
