#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[100][450];
struct  node2{
	int len;
};
node2 q[100];
bool check(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=q[i].len;j++){
			if(g[i][j]!=g[i][j-1])
				return false;
		}
	}
	return true;
}
int cnt=0;
struct node{
	int x,y;
};
node ans[820000];
bool flag;
void dfs(int qi,int zhong){
	if(flag==true)
		return;
	if(cnt>820000)
		return;
	if(check()==true){
		flag=true;
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
			cout<<ans[i].x<<' '<<ans[i].y<<endl;
		return ;
	}
	cnt++;
	for(int i=1;i<=n;i++){
		if(q[i].len==0)
			continue;
		int x=g[i][q[i].len];
		g[i][q[i].len]=0;
		q[i].len--;
		for(int j=1;j<=n+1;j++){
			if(i!=j&&j!=qi&&i!=zhong){
				q[j].len++;
				g[j][q[j].len]=x;
				ans[cnt].x=i;
				ans[cnt].y=j;
				dfs(i,j);
				ans[cnt].x=0;
				ans[cnt].y=0;
				g[j][q[j].len]=0;
				q[j].len--;
			}
		}
		q[i].len++;
		g[i][q[i].len]=x;
	}
} 


int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	for(int i=1;i<=n;i++)
		q[i].len=m;
	dfs(0,0);
	return 0;
}
