#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int d[MAXN];
int to[MAXN];
int Next[MAXN];
int head[MAXN];
int tot=0;
int tx=0,ts;
int op[MAXN];
int jg[MAXN][2];
int os[MAXN];
int osd[MAXN];
int tg[MAXN][2];
bool vis[MAXN];
int gcdc(int n,int m){
	if (n<m){
		swap(n,m);
	}
	int r=n%m;
	while (r>0){
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for (int j=1;j<=d[i];j++){
			int x;
			cin>>x;
			++tot;
			to[tot]=x;
			Next[tot]=head[i];
			head[i]=tot;
		}
		if (d[i]==0){
			op[++tx]=i;
		}
	}
	
	ts=m;
	for (int i=1;i<=m;i++){
		os[i]=i;
		jg[os[i]][0]=1;
		jg[os[i]][1]=1;
	}
	
	bool flag=true;
	while (flag){
		memset(vis,false,sizeof(vis));
		memset(tg,0,sizeof(tg));
		int tsp=0;
		flag=false;
		for (int i=1;i<=ts;i++){
			if (d[os[i]]>0){
				flag=true;
				for (int j=head[os[i]];j;j=Next[j]){
					int rg=gcdc(jg[os[i]][0],d[os[i]]);
					int xz=jg[os[i]][0]/rg;
					int xm=jg[os[i]][1]*(d[os[i]]/rg);
					if (tg[to[j]][1]>0){
						int nz=xm*tg[to[j]][0]+xz*tg[to[j]][1];
						int nm=xm*tg[to[j]][1];
						int xr=gcdc(nz,nm);
						tg[to[j]][0]=nz/xr;
						tg[to[j]][1]=nm/xr;
					}
					else {
						tg[to[j]][0]=xz;
						tg[to[j]][1]=xm;
					}
					if (!vis[to[j]]){
						osd[++tsp]=to[j];
					}
					vis[to[j]]=true;
				}
			}
		}
		ts=tsp;
		for (int i=1;i<=ts;i++){
			if (jg[osd[i]][1]>0){
				int tz=jg[osd[i]][1]*tg[osd[i]][0]+jg[osd[i]][0]*tg[osd[i]][1];
				int tm=jg[osd[i]][1]*tg[osd[i]][1];
				int tr=gcdc(tz,tm);
				jg[osd[i]][0]=tz/tr;
				jg[osd[i]][1]=tm/tr;
			}
			else {
				jg[osd[i]][0]=tg[osd[i]][0];
				jg[osd[i]][1]=tg[osd[i]][1];
			}
			os[i]=osd[i];
		}
	}
	for (int i=1;i<=tx;i++){
		cout<<jg[op[i]][0]<<" "<<jg[op[i]][1]<<endl;
	}
	return 0;
}

