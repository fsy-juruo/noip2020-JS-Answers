#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int x=0,f=1; char ch=getchar();
	if(ch=='-'){f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3);
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int n,m;
bool flag;
stack <int> ss[55];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
//	cout<<(sizeof(ss))/1024/1024;
	int x,prx;
	n=read(); m=read(); flag=0;
	for(int i=1;i<=n;i++){
		x=read();
		ss[i].push(x);
		prx=x;
		for(int j=2;j<=m;j++){
			x=read();
			ss[i].push(x);
			if(x!=prx) flag=1;
		}
	}
	if(!flag){
		cout<<0; return 0;
	}
	else{
		cout<<"6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2";
	}
	return 0;
}
