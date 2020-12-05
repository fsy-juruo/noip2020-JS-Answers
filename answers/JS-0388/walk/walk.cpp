#include <bits/stdc++.h>
using namespace std;
long long a[15],b[500005],c[500005],d[15],e[15];
long long ans=0,n,m;
void gp(){
	for(long long i=1;i<=m;i++)e[i]=d[i];
	while(true){
		for(long long i=1;i<=n;i++){
			ans++;
			ans%=1000000007;
			e[b[i]]+=c[i];
			for(long long ll=1;ll<=m;ll++){
				if(e[ll]>a[ll]||e[ll]<=0)return;
			}
		}
	}
} 
void fp(long long dep){
	if(dep>m)gp();
	for(long long i=1;i<=a[dep];i++)d[dep]=i,fp(dep+1),d[dep]=0;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m;i++)cin>>a[i];
	for(long long i=1;i<=n;i++)cin>>b[i]>>c[i],e[b[i]]=1,d[b[i]]+=c[i];
	for(long long i=1;i<=m;i++){
		if(d[i]==0&&e[i]==1){
			cout<<-1;
			return 0;
		}
	}
	memset(d,0,sizeof(d));
	fp(1);
	cout<<ans;
	return 0;
}

