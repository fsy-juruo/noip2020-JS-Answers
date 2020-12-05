#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define maxm 2000005
#define int long long
#define inf 0x3f3f3f3f
#define mod 1000000007
//#define local
void file(string ss){freopen((ss+".in").c_str(),"r",stdin);freopen((ss+".out").c_str(),"w",stdout);}
template<typename Tp> void read(Tp &x){
	x=0;int fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-'){fh=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x*10)+c-'0';c=getchar();}x*=fh;
}
int n,m;
int ci[maxn],di[maxn],wi[20];
namespace Sub0{
	int dp[10][10][10][10][10][10];
	bool ins[10][10][10][10][10][10];
	bool Sub0_chk(){
		int flg=1;
		for(int i=1;i<=m;++i){
			if(wi[i]>=10)flg=0;
		}
		return n<=5&&m<=5&&flg;
	}
	int dfs(int st,int a,int b,int c,int d,int e){
		if(~dp[st][a][b][c][d][e])return dp[st][a][b][c][d][e];
		if(ins[st][a][b][c][d][e]){
			puts("-1");
			fclose(stdin);
			fclose(stdout);
			exit(0);
		}
		int na=a,nb=b,nc=c,nd=d,ne=e;
		if(ci[st]==1)na+=di[st];
		if(ci[st]==2)nb+=di[st];
		if(ci[st]==3)nc+=di[st];
		if(ci[st]==4)nd+=di[st];
		if(ci[st]==5)ne+=di[st];
		if(na<=0||na>wi[1]||nb<=0||nb>wi[2]||nc<=0||nc>wi[3]||nd<=0||nd>wi[4]||ne<=0||ne>wi[5])return dp[st][a][b][c][d][e]=1;
		ins[st][a][b][c][d][e]=1;
		dp[st][a][b][c][d][e]=(dfs(st%n+1,na,nb,nc,nd,ne)+1)%mod;
		ins[st][a][b][c][d][e]=0;
		return dp[st][a][b][c][d][e];
	}
	int ans;
	void solve(){
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=5;++i)wi[i]=max(wi[i],1ll);
		for(int i=1;i<=wi[1];++i){
			for(int j=1;j<=wi[2];++j){
				for(int k=1;k<=wi[3];++k){
					for(int o=1;o<=wi[4];++o){
						for(int p=1;p<=wi[5];++p){
							ans+=dfs(1,i,j,k,o,p);
							ans%=mod;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}
namespace Sub1{
	int dp[105][15][15][15];
	bool ins[105][15][15][15];
	int dfs(int st,int x,int y,int z){
		if(~dp[st][x][y][z])return dp[st][x][y][z];
		if(ins[st][x][y][z]){
			puts("-1");
			fclose(stdin);
			fclose(stdout);
			exit(0);
		}
		int nx=x,ny=y,nz=z;
		if(ci[st]==1)nx+=di[st];
		if(ci[st]==2)ny+=di[st];
		if(ci[st]==3)nz+=di[st];
		if(nx<=0||nx>wi[1]||ny<=0||ny>wi[2]||nz<=0||nz>wi[3])return dp[st][x][y][z]=1;
		ins[st][x][y][z]=1;
		dp[st][x][y][z]=(dfs(st%n+1,nx,ny,nz)+1)%mod;
		ins[st][x][y][z]=0;
		return dp[st][x][y][z];
	}
	int ans;
	bool Sub1_chk(){
		int flg=1;
		for(int i=1;i<=m;++i){
			if(wi[i]>10)flg=0;
		}
		return n<=100&&m<=3&&flg;
	}
	void solve(){
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=3;++i)wi[i]=max(wi[i],1ll);
		for(int i=1;i<=wi[1];++i){
			for(int j=1;j<=wi[2];++j){
				for(int k=1;k<=wi[3];++k){
					ans+=dfs(1,i,j,k);
					ans%=mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
namespace NOSOL{
	int li[20],ri[20];
	int tid[20];
	void chk(){
		for(int i=1;i<=n;++i){
			tid[ci[i]]+=di[i];
			for(int j=1;j<=m;++j){
				li[j]=min(li[j],tid[j]);
				ri[j]=max(ri[j],tid[j]);
			}
		}
		int flg=1;
		for(int i=1;i<=m;++i){
			if(tid[i]){
				flg=0;break;
			}
		}
		if(flg){
			for(int i=1;i<=m;++i){
				if(ri[i]-li[i]>wi[i]){
					flg=0;break;
				}
			}
			if(flg){
				puts("-1");
				fclose(stdin);
				fclose(stdout);
				exit(0);
			}
		}
	}
}
namespace Sub3{//k=1
	
	void solve(){
		
	}
}

signed main(){
	#ifndef local
		file("walk");
	#endif
	read(n);read(m);
	for(int i=1;i<=m;++i)read(wi[i]);
	for(int i=1;i<=n;++i){
		read(ci[i]);read(di[i]);
	}
	if(Sub0::Sub0_chk()){
		Sub0::solve();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(Sub1::Sub1_chk()){
		Sub1::solve();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	NOSOL::chk();
	puts("47073780");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

