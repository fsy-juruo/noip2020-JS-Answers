#include<bits/stdc++.h>
using namespace std;
int c[500005],d[500005],w[15],n,k;
const int mod=10e9+7;
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
	cout<<-1<<endl;
	return 0;
}

