#include <bits/stdc++.h>
using namespace std;

int n,k,w[20],c[500010],d[500010],fjia[20],fjian[20],yidong[20],zuobiao[20],x[20];
long long ans,mod=1e9+7;

bool check(){
	for(int i=1;i<=k;++i){
		if(fjia[i]+x[i]>w[i])
			return false;
		if(fjian[i]+x[i]<1)
			return false;
	}
	return true;
}

void work(){
	for(int i=1;i<=k;++i)
		x[i]=zuobiao[i];
	while(check()){
		ans=(ans+n)%mod;
		for(int i=1;i<=k;++i)
			x[i]+=yidong[i];
	}
	for(int i=1;i<=n;++i){
		if(x[c[i]]+d[i]<1||x[c[i]]+d[i]>w[c[i]]){
			ans=(ans+1)%mod;
			break;
		}
		x[c[i]]+=d[i];
		ans=(ans+1)%mod;
	}
}

void DFS(int id){
	if(id>k){
		work();
		return;
	}
	for(int i=1;i<=w[id];++i){
		zuobiao[id]=i;
		DFS(id+1);
	}
}

bool first_check(){
	for(int i=1;i<=k;++i)
		if(yidong[i]!=0||fjia[i]-fjian[i]>w[i])
			return false;
	return true;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&c[i],&d[i]);
		yidong[c[i]]+=d[i];
		fjia[c[i]]=max(fjia[c[i]],yidong[c[i]]);
		fjian[c[i]]=min(fjian[c[i]],yidong[c[i]]);
	}
	for(int i=1;i<=k;++i){
		if(fjia[i]==-1e9)
			fjia[i]=0;
		if(fjian[i]==1e9)
			fjian[i]=0;
	}
	if(first_check())
		cout<<-1<<endl;
	else{
		DFS(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
