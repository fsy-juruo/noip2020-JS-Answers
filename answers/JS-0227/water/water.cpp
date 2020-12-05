#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> to[100010];
long long d[100010];
long long ans1[100010],ans2[100010];
long long zzxc(long long x,long long y){
	if(y==0)return x;
	return zzxc(y,x%y);
}
void add(long long &x1,long long &x2,long long y1,long long y2){
	long long gfm=zzxc(x2,y2);
	int xx2=x2;
	x2*=y2/gfm;
	x1*=y2/gfm;
	y2*=xx2/gfm;
	y1*=xx2/gfm;
	x1+=y1;
	gfm=zzxc(x1,x2);
	x1/=gfm;
	x2/=gfm;
}
queue<long long> tps;
vector<long long> ans;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		ans1[i]=1;
		ans2[i]=1;
	}
	for(long long i=1;i<=n;i++)
		ans2[i]=1;
	long long u,v;
	for(long long i=1;i<=n;i++){
		cin>>u;
		if(u==0)ans.push_back(i);
		while(u--){
			cin>>v;
			to[i].push_back(v);
			d[v]++;
		}
	}
	for(long long i=1;i<=m;i++)
		tps.push(i);
	while(!tps.empty()){
		long long pr=tps.front();
		tps.pop();
		for(long long i=0;i<to[pr].size();i++){
			long long ne=to[pr][i];
			add(ans1[ne],ans2[ne],ans1[pr],ans2[pr]*to[pr].size());
			d[ne]--;
			if(d[ne]==0)tps.push(ne);
		}
	}
	for(long long i=0;i<ans.size();i++)
		cout<<ans1[ans[i]]<<" "<<ans2[ans[i]]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
