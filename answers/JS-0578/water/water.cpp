#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>inline void read(T& FF){
	FF=0;T RR=1;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
template<typename T>inline void write(T FF){
	if(FF<0){putchar('-');FF*=-1;}
	if(FF>9)write(FF/10);
	putchar(FF%10+48);
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
ll d[100010],p[100010],q[100010];
vector<int>v[100010];
void add(int x,ll a,ll b){
//	cout<<a<<" "<<b<<endl;
//	cout<<x<<" "<<p[x]<<" "<<q[x]<<endl; 
	p[x]=p[x]*b+q[x]*a;
	q[x]*=b;
	ll z=gcd(p[x],q[x]);
//	cout<<z<<endl;
	p[x]/=z;q[x]/=z;
//	cout<<p[x]<<" "<<q[x]<<endl;
}
void dfs(int x){
//	cout<<x<<endl;
	for(int i=0;i<d[x];i++){
		add(v[x][i],p[x],q[x]*d[x]);
		dfs(v[x][i]);
	}
	if(d[x])p[x]=0,q[x]=1;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;read(n);read(m);
	for(int i=1;i<=n;i++){
		p[i]=0;q[i]=1;
		read(d[i]);
		for(int j=1;j<=d[i];j++){
			int x;read(x);
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		add(i,1ll,1ll);
		dfs(i);
	}
	for(int i=1;i<=n;i++)
		if(!d[i]){
			write(p[i]);putchar(32);write(q[i]);puts("");
		}
	return 0;
}

