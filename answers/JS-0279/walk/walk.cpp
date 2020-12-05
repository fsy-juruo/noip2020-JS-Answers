#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[12],w[12];
int c[110],d[110];
long long ans=0;
void solve(){
	int b[12];
	for(int i=1;i<=k;i++)
		b[i]=a[i];
	for(int i=0;;i++){
		if(i==n){
			bool flag=1;
			for(int i=1;i<=k;i++)
				if(b[i]!=a[i])
					flag=0;
			if(flag){
				cout<<-1<<endl;
				exit(0);
			}
		}
		int j=i%n;
		b[c[j]]+=d[j];
		ans++;
		if(b[c[j]]<=0||b[c[j]]>w[c[j]])
			break;
	}
}
void dfs(int x){
	if(x>k){
		solve();
		return;
	}
	for(int i=1;i<=w[x];i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n>100){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
		cin>>c[i]>>d[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

