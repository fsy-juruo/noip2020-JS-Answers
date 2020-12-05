#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> graph[100002];
vector<int> rgraph[100002];
vector<int> des;
int ind[100002]={0};
bool used[100002]={0};
deque<int> q;
inline long long gcd(long long x,long long y){
	if(y==0) return x;
	return gcd(y,x%y);
}
struct frac{
	long long x,y;
	void plusplus(frac xx){
		long long yyy=gcd(y,xx.y);
		frac ret;
		ret.y=y*xx.y/yyy;
		ret.x=xx.y/yyy*x+y/yyy*xx.x;
		long long gg=gcd(ret.x,ret.y);
		ret.x/=gg;
		ret.y/=gg;
		x=ret.x;
		y=ret.y;
	}
};
frac water[100002];

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x==0) des.push_back(i);
		while(x--){
			int y;
			scanf("%d",&y);
			graph[i].push_back(y);
			rgraph[y].push_back(i);
			ind[y]++;
		}
	}
	sort(des.begin(),des.end());
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push_back(i);
			water[i].x=1;
			water[i].y=1;
		}
		else{
			water[i].x=0;
			water[i].y=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		if(used[x]){
			q.pop_front();
			continue;
		}
		used[x]=true;
		if(graph[x].size()==0) continue;
		bool flag=false;
		for(int i=0;i<(int)rgraph[x].size();i++){
			int p=rgraph[x][i];
			if(!used[p]){
				used[x]=false;
				q.push_front(p);
				flag=true;
			}
		}
		if(!flag) q.pop_front();
		else continue;
		frac toplus;
		toplus.x=water[x].x;
		toplus.y=water[x].y*(int)graph[x].size();
		for(int i=0;i<(int)graph[x].size();i++){
			int y=graph[x][i];
			water[y].plusplus(toplus);
			q.push_back(y);
		}
	}
	for(int i=0;i<(int)des.size();i++){
		long long gg=gcd(water[des[i]].x,water[des[i]].y);
		printf("%lld %lld\n",water[des[i]].x/gg,water[des[i]].y/gg);
	}
}

