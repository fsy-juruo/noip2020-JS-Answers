#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
queue<ak>q;vector<ak>way[111111];
ak ind[111111],oud[111111],dp1[111111],dp2[111111];
void modify(ak x,ak zi,ak mu){
	ak lcm=dp2[x]*mu/__gcd(dp2[x],mu);
	dp1[x]=dp1[x]*lcm/dp2[x];
	dp1[x]+=zi*lcm/mu;dp2[x]=lcm;
}
int main(){
	#ifndef lpcak
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	#endif
	ak n,m;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	F(i,1,n){
		ak k;cin>>k;
		if(k)F(j,1,k){
			ak x;cin>>x;
			way[i].push_back(x);
			ind[x]++,oud[i]++;
		}
	}
	F(i,1,n)dp2[i]=1;
	F(i,1,n)if(!ind[i])
		dp1[i]=dp2[i]=1,q.push(i);
	while(q.size()){
		ak u=q.front();q.pop();
		if(!way[u].size())continue;
		ak mul=way[u].size();
		F(i,0,way[u].size()-1){
			ak v=way[u][i];
			modify(v,dp1[u],dp2[u]*mul);
			ind[v]--;
			if(!ind[v])q.push(v);
		}
	}
	F(i,1,n)if(!oud[i]){
		ak gcd=__gcd(dp1[i],dp2[i]);
		cout<<dp1[i]/gcd<<" ";
		cout<<dp2[i]/gcd<<"\n";
	}
	return 0;
}
/*

5 1
3 2 3 5
2 4 5
2 5 4
0
0

*/
