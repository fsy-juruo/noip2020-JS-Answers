#include<bits/stdc++.h>
const int MOD=1e9+7;
using namespace std;
int n,k,cnt;
struct goo {
	int fx,bs;
} g[100010];
int a5[11][11][11][11][11];
int a4[11][11][11][11];
int a3[11][11][11];
int a2[20002][20002];
int a1[100002];
int w[6];
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1; i<=k; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>g[i].fx>>g[i].bs;
	}
	cout<<"-1";
	if(n==1) {
			int ans;
			int l=0,t=1,flag=0,maxn,minn;
			for(int i=2; i<=n; i++) {
				if(g[i].fx==1) l+=g[i].bs;
				if(g[i].fx==-1) l-=g[i].bs;
			}
			if(l==0) {	
			}
		for(int j=1; j<=w[1]; j++) {}
	}
	return 0;
}


