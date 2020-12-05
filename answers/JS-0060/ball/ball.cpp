#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,a[100][100],sz[100];
vector<pii>ans;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	rep(i,1,n)rep(j,1,m){
		a[i][j]=read();
	}
	rep(i,1,n)sz[i]=m;
	rep(c,1,n){
		rep(t,1,m){
			ri x,y;bool ok=0;
			rep(i,1,n-c+1)REP(j,sz[i],1)if(a[i][j]==c){
				x=i;y=j;break;
			}
			rep(i,x,x)REP(j,sz[i],y+1){
				rep(ii,1,n+1){
					if(sz[ii]!=m){
						a[ii][++sz[ii]]=a[i][j];
						--sz[i];a[i][j]=0;
						ans.pb(mp(i,ii));
						//printf("%d %d\n",i,ii);
					}
				}
			}
			if(sz[n+1]>t-1){
				rep(ii,1,n)if(ii!=x){
					if(sz[ii]!=m){
						while(sz[n+1]>t-1&&sz[ii]<m-1){
							a[ii][++sz[ii]]=a[n+1][sz[n+1]];
							a[n+1][sz[n+1]]=0;--sz[n+1];
							ans.pb(mp(n+1,ii));
							//printf("%d %d\n",n+1,ii);
						}
						if(sz[n+1]==t-1){
							a[n+1][++sz[n+1]]=a[x][y];
							a[x][y]=0;--sz[x];
							ans.pb(mp(x,n+1));
							//printf("%d %d\n",x,n+1);
							ok=1;
						}else{
							a[ii][++sz[ii]]=a[x][y];
							a[x][y]=0;--sz[x];
							ans.pb(mp(x,ii));
							//printf("%d %d\n",x,ii);
							x=ii;y=sz[ii];
						}
						break;
					}
				}
				rep(ii,1,n)if(ii!=x){
					if(sz[ii]!=m){
						while(sz[n+1]>t-1&&sz[ii]<m){
							a[ii][++sz[ii]]=a[n+1][sz[n+1]];
							a[n+1][sz[n+1]]=0;--sz[n+1];
							ans.pb(mp(n+1,ii));
							//printf("%d %d\n",n+1,ii);
						}
						if(sz[n+1]==t-1){
							a[n+1][++sz[n+1]]=a[x][y];
							a[x][y]=0;--sz[x];
							ans.pb(mp(x,n+1));
							//printf("%d %d\n",x,n+1);
							ok=1;break;
						}
					}
				}
			}else{
				a[n+1][++sz[n+1]]=a[x][y];
				a[x][y]=0;--sz[x];
				ans.pb(mp(x,n+1));
				//printf("%d %d\n",x,n+1);
			}
		}
		if(n==2){
			while(sz[1]!=0){
				a[2][++sz[2]]=a[1][sz[1]];
				a[1][sz[1]]=0;--sz[1];
				ans.pb(mp(1,2));
				//printf("1 2\n");
			}
			break;
		}
	}
	ri sz=ans.size();printf("%d\n",sz);
	rep(i,0,sz-1){
		printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}
