#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[100005],du[100005];
vector<int> a,e[100005];
queue<int> q;
struct A{
	long long p,q;
}dp[100005];
int Read(){
	int num=0;
	char cc=getchar();
	while(cc<'0'||cc>'9') cc=getchar();
	while(cc>='0'&&cc<='9'){
		num=(num<<1)+(num<<3);
		num+=cc-'0';
		cc=getchar();
	}
	return num;
}
long long Gcd(long a,long b){ 
	if(a>b) swap(a,b);
	if(a==0) return b;
	return Gcd(b%a,a);
}
A Add(A x,int k,A y){//printf("%d %d %d %d %d",x.p,x.q,k,y.p,y.q);
	A z;
	z.p=x.p;
	z.q=x.q*k;
	z.p=z.p*y.q+z.q*y.p;
	z.q=z.q*y.q;
	long long b;
	b=Gcd(z.q,z.p);
	z.p=z.p/b;
	z.q=z.q/b;
	return z;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=Read();m=Read();
	for(int i=1;i<=n;i++){
		d[i]=Read();
		if(!d[i]) a.push_back(i);
		for(int j=1;j<=d[i];j++){
			int v=Read();
			e[i].push_back(v);
			du[v]++;
		} 
	}
	for(int i=1;i<=n;i++){
		dp[i].q=1;
		if(!du[i]){
			q.push(i);
			dp[i].p=dp[i].q=1;
		}	
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			dp[y]=Add(dp[x],d[x],dp[y]);
			du[y]--;
			if(!du[y]) q.push(y);
		}
	}
	for(int i=0;i<a.size();i++){
		int x=a[i];
		printf("%lld %lld\n",dp[x].p,dp[x].q);
	}
	
	return 0;
}
