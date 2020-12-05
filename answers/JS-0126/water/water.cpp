#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m;
vector <int> q[N];
int cnt[N];
LL fm[N],fz[N];
LL ff(LL x,LL y){
	if(x==0){
		return y;
	}
	if(y==0){
		return x;
	}
	LL ma=max(x,y);
	LL mi=min(x,y);
	return ff(ma%mi,mi);
}
void solve(int t){
	LL x=fz[t],y=fm[t];
	LL k=ff(x,y);
	fz[t]/=k;fm[t]/=k;
}
void add(int x,int fenz,int fenm){
	int k=fm[x];
	fm[x]=fm[x]*fenm;
	fz[x]=fz[x]*fenm+k*fenz;
	solve(x);
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		fz[i]=0;
		fm[i]=1;
	}
	for(int i=1;i<=m;i++){
		fz[i]=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cnt[i]);
		for(int j=1;j<=cnt[i];j++){
			int p;
			scanf("%d",&p);
			q[i].push_back(p);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<cnt[i];j++){
				add(q[i][j],fz[i],fm[i]*cnt[i]);
				//solve(q[i][j]);
		}
//		cout<<i<<":"<<endl;
//		for(int j=1;j<=n;j++){
//			solve(j);
//			cout<<fz[j]<<" "<<fm[j]<<endl;
//		}
//		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){		
			solve(i);
			//cout<<fz[i]<<" "<<fm[i]<<endl;
			printf("%lld %lld\n",fz[i],fm[i]);
		}
	}
	return 0;
}
