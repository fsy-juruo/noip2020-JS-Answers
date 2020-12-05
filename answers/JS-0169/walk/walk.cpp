#include <bits/stdc++.h>
#define MAXK 10
#define MAXN 1005
#define P 1000000007
using namespace std;
typedef long long ll;
int n,k,w[MAXK],c[MAXN],d[MAXN];
int dx[MAXK],a[MAXK],b[MAXK];
int A[MAXK];
ll ans;

bool WithinBond(int x[]){
	for(int i=1;i<=k;++i)
		if(x[i]<1 || x[i]>w[i]) return 0;
	return 1;
}

void calc(){
	int step=0,B[MAXK];
	for(int i=1;i<=k;++i) B[i]=A[i];
	while(WithinBond(B))
		B[c[step]]+=d[step],(++step)%=n,++ans;
}

void GetPos(int D){
	if(D>k) { calc(); return; }
	for(int i=1;i<=w[D];++i)
		A[D]=i,GetPos(D+1),A[D]=0;
	return;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	memset(b,0xc0,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=k;++i) cin>>w[i];
	for(int i=0;i<n;++i){
		cin>>c[i]>>d[i];
		dx[c[i]]+=d[i];
		a[c[i]]=min(a[c[i]],dx[c[i]]);
		b[c[i]]=max(b[c[i]],dx[c[i]]);
	}
	bool flg=1;
	for(int i=1;i<=k;++i) flg&=(b[i]-a[i]<=w[i] && !dx[i]);
	if(flg) { puts("-1"); return 0; }
	GetPos(1);
	cout<<ans<<endl;
	return 0;
}
