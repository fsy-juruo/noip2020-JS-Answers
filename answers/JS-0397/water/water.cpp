//dfoi wlq
#include<queue>
#include<vector>
#include<cstdio>
#define N 100005
#define ll long long
using namespace std;
queue <int> q;
vector <int> a[N];
int n,m,d,x;
ll num[N],ans1[N],ans2[N];
ll gcd(ll x,ll y){
	if(x%y==0) return y;
	return gcd(y,x%y);
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		for(int j=1;j<=d;j++){
			scanf("%d",&x);
			num[x]++;
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		q.push(i);
		ans1[i]=ans2[i]=1;
	}
	for(int i=1;i<=n;i++) ans2[i]=1;
}
void tuopu(){
	while(!q.empty()){
		ll a1,a2,sz,now,gcdd;
		now=q.front();
		sz=a[now].size();
		if(!sz) {q.pop();continue;}
		a1=ans1[now],a2=ans2[now]*sz;
		for(int i=0;i<sz;i++){
			if(--num[x]==0) q.push(x);
			x=a[now][i];
			ans1[x]=a1*ans2[x]+a2*ans1[x];
			ans2[x]=a2*ans2[x];
			gcdd=gcd(ans1[x],ans2[x]);
			ans1[x]/=gcdd,ans2[x]/=gcdd;
		}
		q.pop();
	}
	for(int i=1;i<=n;i++)
	  if(!a[i].size())
	    printf("%lld %lld\n",ans1[i],ans2[i]);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	init();
	tuopu();
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
