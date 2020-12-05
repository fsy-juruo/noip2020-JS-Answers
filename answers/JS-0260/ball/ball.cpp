#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define endl '\n'
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int rdi(){
	int a=0,b=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')b=-1,ch=getchar();
	while(ch>='0'&&ch<='9')a=a*10+ch-'0',ch=getchar();
	return a*b;
}
int n,m;
vector<int>a[60];
//int a[60][410];
vector<pii>ans;
bool solve(int tp,int to){
	int tp2=3-tp,flg=0;
	for(int i=1;i<=3;i++){
		if(i==to)continue;
		while(a[i].size()&&a[i][SZ(a[i])-1]==tp){
			ans.pb(mp(i,to));
			flg=1;
			a[to].pb(a[i][SZ(a[i])-1]);
			a[i].pop_back();
		}
	}
	return flg;
}
void output(){
	
}
void solve10(){
	ans.clear();
	if(solve(1,3))output();
	else{
		solve(2,3);
		output();
	}
}
void solve100(){
	cout<<0<<endl;
}
int main(){
#ifndef OFFLINE
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
#endif
//	freopen("ball3.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x=rdi();
			a[i].pb(x);
		}
//	if(n<=2)solve10();
//	else 
	solve100();
//	freopen("ball.out","r",stdin);
//	int t=rdi();
//	for(int i=1;i<=t;i++){
//		int x=rdi(),y=rdi();
//		a[y].pb(a[x].back());
//		a[x].pop_back();
//		printf("from: %d",x);
//		for(int j=0;j<a[x].size();j++)printf(" %d",a[x][j]);
//		puts("");
//		printf("to: %d",y);
//		for(int j=0;j<a[y].size();j++)printf(" %d",a[y][j]);
//		puts("");
//	}
	return 0;
}
/*
2 20
` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` `
2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 2 1
2 2 2 2 2 2 2 2 2 2 2 2 2
*/
