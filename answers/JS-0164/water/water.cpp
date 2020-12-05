#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
struct Frac{
	long long fz,fm;
};
long long gcd(long long x,long long y){
	if(y==0)return x;
	return gcd(y,x%y);
}
Frac yue(Frac x){
	long long G=gcd(x.fm,x.fz);
	x.fm/=G;x.fz/=G;
	return x;
}
Frac jia(Frac x,Frac y){
	Frac res;
	res.fm=x.fm*y.fm;
	res.fz=x.fz*y.fm+x.fm*y.fz;
	return yue(res);
}
Frac va[100010];
long long n,m,ru[100010],chu[100010],vis[100010];
vector<long long>A[100010];
void dfs(long long x){
	vis[x]=1;
	if(chu[x]==0)return;
	Frac Chu=va[x];
	Chu.fm*=chu[x];
	Chu=yue(Chu);
	va[x].fz=0;va[x].fm=1;
	for(long long i=0;i<A[x].size();i++){
		long long y=A[x][i];
		va[y]=jia(va[y],Chu);
		ru[y]--;
		if(!vis[y]&&ru[y]==0)dfs(y);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	read(n);read(m);
	for(long long i=1;i<=n;i++){
		read(chu[i]);
		for(long long j=1;j<=chu[i];j++){
			long long x;
			read(x);
			A[i].push_back(x);
			ru[x]++;
		}
		va[i].fm=1;va[i].fz=0;
		vis[i]=0;
	}
	
	for(long long i=1;i<=n;i++){
		if(!vis[i]&&ru[i]==0){
			va[i].fz+=va[i].fm;
			dfs(i);
		}
	}
	
	for(long long i=1;i<=n;i++){
		if(chu[i]==0){
			write(va[i].fz);putchar(' ');writeln(va[i].fm);
		}
	}
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

