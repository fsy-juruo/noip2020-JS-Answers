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
const int maxn = 1e3+10 ;
int t ;
string s ;
char C ;
int l1,l2,l ;
int b[30],d[30] ;
int c[2][maxn] ;
bool check(int i,int j,int p){
	for(int k = i+j ; k < (i+j)*p ; k++)
		if(s[k]!=s[(k%(i+j))])
			return false ;
	int x = c[0][i-1] ;
	int y = c[1][(i+j)*p] ;
	if(x>y)return false ;
	return true ;
}
bool ok = 1 ;
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
	read(t) ;
	while(t--){
		memset(b,0,sizeof(b)) ; memset(d,0,sizeof(d)) ;
		memset(c,0,sizeof(c)) ; 
		string s1 ;
		char C = getchar() ;
		while(C<'a'||C>'z')continue ;
		while(C>='a'&&C<='z'){
			if(C!=s1[s1.size()-1])ok = false ;
			s1+=C ;
			
			C = getchar() ;
		}
		s = s1 ;
		l = s.size() ;
		long long ans = 0 ;
		//cout<<l<<endl ;
		b[s[0]-'a'] = c[0][0] = 1 ;
		for(int i = 1 ; i < l-2 ; i++){
			b[s[i]-'a']++ ; 
			if(b[s[i]-'a']%2==1)c[0][i] = c[0][i-1]+1 ;
			else c[0][i] = c[0][i-1]-1 ;
		}
	//	for(int i = 1 ; i < l-2 ; i++)
	//		if(count(0,i)!=c[0][i])
	//			cout<<i<<endl ;
	//	cout<<count(0,14)<<" "<<c[0][14]<<endl ;
		d[s[l-1]-'a'] = c[1][l-1] = 1 ;
		for(int i = l-2 ; i > 1 ; i--){
			d[s[i]-'a']++ ;
			if(d[s[i]-'a']%2==1)c[1][i] = c[1][i+1]+1 ;
			else c[1][i] = c[1][i+1]-1 ;
		}
	 	for(l1 = 1 ; l1 < l-1 ; l1++)
			for(l2 = 1 ; l2+l1 < l ; l2++)
				for(int k = 1 ; (l1+l2)*k < l ; k++)
					if(check(l1,l2,k))
						ans++ ;
							
		printf("%lld\n",ans) ;
	}
	return 0 ;
}

