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
const int maxn = 1e3 ;
int n,m ;
int l[maxn],a[60][maxn] ;
map<string,int>g ;
bool ok[60] ;
bool check(int x){
	if(l[x]==1)return false ;
	for(int i = 2 ; i <= l[x] ; i++)
		if(a[x][i]!=a[x][1])
			return false ;
	return true ;
}
bool flag = 0 ;
stack<pair<int,int> >ans ;
void dfs(int dep){
	//cout<<dep<<endl ;
	int tot = 0 ;
	string str ;
	for(int i = 1 ; i <= n+1 ; i++)
		for(int j = 1 ; j <= m ; j++)
			str+=(char)(a[i][j]+'0') ;
	if(dep>=g[str]&&g[str]!=0)return ;
	//cout<<g[str]<<endl ;
	g[str] = dep ; 
	if(dep>=5000)return ;
	for(int i = 1 ; i <= n+1 ; i++)
		if(l[i]==m&&check(i))
			tot++ ;
	if(tot==n){
		flag = 1 ;
		return ;
	}
	for(int i = 1 ; i <= n+1 ; i++)
		if(l[i]>0)
			for(int j = 1 ; j <= n+1 ; j++)
			{
				
				if(i==j)continue ;
				if(l[j]>=m)continue ;
				//if(j==n+1)cout<<1<<endl ;
				a[j][l[j]+1] = a[i][l[i]] ;
				a[i][l[i]] = 0 ;
				l[i]-- ; l[j]++ ;
				dfs(dep+1) ;
				if(flag){
					ans.push(make_pair(i,j)) ;
					return ;
				}
				a[i][l[i]+1] = a[j][l[j]] ;
				a[j][l[j]] = 0 ;
				l[i]++ ; l[j]-- ;
			}
}
int main(){
    freopen("ball.in","r",stdin) ;
    freopen("ball.out","w",stdout) ;
	read(n) ; read(m) ;
	int x ;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			read(a[i][j]),l[i] = m ;
	dfs(1) ;
	printf("%d\n",ans.size()) ;
	while(!ans.empty()){
		printf("%d %d\n",ans.top().first,ans.top().second) ;
		ans.pop() ;
	}
	return 0 ;
}

