#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int K=20,N=1e5+10;
const ll mod=1e9+7;

int n,k;
int w[K];
int c[N],d[N];
pair<int,int> f[N][11];
int cnt[K];
int minv[K],maxv[K];

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

namespace task1{
	int a[20],b[20];
	ll ans=0;
	
	ll ck(){
//		cerr<<"aha"<<endl;
		for (int i=1;i<=k;i++)b[i]=a[i];
		ll ret=1;
		while (1){
			for (int i=1;i<=n;i++){
				b[c[i]]+=d[i];
				if (b[c[i]]<1 || b[c[i]]>w[c[i]]){
//					cerr<<ret<<endl;
//					for (int j=1;j<=k;j++)cerr<<a[j]<<' ';cerr<<endl;
//					for (int j=1;j<=k;j++)cerr<<b[j]<<' ';cerr<<endl;
//					cerr<<endl;
					return ret;
				}
				ret++;
			}
		}
	}
	
	void dfs(int x){
//		cerr<<x<<endl;
		if (x==k+1){
			ll x=ck();
			ans=(ans+x)%mod;
//			cerr<<ans<<' '<<x<<' '<<ans+x<<endl;
//			ans+=x;
			return ;
		}
		for (int i=1;i<=w[x];i++){
//			cerr<<"#"<<i<<endl;
			a[x]=i;
			dfs(x+1);
		}
	}
	
	void solve(){
		for (int i=1;i<=n;i++){
			cnt[c[i]]+=d[i];
			minv[c[i]]=min(minv[c[i]],cnt[c[i]]);
			maxv[c[i]]=max(maxv[c[i]],cnt[c[i]]);
		}
		bool flag=1;
		for (int i=1;i<=k;i++){
			if (minv[i]+maxv[i]!=0){
				flag=0;break;
			}
		}
		if (flag){
			puts("-1");
			return ;
		}
//		cerr<<"aha"<<endl;
		dfs(1);
		printf("%lld\n",ans);
	}
}

namespace task2{
	void solve(){
		
	}
}

namespace task3{
	void solve(){
		
	}
}

namespace task4{
	ll ans;
	
	void getans(){
		while (1){
			for (int i=1;i<=n;i++){
				ll sum=1;
				bool flag=0;
				for (int j=1;j<=k;j++){
					if (f[i][j].first<=f[i][j].second){
						flag=1;
						sum=sum*((ll)f[i][j].second-(ll)f[i][j].first+1ll)%mod;
					}
				}
				if (flag)ans+=sum;
				else return ;
			}
			for (int i=1;i<=n;i++){
				if (cnt[c[i]]>=0 && d[i]==1){
					f[0][c[i]].second--;
				}
				if (cnt[c[i]]<=0 && d[i]==-1){
					f[0][c[i]].first++;
				}
			}
		}
	}
	
	void solve(){
		for (int i=1;i<=k;i++)f[0][i]=make_pair(1,w[i]);
		
		for (int i=1;i<=n;i++){
			if (cnt[c[i]]>=0 && d[i]==1){
				f[0][c[i]].second--;
			}
			if (cnt[c[i]]<=0 && d[i]==-1){
				f[0][c[i]].first++;
			}
			cnt[c[i]]+=d[i];
			minv[c[i]]=min(minv[c[i]],cnt[c[i]]);
			maxv[c[i]]=max(maxv[c[i]],cnt[c[i]]);
		}
		
		bool flag=1;
		for (int i=1;i<=k;i++){
			if (minv[i]+maxv[i]!=0){
				flag=0;
			}
		}
		if (flag){
			puts("-1");
			return ;
		}
		
		getans();
		
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for (int i=1;i<=k;i++)w[i]=read();
	for (int i=1;i<=n;i++)c[i]=read(),d[i]=read();
	
	if (n<=100)task1::solve();
	else if (k==1)task2::solve();
	else if (k==2)task3::solve();
	else task4::solve();
	
	
	return 0;
}

