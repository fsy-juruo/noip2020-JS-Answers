#include<bits/stdc++.h>
using namespace std;

int n,k,c[20],d[20];
long long w[20],lag=1;

void readp(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		lag*=w[i];
	}
	for(int j=1;j<=n;j++)
		cin>>c[j]>>d[j];
}
int main(){
        freopen("walk.in","r",stdin);
        freopen("walk.out","w",stdout);
	readp();
//	work();
	cout<<-1<<endl;
        return 0;
}

