#include<bits/stdc++.h>
using namespace std;
const long long mod=pow(10,9)+7;
int n,k;
long long w[20],wmax[20],wmin[20],c[500010],d[500010],pre[20];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i];
	long long ans=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&c[i],&d[i]);
	}
	long long mul=1;
	for(int i=1;i<=k;i++){
		wmax[i]=w[i];
		wmin[i]=1;
		mul*=w[i];
		mul%=mod;
	}
	ans+=mul;
	ans%=mod;
	int cnt=0;
	while(1){
		if(cnt>1e8){
			cout<<-1<<endl;
			return 0;
		}
		cnt++;
		int day;
		day=cnt%n;
		if(day==0)day=n;
		pre[c[day]]+=d[day];
		wmax[c[day]]=min(wmax[c[day]],w[c[day]]-pre[c[day]]);
		wmin[c[day]]=max(wmin[c[day]],1-pre[c[day]]);
		mul=1;
		//for(int j=1;j<=k;j++)cout<<wmax[j]<<" "<<wmin[j]<<endl;
		for(int j=1;j<=k;j++){
			if(wmax[j]<wmin[j]){
				flag=false;
				break;
			}
			mul*=(wmax[j]-wmin[j]+1);
			mul%=mod;
		}
		if(!flag){
			cout<<ans<<endl;
			return 0;
		}
		ans+=mul;
		ans%=mod;
		//cout<<ans<<endl;
	}
		
	
	if(flag)cout<<-1<<endl;
	return 0;
}
