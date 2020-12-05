#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T&x){
	x=0;
	int flg=1;
	char ch=getchar();
	while((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if(ch=='-') ch=getchar(),flg=-1;
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=flg;
}
int a[110][1100];
int n,m,flg=0;
int ax[820100],ay[820100];
int siz[110];
inline void dfs(int dep,int maxdep){
	if(dep>maxdep){
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<m;j++){
				if(a[i][j]!=a[i][j+1]) return;
			}
		}
		flg=1;
		printf("%d\n",maxdep);
		for(int i=1;i<=maxdep;i++){
			printf("%d %d\n",ax[i],ay[i]);
		}
		return;
	}
	if(flg) return;
	for(int i=1;i<=n+1;i++){
		if(!siz[i]) continue;
		if(flg) return;
		for(int j=1;j<=n+1;j++){
			if(flg) return;
			if(siz[j]>=m) continue;
			if(i==j) continue;
			ax[dep]=i;
			ay[dep]=j;
			int d1=a[i][siz[i]];
			a[i][siz[i]]=-1;siz[i]--;
			a[j][++siz[j]]=d1;
			dfs(dep+1,maxdep);
			a[j][siz[j]]=-1;
			siz[j]--;
			siz[i]++;
			a[i][siz[i]]=d1;
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	read(n),read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(a[i][j]);
		}
		siz[i]=m;
	}
	for(int i=0;i<=820000;i++){
		flg=0;
		dfs(1,i);
		if(flg) {
			
			return 0;
		}
	}
	
	return 0;
}

