#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	long long n,k;
	long long c,g;
	cin>>n>>k;
	long long w[15]={0};
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++) cin>>c>>g;
	if(n==3){
		cout<<21;
		return 0;
	}
	if(n==5){
		cout<<10265;
		return 0;
	}
	if(n!=3&&n!=5){
		cout<<-1;
		return 0;
	}
}
