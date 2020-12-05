#include <bits/stdc++.h>
using namespace std;

#define MAXN 110000

long long n,m,num1[MAXN],num2[MAXN];
int que[MAXN];
vector<int> g[MAXN];

struct node{
	long long son,mother;
};
node ans[MAXN];

void readp(){
	cin>>n>>m;
	int a,v;
	for(int i=1;i<=n;i++){
		cin>>a;
		num1[i]=a;
		for(int j=1;j<=a;j++){
			cin>>v;
			g[i].push_back(v);
			num2[v]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(num2[i]==0){
			ans[i].mother=1;
			ans[i].son=1;
			que[++que[0]]=i;
		}
	}
}

long long gcd(long long m,long long n){
	return n?gcd(n,m%n):m;
}

long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}

node f1(node q,node p){
	if(q.son!=0){
		long long a=lcm(q.mother,p.mother);
		q.son=q.son*(a/q.mother);
		p.son=p.son*(a/p.mother);
		q.mother=a;
		q.son+=p.son;
		return q;
	}
	else{
		return p;
	}
}

node f2(node q,long long x){
		q.mother*=x;
		return q;
}

void dfs(int point,node q){
	if(g[point].empty()){
		ans[point]=f1(ans[point],q);
		return;
	}
	for(int i=0;i<g[point].size();i++){
		node p=f2(q,num1[point]);
		dfs(g[point][i],p);
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	readp();
	for(int i=1;i<=que[0];i++)	
		dfs(i,ans[i]);
	for(int i=1;i<=n;i++){
		if(num1[i]==0){
			long long a=gcd(ans[i].son,ans[i].mother);
			cout<<ans[i].son/a<<" "<<ans[i].mother/a<<endl;			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
