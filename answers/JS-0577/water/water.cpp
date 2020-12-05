#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while(c=='\n'||c==' ')c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}	
	return x;
}
int n,m;
long long p1[100005],q1[100005];
vector<int>a[100005];
void dfs(int x,long long p,long long q){
	if(p1[x]==0&&q1[x]==0){
		p1[x]=p;
		q1[x]=q;
	}
	else{
		p1[x]=p1[x]*q+q1[x]*p;
		q1[x]=q1[x]*q;
		long long y=__gcd(p1[x],q1[x]);
		p1[x]/=y;
		q1[x]/=y;
	}
	for(int i=0;i<a[x].size();i++){
		dfs(a[x][i],p,q*a[x].size());
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		int d;
		d=read();
		while(d--){
			int x;
			cin>>x;
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i,1,1);
	}
	for(int i=m+1;i<=n;i++){
		if(a[i].size()==0){
			cout<<p1[i]<<' '<<q1[i]<<'\n';
		}
	}
	return 0;
}




