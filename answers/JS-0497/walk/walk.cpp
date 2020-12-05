#include<bits/stdc++.h>
#define maxn 500005
using namespace std;

int n,m,t,l,a[maxn][5],ans=0,h=0;

void work(int x,int y,int k,int s){
	if(s>999999999){
		h=1;return ;
	}
	if(x==0||y==0||x>n||y>m){
		ans+=s;
		return ;
	}
	if(a[k][1]==1){
		if(k+1<=t)work(x+a[k][2],y,k+1,s+1);
		else work(x+a[k][2],y,1,s+1);
	}
	if(a[k][1]==2){
		if(k+1<=t)work(x,y+a[k][2],k+1,s+1);
		else work(x,y+a[k][2],1,s+1);
	}
	return ;
}
void worka(int x,int k,int s){
	if(s>999999999){
		h=1;return ;
	}
	if(x==0||x>n){
		ans+=s;
		return ;
	}
	if(k+1<=t)worka(x+a[k][2],k+1,s+1);
	else worka(x+a[k][2],1,s+1);
	return ;
}
void workc(int x,int y,int z,int k,int s){
	if(s>999999999){
		h=1;return ;
	}
	if(x==0||y==0||z==0||z>l||x>n||y>m){
		//cout<<x<<y<<z<<endl;
		ans+=s;
		return ;
	}
	//cout<<a[k][1]<<endl;
	if(a[k][1]==1){
		if(k+1<=t)workc(x+a[k][2],y,z,k+1,s+1);
		else workc(x+a[k][2],y,z,1,s+1);
	}
	if(a[k][1]==2){
		if(k+1<=t)workc(x,y+a[k][2],z,k+1,s+1);
		else workc(x,y+a[k][2],z,1,s+1);
	}
	if(a[k][1]==3){
		if(k+1<=t)workc(x,y,z+a[k][2],k+1,s+1);
		else workc(x,y,z+a[k][2],1,s+1);
	}
	return ;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int k;
	cin>>t>>k;
	if(k==2){
		cin>>n>>m;
		//cout<<n<<" "<<m<<endl;
		for(int i=1;i<=t;i++)cin>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				work(i,j,1,0);
			}
		}
		if(h==1)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	if(k==1){
		cin>>n;
		for(int i=1;i<=t;i++)cin>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++)worka(i,1,0);
		if(h==1)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	if(k==3){
		cin>>n>>m>>l;
		for(int i=1;i<=t;i++)cin>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				for(int u=1;u<=l;u++){
					workc(i,j,u,1,0);
				}
		}
		if(h==1)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
