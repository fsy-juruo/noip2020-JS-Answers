#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair < int , int > pii;
#define mpr make_pair
#define FS first
#define SC second
template < typename T > void UMIN(T &a,T b){a=(b<a?b:a);}
template < typename T > void UMAX(T &a,T b){a=(b>a?b:a);}
char readch(){
	char c=getchar();
	while(c==' '||c=='\n'||c=='\t'||c=='\r') c=getchar();
	return c;
}
LL readint(){
	char c=getchar();
	bool neg=0;
	while(c<'0' || c>'9'){
		if(c=='-') neg=1;
		c=getchar();
	}
	LL ret=0;
	while(c>='0' && c<='9'){
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return neg?-ret:ret;
}
void putint(LL V){
	if(V<0){
		V=-V;
		putchar('-');
	}
	if(!V){
		putchar('0');
		return;
	}
	if(V>=10) putint(V/10);
	putchar('0'+(V%10));
}
const int maxn=1048576;
int prv[maxn+5],sfv[maxn+5],nx[maxn+5];
int precnt[maxn+5][27];
int n,cc[26];
vector < int > dvs[maxn+5];
char ss[5][maxn+5];
void solve(char *s){
	int i,j,k;
	n=strlen(s);
	j=0;
	memset(nx,0,sizeof(nx));
	for(i=1;i<n;++i){
		while(j && s[j]!=s[i]) j=nx[j-1];
		if(s[j]==s[i]) nx[i]=++j;
	}
	memset(cc,0,sizeof(cc));
	for(i=0;i<n;++i){
		cc[s[i]-'a']^=1;
		prv[i]=0;
		for(j=0;j<26;++j) prv[i]+=cc[j];
	}
	memset(cc,0,sizeof(cc));
	for(i=n-1;i>=0;--i){
		cc[s[i]-'a']^=1;
		sfv[i]=0;
		for(j=0;j<26;++j) sfv[i]+=cc[j];
	}
	memset(precnt,0,sizeof(precnt));
	LL ret=0;
	for(i=0;i<n;++i){
		memcpy(precnt[i+1],precnt[i],sizeof(precnt[i]));
		for(j=prv[i];j<=26;++j) ++precnt[i+1][j];
	}
	for(i=2;i<n;++i){
		int mnrep=i,sv=sfv[i];
		if(!(i%(i-nx[i-1]))) mnrep=i-nx[i-1];
		int pct=i/mnrep;
		for(j=0;j<(int)dvs[pct].size();++j){
			ret+=precnt[mnrep*dvs[pct][j]-1][sv];
		}
	}
	putint(ret);
	putchar('\n');
}
int main(){
	// CHECK CORNER CASES !!!
	// CHECK INITIALIZATION !!!
	// djq txdy !!!
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=readint(),i,j,k;
	int mxl=5;
	for(i=0;i<t;++i){
		scanf("%s",ss[i]);
		UMAX(mxl,(int)strlen(ss[i]));
	}
	for(i=1;i<=mxl;++i){
		for(j=i;j<=mxl;j+=i) dvs[j].push_back(i);
	}
	for(i=0;i<t;++i) solve(ss[i]);
	return 0;
}
/*
code structure
1. prec value of each prefix & suffix
2. build 2-d array for prefix
	ignore 0-length
3. iterate over prefix, iterate over duplicate
	remember to make sure non-emptyness
*/
