#include<bits/stdc++.h>
using namespace std;
int k[10010],d[10010][10],h[10010];
struct node{
	int x,y;
}ans[10010];
long long gys(long long x,long long y){
	if(y==0) return x;
	gys(y,x%y);
}

void pl(long long k,long long tot){
	//cout<<endl<<ans[k].x<<" "<<ans[k].y<<" "<<tot<<endl;
	long long t=ans[k].y*(tot/gys(ans[k].y,tot) );
	long long a=t/ans[k].y , b=t/tot;
	
	ans[k].y=t;
	ans[k].x=a*ans[k].x+b;
	
	int tt=gys(ans[k].x,ans[k].y);
	ans[k].x=ans[k].x/tt;
	ans[k].y=ans[k].y/tt;
	//cout<<ans[k].x<<" "<<ans[k].y<<endl<<endl;
}

void dfs(long long dep,long long tot){
	//cout<<last<<" "<<dep<<" "<<tot<<endl;
	if(h[dep]==1){
		pl(dep,tot);
		return;
	}
	for(int i=1;i<=k[dep];i++){
		dfs(d[dep][i],tot*k[dep]);
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<10010;i++){
    	ans[i].x=0;
    	ans[i].y=1;
	}
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	if(k[i]==0) h[i]=1;
    	for(int j=1;j<=k[i];j++){
    		cin>>d[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i,1);
	}
	for(int i=1;i<=10000;i++){
		if(h[i]==1) cout<<ans[i].x<<" "<<ans[i].y<<endl;
	}
	return 0;
}
