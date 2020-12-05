#include<bits/stdc++.h>
using namespace std ;
template<typename T> void read(T &x){
	x = 0 ; int flag = 1 ;
	char c = getchar() ;
	while(!isdigit(c)){
		if(c=='-')
			flag = -1 ;
		c = getchar() ;
	}
	while(isdigit(c)){
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	x = x * flag ;
}
const int maxn = 5e5+10 ;
int n,k ;
long long w[maxn],c[maxn],d[maxn] ;
long long sum[20],sum2[20],q[20] ;
const long long mod = 1e9+7 ;
long long p ;
long long x[maxn],a[maxn] ;
long long ans = 0 ;
void dfs(int dep){
	if(dep==k+1){
		int i = 1 ;
		for(int i = 1 ; i <= k ; i++)
			a[i] = x[i] ;
		while(1){
			a[c[i]]+=d[i] ;
			ans++ ;
			if(a[c[i]]<1||a[c[i]]>w[c[i]])break ;
			i = (i%n)+1 ;
			
		}
		//printf("%lld\n",ans) ;
		return ;
	}
	for(int i = 1 ; i <= w[dep] ; i++){
		x[dep] = i ;
		dfs(dep+1) ;
	}
}
int main(){
    freopen("walk.in","r",stdin) ;
    freopen("walk.out","w",stdout) ;
	read(n) ; read(k) ;
	for(int i = 1 ; i <= k ; i++)
		read(w[i]) ;
	for(int i = 1 ; i <= n ; i++)
		read(c[i]),read(d[i]),sum[c[i]]+=d[i],q[c[i]]++ ;
	int tot = 0 ;
	for(int i = 1 ; i <= k ; i++)
		tot+=abs(sum[i]) ;
	if(tot==0){
		printf("-1\n") ;
		return 0 ;
	}
	dfs(1) ;
	printf("%lld\n",ans) ;
	return 0 ;
}

