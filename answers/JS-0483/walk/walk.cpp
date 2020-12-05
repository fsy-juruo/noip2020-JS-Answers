#include<bits/stdc++.h>
#define MAXN 500005
#define M 1000000007
using namespace std;
struct node{
	int c,d;
}a[MAXN];
int n,k,w[20],dis[20],st[20],s[20],t=1000000000,tmp;
long long ans=0,sumstep,step;
bool flag=0,tag=0;
void solve(){
	for(int i=1;i<=k;++i)st[i]=s[i];
	if(k==1){ 
	t=1000000000;
	for(int i=1;i<=k;++i){
		//cout<<st[i]<<' ';
		if(dis[i]==0)continue;
		if(dis[i]>0){
			tmp=(w[i]-st[i]+1)/dis[i]+((w[i]-st[i]+1)%dis[i]!=0);
			if(tmp<t)t=tmp;
		}
		else {tmp=st[i]/(-dis[i])+(st[i]%(-dis[i])!=0);
			if(tmp<t)t=tmp;
		}
	}
	//if(st[1]==1&&st[2]==1&&st[3]==1&&st[4]==1)cout<<t<<endl;
	//cout<<endl;
	t--;
	for(int i=1;i<=k;++i){
		st[i]+=t*dis[i];
		if(st[i]>w[i]||st[i]<1){ans=(ans+(sumstep%M*t%M)%M)%M;return;}
		}
		step=0;
		for(int i=1;i<=n;++i){
			st[a[i].c]+=a[i].d;
			step++;
			if(st[a[i].c]>w[a[i].c]||st[a[i].c]<1){break;}
		}
	ans=((ans+(t*sumstep%M)%M)%M+step%M)%M;
	return;
	}
	step=0;
	tag=0;
	while(1){
	for(int i=1;i<=n;++i){
		st[a[i].c]+=a[i].d;
		step++;
		if(st[a[i].c]>w[a[i].c]||st[a[i].c]<1){tag=1;break;}
		}
		if(tag==1)break;
	}
	ans=(ans+step%M)%M;
	return;
}
void dfs(int dep){
	//cout<<dep<<endl;
	if(dep==k+1){
		//for(int i=1;i<=k;++i)cout<<s[i]<<' ';
		//cout<<endl;
		solve();
		return;
	}
	for(int i=1;i<=w[dep];++i){
		s[dep]=i;
		//cout<<i<<endl;
		dfs(dep+1);
		
	}
	return;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].c,&a[i].d);
		dis[a[i].c]+=a[i].d;
		sumstep+=abs(a[i].d);
	}
	for(int i=1;i<=k;++i){if(dis[i]!=0)flag=1;}//cout<<dis[i]<<endl;
	if(!flag){printf("-1\n");return 0;}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
/*5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

*/
