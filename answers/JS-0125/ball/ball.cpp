#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f,MAXN=55,MAXM=405,MAXO=1e6+10;
int N,M,st[MAXN][MAXM],tp[MAXN];
int opc,opl[MAXO],opr[MAXO];
inline void MOVE(int x,int y) {
//	printf("%d -> %d\n",x,y);
	opc++;
	opl[opc]=x;
	opr[opc]=y;
	st[y][++tp[y]]=st[x][tp[x]];
	tp[x]--;
}
inline void get_room(int i,int x,int cnt) {
//	puts("Get room");
	// Get room ------O(M)
	int res=M-tp[N+1];
	if(res<cnt) {
		for(int k=i+1; k<=N; k++) {
			if(k==x) {
				continue;
			}
			while(res<cnt&&tp[k]<M) {
				MOVE(N+1,k);
				res++;
			}
		}
	} else if(res>cnt) {
		for(int k=i+1; k<=N; k++) {
			if(k==x) {
				continue;
			}
			while(res>cnt&&tp[k]>0) {
				MOVE(k,N+1);
				res--;
			}
		}
	}
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d",st[i]+j);
//			printf("%d ",st[i][j]);
		}
//		puts("");
		tp[i]=M;
	}
	tp[N+1]=0;
	for(int x=1; x<N; x++) {
		// caution: iterater name!
		//the chosen colour is c
		int c=st[x][1],bt=0;
		for(int i=x; i<=N; i++) {
			int bl=M,wt=M;
			for(int j=1; j<=M; j++) {
				if(st[i][j]==c) {
					wt--;
				} else {
					bl--;
				}
			}
			if(i==N) {
				for(int j=bt+1;j<=M;j++){
					MOVE(x,N+1);
				}
				for(int j=1;j<=4;j++){
					while(tp[N]&&tp[N+1]<M){
						if(st[N][tp[N]]==c){
							MOVE(N,x);
						}else{
							MOVE(N,N+1);
						}
					}
					while(tp[N+1]&&tp[N]<M){
						if(st[N+1][tp[N+1]]==c){
							MOVE(N+1,x);
						}else{
							MOVE(N+1,N);
						}
					}
				}
			} else {
				while(tp[N]>bl) {
					MOVE(N,N+1);
				}
				while(tp[N+1]>wt) {
					MOVE(N+1,N);
				}
				int cnt=0;
				while(tp[i]) {
					if(st[i][tp[i]]==c) {
						MOVE(i,N+1);
						cnt++;
					} else {
						MOVE(i,N);
					}
				}
				if(i==x) {
					for(int k=1; k<=cnt; k++) {
						MOVE(N+1,x);
					}
					for(int k=cnt+1; k<=M; k++) {
						MOVE(N,x);
					}
					bt+=cnt;
				} else {
					for(int k=bt+1; k<=M; k++) {
						MOVE(x,i);
					}
					for(int k=1; k<=cnt; k++) {
						MOVE(N+1,x);
					}
					for(int k=1; k<=M-cnt; k++) {
						MOVE(N,i);
					}
				}
			}
		}
	}
	while(tp[N+1]){
		MOVE(N+1,N);
	}
	printf("%d\n",opc);
	for(int i=1; i<=opc; i++) {
		printf("%d %d\n",opl[i],opr[i]);
	}
	return 0;
}
