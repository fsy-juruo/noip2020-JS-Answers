#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >mp;
int n,k,a,b;
int now[15],tmp[15],ans,maxn[15];
void dfs(int floor){
	if(floor==k){
		for(int i=0;i<k;i++){
			tmp[i]=now[i];
		}
		int i=0;
		while(true){
			tmp[mp[i%n].first]+=mp[i%n].second;
			if(tmp[mp[i%n].first]<1||tmp[mp[i%n].first]>maxn[mp[i%n].first]){
				i++;break;
			}
			i++;
		}
		ans+=i;
		return ;
	}
	for(int i=1;i<=k;i++){
		now[floor]=i;
		dfs(floor+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d",&maxn[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		mp.push_back(make_pair(a-1,b));
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}

