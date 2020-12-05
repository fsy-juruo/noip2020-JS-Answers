#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=55,M=405,K=820005;
int n,m,l,cnt,longest=K;
int a[N][M],b[N][N],c[N],len[N],ansa[K],ansb[K];
queue<int> q;
void fang(int t,int st,int k){
	for(int i=c[t];i>=st;i--){
		ansa[++cnt]=t;ansb[cnt]=k;
		a[k][++c[k]]=a[t][i];
		b[k][a[t][i]]=c[k];
	}
}
int minx(int k){
	int maxv=0,t,x=a[k][1];
	for(int i=1;i<=n+1;i++){
		if(i==k) continue;
		if(b[i][x]>maxv){
			maxv=b[i][x];
			t=i;
		}
	}
	return t;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	int st,maxv=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==a[i][j-1]) len[i]++;
			b[i][a[i][j]]=j;
		}
		c[i]=m;
		if(len[i]>maxv){
			maxv=len[i];
			st=i;
		}
	}
	q.push(st);
	for(int i=m;i>=len[st]+1;i--){
		ansa[++cnt]=st;ansb[cnt]=n+1;
		a[n+1][++c[n+1]]=a[st][i];
		b[n+1][a[st][i]]=c[n+1];
	}
	while(q.size()){
		int x=q.front();q.pop();
		int c=a[x][1];
		while(len[x]<m){
			int t=minx(x),st;
			for(int i=b[t][c];i;i--){
				if(a[t][i]!=c)
					break;
				st=i;
			}
			fang(t,st,n+1);
			if(cnt>longest) return 0;
			
		}
	}
	return 0;
}
