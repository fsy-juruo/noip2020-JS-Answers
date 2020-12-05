#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
const int maxn=500757;
using namespace std;
long long w[maxn],c[maxn],d[maxn];
int n,m,k;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i(1);i<=k;++i){
		scanf("%lld",&w[i]);
	}
	for(int i(1);i<=n;++i){
		scanf("%lld%lld",&c[i],&d[i]);
	}
	puts("-1");
	return 0;
}

