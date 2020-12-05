#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n,k,wi[10],ans;

struct node{
	int c,d;
}step[100010];

int dfs1(int pos,int ns,int sum){
	if(pos>wi[1]||pos<1) return sum;
	if(ns==n+1) ns=1;
	return dfs1(pos+step[ns].d,ns+1,(sum+1)%MOD);
}

int dfs2(int x,int y,int ns,int sum){
	if(x<1||y<1||x>wi[1]||y>wi[2]) return sum;
	if(ns==n+1) ns=1;
	if(step[ns].c==1) return dfs2(x+step[ns].d,y,ns+1,sum+1);
	else return dfs2(x,y+step[ns].d,ns+1,(sum+1)%MOD);
}

int dfs3(int x,int y,int z,int ns,int sum){
	if(x<1||y<1||x>wi[1]||y>wi[2]||z<1||z>wi[3]) return sum;
	if(ns==n+1) ns=1;
	if(step[ns].c==1) return dfs3(x+step[ns].d,y,z,ns+1,(sum+1)%MOD);
	else if(step[ns].c==2) return dfs3(x,y+step[ns].d,z,ns+1,(sum+1)%MOD);
	else return dfs3(x,y,z+step[ns].d,ns+1,(sum+1)%MOD);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>wi[i];
	for(int i=1;i<=n;i++) cin>>step[i].c>>step[i].d;
	if(k==1){
		for(int i=1;i<=wi[1];i++){
			int tem=dfs1(i,1,0);
			if(tem!=-1) ans+=tem;
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
		cout<<ans<<endl;
	}
	else if(k==2){
		for(int i=1;i<=wi[1];i++)
			for(int j=1;j<=wi[2];j++){
				int tem=dfs2(i,j,1,0);
				ans+=tem;
			}
		cout<<ans<<endl;
	}
	else if(k==3){
		for(int i=1;i<=wi[1];i++)
			for(int j=1;j<=wi[2];j++)
				for(int w=1;w<=wi[3];w++){
					int tem=dfs3(i,j,w,1,0);
					ans+=tem;
				}
		cout<<ans<<endl;
	}
	else cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
