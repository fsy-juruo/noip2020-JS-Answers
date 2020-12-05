#include <bits/stdc++.h>
using namespace std;
long long a[100005][7],b[100005],c[100005];
long long n,m,x,y,z;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i][0];
		for(long long j=1;j<=a[i][0];j++)cin>>a[i][j];
	}
	for(long long i=1;i<=m;i++)b[i]=1,c[i]=1;
	for(long long i=1;i<=n;i++){
		if(a[i][0]){
			for(long long j=1;j<=a[i][0];j++){
				x=c[i]*a[i][0],y=c[a[i][j]];
				if(y==0){
					c[a[i][j]]=c[i]*a[i][0];
					b[a[i][j]]=b[i];
					continue;
				}
				while(y)z=x%y,x=y,y=z;
				z=c[i]*a[i][0]*c[a[i][j]]/x;
				b[a[i][j]]=(z/c[a[i][j]])*b[a[i][j]]+(z/(c[i]*a[i][0]))*b[i];
				c[a[i][j]]=z;
				x=c[a[i][j]],y=b[a[i][j]];
				if(y==0)continue;
				while(y)z=x%y,x=y,y=z;
				b[a[i][j]]/=x,c[a[i][j]]/=x;
			}
			b[i]=0,c[i]=0;
		}
	}
	for(long long i=1;i<=n;i++){
		if(!a[i][0])cout<<b[i]<<' '<<c[i]<<endl;
	}
	return 0;
}
