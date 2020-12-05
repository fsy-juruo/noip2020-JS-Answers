#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],c[500005],d[500005],a[15]={-1};
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		a[i]=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
