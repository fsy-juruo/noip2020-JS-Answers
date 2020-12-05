/*#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
void read(int &x)
{
	char c;int s=0,f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f*=-1;
	s=(c&15);while((c=getchar())>='0'&&c<='9')s=s*10+(c&15);
	x=s*f;
}
const long long inf=0x7fffffffffffffffll;
const int mod=1e9+7,inv6=166666668;
int n,m,i,j,a[11],inv[1000005],s[11],ans,pc[1000005],pd[1000005],p[11];
long long f[11][1000005];
long long g[11][1000005];
long long h[10000005];
int l[5],r[5],d[5],dd[5];
namespace solve2
{
	int typ[5];
	void calc(int x)
	{
		int ss=1,i;
		fz1(i,m)if(m!=x) ss=1ll*ss*s[i]%mod;
		ans=(ans+ss)%mod;
	}
	int gsum(int e,int x)
	{
		if(e==0) return x+1;
		if(e==1) return 1ll*x*(x+1)%mod;
		if(e==2) return 1ll*x*(x+1)%mod*(x+x+1)%mod*inv6%mod;
	}
	void dfs(int x,int y,int tim)
	{
		if(x>m){
			int a=1,e=0;
			int i;
			fz1(i,m)if(i!=y){
				if(typ[i]){
					e++;
					a=1ll*a*(mod-dd[i])%mod;
				}
				else{
					a=1ll*a*s[i]%mod;
				}
			}
			ans=(ans+1ll*a*gsum(e,tim))%mod;
			return;
		}
		if(x==y)dfs(x+1,y,tim);
		else{
			typ[x]=1;dfs(x+1,y,tim);
			typ[x]=0;dfs(x+1,y,tim);
		}
	}
	void calc2(int x,int tim)
	{
		int ss=1,i;
		fz1(i,m)if(m!=x) ss=1ll*ss*max(0ll,s[i]-1ll*tim*dd[i])%mod;
		ans=(ans+ss)%mod;
		if(!tim)return;
		dfs(1,x,tim-1);
	}
	int main()
	{
		fz1(i,m){
			l[i]=1;r[i]=a[i];d[i]=0;
			s[i]=a[i];
		}
		fz1(i,n){
			int x;d[x=pc[i]]+=pd[i];
			if(r[x]>=l[x]&&r[x]+d[x]>a[x]){
				r[x]--;s[x]--;calc(x);
			}
			if(l[x]<=r[x]&&l[x]+d[x]<1){
				l[x]++;s[x]--;calc(x);
			}
		}
		int tim=0x7fffffff;
		fz1(i,m)if(d[i]){
			tim=min(tim,(r[i]-l[i]+abs(d[i]))/abs(d[i]));
		}
		if(tim==0x7fffffff){
			puts("-1");return 0;
		}
		fz1(i,m) dd[i]=abs(d[i]);
		fz1(i,n){
			int x;d[x=pc[i]]+=pd[i];
			if(r[x]>=l[x]&&r[x]+d[x]>a[x]){
				r[x]--;s[x]--;calc2(x,tim-1);
			}
			if(l[x]<=r[x]&&l[x]+d[x]<1){
				l[x]++;s[x]--;calc2(x,tim-1);
			}
		}
		return 0;
	}
}
namespace solve1
{
	bool solve(int x)
	{
		int i,l=1,r=a[x],d=0,cc=0;
		fz1(i,n){
			if(pc[i]==x) d+=pd[i];
			if(r>=1&&r+d>a[x]&&f[x][r]>i){
				f[x][r]=i;
				g[x][++cc]=r;
				r--;
			}
			if(l<=a[x]&&l+d<1&&f[x][l]>i){
				f[x][l]=i;
				g[x][++cc]=l;
				l++;
			}
		}
		if(d<0){
			fz1(i,a[x])if(inf==f[x][i]){
				f[x][i]=f[x][i+d]+n;
				g[x][++cc]=i;
			}
			return 0;
		}
		if(d>0){
			fd1(i,a[x])if(inf==f[x][i]){
				f[x][i]=f[x][i+d]+n;
				g[x][++cc]=i;
			}
			return 0;
		}
		bool fg=0;
		fz1(i,a[x])if(inf==f[x][i]){
			g[x][++cc]=i;
			fg=1;
		}
		return fg;
	}
	int merge()
	{
		int p0=0,i,j;
		fz1(i,m) p[i]=1;
		for(;;){
			int t=0;
			fz1(i,m){
				if(p[i]<=a[i]&&(!t||f[i][g[i][p[i]]]<f[t][g[t][p[t]]])) t=i;
			}
			if(!t) break;
			h[++p0]=t;
			p[t]++;
		}
		return p0;
	}
	int main()
	{
		bool fg=1;
		fz1(i,m){
			fg&=solve(i);
		}
		if(fg){
			puts("-1");return 0;
		}
		int all=merge();
		int ss=1,c0=m;
		fz1(i,m){
			s[i]=0;
			reverse(g[i]+1,g[i]+a[i]+1);
		}
		fd1(i,all){
			int tmp=1ll*ss*inv[s[h[i]]]%mod;
			if(!s[h[i]]) c0--;
			s[h[i]]++;
			if(!c0) ans=(ans+f[h[i]][g[h[i]][s[h[i]]]]%mod*tmp)%mod;
			ss=1ll*tmp*s[h[i]]%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
}
int main()
{
//	cerr<<sizeof(f)*3/1000.0/1000.0<<endl;
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	inv[1]=inv[0]=1;for(i=2;i<=1000000;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	read(n);read(m);
	int mx=0;
	fz1(i,m){
		read(a[i]);mx=max(mx,a[i]);
		fz1(j,a[i]) f[i][j]=inf;
	}
	fz1(i,n){
		read(pc[i]);read(pd[i]);
	}
	if(mx<=1000000){
		solve1::main();
		return 0;
	}
	solve2::main();
	return 0;
}*/
#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
void read(int &x)
{
	char c;int s=0,f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f*=-1;
	s=(c&15);while((c=getchar())>='0'&&c<='9')s=s*10+(c&15);
	x=s*f;
}
const long long inf=0x7fffffffffffffffll;
const int mod=1e9+7,inv6=166666668;
int n,m,i,j,a[11],inv[1000005],s[11],ans,pc[1000005],pd[1000005],p[11];
long long f[11][1000005];
long long g[11][1000005];
long long h[10000005];
int l[5],r[5],d[5],dd[5];
namespace solve2
{
	int typ[5];
	void calc(int x,int val)
	{
		int ss=1,i;
		fz1(i,m)if(i!=x) ss=1ll*ss*s[i]%mod;
		ans=(ans+1ll*val*ss)%mod;
	}
	int gsum(int e,int x)
	{
		if(e==0) return x+1;
		if(e==1) return 1ll*x*(x+1)/2%mod;
		if(e==2) return 1ll*x*(x+1)%mod*(x+x+1)%mod*inv6%mod;
		if(e==3){
			int t=gsum(1,x);
			return 1ll*t*t%mod;
		}
	}
	void dfs(int x,int y,int tim,int tt)
	{
		if(x>m){
			int a=1,e=0;
			int i;
			fz1(i,m)if(i!=y){
				if(typ[i]){
					e++;
					a=1ll*a*(mod-dd[i])%mod;
				}
				else{
					a=1ll*a*s[i]%mod;
				}
			}
			else{
				if(typ[i]){
					e++;
					a=1ll*a*n%mod;
				}
				else{
					a=1ll*a*tt%mod;
				}
			}
//			cerr<<a<<' '<<e<<' '<<1ll*a*gsum(e,tim)%mod<<' ';
//			int j,sss=0;fz0g(i,tim){
//				int t=a;j=e;while(j--) t=1ll*t*i%mod;
//				sss=(0ll+mod+sss+t)%mod;
//			}cerr<<sss<<endl;
			ans=(ans+1ll*a*gsum(e,tim))%mod;
			return;
		}
		typ[x]=1;dfs(x+1,y,tim,tt);
		typ[x]=0;dfs(x+1,y,tim,tt);
	}
	void calc2(int x,int tim,int tt)
	{
		int ss=1,i;
		fz1(i,m)if(i!=x) ss=1ll*ss*max(0ll,s[i]-1ll*tim*dd[i])%mod;
		if(s[x]-1ll*tim*dd[x]>=0) ans=(ans+1ll*(tt+1ll*n*tim%mod)*ss)%mod;
		if(!tim)return;
//		fz0g(i,tim){
//			ans+=(9-i)*(9-i)*(i+i+i+4);
//		}
		dfs(1,x,tim-1,tt);
	}
	int main()
	{
		fz1(i,m){
			l[i]=1;r[i]=a[i];d[i]=0;
			s[i]=a[i];
		}
		fz1(i,n){
			int x;d[x=pc[i]]+=pd[i];
			if(r[x]>=l[x]&&r[x]+d[x]>a[x]){
				r[x]--;s[x]--;calc(x,i);
			}
			if(l[x]<=r[x]&&l[x]+d[x]<1){
				l[x]++;s[x]--;calc(x,i);
			}
		}
		int tim=0x7fffffff;
		fz1(i,m)if(d[i]){
			tim=min(tim,(r[i]-l[i]+abs(d[i]))/abs(d[i]));
		}
		if(tim==0x7fffffff){
			puts("-1");return 0;
		}
		fz1(i,m) dd[i]=abs(d[i]);
		fz1(i,n){
			int x;d[x=pc[i]]+=pd[i];
			if(r[x]>=l[x]&&r[x]+d[x]>a[x]){
				r[x]--;s[x]--;calc2(x,tim-1,i+n);
			}
			if(l[x]<=r[x]&&l[x]+d[x]<1){
				l[x]++;s[x]--;calc2(x,tim-1,i+n);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}
namespace solve1
{
	bool solve(int x)
	{
		int i,l=1,r=a[x],d=0,cc=0;
		fz1(i,n){
			if(pc[i]==x) d+=pd[i];
			if(r>=1&&r+d>a[x]&&f[x][r]>i){
				f[x][r]=i;
				g[x][++cc]=r;
				r--;
			}
			if(l<=a[x]&&l+d<1&&f[x][l]>i){
				f[x][l]=i;
				g[x][++cc]=l;
				l++;
			}
		}
		if(d<0){
			fz1(i,a[x])if(inf==f[x][i]){
				f[x][i]=f[x][i+d]+n;
				g[x][++cc]=i;
			}
			return 0;
		}
		if(d>0){
			fd1(i,a[x])if(inf==f[x][i]){
				f[x][i]=f[x][i+d]+n;
				g[x][++cc]=i;
			}
			return 0;
		}
		bool fg=0;
		fz1(i,a[x])if(inf==f[x][i]){
			g[x][++cc]=i;
			fg=1;
		}
		return fg;
	}
	int merge()
	{
		int p0=0,i,j;
		fz1(i,m) p[i]=1;
		for(;;){
			int t=0;
			fz1(i,m){
				if(p[i]<=a[i]&&(!t||f[i][g[i][p[i]]]<f[t][g[t][p[t]]])) t=i;
			}
			if(!t) break;
			h[++p0]=t;
			p[t]++;
		}
		return p0;
	}
	int main()
	{
		bool fg=1;
		fz1(i,m){
			fz1(j,a[i]) f[i][j]=inf;
		}
		fz1(i,m){
			fg&=solve(i);
		}
		if(fg){
			puts("-1");return 0;
		}
		int all=merge();
		int ss=1,c0=m;
		fz1(i,m){
			s[i]=0;
			reverse(g[i]+1,g[i]+a[i]+1);
		}
		fd1(i,all){
			int tmp=1ll*ss*inv[s[h[i]]]%mod;
			if(!s[h[i]]) c0--;
			s[h[i]]++;
			if(!c0) ans=(ans+f[h[i]][g[h[i]][s[h[i]]]]%mod*tmp)%mod;
			ss=1ll*tmp*s[h[i]]%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
}
int main()
{
//	cerr<<sizeof(f)*3/1000.0/1000.0<<endl;
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	inv[1]=inv[0]=1;for(i=2;i<=1000000;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	read(n);read(m);
	int mx=0;
	fz1(i,m){
		read(a[i]);mx=max(mx,a[i]);
	}
	fz1(i,n){
		read(pc[i]);read(pd[i]);
	}
	if(mx<=1000000){
		solve1::main();
		return 0;
	}
	solve2::main();
	return 0;
}
