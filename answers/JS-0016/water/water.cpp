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
const int maxn = 2e5+10 ;
int n,m ;
long long p[maxn],q[maxn] ;
vector<int>v[maxn] ;
long long d[maxn] ;
int inq[maxn] ;
long long Gcd(long long a,long long b){
	if(a<b)swap(a,b) ;
	//cout<<a<<" "<<b<<endl ;
	if(b==1)return 1 ;
	if(b==0)return a ;
	return Gcd(a%b,b) ;
}
void bfs(){
	queue<int>s ;
	for(int i = 1 ; i <= n ; i++)
		if(inq[i]==0)
			p[i] = 1ll,s.push(i) ;
	int t ;
	while(!s.empty()){
		t = s.front() ; s.pop() ;
		for(int i = 0 ; i < d[t] ; i++)
		{	
			int x = v[t][i] ;
			inq[x]-- ;
			p[x] = p[t]*q[x]+q[t]*p[x]*d[t] ;
			q[x] = q[x]*q[t]*d[t] ;	
			long long g = Gcd(p[x],q[x]) ;
			p[x] = p[x]/g ; q[x] = q[x]/g ;
			if(inq[x]==0)
				s.push(x) ;
		}
			
	}
}
int main(){
    freopen("water.in","r",stdin) ;
    freopen("water.out","w",stdout) ;
	read(n) ; read(m) ;
	int x ;
	for(int i = 1 ; i <= n ; i++){
		read(d[i]) ;
		q[i] = 1 ;
		for(int j = 1 ; j <= d[i] ; j++){
			read(x) ; v[i].push_back(x) ; inq[x]++ ;
		}
	}
	
	bfs() ;
	
	for(int i = 1 ; i <= n ; i++)
		if(d[i]==0)
			printf("%lld %lld\n",p[i],q[i]) ;
	return 0 ;
}

