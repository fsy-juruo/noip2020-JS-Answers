#include<stdio.h>
#include<vector>
using namespace std;
long long maxy(long long a,long long b){
	if(a%b==0ll) return b;
	return maxy(b,a%b);
}
struct faction{
	long long up;
	long long down;
	void less(){
		int my=maxy(up,down);
		up/=my;down/=my;
	}
	void pout(){
		printf("%lld %lld\n",up,down);
		return ;
	}
	void add(faction b){
		if(down==0ll){
			up=b.up;
			down=b.down;
			return ;
		}
		long long u=b.down*up+b.up*down;
		long long d=down*b.down;
		up=u,down=d;
		less();
	}
};
long long in[100005],out[100005];
faction t[100005];
vector<int> G[100005];
void go(int i,faction each){
	if(out[i]==0ll) return ;
	each.down*=out[i];each.less();
	for(int j=0;j<G[i].size();j++){
		int v=G[i][j];
		t[v].add(each);
		go(v,each);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,fm=0;
	scanf("%d%d",&n,&m);
	if(m==0){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int dii,u;
		scanf("%d",&dii);
		out[i]=(long long)dii;
		for(int j=1;j<=dii;j++){
			scanf("%d",&u);
			in[u]++;
			G[i].push_back(u);
		}
	}
	int i=1;
	while(fm<m){
		if(in[i]==0ll){
			faction each;
			each.up=1ll;each.down=1ll;
			go(i,each);
			fm++;
		}
		i++;
	}
	for(int i=1;i<=n;i++){
		if(out[i]==0) t[i].pout();
	}
	return 0;
}
