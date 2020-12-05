#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T&x){
	x=0;
	int flg=1;
	char ch=getchar();
	while((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if(ch=='-') ch=getchar(),flg=-1;
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=flg;
}
const int N=1e5+10;
vector<int>mp[N];
int d[N],b[N];//d:chudu;b:rudu
long long ansx[N],ansy[N];
inline long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
inline void clc(long long x,long long y,long long dep){
	long long ax=ansx[dep],ay=ansy[dep];
	if(ax==0){
		ansx[dep]=x,ansy[dep]=y;return;
	}
	long long tx=ax*y+ay*x;
	long long ty=ay*y;
	long long g=gcd(tx,ty);
	tx/=g,ty/=g;
	ansx[dep]=tx,ansy[dep]=ty;
}
void dfs(int dep,long long x,long long y){
	if(d[dep]==0){
		long long g=gcd(x,y);
		x/=g,y/=g;
		clc(x,y,dep);
		return;
	}
	for(int i=0;i<d[dep];i++){
		int to=mp[dep][i];
		dfs(to,x,y*d[dep]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(d[i]);
		for(int j=1;j<=d[i];j++){
			int x;
			read(x);
			mp[i].push_back(x);
			b[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			dfs(i,1ll,1ll);
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			printf("%lld %lld\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}

