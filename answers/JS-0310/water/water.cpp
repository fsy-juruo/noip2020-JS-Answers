#include<bits/stdc++.h>
using namespace std;

struct node{
	long long fz,fm;
}sum[100010];
long long n,m,t,s[100010],pour_in[100010];
vector<long long>a[100010];

void readp(){
	memset(pour_in,0,sizeof(pour_in));
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		for(int j=1;j<=s[i];++j){
			cin>>t;
			pour_in[t]++;
			a[i].push_back(t);
		}
	}
}

long long GCD(long long c,long long b){
	if(b==0) return c;
	return GCD(b,c%b);
}

void add_up(long long aimt,long long fenzi,long long fenmu){
	if(sum[aimt].fz==0&&sum[aimt].fm==0){
		sum[aimt].fz=fenzi;
		sum[aimt].fm=fenmu;
		return;
	}
	else{
		long long p=sum[aimt].fm*fenmu/GCD(sum[aimt].fm,fenmu);
		long long q=p/sum[aimt].fm*sum[aimt].fz;
		long long z=p/fenmu*fenzi;
		long long u=GCD(q+z,p);
		sum[aimt].fz=(q+z)/u;
		sum[aimt].fm=p/u;
		return;
	}
}

void DFS(int x){
	if(s[x]==0) return;
	for(int i=0;i<a[x].size();++i){
		add_up(a[x][i],sum[x].fz,sum[x].fm*s[x]);
		DFS(a[x][i]);
	}
	sum[x].fz=sum[x].fm=0;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	readp();
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;++i){
		if(pour_in[i]==0){
			sum[i].fz=sum[i].fm=1;
			DFS(i);
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]==0)
			cout<<sum[i].fz<<' '<<sum[i].fm<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

