#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[100010],b[100010][110],c[100010];
bool f[100010],k[100010];
queue<unsigned long long> in;
vector<unsigned long long> p;
pair<unsigned long long,unsigned long long> ans[100010];
void yuefen(unsigned long long x){
	if (ans[x].first==0) return ;
	for (unsigned long long i=0;i<p.size();i++)
		while (ans[x].first%p[i]==0&&ans[x].second%p[i]==0){
			ans[x].first=ans[x].first/p[i];
			ans[x].second=ans[x].second/p[i];
		}
}
int main(){
	freopen("water3.in","r",stdin);
	freopen("water.out","w",stdout);
	for (unsigned long long i=2;i<=100000;i++)
		if (k[i]==0)
			for (unsigned long long j=i+i;j<=100000;j+=i)
				k[j]=1;
	for (unsigned long long i=2;i<=100000;i++) if (k[i]==0) p.push_back(i);
	cin>>n>>m;
	for (unsigned long long i=1;i<=n;i++){
		cin>>a[i];
		for (unsigned long long j=0;j<a[i];j++){
			cin>>b[i][j];
			c[b[i][j]]++;
		}
	}
	for (unsigned long long i=1;i<=n;i++){
		if (a[i]==0) f[i]=1;
		if (c[i]==0){
			in.push(i);
			ans[i].first=1;
			ans[i].second=1;
		}
	}
	while (!in.empty()){
		unsigned long long d=in.front();in.pop();
		if (f[d]==1) continue;
		unsigned long long x=ans[d].first,y=ans[d].second*a[d];
		if (x==0) continue;
		ans[d].first=ans[d].second=0;
		for (unsigned long long i=0;i<a[d];i++){
			in.push(b[d][i]);
			if (ans[b[d][i]].first==0){
				ans[b[d][i]].first=x;
				ans[b[d][i]].second=y;
			}
			else{
				ans[b[d][i]].first=x*ans[b[d][i]].second+y*ans[b[d][i]].first;
				ans[b[d][i]].second=y*ans[b[d][i]].second;
				yuefen(b[d][i]);
			}
		}
	}
	for (unsigned long long i=1;i<=n;i++) if (f[i]==1) cout<<ans[i].first<<' '<<ans[i].second<<endl;
	return 0;
}
