#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const ll INF64=1e18;
inline char nc(){
	static char buf[100005],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=getchar(); int sum=0; int f=0;
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) sum=(sum<<3)+(sum<<1)+(ch^48),ch=getchar();
	return f?-sum:sum;
}
const int maxn=1e5+5;
int n,m;
namespace Graph{
	struct Node{
		int to;
		int next;
	}edge[maxn<<1];
	int head[maxn],cnt;
	inline void add_edge(int x,int y){
		edge[++cnt].next=head[x];
		edge[cnt].to=y; head[x]=cnt;
	}
}
using namespace Graph;
ll dp1[maxn],dp2[maxn];
int ind[maxn],oud[maxn];
inline ll gcd(ll x,ll y){
	if(!y) return x;
	else return gcd(y,x%y);
}
inline void topo(){
	queue<int>q; while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) if(!ind[i]) q.push(i),dp1[i]=dp2[i]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		ll temp1=dp1[x],temp2=1ll*dp2[x]*oud[x];
		ll temp=gcd(temp1,temp2);
		temp1=temp1/temp; temp2/=temp;
//		cout<<x<<' '<<temp1<<' '<<temp2<<endl;
		for(int i=head[x];i!=0;i=edge[i].next){
			int k=edge[i].to;
			if((!dp1[k])&&(!dp2[k])){
				dp1[k]=temp1; dp2[k]=temp2;
			}else{
//				cout<<k<<' '<<dp1[k]<<' '<<dp2[k]<<endl;
				ll tmp1=dp1[k],tmp2=dp2[k];
				dp1[k]=1ll*tmp1*temp2+1ll*temp1*tmp2;
				dp2[k]=1ll*tmp2*temp2;
				ll tmp=gcd(dp1[k],dp2[k]);
				dp1[k]/=tmp,dp2[k]/=tmp;
			}
			ind[k]--; if(!ind[k]) q.push(k);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		int len; len=read();
		for(int j=1;j<=len;j++){
			int x; x=read();
			add_edge(i,x); ind[x]++; oud[i]++;
//			cout<<i<<' '<<x<<endl;
		}
	}
	topo();
	for(int i=1;i<=n;i++) if(!oud[i]) printf("%lld %lld\n",dp1[i],dp2[i]);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
