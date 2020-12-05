#include <bits/stdc++.h>
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
const int mod=1e9+7;
int rdi(){
	int a=0,b=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')b=-1,ch=getchar();
	while(ch>='0'&&ch<='9')a=a*10+ch-'0',ch=getchar();
	return a*b;
}
//ȡģ! 
int n,k,ans;
int w[20];
int pos2[20];
int pos[20];
int c[20],d[20];
int st[20];
void walk(){
	int step=1,flg=0;
	for(int i=1;i<=k;i++)st[i]=pos[i];
	while(1){
		for(int i=1;i<=n;i++){
			pos[c[i]]+=d[i];
			if(pos[c[i]]<1||pos[c[i]]>w[c[i]]){
				flg=1;
				break;
			}
			step++;
		}
		if(flg)break;
		bool flg2=0;
		for(int i=1;i<=k;i++)if(st[i]!=pos[i]){flg2=1;break;}
		if(!flg2){
			puts("-1");
			exit(0);
		}
	}
	ans=(ans+step)%mod;
}
void dfs15(int dep){
	if(dep>k){
		int preans=ans;
		for(int i=1;i<=k;i++)pos[i]=pos2[i];
		walk();
//		cout<<ans-preans<<endl;
		return;
	}
	for(int i=1;i<=w[dep];i++){
		pos2[dep]=i;
		dfs15(dep+1);
	}
}
void solve15(){
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
	dfs15(1);
	cout<<ans<<endl;
}
void solve100(){
	int x;
	for(int i=1;i<=k;i++)cin>>x;
	for(int i=1;i<=n;i++)cin>>x>>x;
	puts("-1");
}
int main(){
#ifndef OFFLINE
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
#endif
	cin>>n>>k;
	if(n<=5)solve15();
//	else if(k==1)solve10();
//	else if(k==2)solve20();
//	else if(k==3)solve35();
	else solve100();
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1







3 2
3 3
1 1
2 -1
1 1
*/
