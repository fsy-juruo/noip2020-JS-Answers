#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,To,in[100005],out[100005];
vector<int>ve[100005];
struct node{
	ll a,b;
}ans[100005];
ll Gcd(ll x,ll y){
	if(x<y)return Gcd(y,x);
	else if(!y)return x;
	else return Gcd(y,x%y);
}
node ADD(node x,node y){
	node res;
	res.a=res.b=0;
	res.b=x.b*y.b;
	res.a=x.a*y.b+y.a*x.b;
	ll GCD=Gcd(res.a,res.b);
	res.a/=GCD,res.b/=GCD;
	return res;
}
void bfs(){
	queue<int>q;
	for(int i=1;i<=n;i++)ans[i].b=1;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i),ans[i].a=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(ve[now].size()>0)ans[now].b*=ve[now].size();
		ll GCD=Gcd(ans[now].a,ans[now].b);
		ans[now].a/=GCD,ans[now].b/=GCD;	
		for(int i=0;i<ve[now].size();i++){
			int y=ve[now][i];
			in[y]--;
			if(!in[y])q.push(y);
			ans[y]=ADD(ans[y],ans[now]);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++)scanf("%d",&To),ve[i].push_back(To),in[To]++,out[i]++;
	}
	bfs();
	for(int i=1;i<=n;i++)
		if(!out[i])printf("%lld %lld\n",ans[i].a,ans[i].b);
	fclose(stdin);
	fclose(stdout);
}
