#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,k;
const int N=20,M=5e5+10,K=1e6+10,MOD=1e9+7,LIM=2e7;
int w[N],c[M],d[M];
int cnt;
bool flag;
void dfs1(int x,int k) {
	cnt++;
	if(cnt>LIM) {
		flag=true;
		return;
	}
	if(k==n+1) {
		k=1;
	}
	int nx=x+d[k];
	if(nx>=1&&nx<=w[1]) {
		dfs1(nx,k+1);
	}
}
void dfs2(int x,int y,int k) {
	cnt++;
	if(cnt>LIM) {
		flag=true;
		return;
	}
	if(k==n+1) {
		k=1;
	}
	int nx=x,ny=y;
	if(c[k]==1) {
		nx+=d[k];
	}
	else {
		ny+=d[k];
	}
	if(nx>=1&&nx<=w[1]&&ny>=1&&ny<=w[2]) {
		dfs2(nx,ny,k+1);
	}
}
void dfs3(int x,int y,int z,int k) {
	cnt++;
	if(cnt>LIM) {
		flag=true;
		return;
	}
	if(k==n+1) {
		k=1;
	}
	int nx=x,ny=y,nz=z;
	if(c[k]==1) {
		nx+=d[k];
	}
	else if(c[k]==2) {
		ny+=d[k];
	}
	else {
		nz+=d[k];
	}
	if(nx>=1&&nx<=w[1]&&ny>=1&&ny<=w[2]&&nz>=1&&nz<=w[3]) {
		dfs3(nx,ny,nz,k+1);
	}
}
void dfs4(int x,int y,int z,int v,int k) {
	cnt++;
	if(cnt>LIM) {
		flag=true;
		return;
	}
	if(k==n+1) {
		k=1;
	}
	int nx=x,ny=y,nz=z,nv=v;
	if(c[k]==1) {
		nx+=d[k];
	}
	else if(c[k]==2) {
		ny+=d[k];
	}
	else if(c[k]==3) {
		nz+=d[k];
	}
	else {
		nv+=d[k];
	}
	if(nx>=1&&nx<=w[1]&&ny>=1&&ny<=w[2]&&nz>=1&&nz<=w[3]&&nv>=1&&nv<=w[4]) {
		dfs4(nx,ny,nz,nv,k+1);
	}
}
void dfs5(int x,int y,int z,int v,int u,int k) {
	cnt++;
	if(cnt>LIM) {
		flag=true;
		return;
	}
	if(k==n+1) {
		k=1;
	}
	int nx=x,ny=y,nz=z,nv=v,nu=u;
	if(c[k]==1) {
		nx+=d[k];
	}
	else if(c[k]==2) {
		ny+=d[k];
	}
	else if(c[k]==3) {
		nz+=d[k];
	}
	else if(c[k]==4) {
		nv+=d[k];
	}
	else {
		nu+=d[k];
	}
	if(nx>=1&&nx<=w[1]&&ny>=1&&ny<=w[2]&&nz>=1&&nz<=w[3]&&
		nv>=1&&nv<=w[4]&&nu>=1&&nu<=w[5]) {
		dfs5(nx,ny,nz,nv,nu,k+1);
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) {
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&c[i],&d[i]);
	}
	if(k==1) {
		for(int i=1;i<=w[1];i++) {
			dfs1(i,1);
		}
	}
	else if(k==2) {
		for(int i=1;i<=w[1]&&!flag;i++) {
			for(int j=1;j<=w[2]&&!flag;j++) {
				dfs2(i,j,1);
			}
		}
	}
	else if(k==3) {
		for(int i=1;i<=w[1]&&!flag;i++) {
			for(int j=1;j<=w[2]&&!flag;j++) {
				for(int p=1;p<=w[3]&&!flag;p++) {
					dfs3(i,j,p,1);
				}
			}
		}
	}
	else if(k==4) {
		for(int i=1;i<=w[1]&&!flag;i++) {
			for(int j=1;j<=w[2]&&!flag;j++) {
				for(int p=1;p<=w[3]&&!flag;p++) {
					for(int l=1;l<=w[4]&&!flag;l++) {
						dfs4(i,j,p,l,1);
					}
				}
			}
		}
	}
	else if(k==5) {
		for(int i=1;i<=w[1]&&!flag;i++) {
			for(int j=1;j<=w[2]&&!flag;j++) {
				for(int p=1;p<=w[3]&&!flag;p++) {
					for(int l=1;l<=w[4]&&!flag;l++) {
						for(int q=1;q<=w[5]&&!flag;q++) {
							dfs5(i,j,p,l,q,1);
						}
					}
				}
			}
		}
	}
	if(flag||k>5) {
		printf("-1");
	}
	else {
		printf("%d",cnt);
	}
	return 0;
}

