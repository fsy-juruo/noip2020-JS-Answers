#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res;
}

#define N 55
#define M 405
#define MAX 3400
int n,m;
int a[N][M];
int from[MAX+5],to[MAX+5];
struct node{
	int x[N][M],from[N],to[N],d;
//	bool operator <(node o){
//		x[0][0]<o.x[0][0];
//	}
};
queue<node> q;

void bfs(){
	node k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			k.x[i][j]=a[i][j];
		}
	}
	k.d=1;
	q.push(k);
	while(!q.empty()){
		k=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				a[i][j]=k.x[i][j];
			}
		}
		int d=k.d;
		if(d>MAX) return;
		int flag=1;
		for(int i=1;i<=n;i++){
			if(!a[i][0]) continue;
			int k=a[i][1];
			for(int j=1;j<=a[i][0];j++){
				if(a[i][j]!=k){
					flag=0;
					break;
				}
			}
		}
		if(flag){
			printf("%d\n",d-1);
			for(int i=1;i<d;i++){
				printf("%d %d\n",from[i],to[i]);
			}
		exit(0);
		}
		for(int i=1;i<=n;i++){
			if(!a[i][0]) continue;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(a[j][0]>=m) continue;
				from[d]=i;
				to[d]=j;
				a[j][++a[j][0]]=a[i][a[i][0]];
				a[i][a[i][0]--]=0;
				for(int x=1;x<=n;x++){
					for(int y=0;y<=m;y++){
						k.x[x][y]=a[x][y];
					}
				}
				q.push(k);
				from[d]=0;
				to[d]=0;
				a[i][++a[i][0]]=a[j][a[j][0]];
				a[j][a[j][0]--]=0;
			}
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	n++;
	for(int i=1;i<n;i++){
		a[i][0]=m;
		for(int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	dfs(1);
	return 0;
}
