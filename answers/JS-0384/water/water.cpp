#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005][10],waas[100005][2]={};
vector<int> outt;
int gcd(int a,int b){
	if(a==b)
		return a;
	if(a<b)
		swap(a,b);
	return gcd(b,a-b);
}
void add(int z,int b,int c,int d,int e,int f){
	z*=d/gcd(b,d);
	c*=b/gcd(b,d);
	int x=z+c;
	int y=(b*d)/gcd(b,d);
	waas[a[e][f]][0]=x/gcd(x,y);
	waas[a[e][f]][1]=y/gcd(x,y);
}
void dfs(int x){
	for(int i=0;i<a[x][5];i++)
	{
		add(waas[a[x][i]][0],waas[a[x][i]][1],waas[x][0],waas[x][1]*a[x][5],x,i);
		waas[x][1]=0;
		waas[x][0]=0;
		dfs(a[x][i]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][5];
		if(a[i][5]==0)
			outt.push_back(i);
		for(int j=0;j<a[i][5];j++)
			cin>>a[i][j];
	}
	for(int i=0;i<m;i++)
	{
		waas[i][0]=waas[i][1]=1;
		dfs(i);
	}	
	for(int i=0;i<outt.size();i++)
		cout<<waas[outt[i]][0]<<' '<<waas[outt[i]][1]<<endl;
 	return 0;
}
