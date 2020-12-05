#include<bits/stdc++.h>
using namespace std;
int n,k;
int w[11];
pair<int,int> steps[500002];
const int MOD=1e9+7;
int nw[11];
void solve1(){
	int ans=0;
	for(int i=1;i<=w[1];i++){
		int nwx=i,st=1;
		while(nwx>0&&nwx<=w[1]){
			nwx+=steps[st].second;
			st++;
			ans++;
			if(st>n) st-=n;
			if(ans>MOD) ans-=MOD;
			if(nwx==i){
				printf("-1\n");
				return;
			}
		}
	}
	printf("%d\n",ans);
}
void solve2(){
	int ans=0;
	for(int i=1;i<=w[1];i++){
		for(int j=1;j<=w[2];j++){
			int st=1;
			nw[1]=i; nw[2]=j;
			while(nw[1]>0&&nw[2]>0&&nw[1]<=w[1]&&nw[2]<=w[2]){
				nw[steps[st].first]+=steps[st].second;
				st++;
				ans++;
				if(st>n) st-=n;
				if(ans>MOD) ans-=MOD;
				if(nw[1]==i&&nw[2]==j){
					printf("-1\n");
					return;
				}
			}
		}
	}
	printf("%d\n",ans);
}
void solve3(){
	int ans=0;
	for(int i=1;i<=w[1];i++){
		for(int j=1;j<=w[2];j++){
			for(int l=1;l<=w[3];l++){
				int st=1;
				nw[1]=i; nw[2]=j; nw[3]=l;
				while(true){
					bool flag=true;
					for(int t=1;t<=k;t++){
						if(nw[t]<0||nw[t]>w[t]){
							flag=false;
							break;
						}
					}
					if(!flag) break;
					nw[steps[st].first]+=steps[st].second;
					st++;
					ans++;
					if(st>n) st-=n;
					if(ans>MOD) ans-=MOD;
					if(nw[1]==i&&nw[2]==j&&nw[3]==l){
						printf("-1\n");
						return;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
void solve4(){
	int ans=0;
	for(int i=1;i<=w[1];i++){
		for(int j=1;j<=w[2];j++){
			for(int l=1;l<=w[3];l++){
				for(int m=1;m<=w[4];m++){
					int st=1;
					int tmp[5]={0,i,j,l,m};
					for(int t=1;t<=4;t++) nw[t]=tmp[t];
					while(true){
						bool flag=true;
						for(int t=1;t<=k;t++){
							if(nw[t]<0||nw[t]>w[t]){
								flag=false;
								break;
							}
						}
						if(!flag) break;
						nw[steps[st].first]+=steps[st].second;
						st++;
						ans++;
						if(st>n) st-=n;
						if(ans>MOD) ans-=MOD;
						flag=true;
						for(int t=1;t<=4;t++){
							if(nw[t]!=tmp[t]){
								flag=false;
								break;
							}
						}
						if(flag){
							printf("-1\n");
							return;
						}					
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
void solve5(){
	int ans=0;
	for(int i=1;i<=w[1];i++){
		for(int j=1;j<=w[2];j++){
			for(int l=1;l<=w[3];l++){
				for(int m=1;m<=w[4];m++){
					for(int x=1;x<=w[5];x++){
						int st=1;
						int tmp[6]={0,i,j,l,m,x};
						for(int t=1;t<=5;t++) nw[t]=tmp[t];
						while(true){
							bool flag=true;
							for(int t=1;t<=k;t++){
								if(nw[t]<0||nw[t]>w[t]){
									flag=false;
									break;
								}
							}
							if(!flag) break;
							nw[steps[st].first]+=steps[st].second;
							st++;
							ans++;
							if(st>n) st-=n;
							if(ans>MOD) ans-=MOD;
							flag=true;
							for(int t=1;t<=5;t++){
								if(nw[t]!=tmp[t]){
									flag=false;
									break;
								}
							}
							if(flag){
								printf("-1\n");
								return;
							}					
						}						
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
void solver(){
	printf("-1\n");
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		steps[i]=make_pair(x,y);
	}
	if(k==1) solve1();
	else if(k==2) solve2();
	else if(k==3) solve3();
	else if(k==4) solve4();
	else if(k==5) solve5();
	else solver();
}

