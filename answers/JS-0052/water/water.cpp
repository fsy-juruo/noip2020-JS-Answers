#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 200005

ll gcd(ll a,ll b){
    if(b){
	return gcd(b,a%b);
    }else{
	return a;
    }
}
ll n,m;
ll cd[MAXN],rd[MAXN];
struct val{
    ll a,b;
}ans[MAXN];
val add(val x,val y){
    val ans;ans.a=0;ans.b=1;
    ll lcm=x.b/gcd(x.b,y.b)*y.b;
    ans.a=lcm/x.b*x.a+lcm/y.b*y.a;
    ans.b=lcm;
    ll g=gcd(ans.a,ans.b);
    ans.a/=g;ans.b/=g;
    return ans;
}
vector<ll> a[MAXN];
int vis[MAXN];
queue<ll> que;
int main(){
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1LL;i<=n;i++){
	ans[i].b=1LL;
	scanf("%lld",&cd[i]);
	//printf("%lld %lld\n",i,cd[i]);
	for(ll j=1;j<=cd[i];j++){
	    ll t=0LL;
	    scanf("%lld",&t);
	    a[i].push_back(t);
	    rd[t]++;
	}
    }
    for(ll i=1;i<=m;i++){
	que.push(i);
	vis[i]=1;
	ans[i].a=1LL;
    }
    while(!que.empty()){
	ll tp=que.front();
	//printf("%lld:%lld %lld\n",tp,ans[tp].a,ans[tp].b);
	que.pop();
	vis[tp]=0;
	if(!cd[tp])continue;
	val tmp=ans[tp];
	tmp.b*=cd[tp];
	ans[tp].a=0;ans[tp].b=1;
	for(ll i=0;i<cd[tp];i++){
	    val &xx=ans[a[tp][i]];
	    //printf("bf%lld:%lld %lld\n",a[tp][i],xx.a,xx.b);
	    xx=add(xx,tmp);
	    //printf("%lld:%lld %lld\n",a[tp][i],xx.a,xx.b);
	    if(!vis[a[tp][i]]){
		que.push(a[tp][i]);
		vis[a[tp][i]]=1;
	    }
	}
    }
    for(ll i=1LL;i<=n;i++){
	//printf("%lldcd%lld\n",i,cd[i]);
	if(!cd[i]){
	    //printf("%lld:",i);
	    printf("%lld %lld\n",ans[i].a,ans[i].b);
	}
    }
    return 0;
}
