#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500005;
const int INF=1000000007;

int read(){
	int x=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}

int n,k;
int w[10];
int c[maxn],d[maxn];
int dd[10];
int mdp[10],mdm[10];

namespace task30{
	int pos[10];
	ll ans=0;
	void calc(){
		int npos[10];
		for(int i=0;i<k;++i)npos[i]=pos[i];
	//	cerr<<npos[0]<<endl;
		while(true){
			for(int i=0;i<n;++i){
				npos[c[i]]+=d[i];
				ans++;
				if(npos[c[i]]<=0||npos[c[i]]>w[c[i]])break;
			}
			bool flag=true;
			for(int i=0;i<k;++i)if(npos[i]<=0||npos[i]>w[i])flag=false;
			if(!flag)break;
		}
	//	cerr<<ans<<endl;
	}
	void dfs(int layer){
		if(layer==k){
			calc();
			return;
		}
		for(pos[layer]=1;pos[layer]<=w[layer];++pos[layer])dfs(layer+1);
	}
	ll solve(){
		dfs(0);
		printf("%lld\n",ans);
		return ans;
	}
}

namespace task40{
	int sd[maxn];
	int mn[maxn],mx[maxn];
	ll ans=0;
	inline bool isvalid(int x){
		return x>0&&x<=w[0];
	}
	void calc(int x){
	//	cerr<<x<<endl;
		int l=0,r=n,res=0;
		while(l<=r){
			int mid=l+r>>1;
		//	cerr<<mid<<endl;
			if(!mid||(isvalid(x+mn[mid-1])&&isvalid(x+mx[mid-1]))){
				l=mid+1;
				res=mid;
			}
			else{
				r=mid-1;
			}
		}
	//	cerr<<res<<' ';
		ans+=res+1;
//		cerr<<ans<<endl;
	}
	ll solve(){
		sd[0]=d[0];
		mn[0]=min(mn[0],d[0]);
		mx[0]=max(mx[0],d[0]);
		for(int i=1;i<n;++i){
			sd[i]=sd[i-1]+d[i];
			mn[i]=min(mn[i-1],sd[i]);
			mx[i]=max(mx[i-1],sd[i]);
		}
		for(int i=1;i<=w[0];++i){
		//	cerr<<i<<' ';
			if(i+mn[n-1]<=0||i+mx[n-1]>w[0]){calc(i);continue;}
			if(sd[n-1]<0){
				int steps=(i+mn[n-1]+(-sd[n-1]-1))/(-sd[n-1]);
				ans+=ll(n)*steps;
				calc(i+sd[n-1]*steps);
			}
			else{
				int steps=(w[0]-i+1-mx[n-1]+sd[n-1]-1)/(sd[n-1]);
				ans+=ll(n)*steps;
				calc(i+sd[n-1]*steps);
			}
		}
		printf("%lld\n",ans);
		return ans;
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	int mw=0;
	for(int i=0;i<k;++i)w[i]=read(),mw=max(mw,w[i]);
	for(int i=0;i<n;++i){
		c[i]=read()-1,d[i]=read();
		dd[c[i]]+=d[i];
	}
	bool flag=true;
	for(int i=0;i<k;++i)if(dd[i])flag=false;
	if(flag){
		puts("-1");
		return 0;
	}
	if(n<=100&&k<=5&&mw<=10)task30::solve();
	else if(n<=100000&&k<=1&&mw<=100000)task40::solve();
	return 0;
}

