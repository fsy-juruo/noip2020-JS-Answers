#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=100010;
struct node{
	ll x,y; 
	ll p,q;
	int k;//±‡∫≈ 
}num[N];
int n,m;
ll gcd(ll m,ll n){
	if(n==0) return m;
	return gcd(n,m%n);
}
void add(ll k,ll x,ll y,ll c,ll v){
	x=x*v,c=y*c;
	num[k].p=x+c;
	num[k].q=y*v;
	ll z=gcd(num[k].p,num[k].q);
	num[k].p=num[k].p/z,num[k].q=num[k].q/z;
	num[k].x=0,num[k].y=0;
}
bool st[N];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(st,1,sizeof(st));
	for(int i=1;i<=n;i++) num[i].p=num[i].q=0;
	for(int i=1;i<=m;i++) num[i].p=num[i].q=1;
	for(int i=1;i<=n;i++){
		int d;
		cin>>d;
		if(d==0){
			st[i]=false;
			continue;
		}
		for(int j=1;j<=d;j++){
			cin>>num[i].k;
			int t=num[i].k;
			if(num[t].p&&num[t].q){
				num[t].x=num[i].p;
				num[t].y=num[i].q*d;
				add(t,num[t].x,num[t].y,num[t].p,num[t].q);
			}
			else{
				num[t].p=num[i].p;
				num[t].q=num[i].q*d;
				add(t,0,1,num[t].p,num[t].q);//∑¿÷πp”Îq*d≤ªª•÷  
			}
		}
	}
	for(int i=1;i<=n;i++) if(!st[i]) printf("%lld %lld\n",num[i].p,num[i].q);
	return 0;
}
