#include<cstdio>
#include<iostream>
#define rep(i,j,k) for (i=j;i<=k;i++)
#define dep(i,j,k) for (i=j;i>=k;i--)
#define LL long long
using namespace std;
const int mod1=1e9+7;
LL n,m,i,j,w,ps,ans,nw;
bool f;
LL a[500005],a1[500005],c[500005],k[500005],d[500005];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	if (n>100) {
		cout<<-1;
		return 0;
	}
	w=1;
	rep(i,1,m) cin>>k[i],w=w*k[i];
	rep(i,1,n){
		cin>>c[i]>>d[i];
	}
	rep(i,1,m-1) a[i]=1;a[m]=0;
	rep(j,1,w){
		a[m]++;
		dep(i,m,1) if (a[i]>k[i]) a[i]=1,a[i-1]=a[i-1]+1;
		rep(i,1,m) a1[i]=a[i];
		nw=0;
		while(true){
			nw++;
			if (nw>n) nw=1;
			a1[c[nw]]+=d[nw];ans++;
			if (a1[c[nw]]>k[c[nw]] || a1[c[nw]]<=0) break;
			f=true;
			rep(i,1,w) if (a[i]!=a1[i]) f=false;
			if (f) ps++;
			if (ps>=100) break;
		}
		if (ps>=100){
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
