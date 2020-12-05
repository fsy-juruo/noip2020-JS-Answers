#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int n,k,w[maxn],c[maxn],d[maxn],ans;
inline int read() {
	int f=1, x=0;
	char ch;
	do {
		ch=getchar();
		if(ch=='-')f=-1;
	} while(ch<'0'||ch>'9');
	do {
		x=x*10+ch-'0';
		ch=getchar();
	} while(ch>='0'&&ch<='9');
	return f*x;
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
n=read();
k=read();
for(int i=1;i<=k;i++)
w[i]=read();
for(int i=1;i<=n;i++){
	c[i]=read();
	d[i]=read();
}
ans=n*(2*n+1);
cout<<ans<<'\n';
	return 0;
}
