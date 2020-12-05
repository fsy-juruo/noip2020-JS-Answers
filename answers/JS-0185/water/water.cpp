#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[100010];
vector <int> v[100010];
vector <int> ck;
queue <int> q;
long long  f[100010],ff[100010];
bool h[100010];
long long gcdd(long long ax,long long bx){
	if(bx==0)return ax;
	return gcdd(bx,ax%bx);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;++i){
		ff[i]=1;
		int d;
		scanf("%d",&d);
		if(d==0)ck.push_back(i);
		for(int j=1;j<=d;++j){
			int vt;
			scanf("%d",&vt);
			v[i].push_back(vt);
			r[vt]++;
	}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;++i){
		f[i]=1;
		h[i]=1;
		q.push(i);
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		long long cf=f[t],cff=ff[t]*v[t].size();
		long long g=gcdd(cf,cff);
		cf/=g;cff/=g;
		for(int i=0;i<v[t].size();++i){
			int tx=v[t][i];
			f[tx]=f[tx]*cff+cf*ff[tx];
			ff[tx]=ff[tx]*cff;
			g=gcdd(ff[tx],f[tx]);
			f[tx]/=g;ff[tx]/=g;
			r[tx]--;
			if(r[tx]==0&&h[tx]==0){
				q.push(tx);
				h[tx]=1;
			}
		}
	}
	for(int i=0;i<ck.size();++i)printf("%lld %lld\n",f[ck[i]],ff[ck[i]]);
	return 0;
}

