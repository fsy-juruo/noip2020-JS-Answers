#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long fenzi,fenmu;
}w[10100];
void gcd(long long x,long long y,long long z){
	long long r=x%y,a=x,b=y;
	while(x%y!=0){
		x=y;
		y=r;
		r=x%y;
	}
	w[z].fenzi=a/y;
	w[z].fenmu=b/y;
	
}
long long n,m;
long long maps[10100][10],f[10010],f2[10010],d[10010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		f[i]=1;
		w[i].fenzi=1;
		w[i].fenmu=1;
	} 
	for(int i=1;i<=n;i++){
	
	
		w[i].fenmu=1;
	} 
	for(int i=1;i<=n;i++){

		cin>>d[i];
		if(d[i]==0) f2[i]=1;
		for(int j=1;j<=d[i];j++)
		{
			long long a;
			cin>>a;
			maps[i][j]=a;
			
		}
	}
	while(1){
		long long f=0;
		for(int i=1;i<=n;i++){
		if(f2[i]==0&&w[i].fenmu!=0&&w[i].fenzi!=0) {
		f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			if(f2[i]==1) {
			cout<<w[i].fenzi<<" "<<w[i].fenmu<<endl;
			
			}
		}
		break;
	}
	for(int i=1;i<=n;i++)
	{	
	///for(int j=1;j<=n;j++) cout<<w[j].fenzi<<" "<<w[j].fenmu<<endl;
	//cout<<endl;
		if(f2[i]==0){
			if(w[i].fenzi!=0){
				for(int k=1;k<=d[i];k++){
				long long j=maps[i][k];
						
						w[j].fenzi=w[j].fenzi*w[i].fenmu*d[i]+w[i].fenzi*w[j].fenmu;
						w[j].fenmu=w[i].fenmu*w[j].fenmu*d[i];
						gcd(w[j].fenzi,w[j].fenmu,j);
					
				}
				w[i].fenzi=0;
				w[i].fenmu=0;
			}
		}
	}
	}
	
	return 0;
}
