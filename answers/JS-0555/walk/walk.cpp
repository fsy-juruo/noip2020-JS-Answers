#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read(){
	int res=0,f=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res*f;
}

#define N 500005
int n,k,w[N];
struct node{
	int w,x;
}a[N];
int to[N],ma[N],mi[N],x[N];
int p[N];
int yuan;
ll res;

void dfs(int d){
	if(d>k){
		ll ans=0;
		for(int i=1;i<=k;i++) x[i]=p[i];
		while(1){
			int flag=1;
			for(int i=1;i<=k;i++){
				if(x[i]+ma[i]>w[i]||x[i]+mi[i]<1){
					flag=0;
					break;
				}
			}
			if(!flag) break;
			if(!yuan){
				puts("-1");
				exit(0);
			}
			for(int i=1;i<=k;i++){
				x[i]+=to[i];
			}
			ans+=n;
		}
		for(int i=1;i<=n;i++){
			ans++;
			if(x[a[i].w]+a[i].x>w[a[i].w]||x[a[i].w]+a[a[i].w].x<1) break;
			x[a[i].w]+=a[i].x;
		}
		res+=ans;
//		cout<<ans<<endl;
	}
	for(p[d]=1;p[d]<=w[d];p[d]++) dfs(d+1);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	if(n>100){
		puts("-1");
		return 0;
	}
	k=read();
	for(int i=1;i<=k;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		a[i].w=read();
		a[i].x=read();
		to[a[i].w]+=a[i].x;
		ma[a[i].w]=max(ma[a[i].w],to[a[i].w]);
		mi[a[i].w]=min(mi[a[i].w],to[a[i].w]);
	}
	for(int i=1;i<=k;i++){
		if(to[i]) yuan=1;
	}
	dfs(1);
	printf("%lld\n",res);
	return 0;
}
