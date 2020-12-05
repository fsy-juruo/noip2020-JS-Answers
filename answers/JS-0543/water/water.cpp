#include<bits/stdc++.h>
#define N 100099
#define ll long long
using namespace std;
struct f{
	ll p,q;
};
f add(f a1,f a2){
	f c;
	c.q=a1.q*a2.q;
	c.p=a1.p*a2.q+a2.p*a1.q;
	ll x=__gcd(c.p,c.q);
	c.p/=x;
	c.q/=x;
	return c;
}
f div(f a,ll j){
	a.q*=j;
	ll x=__gcd(a.p,a.q);
	a.p/=x;
	a.q/=x;	
	return a;
}
inline ll read(){
//	ll x;
//	cin>>x;
//	return x;
	ll s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10;
		s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}
vector<ll>g[N];
vector<ll>gg[N];
ll d[N],nd[N],now;
f ans[N];
queue<ll>q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ll n=read(),m=read(),i,j,s,u;
	f t;
	for(i=1;i<=n;++i){
//		cout<<i<<endl;
		d[i]=read();
		if(d[i]==0){
			q.push(i);
		} 
		for(j=1;j<=d[i];++j){
			u=read();
			g[i].push_back(u);
			gg[u].push_back(i);
		}
	}
	for(i=1;i<=n;++i){
		if(gg[i].size()==0){
		//	cout<<i;
			d[0]++;
			gg[i].push_back(0);
			g[0].push_back(i);
		}
	}
	while(q.size()){
		u=q.front();
		nd[++now]=u;
		q.pop();
		for(i=0;i<gg[u].size();++i){
			d[gg[u][i]]--;
			if(d[gg[u][i]]==0)q.push(gg[u][i]);
		}
	}
	for(ll p=1,q=now;p<q;++p,--q){
		swap(nd[p],nd[q]);
	}
//	cout<<n<<endl<<endl;
//	for(i=1;i<=now;++i)cout<<nd[i]<<' ';
//	cout<<endl;
	ans[0].p=m;
	for(i=0;i<=n;++i){
		ans[i].q=1;
	}
	for(int b=0;b<=n;++b){
		i=nd[b];
	//	printf("%d %d\n",ans[i].p,ans[i].q);
		t=div(ans[i],g[i].size());
		for(j=0;j<g[i].size();++j){
			ans[g[i][j]]=add(ans[g[i][j]],t);
		}
	}
	for(i=1;i<=n;++i){
		ans[i]=div(ans[i],2);
		if(g[i].size()==0){
			printf("%lld %lld\n",ans[i].p,ans[i].q);
		}
	}
	return 0;
}
