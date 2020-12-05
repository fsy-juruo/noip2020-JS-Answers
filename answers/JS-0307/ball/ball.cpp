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
int n,m;
vector < int > bs[55];
bool done[55];
vector < pii > opr;
void op(int x,int y){
	opr.push_back(mpr(x+1,y+1));
	bs[y].push_back(bs[x].back());
	bs[x].pop_back();
}
void op(int x,int y,int c){
	while(c--) op(x,y);
}
int main(){
	// CHECK CORNER CASES !!!
	// CHECK INITIALIZATION !!!
	// djq txdy !!!
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j,k;
	n=readint();m=readint();
	for(i=0;i<n;++i){
		for(j=0;j<m;++j) bs[i].push_back(readint()-1);
	}
	if(n==1){
		printf("0\n");
		return 0;
	}
	int em=n;
	++n;
	for(i=0;i<n-1;++i){
		for(j=0;j<n;++j){
			if(j==em) continue;
			if(done[j]) continue;
			// sort
			for(k=m-1;k>=0;){
				if(bs[j][k]==i){
					--k;
					continue;
				}
				int ot=0;
				for(ot=0;ot<n;++ot){
					if(ot!=em && ot!=j) break;
				}
				op(ot,em,m-k);
				op(j,ot,m-k);
				op(j,em,k);
				op(ot,j,1);
				op(em,j,k);
				op(ot,j,m-k-1);
				op(em,ot,m-k);
			}
		}
		for(j=0;j<n;++j){
			while(!bs[j].empty() && bs[j].back()==i){
				op(j,em,1);
			}
		}
		done[em]=1;
		for(em=0;em<n;++em){
			if(!done[em]) break;
		}
		while(!bs[em].empty()){
			for(j=0;j<n;++j){
				if(!done[j] && j!=em && bs[j].size()<m) break;
			}
			op(em,j,1);
		}
	}
	printf("%d\n",(int)opr.size());
	for(i=0;i<(int)opr.size();++i){
		printf("%d %d\n",opr[i].FS,opr[i].SC);
	}
	return 0;
}
