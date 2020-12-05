#include<iostream>
#include<fstream>
using namespace std;
long long n,k;
long long ans;
const long long maxn= 1000000007;
long long ground[20],now[20],node[20];
long long c[1000010],d[1000010];

void move(){
	
	bool over = 0;
	for(long long i =0;i<k;i++){
		node[i] = now[i];
	}
	while(1){
		if(over)break;
		for(long long i = 0;i<n;i++){
			node[c[i]-1]+=d[i];
			ans++;
			if(ans == maxn)ans = 0;
			if(node[c[i]-1]<0||node[c[i]-1]>=ground[c[i]-1]){
				over = 1;
				break;
			}
		}
	}
}

void dfs(long long div){
	if(div == -1){move();return;}
	for(long long i = 0;i<ground[div];i++){
		now[div] = i;
		dfs(div-1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(long long i = 0;i<k;i++){
		cin>>ground[i];
	}
	for(long long i = 0;i<n;i++){
		cin>>c[i]>>d[i];
	}
	dfs(k-1);
	cout<<ans<<endl;
	return 0;
}
