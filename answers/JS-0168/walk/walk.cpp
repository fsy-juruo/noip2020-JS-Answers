#include<bits/stdc++.h>
using namespace std;
int ans;
int n,k;
int a[20];
int c[105],d[105],w[105];
inline long long read(){
	long long x=0;int m=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') m=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*m;
}
void dfs(int x){
	for(int i=1;i<=w[x];i++){
		a[x]=i;
		if(x<k) dfs(x+1);
		if(x==k) {
			int b[100];
			for(int j=1;j<=k;j++) b[j]=a[j];
			int p=1;
			while(true){
				b[c[p]]+=d[p];
				ans++;
				if(b[c[p]]<1||b[c[p]]>w[c[p]]) break;
				p++;
				if(p>n) p-=n;
			}
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		d[i]=read();
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
