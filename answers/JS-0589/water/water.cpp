#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll read(){
	ll x=0,f=1; char ch=getchar();
	if(ch=='-'){f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3);
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
//bool flage[N];
struct node{
	ll p,q;
}sum[N],ress;
vector <int> ver[N];
ll d[N];
vector <int> ene,ena;
int n,m;
ll gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return (a/gcd(a,b))*b;
}
void jia(int y){
	ll pul=lcm(sum[y].q,ress.q);
	sum[y].p*=(pul/sum[y].q);
	ll nresp=(pul/ress.q)*ress.p;
	sum[y].p+=nresp;
	sum[y].q=pul;
}
void init(int x){
	sum[x].p=0; sum[x].q=1;
}
void huajian(int x){
	ll pul=gcd(sum[x].p,sum[x].q);
	sum[x].p/=pul; sum[x].q/=pul;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
//	cout<<(sizeof(ver)+sizeof(sum)+sizeof(ress)+sizeof(d)+2*sizeof(ene))/1024/1024;
	int v;
//	memset(flage,0,sizeof(flage));
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		d[i]=read();
		init(i);
		if(d[i]==0) ene.push_back(i);
		else ena.push_back(i);
		for(int j=0;j<d[i];j++){
			v=read();
			ver[i].push_back(v);
		}
	}
//	int na=ena.size(),ne=ene.size();
	for(int i=1;i<=m;i++){
		ress.p=1; ress.q=d[i];
		for(int j=0;j<d[i];j++){
			jia(ver[i][j]);//next_sum=ress+sum
		}
	}
	bool flag=1;
	vector <int> :: iterator it;
	while(flag){
		flag=0;
		for(it=ena.begin();it!=ena.end();it++){
			int u=*it;
			if(sum[u].p==0) continue;
			flag=1;
			ress.p=sum[u].p; ress.q=sum[u].q*d[u];
			init(u);
			for(int j=0;j<d[u];j++){
				jia(ver[u][j]);
			}
		}
	}
	for(it=ene.begin();it!=ene.end();it++){
		huajian(*it);
		printf("%lld %lld\n",sum[*it].p,sum[*it].q);
	}
	return 0;
}
