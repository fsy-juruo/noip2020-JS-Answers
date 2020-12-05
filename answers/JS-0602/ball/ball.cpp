#include<bits/stdc++.h>
using namespace std;
int n,m,g[100][500];
struct node{
	int fr,to;
}act[820010];
int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
void print(int dep){
	cout<<dep-1<<endl;
	for (int i=1;i<dep;i++)
	   cout<<act[i].fr<<" "<<act[i].to<<endl;
	return ;
}
int top(int x){
	for (int i=m;i>=1;i--)
	   if (g[x][i]!=0)
	   	return i;
	return 0;
}
int lowest(int x){
	for (int i=1;i<=m;i++)
	   if (g[x][i]==0)return i;
	return m+1;
}
bool check(){
	for (int i=1;i<=n+1;i++){
		int x=g[i][1];
		for (int j=2;j<=m;j++)
		   if (g[i][j]!=x)return 0;
	}
    return 1;
}
void dfs(int dep){
	//cout<<act[dep-1].fr<<" "<<act[dep-1].to<<endl;
	if (dep>8)return ;
	if (check()){
		print(dep);
		exit(0);
	}
	for (int i=1;i<=n+1;i++)
	   if (g[i][top(i)]!=0)
	   for (int j=1;j<=n+1;j++){
	   	if (i==act[dep-1].to&&j==act[dep-1].fr)continue;
	   	if (g[j][lowest(j)]!=0)continue;
	   	if (i==j)continue;
	   	act[dep].fr=i,act[dep].to=j;
	   	int mema=top(i),memb=lowest(j);
	   	swap(g[i][top(i)],g[j][lowest(j)]);
	   	dfs(dep+1);
	    swap(g[j][memb],g[i][mema]);
	   }
	return ;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	   for (int j=1;j<=m;j++)
	      g[i][j]=read();
    for (int i=1;i<=m;i++)
       g[n+1][i]=0;
	dfs(1);
	return 0;
}

