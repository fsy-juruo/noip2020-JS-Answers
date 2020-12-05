#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;
const int Mod=1000000007;
int n,k;
int wei[11];
int spot[11];
pair<int,int> Step[500010];
int dis[11]={0};
int maxdis[11]={0};
int leftmax[11]={0};
int rightmax[11]={0};
int con[100010];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	int P=1;
	for(int i=1;i<=k;i++){
		cin>>wei[i];
		P*=wei[i];
	}
	
	int total;
	for(int i=1;i<=n;i++){
		int c,d;
		cin>>c>>d;
		total+=abs(d);
		Step[i]=make_pair(c,d);
		dis[c]+=d;
		maxdis[c]=max(maxdis[c],abs(dis[c]));
		leftmax[c]=min(leftmax[c],dis[c]);
		rightmax[c]=max(rightmax[c],dis[c]);
	}
	bool real=false;
	for(int i=1;i<=k;i++){
		if(dis[i])real=true;
		else if(1+maxdis[i]>wei[i])real=true;
	}
	
	
	int ans=0;
	if(!real){
		cout<<"-1";
	}else if(k==1){
		for(int i=1;i<=wei[1];i++){
			if(i>n-rightmax[1]||i<1-leftmax[1]){
				for(int j=1;j<=n;j++){
					ans=ans+abs(Step[j].second)%Mod;
					ans%=Mod;
					con[i]+=Step[j].second;
					spot[1]+=Step[j].second;
					if(spot[1]>n||spot[1]<1)continue;	
				}
			}
			else{
				int chu=0;
				if(dis[1]>0){
					chu=(n-rightmax[1]-i)/dis[1];
				}else{
					chu=(1-leftmax[1]-i)/dis[1];
				}
				ans=ans+total*chu%Mod;
				ans%=Mod;
				i+=chu*dis[1];
				if(i+dis[1]<=n&&i+dis[1]>=1){
					i=i+dis[1];
					ans+=con[i]+abs(dis[1]);
				}else{
					for(int j=1;j<=n;j++){
					ans=ans+abs(Step[j].second)%Mod;
					ans%=Mod;
					con[i]+=Step[j].second;
					spot[1]+=Step[j].second;
					if(spot[1]>n||spot[1]<1)continue;	
				}
				}
			}
		}
		cout<<ans;
	}
	else if(n<=1000){
		if(k==5){
			for(int i=1;i<=wei[1];i++){
				//if(i<=)
				for(int j=1;j<=wei[2];j++){
					for(int k=1;k<=wei[3];k++){
						for(int a=1;a<=wei[4];a++){
							for(int b=1;b<=wei[5];b++){
							}
						}
					}
				}
			}
		}else if (k==3){
			
		}
	}else{
		cout<<"-1";
	}
	return 0;
}
