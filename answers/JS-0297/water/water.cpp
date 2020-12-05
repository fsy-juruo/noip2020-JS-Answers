#include<bits/stdc++.h>
using namespace std;
bool hash[1001];
int a[1001][1001];
int start[1001];
int K=0;
struct node{
	long long a,b;
	node operator +(node x){
		long long gcd=__gcd(b,x.b);
		long long lcm=b*x.b/gcd;
		a=a*(lcm/b)+x.a*(lcm/x.b);
		b=lcm;
		gcd=__gcd(a,b);
		a/=gcd;b/=gcd;
		node z;
		z.give(a,b);
		return z;
	}
	node operator /(long long x){
		long long gcd=__gcd(x,a);
		a/=gcd;x/=gcd;
		b*=x;
		node z;
		z.give(a,b);
		return z;
	}
	void give(long long x,long long y){
		a=x;b=y;
	}
	void output(){
		cout<<a<<' '<<b<<endl;
	}
	void clear(){
		a=0;b=1;
	}
};
node ans[1001];
void dfs(int now,node num){
	if(a[now][0]==0){
		ans[now]=ans[now]+num;
		return ;
	}
	node num1=num/a[now][0];
	for(int i=1;i<=a[now][0];i++){
		dfs(a[now][i],num1);
	}
	return ;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			hash[a[i][j]]=1;
		}
		a[i][0]=k;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=a[i][0];j++)cout<<a[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)if(hash[i]==0)start[++K]=i;
//	cout<<start<<endl;
	for(int i=1;i<=n;i++){
		ans[i].clear();
	}
	node total;
	total.give(1,1);
	for(int i=1;i<=m;i++)dfs(start[i],total);
	for(int i=1;i<=n;i++){
		if(a[i][0]==0)ans[i].output();
	}
	return 0;
}


