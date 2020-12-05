//gzz
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define dep(i,j,k) for (int i=j;i>=k;--i)
#define FILE "ball"
using namespace std;
int n,m,y,h,z,col[60][500],num[60],ans,p[820000][5];
bool chun(int x){
	if (num[x]==0) return true;
	int b1=0,b2=0;
	rep(i,1,num[x]) b1+=(col[x][i]==1),b2+=(col[x][i]==2);
	return ((b1==0 && b2==num[x]) || (b1==num[x] && b2==0));
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
		rep(j,1,m) scanf("%d",&col[i][j]),num[i]++;
	if (n==2){
		while (true){
			if (chun(1) && chun(2) && chun(3)) break;
			while (!chun(1)){
				p[++ans][1]=1;
				if (num[2]<=m-1 && (col[2][num[2]]==0 || col[2][num[2]]==col[1][num[1]])){
					p[ans][2]=2;
					num[2]++;
					col[2][num[2]]=col[1][num[1]];
					num[1]--;
				}
				else{
					p[ans][2]=3;
					num[3]++;
					col[3][num[3]]=col[1][num[1]];
					num[1]--;
				}
			}
			while (!chun(2)){
				p[++ans][1]=2;
				if (num[1]<=m-1 && (col[1][num[1]]==0 || col[2][num[2]]==col[1][num[1]])){
					p[ans][2]=1;
					num[1]++;
					col[1][num[1]]=col[2][num[2]];
					num[2]--;
				}
				else{
					p[ans][2]=3;
					num[3]++;
					col[3][num[3]]=col[2][num[2]];
					num[2]--;
				}
			}
		}
		if (chun(1) && num[1]!=m){
			if (col[2][num[2]]==col[1][num[1]])
				rep(i,1,num[1]){
					ans++;
					p[ans][1]=1;p[ans][2]=2;num[2]++;
				}
			else{
				rep(i,1,num[1]){
					ans++;
					p[ans][1]=1;p[ans][2]=3;num[3]++;
				}
			}
		}
		if (chun(2) && num[2]!=m){
			if (col[2][num[2]]==col[1][num[1]])
				rep(i,1,num[2]){
					ans++;
					p[ans][1]=2;p[ans][2]=1;num[1]++;
				}
			else{
				rep(i,1,num[2]){
					ans++;
					p[ans][1]=2;p[ans][2]=3;num[3]++;
				}
			}
		}	
		if (chun(3) && num[3]!=m){
			if (col[3][num[3]]==col[1][num[1]])
				rep(i,1,num[3]){
					ans++;
					p[ans][1]=3;p[ans][2]=1;num[1]++;
				}
			else{
				rep(i,1,num[3]){
					ans++;
					p[ans][1]=3;p[ans][2]=2;num[2]++;
				}
			}
		}	
		printf("%d\n",ans);
		rep(i,1,ans) printf("%d %d\n",p[i][1],p[i][2]);
	}
	return 0;
}
