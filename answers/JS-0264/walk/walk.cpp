#include<bits/stdc++.h>
using namespace std;
int w[20],small[20],large[20],a[20],n,k,c[100005],d[100005],t,x[20];
long long day=1,ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i],day*=w[i];
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		a[c[i]]+=d[i];
		large[c[i]]=max(a[c[i]],large[c[i]]);
		small[c[i]]=max(a[c[i]],small[c[i]]);
	}
	for(int i=1;i<=k;i++){
		if(a[i]!=0)break;
		t=1;
	}
	if(t==1){
		for(int i=1;i<=k;i++){
			if(large[i]-small[i]>=w[i])ans=-1;
		}
	}
	if(ans!=-1){
		for(int i=1;i<=day;i++){
			x[1]=i;
			for(int i=1;i<=k-1;i++){
				x[i+1]=x[i]/w[i];
				x[i]=x[i]%w[i];
				if(x[i]==0)x[i]=w[i];
			}
			while(t==0){
				for(int i=1;i<=n;i++){
					x[c[i]]+=d[i];
					if(x[c[i]]<=0 || x[c[i]]>w[c[i]]){
						t=1;
						ans++;
						ans=ans%1000000007;
						break;
					}
					ans++;
					ans=ans%1000000007;
					
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
