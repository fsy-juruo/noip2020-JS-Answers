#include<bits/stdc++.h>
using namespace std;
int MOD=1000000007;
template<typename T>inline void read(T &cn){
	cn=0;int sig=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')sig=-1;c=getchar();}
	while(isdigit(c)){cn=cn*10+c-48;c=getchar();}
	cn*=sig;
}
template<typename T>inline void write(T cn){
	int wei=0;
	int cx=cn%10;cn/=10;
	if(cx<0||cn<0){
		putchar('-');
		cx=0-cx;cn=0-cn;
	}
	T cm=0;
	while(cn){
		cm=cm*10+cn%10;cn/=10;
		wei++;
	}
	while(wei--){
		putchar(cm%10+48);
		cm/=10;
	}
	putchar(cx+48);
}
int f1,s=0,c[500005],d[500005],w[500005];
int n,k;
inline void dfs1(int x,int dep){
	if(x>n||x<1){
		s+=dep;
		s%=MOD;
		return ;
	}
	if(dep>n){
		if(x==f1){
			printf("-1\n");
			exit(0);
		}else{
			dep%=n;
		}
	}
	dfs1(x+d[dep],dep+1);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);	
	read(n),read(k);
	for(int i=1;i<=k;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		read(c[i]),read(d[i]);
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			f1=i;
			dfs1(i,1);
		}
	}else{
		printf("-1\n");
	}
	return 0;
}

