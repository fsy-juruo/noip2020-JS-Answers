#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],mod=1e9+7,a[15],b[100005],c[100005],d[100005],ans;
void pl(int x){
	a[x]++;//cout<<a[x]<<" "<<w[x]<<endl;
	while(a[x]>w[x]){
		a[x-1]++;x--;a[x+1]=1;
	}
	for(int i=1;i<=k;i++) d[i]=a[i];
}
int main( ){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;int x=1,f=0;
	for(int i=1;i<=k;i++){
		cin>>w[i];x*=w[i];a[i]=1;
	}
	a[k]=0;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=1;i<=x;i++){
		pl(k);
		//for(int i=1;i<=k;i++) cout<<d[i]<<" ";cout<<endl;
		for(int j=1;;j++){
			if(j==n+1) j=1;
			if(c[j]>0) d[b[j]]++;
			else d[b[j]]--;
			ans++;ans=ans%mod;//cout<<d[b[j]]<<endl;
			if(d[b[j]]>w[b[j]] || d[b[j]]<1) break;
			if(j==n){
				f=0;
				for(int l=1;l<=k;l++){
					if(a[l]!=w[l]) f=1;
				}
				if(!f){
					cout<<"-1"<<endl;return 0;
				}
			}
		}
	}
	cout<<ans<<endl;return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
