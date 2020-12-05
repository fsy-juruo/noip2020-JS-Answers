#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=1e9+7;
int n,k,w[15],a[N][2],c[15],pos[10],ans=0,pp[10];
ll d1[N*2],d2[N*2],a1[N],q1[N],a2[N];
/*int check(){
	int i;
	for(i=1;i<=k;i++)
	if(pp[i]<=0||pp[i]>w[i]) return 1;
	return 0;
}*/
void dfs(int d){
	if(d>k){
		int i=1;
		for(i=1;i<=k;i++) pp[i]=pos[i];
		i=0;
		while(1) {
			int qq=a[i+1][0];
			pp[qq]+=a[i+1][1];
			ans++;
			if(pp[qq]<=0||pp[qq]>w[qq]) break;
			i++;
			i=i%n;
		}
		//printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=w[d];i++){
		pos[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=k;i++) scanf("%d",&w[i]);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		c[a[i][0]]+=a[i][1];
	}
	int flag=0;
	for(i=1;i<=k;i++)
	if(c[i]!=0) flag=1;
	if(!flag){
		printf("-1");
		return 0;
	}
	if(n<=100){
		int ii,jj;
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
	if(k==1){
		ans=0;
		int p=w[1],lm=w[1],rm=w[1];
		memset(d1,0x3f,sizeof(d1));
		//cout<<d1[0]<<endl;
		for(i=1;i<=n;i++){
			p+=a[i][1];
			if(d1[p]>mod) d1[p]=i;
			lm=min(p,lm);
			rm=max(p,rm);
		}
		p-=w[1];lm-=w[1];rm-=w[1];
		lm*=-1;
		for(i=1;i<=w[1];i++){
			ll ff;
			int m1=-(i-lm-1)/p+1,m2=(w[1]-rm-i)/p+1;
			if(p>0){
				if(w[1]<rm+i) m2=0;
				ff=d1[w[1]+w[1]-m2*p-i+1]+m2*n;//
				ans=(ans+min(ff,d1[w[1]-i]))%mod;
			}
			else{
				if(i<=lm) m1=0;
				ff=d1[w[1]-i-m1*p]+m1*n;
				ans=(ans+min(ff,d1[w[1]+w[1]-i+1]))%mod;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==2){
		ans=0;
		int p=w[1],lm=w[1],rm=w[1];
		memset(d1,0x3f,sizeof(d1));
		//cout<<d1[0]<<endl;
		for(i=1;i<=n;i++){
			if(a[i][0]==2) continue ;
			p+=a[i][1];
			if(d1[p]>mod) d1[p]=i;
			lm=min(p,lm);
			rm=max(p,rm);
		}
		p-=w[1];lm-=w[1];rm-=w[1];
		lm*=-1;
		for(i=1;i<=w[1];i++){
			ll ff;
			int m1=-(i-lm-1)/p+1,m2=(w[1]-rm-i)/p+1;
			if(p>0){
				if(w[1]<rm+i) m2=0;
				ff=d1[w[1]+w[1]-m2*p-i+1]+m2*n;//
				a1[i]=min(ff,d1[w[1]-i]);
			}
			else{
				if(i<=lm) m1=0;
				ff=d1[w[1]-i-m1*p]+m1*n;
				a1[i]=min(ff,d1[w[1]+w[1]-i+1]);
			}
		}
		sort(a1+1,a1+w[1]+1);
		for(i=1;i<=w[1];i++)
		q1[i]=q1[i-1]+a1[i];
		
		p=w[2],lm=w[2],rm=w[2];
		memset(d2,0x3f,sizeof(d2));
		//cout<<d1[0]<<endl;
		for(i=1;i<=n;i++){
			if(a[i][0]==1) continue ;
			p+=a[i][1];
			if(d2[p]>mod) d2[p]=i;
			lm=min(p,lm);
			rm=max(p,rm);
		}
		p-=w[2];lm-=w[2];rm-=w[2];
		lm*=-1;
		for(i=1;i<=w[2];i++){
			ll ff;
			int m1=-(i-lm-1)/p+1,m2=(w[2]-rm-i)/p+1;
			if(p>0){
				if(w[2]<rm+i) m2=0;
				ff=d2[w[2]+w[2]-m2*p-i+1]+m2*n;//
				a2[i]=min(ff,d2[w[2]-i]);
			}
			else{
				if(i<=lm) m1=0;
				ff=d2[w[2]-i-m1*p]+m1*n;
				a2[i]=min(ff,d2[w[2]+w[2]-i+1]);
			}
			int laa=lower_bound(a1+1,a1+w[1]+1,a2[i])-a1-1;
			
			ans=(ans+q1[laa]+a2[i]*(w[1]-laa))%mod;
		//printf("%d\n",ans);
		}
		
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}/*
6 2 3 3
1 -1
2 1
2 -1
1 1
1 -1
2 1
*/
