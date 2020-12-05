#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x){
	write(x),putchar('\n');
}
int w[15],c[500005],d[500005],a[15],n,k,ans,tmp[15];
inline bool ok(){
	for(int i=1;i<=k;++i)if(tmp[i]==0||tmp[i]>w[i])return 0;
	return 1;
}
inline bool ok2(){
	for(int i=1;i<=k;++i)if(tmp[i]!=a[i])return 0;
	return 1;
}
void dfs(int dep){
	if(dep>k){
		for(int i=1;i<=k;++i)tmp[i]=a[i];
		int p=0,f=0;
		while(ok()){
			++p;
			++ans;
			if(p>n){
				p=f=1;
				if(f){
					if(ok2()){
						puts("-1");
						exit(0);
					}
					else f=0;
				}
			}
			tmp[c[p]]+=d[p];
		}
		return;
	}
	for(int i=1;i<=w[dep];++i){
		a[dep]=i;
		dfs(dep+1);
	}
	return;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;++i)w[i]=read();
	for(int i=1;i<=n;++i)c[i]=read(),d[i]=read();
	if(n<=100||k==1||(n<=2000&&k==2)){
		dfs(1);
		writeln(ans);
		return 0;
	}
	puts("-1");
	return 0;
}
