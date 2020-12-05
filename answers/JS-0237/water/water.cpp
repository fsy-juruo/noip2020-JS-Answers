#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f;
typedef long long ll;
signed n,m;
vector<long long>g[100005],rg[100005];
long long deg[100005],ord[100005],sz;
bool b[100005];
queue<long long>q;
long long ansx[100005],ansy[100005];
long long Gcd(long long x,long long y){
	while(x!=0&&y!=0){
		if(x>y)x%=y;
		else y%=x;
	}
	return x+y;
}
long long lcm(long long x,long long y){
	return x/Gcd(x,y)*y;
}
void add(long long pos,long long x,long long y){
	long long num=lcm(ansy[pos],y);
	ansx[pos]=ansx[pos]*num/ansy[pos]+x*num/y;
	ansy[pos]=num;
	long long tmp=Gcd(ansx[pos],ansy[pos]);
	ansx[pos]/=tmp;
	ansy[pos]/=tmp;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++){
		signed d;scanf("%d",&d);
		deg[i]=d;
		if(!d)q.push(i);
		while(d--){
			signed x;scanf("%d",&x);
			g[i].push_back(x);
			rg[x].push_back(i);
		}
	}
	while(!q.empty()){
		long long x=q.front();q.pop();
		sz++;ord[sz]=x;
		for(long long i=0;i<rg[x].size();i++){
			long long to=rg[x][i];
			deg[to]--;
			if(deg[to]==0){
				q.push(to);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(i<=m)ansx[i]=1;
		else ansx[i]=0;
		ansy[i]=1;
	}
	for(long long i=sz;i>=1;i--){
		for(long long j=0;j<g[ord[i]].size();j++){
			add(g[ord[i]][j],ansx[ord[i]],ansy[ord[i]]*g[ord[i]].size());
		}
	}
	for(long long i=1;i<=n;i++)if(!g[i].size())cout<<ansx[i]<<" "<<ansy[i]<<endl;
	return 0;
}
