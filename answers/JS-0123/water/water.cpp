#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define ll long long
ll get_gcd(ll x,ll y){
	if(y==0)return x;
	return get_gcd(y,x%y);
}
ll get_gbs(ll x,ll y){
	return x*y/get_gcd(x,y);
}
struct node{
	ll fz,fm;
	ll tot;
}q[MAXN];
int zs[MAXN][15],n,m,jsk[20],tj=0;
bool judgem[MAXN],judgen[MAXN];
void dfs(int x){
	if(q[x].tot==0)return ;
	ll nz=q[x].fz;
	ll nm=q[x].fm*q[x].tot;
	q[x].fz=0;q[x].fm=1;
	for(int i=1;i<=q[x].tot;i++){
		int pos=zs[x][i];
		ll ez=q[pos].fz;ll em=q[pos].fm;
		ll g=get_gbs(em,nm);
		ll bs1=g/nm;ll bs2=g/em;
		q[pos].fm=g;q[pos].fz=ez*bs2+nz*bs1;
		dfs(pos);	
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(judgem,1,sizeof(judgem));
	memset(judgen,0,sizeof(judgen));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i].tot;
		q[i].fm=1;
		if(q[i].tot==0)judgen[i]=1;
		for(int j=1;j<=q[i].tot;j++){
			cin>>zs[i][j];
			judgem[zs[i][j]]=false;
		}
	}
	for(int i=1;i<=n;i++)if(judgem[i]){jsk[tj]=i;tj++;q[i].fm=1;q[i].fz=1;}
	for(int i=0;i<tj;i++){dfs(jsk[i]);}
	for(int i=1;i<=n;i++){
		if(judgen[i]==1){
			ll gc=get_gcd(q[i].fz,q[i].fm);
			q[i].fz/=gc;q[i].fm/=gc;
			cout<<q[i].fz<<" "<<q[i].fm<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
