//GZZ±£”” 
#include<cstdio>
using namespace std;
//int abs(int a){
//	if(a<0)return -a;
//	return a;
//}
const int MOD=1000000007;
int w[15],k,n,c[100005],d[100005],ans,exit,now[15],now2[15];
void play(){
	for(int i=1;i<=k;i++)
	now2[i]=now[i];
	while(1){
		for(int i=1;i<=n;i++){
			now2[c[i]]+=d[i];ans++;
			if(ans>=MOD)ans-=MOD;
			if(now2[c[i]]<1||now2[c[i]]>w[c[i]])return;
		}
		for(int i=1;i<=k;i++)if(now2[i]!=now[i])exit=-1;
		if(exit==-1)exit=0;
		else{exit=1;return;}
	}
}
void dfs(int wd){
	if(wd==k+1){
		play();
		return;
	}
	for(int i=1;i<=w[wd];i++){
		now[wd]=i;
		dfs(wd+1);
		if(exit)return;
	}
}
//void special(){
//	int len;
//	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
//	for(int i=1;i<=n;i++){
//		scanf("%d%d",&c[len+1],&d[len+1]);
//		if(d[len]/d[len+1]<0)len++;
//		else{
//			if(d[len]<0)d[len]--;
//			else d[len]++;
//		}
//		for(int now=1;now<=w[1];now++){
//			int now22=now;
//			while(1){
//				for(int i=1;i<=n;i++){
//					if(now22+d[i]<1||now22+d[i]>w[1]){
//						ans+=abs(now22-d[i]);
//						break;
//					}
//					now22+=d[i];ans+=d[i];
//				}
//				for(int i=1;i<=k;i++)if(now22!=now)exit=-1;
//				if(exit==-1)exit=0;
//				else{exit=1;break;}
//			}
//		}
//	}
//	return;
//}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
//	if(k==1){
//		special();
//		if(exit){printf("-1");return 0;}
//		printf("%d",ans);
//		return 0;
//	}
	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&d[i]);
	dfs(1);
	if(exit){printf("-1");return 0;}
	printf("%d",ans%MOD);
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
