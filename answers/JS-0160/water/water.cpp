#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pll;
const int N=1e5+5;
const long long BT=100000000000000ll;
int n,m,t;
int deg[N],sz[N],ord[N];
pll flw[15][N];
vector<int> nei[N];
queue<int> q;

long long GCD(long long x,long long y){
	if(y==0ll) return x;
	else return GCD(y,x%y);
}

void relax(pll &x){
	long long g=GCD(x.first,x.second);
	if(g!=0ll){
		x.first/=g;
		x.second/=g;
	}
}

inline pll add(pll x,pll y){
	pll res=make_pair(x.first*y.second+y.first*x.second,x.second*y.second);
	relax(res);
	return res;
}

void print(pll x){
	if(x.first!=0ll) printf("%lld%014lld",x.first,x.second);
	else printf("%lld",x.second);
}

inline void mult(pll& x,int y){
	x.first*=1ll*y;
	x.second*=1ll*y;
	x.first+=x.second/BT;
	x.second=x.second%BT;
}

inline int cmod(pll x,int y){
	x.second+=x.first%(1ll*y)*BT;
	return x.second%(1ll*y)==0ll;
}

inline void div(pll &x,int y){
	x.second+=x.first%(1ll*y)*BT;
	x.second/=1ll*y;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",sz+i);
		for(int j=1;j<=sz[i];j++){
			int x;
			scanf("%d",&x);
			deg[x]++;
			nei[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ord[++t]=x;
		for(int i=0;i<sz[x];i++){
			int to=nei[x][i];
			deg[to]--;
			if(!deg[to]) q.push(to);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) flw[i][j]=make_pair(0ll,1ll);
		flw[i][i]=make_pair(1ll,1ll);
		for(int j=1;j<=n;j++){
			int x=ord[j];
			for(int k=0;k<sz[x];k++){
				int to=nei[x][k];
				flw[i][to]=add(flw[i][to],make_pair(flw[i][x].first,flw[i][x].second*sz[x]));
			}
		}
	}
	for(int i=1;i<=n;i++) if(!sz[i]){
		pll ff,fs=make_pair(0ll,1ll);
		int m2=0,m3=0,m5=0;
		for(int j=1;j<=m;j++){
			int c2=0,c3=0,c5=0;
			long long x=flw[j][i].second;
			while(x%2ll==0ll){
				x/=2ll;
				c2++;
			}
			while(x%3ll==0ll){
				x/=3ll;
				c3++;
			}
			while(x%5ll==0ll){
				x/=5ll;
				c5++;
			}
			m2=max(m2,c2);
			m3=max(m3,c3);
			m5=max(m5,c5);
		}
		for(int j=0;j<m2;j++) mult(fs,2);
		for(int j=0;j<m3;j++) mult(fs,3);
		for(int j=0;j<m5;j++) mult(fs,5);
		for(int j=1;j<=m;j++){
			pll nf=make_pair(0ll,flw[j][i].first);
			int c2=0,c3=0,c5=0;
			long long x=flw[j][i].second;
			while(x%2ll==0ll){
				x/=2ll;
				c2++;
			}
			while(x%3ll==0ll){
				x/=3ll;
				c3++;
			}
			while(x%5ll==0ll){
				x/=5ll;
				c5++;
			}
			c2=m2-c2;
			c3=m3-c3;
			c5=m5-c5;
			for(int k=0;k<c2;k++) mult(nf,2);
			for(int k=0;k<c3;k++) mult(nf,3);
			for(int k=0;k<c5;k++) mult(nf,5);
			ff.first+=nf.first;
			ff.second+=nf.second;
			ff.first+=ff.second/BT;
			ff.second=ff.second%BT;
		}
		while(cmod(ff,2)&&cmod(fs,2)) div(ff,2),div(fs,2);
		while(cmod(ff,3)&&cmod(fs,3)) div(ff,3),div(fs,3);
		while(cmod(ff,5)&&cmod(fs,5)) div(ff,5),div(fs,5);
		print(ff);putchar(' ');print(fs);putchar('\n');
	}
	return 0;
}
