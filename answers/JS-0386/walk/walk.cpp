#include<bits/stdc++.h>
using namespace std;
int a[110];
int d[100010][2];
int na[20];
int nx[20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		na[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>d[i][0]>>d[i][1];
	}
	int ans=0;
	while(!na[k+1]){
		for(int i=1;i<=k;i++){
			nx[i]=na[i];
		}
		int t=0,flg=0;
		while(1){
			for(int i=1;i<=n;i++){
				nx[d[i][0]]+=d[i][1];
				t++;
				for(int j=1;j<=k;j++){
					if(nx[j]<1||nx[j]>a[j]){
						flg=1;
						break;
					}
				}
				if(flg)break;
			}
			if(flg)break;
			int flg2=1;
			for(int j=1;j<=k;j++){
				if(nx[j]!=na[j]){
					flg2=0;
					break;
				}
			}
			if(flg2){
				cout<<-1<<endl;
				return 0; 
			}
		}
		ans+=t;
		na[1]++;
		for(int i=1;i<=k;i++){
			if(na[i]>a[i]){
				na[i+1]++;
				na[i]-=a[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
