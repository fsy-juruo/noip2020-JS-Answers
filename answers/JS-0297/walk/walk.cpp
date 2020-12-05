#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans=0;
int a[10];
int p[10];
int c[11000],d[11000];
void dfs(int dep){
	if(dep==k+1){
		long long sum=0;
		int pp[10];
		for(int i=1;i<=9;i++)pp[i]=p[i];
		for(int i=1;i<=n;i++){
			pp[c[i]]+=d[i];
			sum++;
			sum=sum%1000000007;
			if(pp[c[i]]>a[c[i]]||pp[c[i]]<1){
				ans+=sum;
				ans=ans%1000000007;
				return ;
			}
		}
		bool flag=1;
		for(int i=1;i<=k;i++)if(a[i]!=pp[i])flag=0;
		if(flag==1){
			cout<<-1<<endl;
			exit(0);
		}
		while(1){
			for(int i=1;i<=n;i++){
				pp[c[i]]+=d[i];
				sum++;
				sum=sum%1000000007;
				if(pp[c[i]]>a[c[i]]||pp[c[i]]<1){
					ans+=sum;
					ans=ans%1000000007;
					return ;
				}
			}
		}
	}
	for(int i=1;i<=a[dep];i++){
		p[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	if(n<=100){
		dfs(1);
		cout<<ans<<endl;
	}else cout<<-1<<endl;
	
	return 0;
}


