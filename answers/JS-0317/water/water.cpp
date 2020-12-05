#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(x%y==0)
	return y;
	else
	return gcd(y,x%y);
}
pair<int ,int>w[100005];
vector<int>v[100005];
int cnt[100005],d[100005];
vector<int>End;
queue<int>Q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=0;j<d[i];j++){
			int t;
			scanf("%d",&t);
			v[i].push_back(t);
			cnt[t]++;
		}
		if(d[i]==0){
			End.push_back(i);
			}
		w[i].first=0;
		w[i].second=max(1,d[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0)
		{
		Q.push(i);
		w[i].first=1;
		w[i].second=1;
		}
	}
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		if(d[tmp])
			w[tmp].second*=d[tmp];
		for(int i=0;i<v[tmp].size();i++){
			cnt[v[tmp][i]]--;
			int p=w[v[tmp][i]].first;
			int q=w[v[tmp][i]].second;
			int t1=gcd(q,w[tmp].second);
			p=w[tmp].second/t1*p+q/t1*w[tmp].first;
			q=q/t1*w[tmp].second;
			int t=gcd(p,q);
			p/=t;
			q/=t;
			w[v[tmp][i]].first=p;
			w[v[tmp][i]].second=q;
			if(cnt[v[tmp][i]]==0){
				Q.push(v[tmp][i]);
			}
		}
	}
	for(int i=0;i<End.size();i++)
	{
		
		printf("%d %d\n",w[End[i]].first,w[End[i]].second);
	}
}	
