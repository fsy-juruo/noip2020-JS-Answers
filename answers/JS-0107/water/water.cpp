#include<bits/stdc++.h>
using namespace std;
long long n,u,v,m,gfz,gfm;
bool vis[100005];
struct node{
	long long fz,fm,cd;
	bool jw;
}a[100005];
vector<long long> e[100005];
vector<long long> jsk;
long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
void yf(long long j){
	long long t=gcd(a[j].fz,a[j].fm);
	a[j].fz/=t;
	a[j].fm/=t;
}
void jf(long long k){
	if(a[k].fz==0){
	a[k].fz=gfz;
	a[k].fm=gfm;
	}
	else{
	long long fmh=gfm*a[k].fm;
	long long fzh=gfz*a[k].fm+a[k].fz*gfm;
	long long t=gcd(fmh,fzh);
	a[k].fz=fzh/t;
	a[k].fm=fmh/t;
    }
}
void dfs(long long x){
	if(a[x].jw)
	return ;
	a[x].fm*=a[x].cd;
	yf(x);
	gfz=a[x].fz;
	gfm=a[x].fm;
	a[x].fz=0;
	a[x].fm=1;
	for(long long i=0;i<e[x].size();i++){
		jf(e[x][i]);	
	}
	for(long long i=0;i<e[x].size();i++){
		dfs(e[x][i]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> u;
		for(int j=1;j<=u;j++){
			cin >> v;
			e[i].push_back(v);
			vis[v]=true;
		}
		a[i].cd=u;
		if(u==0)
		a[i].jw=true;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		a[i].fz=1;
		a[i].fm=1;
		jsk.push_back(i);
	}
	for(int i=0;i<jsk.size();i++){
		dfs(jsk[i]);
	}	
	for(int i=1;i<=n;i++){
		if(a[i].jw)
		if(a[i].fm==1)
		cout << a[i].fz << endl;
		else
		cout << a[i].fz << " " << a[i].fm << endl;
	}
	return 0;
}
