#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ball[55][20005];
bool vis[60];
void move(int n,int f,int t,int m){
	for(int i=min(f,t);i<=max(f,t);i++)
		cout<<n<<" "<<m<<endl;
	
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){		
		for(int j=1;j<=n;j++){
			cin>>ball[i][j];
			if(vis[ball[i][j]]==0) vis[ball[i][j]]=1,cnt++;
		}
	}
	int lost;
	if(cnt==n+1){
		for(int i=1;i<=n;i++){
			if(vis[ball[i][1]]==1) vis[ball[i][1]]=0;
		}	
		for(int i=1;i<=n;i++){
			if(vis[ball[i][1]==0]) vis[ball[i][1]]=1;
			else lost=ball[i][1];			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ball[i][j]==lost){
					if(i==1) move(i,j+1,n,i+1);
					else move(i,j+1,n,i-1);
					cout<<i<<" "<<n+1;
				}
			}
		}
	}
			

	return 0;
}
