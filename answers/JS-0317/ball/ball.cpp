#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[55][405];
pair<int,int>ans[820005];
vector<pair<int,int> >v[55];
int cnt=0;
void Go(int i1,int j1,int i2,int j2){
//	cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
	for(int i=m;i>=j1;i--)
	ans[cnt++]=make_pair(i1,n+1);
	for(int i=m;i>j2;i--)
	ans[cnt++]=make_pair(i2,n+1);
	ans[cnt++]=make_pair(i2,i1);
	ans[cnt++]=make_pair(n+1,i2);
}
void Back(int i1,int j1,int i2,int j2){
	for(int i=m;i>j1;i--)
	ans[cnt++]=make_pair(n+1,i1);
	for(int i=m;i>j2;i--)
	ans[cnt++]=make_pair(n+1,i2);
}
int main(){ 
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//checker.cpp - o checker
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
		cin>>x[i][j];
		v[x[i][j]].push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=n;i++)
		{
			int now=0;
			while(v[i][now].first==i)
			now++;
			for(int j=1;j<=m;j++)
			if(x[i][j]!=i){
			swap(x[i][j],x[v[i][now].first][v[i][now].second]);
			Go(i,j,v[i][now].first,v[i][now].second);	
			Back(i,j,v[i][now].first,v[i][now].second);
			}
		}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
	cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}	
