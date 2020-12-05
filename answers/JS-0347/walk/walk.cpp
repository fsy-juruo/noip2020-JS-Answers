#include<bits/stdc++.h>
#define ll long long 
#define N 100100
#define M 1000000007
using namespace std;
ll n,k,P,x,y;
ll w[N],c[N],d[N];
ll ans;
bool y_1,y_2;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
for(int i=1;i<=k;i++){
	cin>>w[i];
}	
for(int i=1;i<=n;i++){
	cin>>c[i]>>d[i];
	
}
int dz=0;
if(k==1){
	for(int i=1;i<=n;i++){
		if(d[i]==-1) y_1=1;
		if(d[i]==1) y_2=1;
		 dz+=d[i];
	}
	if(dz==0) cout<<"-1"<<endl;
	else {
	ans=(w[1]-1)*w[1]%M/2;cout<<ans<<endl;}
	return 0;
}



cout<<"-1"<<endl;
	return 0;
}

