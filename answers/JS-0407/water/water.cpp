#include <bits/stdc++.h>
#define maxn 100007
#define ll long long
using namespace std;

inline ll gcd(ll a,ll b){
	if (a == 0 || b == 0) return (a == 0?b:a);
	return (a>b?gcd(a%b,b):gcd(a,b%a));
}

struct frac{
	ll fz,fm;
	
	frac(){fz = 0;fm = 1;}
	frac(ll a,ll b){
		fz = a;fm = b;
	}
	
	frac operator + (const frac &b) const{
		int ggg = gcd(fz*b.fm+fm*b.fz,fm*b.fm);
		return frac((fz*b.fm+fm*b.fz)/ggg,fm*b.fm/ggg);
	}
	
	frac operator - (const frac &b) const{
		int ggg = gcd(fz*b.fm-fm*b.fz,fm*b.fm);
		return frac((fz*b.fm-fm*b.fz)/ggg,fm*b.fm/ggg);
	}
	
	frac operator * (const frac &b) const{
		int ggg = gcd(fz*b.fz,fm*b.fm);
		return frac(fz*b.fz/ggg,fm*b.fm/ggg);
	}
	
	frac operator / (const frac &b) const{
		int ggg = gcd(fz*b.fm,fm*b.fz);
		return frac(fz*b.fm/ggg,fm*b.fz/ggg);
	}
};

frac flw[maxn];
bool isf[maxn],used[maxn];
vector<int> gv[maxn];
int n,m,k,t,ind[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>t;
			gv[i].push_back(t);
			ind[t]++;
		}
		
		if (k == 0) isf[i] = true;
	}
	
	for (int i=1;i<=n;i++)
		if (ind[i] == 0 ) flw[i] = frac(1,1);
	
	while (true){	
		int u = 1;
		while (u <= n && (used[u] || ind[u] || isf[u])) u++;
		if (u > n) break;
		used[u] = true;
		for (int i=0;i<gv[u].size();i++){
			flw[gv[u][i]] = flw[gv[u][i]] + flw[u] / frac(gv[u].size(),1);
			ind[gv[u][i]]--;
		}
		
		flw[u] = frac(0,1);
	}
	
	for (int i=1;i<=n;i++)
		if (isf[i])
			cout<<flw[i].fz<<' '<<flw[i].fm<<endl;
			
	return 0;
}
