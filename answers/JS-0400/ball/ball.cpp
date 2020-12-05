#include<bits/stdc++.h>
using namespace std;
int n,m,a[57][407];

inline int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			a[i][j]=read();
	return 0;
}

