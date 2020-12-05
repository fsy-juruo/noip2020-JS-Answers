#include<bits/stdc++.h>
#define ll long long
#define int ll
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

const int N=5e5+5,p=1e9+7;
int n,k,w[20],c[N],d[N],val[20];
bool issub1(){
	return n<=100;
}
namespace sub1{
int a[20],ans,a2[20];
void dfs(ri t){
	if(t>k){
		rep(j,1,k)a2[j]=a[j];
		ri i=1;
		while(1){
			a2[c[i]]+=d[i];++ans;
			if(a2[c[i]]<1||a2[c[i]]>w[c[i]])break;
			++i;if(i>n)i=1;
		}
//		rep(j,1,k)cout<<a[j]<<' ';cout<<":";
//		cout<<ans<<endl;
		return;
	}
	rep(i,1,w[t]){
		a[t]=i;
		dfs(t+1);
	}
}
void work(){
	dfs(1);
	cout<<ans<<endl;
}
}

/*namespace k1{
const int K1=1e6+10;
int num[K1],ans;
void work(){
	ri x=n;
	rep(i,0,n+n)num[i]=-1;
	rep(i,1,n){
		x+=d[i];
		if(num[x]==-1)num[x]=i,cout<<x<<":"<<i<<endl;
	}
	rep(i,1,w[1]){
		cout<<ans<<endl;
		if(num[-i+n]!=-1){
			ans=(ans+num[-i+n])%p;
			continue;
		}
		if(num[w[1]+1-i+n]!=-1){
			ans=(ans+num[w[1]+1-i+n])%p;
			continue;
		}
		ri y,z;
		if(val[1]<0){
			y=i/(-val[1]),z=i%(-val[1]);
		}else{
			y=(w[1]+1-i)/val[1],z=(w[1]+1-i)%val[1];
		}
		ans=(ans+y*n%p)%p;//cout<<ans<<"    ";
		ans=(ans+num[z+n])%p;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
}*/

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	rep(i,1,k)w[i]=read();
	rep(i,1,n)c[i]=read(),d[i]=read(),val[c[i]]+=d[i];
	bool ok=0;
	rep(i,1,k)if(val[i]!=0ll){ok=1;break;}
	if(!ok){puts("-1");return 0;}
//	if(k==1&&w[1]<=100000){
//		k1::work();
//		return 0;
//	}
	if(issub1()){
		sub1::work();
		return 0;
	}
	return 0;
}
