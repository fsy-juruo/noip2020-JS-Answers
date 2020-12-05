#include<bits/stdc++.h>
using namespace std;
const int K=12;
const int N=5e5+10;
const int mod=1e9+7;
int n,k,w[K],p[K],s[K][N*2+10],sw[2][K];//p:一个循环后总移动 s:循环内部移动  sw:边界 
int ans=0;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(s,0x3f3f3f3f,sizeof(s));
	scanf("%d%d",&n,&k);
	w[k+1]=-1;
	
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
		s[i][N]=0;
	}
	memset(p,0,sizeof(p));
	int c,d;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c,&d);
		p[c]+=d;
		sw[0][c]=min(sw[0][c],p[c]);
		sw[1][c]=max(sw[1][c],p[c]);
		s[c][N+p[c]]=min(s[c][N+p[c]],i);
	}
	bool er=true;
	for(int i=1;i<=k;i++){
		er&=p[i]==0;
		er&=(w[i]>(sw[1][i]-sw[0][i]));
	}
	if(er){
		printf("-1\n");
		return 0;
	}
	
	int a[K],b[K];
	for(int i=1;i<=k;i++){
		b[i]=1;
	}
	b[k+1]=0;
	b[1]=0;
	while(true){
		
		
		int i=1;
		while(b[i]==w[i]){
			b[i]=1;
			i++;
		}
		if(i>k)break;
		b[i]++;
		for(int i=1;i<=k;i++){
			a[i]=b[i];
			printf("%d ",b[i]);
		}
		int sum=0;
		while(true){
			int mn=0x3f3f3f3f;
			for(i=1;i<=k;i++){
				if(a[i]+sw[0][i]<1){
					mn=min(mn,s[i][N-a[i]+1]);
				}
				if(a[i]+sw[1][i]>w[i]){
					mn=min(mn,s[i][N-a[i]+w[i]+1]);
				}
			}
			if(mn!=0x3f3f3f3f){
				sum=(sum+mn)%mod;
				break;
			}
			sum=(sum+n)%mod;
			for(i=1;i<=k;i++){
				a[i]+=p[i];
			}
			
			for(int i=1;i<=k;i++){
			
			printf("%d ",a[i]);
		}
		}
		printf("%d\n",sum);
		ans=(ans+sum)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
