#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Point{
	ll a;
	ll b;
}pv[100005];
vector<ll> wat[100005];
int pnt[100005];

bool check(int x){
	for(int i=1;i<=x;i++)
		if(pnt[i]!=-1 && pv[i].a!=0) return 1;
		
	return 0;
}
void print(int x){
	cout<<endl<<"Operation:"<<endl;
	for(int i=1;i<=x;i++) cout<<pv[i].a<<" "<<pv[i].b<<endl;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	// 1 normal
	// 0 input
	//-1 output
	for(int i=1;i<=n;i++){
		ll k,v;
		cin>>k;
		if(k==0) pnt[i]=-1;
		for(int j=1;j<=k;j++){
			cin>>v;
			if(pnt[v]==0) pnt[v]=1;
			wat[i].push_back(v);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(pnt[i]==0) pv[i].a=1;
		pv[i].b=1;
	}
	
	//print(n);
	while(check(n)==1){
		for(int i=1;i<=n;i++){
			ll v=wat[i].size();
			if(v>0 && pv[i].a!=0){
				ll a2=pv[i].a;
				ll b2=(pv[i].b)*v;
				ll fm,fz,a1,b1;
				for(int j=0;j<v;j++){
					a1=pv[wat[i][j]].a;
					b1=pv[wat[i][j]].b;
					fm=b1*b2;
					fz=(a2*b1)+(a1*b2);
					ll g=__gcd(fz,fm);
					pv[wat[i][j]].a=fz/g;
					pv[wat[i][j]].b=fm/g;
				}
				pv[i].a=0;
				pv[i].b=1;				
			}				

		}
		//print(n);
	}
	
	for(int i=1;i<=n;i++)
		if(pnt[i]==-1) cout<<pv[i].a<<" "<<pv[i].b<<endl;
		
	return 0;
}
