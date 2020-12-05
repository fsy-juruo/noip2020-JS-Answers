#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n,m;
vector<int> e[N];
queue<int> q;
int du[N],id[N];
ll a[N],b[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		if(k==0) id[++cnt]=i;
		for(int j=1;j<=k;j++){
			int x;scanf("%d",&x);
			e[i].push_back(x);
			du[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		b[i]=1;
	for(int i=1;i<=m;i++)
		a[i]=1,q.push(i);
	while(q.size()){
		int x=q.front();q.pop();
		ll fa=a[x],fb=b[x]*(ll)(e[x].size());
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			du[y]--;
			if(du[y]==0&&e[y].size()) 
				q.push(y);
			a[y]=a[y]*fb+fa*b[y];
			b[y]*=fb;
			ll c=gcd(a[y],b[y]);
			a[y]/=c;b[y]/=c;
		}
	}
	for(int i=1;i<=cnt;i++){
		int x=id[i];
		printf("%lld %lld\n",a[x],b[x]);
	}
	return 0;
}
