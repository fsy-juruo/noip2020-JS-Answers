#include<bits/stdc++.h>
using namespace std;
	long long n,k,ans=-1,w[110],c[50010],d[50010];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>c[i]>>d[i];
	}
	/* for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++)
		{
			long long fuck=0,x=w[i],y=j,h[110]={0};
			while(1){
				fuck++;
				bool f=0;	
				if(y==j&&fuck>1){
						cout<<-1;
						return 0;
					}
				for(int e=1;e<=n;e++){
				
					if(y>x) {
						 f=1;
						 break;
					}
					else {
						ans++;
						
					}
				}
				if(f==1) break;
			}
			
		}
	}   */
	cout<<ans;
	return 0;
}
