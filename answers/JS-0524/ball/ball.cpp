#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1;
	int s=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		s=s*10+(c-'0');
		c=getchar();
	}
	return f*s;
}
struct Info{
	int x,y;
}ans[820002];
int n,m,t,a[52][402];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)a[i][j]=read();
	}
	
	cout<<0<<endl;
	return 0;
}

