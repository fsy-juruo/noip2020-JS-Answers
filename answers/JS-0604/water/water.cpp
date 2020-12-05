//T1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
#define dg() printf("pty AK IOI!!!");
#define out(x) printf("%lld ",(x));
inline int Read() {
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
struct Edge{
	int nex,t;
} e[N*5]; int head[N],tot;
inline void Add(int x,int y) {
	e[++tot].t=y; e[tot].nex=head[x]; head[x]=tot;
}
int n,m,b[N],d[N];
ll ans1[N],ans2[N];
ll gcd(ll x,ll y) {
	if(y==0) return x;
	else return gcd(y,x%y);
}
void dfs(int x,ll sum) { 
    if(b[x]==2) {
    	if(ans1[x]==0||ans2[x]==0) { //dg();
    		ans1[x]=1; ans2[x]=sum; 
    	//	out(ans2) out(sum) printf("\n"); 
			return;
		}
		ll xx=gcd(ans2[x],sum);
//		out(xx) out(ans2[x]) out(sum) printf("\n"); 
		ans1[x]*=(sum/xx); ans1[x]+=(ans2[x]/xx);
		ans2[x]=(ans2[x]/xx)*sum;
		xx=gcd(ans1[x],ans2[x]);
		ans1[x]/=xx; ans2[x]/=xx;
    	return;
	} 
	for(int i=head[x];i;i=e[i].nex) { //dg()
		int y=e[i].t; 
		dfs(y,sum*(ll)d[x]);
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    n=Read(); m=Read();
    for(int i=1;i<=n;i++) {              
    	int dd=Read(); d[i]=dd;             
    	if(dd==0) b[i]=2;              
    	for(int j=1;j<=dd;j++) {
    		int a=Read(); Add(i,a); b[a]=1;
		}
	}  //dg();
	for(int i=1;i<=n;i++) {
		if(b[i]==0)  dfs(i,1);
	}
	for(int i=1;i<=n;i++) {
		if(b[i]==2) {
			printf("%lld %lld\n",ans1[i],ans2[i]);
		}
	}
	return 0;
}
/*


*/
