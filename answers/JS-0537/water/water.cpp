#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF 2147483647
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
//36279705600000000000
//3.6*10^19
const int Maxn=100005;
const LL lim=1e18;
struct Int{
	LL A,B;
	//A*10^18+B
	Int(LL _A=0,LL _B=0){
		A=_A;B=_B;
	}
	void Add(Int I){
		A+=I.A;
		B+=I.B;
		if (B>=lim){
			B-=lim;A++;
		}
	}
	void Div(LL d){
		LL t=(A%d)*lim+B;
		A/=d;B=t/d;
	}
	LL mod(LL d){
		return ((A%d)*lim+B)%d;
	}
	void Out(){
		if (!A){
			printf("%lld",B);
		}
		else{
			printf("%lld",A);printf("%.18lld",B);
		}
	}
};
vector<int> G[Maxn];
int deg[Maxn],n,m;
Int dp[Maxn];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Int beg=Int(36,279705600000000000LL);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		int x=read();
		for (int j=0;j<x;j++){
			int y=read();G[i].pb(y);deg[y]++;
		}
		if(i<=m) dp[i]=beg;
	}
//cout<<123<<endl;
	vector<int> V;
	for (int i=1;i<=n;i++){
		if (!deg[i]) V.pb(i);
	}
	
	while (!V.empty()){
		int x=V.back();V.pop_back();
	//	cout<<x<<endl;
		int D=G[x].size();
		if (D==0) continue;
		Int tmp=dp[x];tmp.Div(D);
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			deg[v]--;
			dp[v].Add(tmp);
			if (!deg[v]) V.pb(v);
		}
	}
	
	for (int i=1;i<=n;i++){
		
		if (G[i].empty()){
			Int X=dp[i],Y=beg;
		//	X.Out();Y.Out();
			if (X.A==0 && X.B==0){
				printf("1 0\n");
				continue;
			}
			while (X.mod(2)==0 && Y.mod(2)==0){
				X.Div(2);Y.Div(2);
			}
			while (X.mod(3)==0 && Y.mod(3)==0){
				X.Div(3);Y.Div(3);
			}
			while (X.mod(5)==0 && Y.mod(5)==0){
				X.Div(5);Y.Div(5);
			}
			X.Out();printf(" ");Y.Out();printf("\n");
		}
	}
}
