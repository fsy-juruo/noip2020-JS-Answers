#include<bits/stdc++.h>
using namespace std;
int w[15],tmp[15];
int c[500005],d[500005];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
	if(k==2){
			for(int i=1;i<=w[1];i++)
				for(int j=1;j<=w[2];j++){
					tmp[i]=j;
			while(1){
				tmp[i]+=d[c[i]];
				ans++;
				if(tmp[i]<0||tmp[i]>w[2])
				break;
			}		
		}
		cout<<ans;
	}
	if(k==3){
			for(int i=1;i<=w[1];i++)
				for(int j=1;j<=w[2];j++)
					for(int k=1;k<w[3];k++){
					tmp[i]=j;
			while(1){
				tmp[i]+=d[c[i]];
				ans++;
				if(tmp[i]<0||tmp[i]>w[2])
				break;
			}		
		}
		cout<<ans;
	}
	if(k==4){
			for(int i=1;i<=w[1];i++)
				for(int j=1;j<=w[2];j++)
					for(int k=1;k<w[3];k++)
						for(int l=1;l<w[4];l++){
					tmp[i]=j;
			while(1){
				tmp[i]+=d[c[i]];
				ans++;
				if(tmp[i]<0||tmp[i]>w[2])
				break;
			}		
		}
		cout<<ans;
	}	if(k==4){
			for(int i=1;i<=w[1];i++)
				for(int j=1;j<=w[2];j++)
					for(int k=1;k<w[3];k++)
						for(int l=1;l<w[4];l++)
							for(int ll=1;ll<w[5];ll++){
					tmp[i]=j;
			while(1){
				tmp[i]+=d[c[i]];
				ans++;
				if(tmp[i]<0||tmp[i]>w[2])
				break;
			}		
		}
		cout<<ans;
	}
}	
