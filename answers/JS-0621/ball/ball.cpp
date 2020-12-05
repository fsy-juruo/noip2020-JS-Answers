#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define gc getchar
using namespace std;

inline int read(){
	int x=0,y=1;char c=gc();while(c<'0'||c>'9'){if(c=='-') y=-1;c=gc();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();return (y==1)?x:-x;
}

int n,m,p[55][405],num[55],sum[55],ans[850000][2],tot;
bool vis[55];

inline void work(int x,int y){
	p[y][++num[y]]=p[x][num[x]];
	p[x][num[x]--]=0;
	ans[++tot][0]=x;ans[tot][1]=y;
}

inline int findcol(int col,int &d){
	for(int i=1;i<=n+1;i++){
		if(vis[i]) continue;
		for(int j=num[i];j>0;j--)
			if(p[i][j]==col){
				d=i;
				return j;
			}
	}
}

inline void calc(int col,int d){
	int dd;
	int ip=findcol(col,dd);
	for(int i=1;i<=n+1;i++){
		if(i==d||i==dd||vis[i]) continue;
		while(ip<num[dd]&&num[i]<m){
			work(dd,i);
		}
	}
	if(ip==num[dd]){
		work(dd,d);
		return;
	}
	int dep=num[dd]-ip+1;
	int z;
	for(int i=1;i<=n+1;i++){
		if(vis[i]||i==d||i==dd) continue;
		z=i;break;
	}
	for(int i=1;i<=dep;i++){
		work(z,d);
	}
	for(int i=1;i<=dep;i++){
		work(dd,z);
	}
	for(int i=1;i<=dep;i++){
		work(d,dd);
	}
	work(z,d);
}

inline int choose(){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n+1;i++){
		if(vis[i]) continue;
		for(int j=1;j<=num[i];j++){
			sum[p[i][j]]+=(num[i]+1-j);
		}
	}
	int ip,minn=1e9;
	for(int i=1;i<=n+1;i++){
		if(sum[i]!=0&&sum[i]<minn){
			ip=i;minn=sum[i];
		}
	}
	return ip;
}

inline void move(int col,int d){
	while(num[d]<m) calc(col,d);
	vis[d]=1;
	int ip,minn=1e9;
	for(int i=1;i<=n+1;i++){
		if(vis[i]) continue;
		if(num[i]<minn){
			ip=i;minn=num[i];
		}
	}
	for(int i=1;i<=n+1;i++){
		if(vis[i]||i==ip) continue;
		while(num[ip]>0&&num[i]<m){
			work(ip,i);
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			p[i][j]=read();
	for(int i=1;i<=n;i++) num[i]=m;
	num[n+1]=0;
	for(int k=1;k<n;k++){
		int x=choose();//cout<<x<<' ';
		for(int i=1;i<=n+1;i++){
			if(num[i]==0){
				//cout<<i<<endl;
				move(x,i);
				break;
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}

















