#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
template <typename T> inline T chkmax(T&x,T y){return (x=(x>y?x:y));}
template <typename T >inline T chkmin(T&x,T y){return (x=(x<y?x:y));}
template <typename T> inline void read(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-')f=-1;ch=getchar();}
	while(ch>=48&&ch<=57){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	x*=f;
}
const int N=5e5+10,mod=1e9+7;
int fa[11];//+1
int fb[11];//-1
int to[11][N<<1];
int fa1[11][N],fb1[11][N];
int a[11],w[N];
ll ans;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d",&w[i]);
	rep(i,1,m)fa[i]=fb[i]=0;
	rep(i,1,m)to[i][N]=0;
	rep(i,1,m)fb1[i][0]=fa1[i][0]=0;
	rep(i,1,n)
	{
		scanf("%d%d",&x,&y);
		a[x]+=y;
		chkmax(fa[x],a[x]);
		chkmin(fb[x],a[x]);
		rep(j,1,m)
		fa1[j][i]=max(fa1[j][i-1],fa[j]),
		fb1[j][i]=min(fb1[j][i-1],fb[j]);
		if(to[x][a[x]+N]==0)
		to[x][a[x]+N]=i;
	}
	bool fff=1;
	rep(i,1,m)
	if(a[i]!=0)fff=0;
	if(fff)
	{
		
		bool ff=1;
		rep(i,1,m)
		if(fa[i]-fb[i]+1>=w[i])
		ff=0;
		if(!ff)
		{
			printf("-1\n");
			return 0;
		}
	}
	rep(i,1,m)
	{
		if(a[i]>0)
		{
			rep(j,1,fa[i])
			{
				int t=to[i][j+N];
				rep(T,0,n)
				{
					
					ll s=1;
					rep(k,1,m)
					{
						int tt=(k==i?(w[k]):w[k])+(a[k]>0?(+(T?fb[k]:fb1[k][t])-(T==0?fa1[k][t]:max(T*a[k]+fa1[k][t],(T-1)*a[k]+fa[k])))
														   :(-(T?fa[k]:fa1[k][t])+(T==0?fb1[k][t]:min(T*a[k]+fb1[k][t],(T-1)*a[k]+fb[k]))));
//						if(i==1&&j==1&&T==1)printf("%d\n",tt);
						if(tt<=0){s=0;break;}
						if(k!=i)s=s*tt%mod;
					}
					if(s==0)break;
					ans=(ans+s*((ll)T*n%mod+t)%mod)%mod;
//					printf("%d %d %d %lld\n",i,j,T,ans);
				}
			}
		}
		if(a[i]<0)
		{
			Rep(j,-1,fb[i])
			{
				int t=to[i][j+N];
				rep(T,0,n)
				{
					ll s=1;
					rep(k,1,m)
					{
						int tt=(k==i?(w[k]+1):w[k])+(a[k]>0?(+(T?fb[k]:fb1[k][t])-(T==0?fa1[k][t]:max(T*a[k]+fa1[k][t],(T-1)*a[k]+fa[k])))
														   :(-(T?fa[k]:fa1[k][t])+(T==0?fb1[k][t]:min(T*a[k]+fb1[k][t],(T-1)*a[k]+fb[k]))));
						if(tt<=0){s=0;break;}
						if(k!=i)s=s*tt%mod;
					}
					if(s==0)break;
					ans=(ans+s*((ll)T*n%mod+t)%mod)%mod;
//					printf("%d %d %d %lld\n",i,j,T,ans);
				}
			}
		}
		if(a[i]==0)
		{
			rep(j,0,fa[i])
			{
				int t=to[i][j+N];
				ll s=1;
				int T=0;
				rep(k,1,m)
				{
					int tt=(k==i?(w[k]+1):w[k])+(a[k]>0?(+(T?fb[k]:fb1[k][t])-(T==0?fa1[k][t]:max(T*a[k]+fa1[k][t],(T-1)*a[k]+fa[k])))
													   :(-(T?fa[k]:fa1[k][t])+(T==0?fb1[k][t]:min(T*a[k]+fb1[k][t],(T-1)*a[k]+fb[k]))));
					if(tt<=0){s=0;break;}
					if(k!=i)s=s*tt+mod;
				}
//				printf("%d %d\n",i,j);
				ans=(ans+s*t%mod)%mod;
			}
			Rep(j,-1,fb[i])
			{
				int t=to[i][j+N];
				ll s=1;
				int T=0;
				rep(k,1,m)
				{
					int tt=(k==i?(w[k]+1):w[k])+(a[k]>0?(+(T?fb[k]:fb1[k][t])-(T==0?fa1[k][t]:max(T*a[k]+fa1[k][t],(T-1)*a[k]+fa[k])))
													   :(-(T?fa[k]:fa1[k][t])+(T==0?fb1[k][t]:min(T*a[k]+fb1[k][t],(T-1)*a[k]+fb[k]))));
					if(tt<=0){s=0;break;}
					if(k!=i)s=s*tt%mod;
				}
//				printf("%d %d\n",i,j);
				ans=(ans+s*t%mod)%mod;
			}
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
}
/*
3 2
3 3 
1 -1
2 1
1 -1


5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
