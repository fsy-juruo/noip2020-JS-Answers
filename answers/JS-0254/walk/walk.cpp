#include<bits/stdc++.h>
using namespace std;
int n,k,res,ans;
int w[10010];
int a[100],c[10010],d[10010],b[100];
int ma[10010];
void work(){
	int res=0;int p=1;
	while(1){
		b[c[p]]+=d[p];res++;
		if(b[c[p]]<1||b[c[p]]>w[c[p]]){
			break;
		}
		p++;if(p>n)p=1;
	}
	ans+=res;
}
void dfs(int dep){
	if(dep>k){
		for(int i=1;i<=k;i++)b[i]=a[i];
		work();
	} 
	for(int i=1;i<=w[dep];i++){
		a[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		ma[c[i]]+=d[i];
	}
	bool flg=1;
	for(int i=1;i<=k;i++){
		if(ma[c[i]]!=0)flg=0;
	}
	if(flg){
		cout<<-1<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

