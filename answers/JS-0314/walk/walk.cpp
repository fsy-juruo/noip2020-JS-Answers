#include<bits/stdc++.h>
using namespace std;
int const mod=1000000007;
int bk;
int js3[12][12][12],js4[12][12][12][12];
int n,k,w[15],c[500100],d[500100],js1[100010],ans,js5[12][12][12][12][12],js2[12][12];
int f=0;

void dfs1(int x,int k,int sp,int lu){
//	printf("%d %d %d %d\n",x,k,sp,lu);
	if(f) return;
	if(lu&&js1[x]==k){
		f=2;
		return;
	}
		if(x>w[1]||x<1) {
		f=1;
		ans+=sp;
		if(ans>mod) ans%=mod;
		return;
	}
if(js1[x]==-1)	js1[x]=k;
	if(k==n){
		dfs1(x,0,sp,lu+1);
	}
	else{
	dfs1(x+d[k+1],k+1,sp+1,lu);
}
}
void dfs2(int x,int y,int k,int sp,int lu){
	//printf("%d %d %d %d %d\n",x,y,k,sp,lu);
	if(f) return;
	if(lu&&js2[x][y]==k){
		f=2;
		return;
	}
	if(x>w[1]||y>w[2]||x<1||y<1){
		f=1;
		ans+=sp;
		if(ans>mod) ans%=mod;
		return;
	}
	if(js2[x][y]==-1) js2[x][y]=k;
	if(k==n){
		dfs2(x,y,0,sp,lu+1);
	}
	else{
		if(c[k+1]==1){
			dfs2(x+d[k+1],y,k+1,sp+1,lu);
		}
		else{
			dfs2(x,y+d[k+1],k+1,sp+1,lu);
		}
	}
	
}
void dfs3(int x,int y,int z,int k,int sp,int lu){
		if(f) return;
	if(lu&&js3[x][y][z]==k){
		f=2;
		return;
	}
	if(x>w[1]||y>w[2]||x<1||y<1||z<1||z>w[3]){
		f=1;
		ans+=sp;
		if(ans>mod) ans%=mod;
		return;
	}
	if(js3[x][y][z]==-1) js3[x][y][z]=k;
	if(k==n){
		dfs3(x,y,z,0,sp,lu+1);
	}
	else{
		if(c[k+1]==1){
			dfs3(x+d[k+1],y,z,k+1,sp+1,lu);
		}
		else{
			if(c[k+1]==2)
			dfs3(x,y+d[k+1],z,k+1,sp+1,lu);
			else
			dfs3(x,y,z+d[k+1],k+1,sp+1,lu);
		}
	}
}
void dfs4(int x,int y,int z,int b,int k,int sp,int lu){
		if(f) return;
	if(lu&&js4[x][y][z][b]==k){
		f=2;
		return;
	}
	if(x>w[1]||y>w[2]||x<1||y<1||z<1||z>w[3]||b<1||b>w[4]){
		f=1;
		ans+=sp;
		if(ans>mod) ans%=mod;
		return;
	}
	if(js4[x][y][z][b]==-1) js4[x][y][z][b]=k;
	if(k==n){
		dfs4(x,y,z,b,0,sp,lu+1);
	}
	else{
		if(c[k+1]==1){
			dfs4(x+d[k+1],y,z,b,k+1,sp+1,lu);
		}
		else{
			if(c[k+1]==2)
			dfs4(x,y+d[k+1],z,b,k+1,sp+1,lu);
			else
			if(c[k+1]==3)
			dfs4(x,y,z+d[k+1],b,k+1,sp+1,lu);
			else{
				dfs4(x,y,z,b+d[k+1],k+1,sp+1,lu);
			}
		}
	}
}
int main(){

freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
scanf("%d%d",&n,&bk);
for(int i=1;i<=bk;i++) scanf("%d",&w[i]);
for(int i=1;i<=n;i++){
	scanf("%d%d",&c[i],&d[i]);
}
if(n>100000){
	printf("-1\n");
	return 0;
}
if(bk==1){

	for(int i=1;i<=w[1];i++){
		//	printf("%d\n",1);
			for(int j=1;j<=w[1];j++) js1[j]=-1;
			f=0;
			dfs1(i,0,0,0);
			if(f==2){
				printf("%d\n",-1);
				return 0;
			}
	}
	if(f==1)
	printf("%d\n",ans);
}
else{
	if(bk==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int h=1;h<=w[1];h++){
					for(int l=1;l<=w[2];l++){
						js2[h][l]=-1;
					}
				}
				f=0;
				dfs2(i,j,0,0,0);
				if(f==2){
					printf("%d\n",-1);
					return 0;
				}
			}
		}
		if(f==1){
			printf("%d\n",ans);
		}
	}
	else{
		if(bk==3){
			for(int i=1;i<=w[1];i++){
				for(int j=1;j<=w[2];j++){
					for(int k=1;k<=w[3];k++){
						for(int h=1;h<=w[1];h++){
							for(int l=1;l<=w[2];l++){
								for(int m=1;m<=w[3];m++){
									js3[h][l][m]=-1;
								}
							}
						}
						f=0;
						dfs3(i,j,k,0,0,0);
						if(f==2){
							printf("%d\n",-1);
							return 0;
						}
					}
				}
			}
			if(f){
				printf("%d\n",ans);
			}
		}
		else{
			if(bk==4){
				for(int i=1;i<=w[1];i++){
					for(int j=1;j<=w[2];j++){
						for(int k=1;k<=w[3];k++){
							for(int l=1;l<=w[4];l++){
								for(int h=1;h<=w[1];h++){
									for(int m=1;m<=w[2];m++){
										for(int kk=1;kk<=w[3];kk++){
											for(int mm=1;mm<=w[4];mm++){
												js4[h][m][kk][mm]=-1;
											}
										}
									}
								}
								f=0;
								dfs4(i,j,k,l,0,0,0);
								if(f==2){
									printf("%d\n",-1);
									return 0;
								}
							}
						}
					}
				}
				if(f==1){
					printf("%d\n",ans);
				}
			}
			else{
				if(bk==5){
					printf("-1\n");
					return 0;
				}
				else {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
}

return 0;
}

