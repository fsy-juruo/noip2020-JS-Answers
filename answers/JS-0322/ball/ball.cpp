#include<cstdio>
#include<iostream>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
struct HH{
	int x,y;
}tmp[1000];
int t[1000][1000],ans,n,m,i,num[100],tot,j;
bool check(){
	int i=0,j=0;
	rep(i,1,n){
		rep(j,1,num[i])
 			if (t[i][j]!=t[i][1]) return false;
 	}
    return true;
}
void dfs(int x,int dep){
	int i=0;
	if (check()) {
		ans=dep;
	}
	if (ans<=820000){
		rep(i,1,n) 
			if (num[x]>=1 && i!=x) t[i][num[i]+1]=t[x][num[x]],num[x]--,tmp[tot++].x=x,tmp[tot].y=i,dfs(i,dep+1),num[x]++,t[x][num[x]]=t[i][num[i]+1];
	}
	else return;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		num[i]=m;
		rep(j,1,m)
		 cin>>t[i][j];
	}
	rep(i,1,n) 
		dfs(i,0);
	rep(i,1,ans){
		cout<<tmp[i].x<<tmp[i].y;
	}
}
