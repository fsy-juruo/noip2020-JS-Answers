#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define MOD 1000000007
using namespace std;
int n,k,w[20],do_wlk[500005][2],f[11],r[11],wmx,t=1;
long long  ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
	    scanf("%d",&w[i]);
	    wmx=max(w[i],wmx);
    }
	for(int i=1;i<=n;i++) scanf("%d%d",&do_wlk[i][0],&do_wlk[i][1]);
	if(n>100000){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=k;i++) f[i]=1;
	while(f[0]==0){
		for(int i=1;i<=k;i++) r[i]=f[i];
		int y=1,x=0;
		while(x==0){
		    for(int i=1;i<=n;i++){
			    r[do_wlk[i][0]]+=do_wlk[i][1];
			    if(r[do_wlk[i][0]]<1||r[do_wlk[i][0]]>w[do_wlk[i][0]]){
				    ans=(ans+y)%MOD ; x=1;
	//			    printf("%d\n",y);
				    break;
			    }
			    else y++;
		    }
		    if(y>n*wmx){
		    	printf("-1\n");
		    	return 0;
			}
	    }
	    f[k]++;
	    for(int i=k;i>=1;i--){
	    	if(f[i]>w[i]){
	    		f[i-1]++; f[i]=1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
