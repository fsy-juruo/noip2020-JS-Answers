#include<bits/stdc++.h>

using namespace std;

#define ll long long;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pii pair<int,int>

const int INF=1e9+7;
int n,k;
int w[11];
int c[500001];
int d[500001];
int ans;
int a[11],b[11];
int tp[200001];
int dp[100001];
bool endgame;
bool check1(){
	rep(i,k)if(b[i]<1||b[i]>w[i])return 0;
	return 1;
}
void dg1(int step){
	if(endgame)return;
	if(step==k+1){
		rep(i,k)b[i]=a[i];
		int now=0;
		while(check1()){
			ans++;
			now++;
			if(now==n+1)now=1;
			b[c[now]]+=d[now];
			if(ans>=10000000){
				endgame=1;
				return;
			}
		}
		return;
	}
	rep(i,w[step]){
		a[step]=i;
		dg1(step+1);
	}
}
void go1(){
	rep(i,k)cin>>w[i];
	rep(i,n)cin>>c[i]>>d[i];
	dg1(1);
	if(endgame)cout<<-1;
	else cout<<ans;
}
void go2(){
	int ww;
	int x=0;
	int maxf=-1;
	int minf=INF;
	cin>>ww;
	rep(i,n){
		cin>>c[i]>>d[i];
		x+=d[i];
		if(x>maxf)maxf=x;
		if(x<minf)minf=x;
		if(tp[x+ww]==0)tp[x+ww]=i;
		if(x<=-ww-1||x>=ww+1){
			cout<<-1;
			return;
		}
	}
	if(x==0){
		if(maxf-minf>ww){
			cout<<-1;
			return;
		}
		rep(i,ww){
			ans+=min(tp[ww+ww-i+1],tp[ww-i-1]);
		}
		cout<<ans;
		return;
	}
	else if(x>0){
		for(int i=1;i<=ww;i++){
			if(i+maxf>ww||i+minf<1){
				dp[i]=min(tp[ww+ww-i+1],tp[ww-i-1]);
				ans+=dp[i];
			}
			else if(i-x>=1&&dp[i-x]!=0){
				dp[i]=dp[i-x]+n;
				ans+=dp[i];
			}
		}
		cout<<ans;
		return;
	}
	else{
		for(int i=ww;i>=1;i--){
			if(i+maxf>ww||i+minf<1){
				dp[i]=min(tp[ww+ww-i+1],tp[ww-i-1]);
				ans+=dp[i];
			}
			else if(i+x<=ww&&dp[i+x]!=0){
				dp[i]=dp[i+x]+n;
				ans+=dp[i];
			}
		}
		cout<<ans;
		return;
	}
}
void go3(){
	
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n<=100)go1();
	else if(k==1)go2();
	else go3();
	return 0;
}
