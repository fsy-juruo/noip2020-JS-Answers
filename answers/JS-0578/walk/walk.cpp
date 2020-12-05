#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T& FF){
	FF=0;T RR=1;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
const int MOD=1e9+7;
bool flag=true;
int n,k,f[500010],ans,t[500010],c[500010],d[500010],a[500010];
void dfs(int x){
	if(x==k+1){
		for(int i=1;i<=k;i++)f[i]=t[i];
		while(1){
			bool fg=false;
			for(int i=1;i<=n;i++){
				f[c[i]]+=d[i];
				ans++;
				if(ans>MOD)ans-=MOD;
				if(f[c[i]]<1||f[c[i]]>a[c[i]]){
					fg=true;
					break;
				}
			}
			if(fg)break;
			if(flag){
				puts("-1");
				exit(0);
			}
		}return;
	}
	for(int i=1;i<=a[x];i++){
		t[x]=i;
		dfs(x+1);
	}
}
const long long MAXN=1e9;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	long long s=1;
	for(int i=1;i<=k;i++){
		read(a[i]);
		s=s*a[i];
		if(s>MAXN){
			cout<<-1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		read(c[i]),read(d[i]);
		f[c[i]]+=d[i];
	}
	for(int i=1;i<=k;i++)
		if(f[i])flag=false;
	dfs(1);
//	if(){
//		cout<<-1;
//		return 0;
//	}
	cout<<ans;
	return 0;
}

