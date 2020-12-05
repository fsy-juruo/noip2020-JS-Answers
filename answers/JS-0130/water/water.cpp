#include <fstream>
#include <queue>
using namespace std;

ifstream cin("water.in");
ofstream cout("water.out");
long long gcd(long long a,long long b){
	if(a==0)return b;
	return gcd(b%a,a);
}
struct realnum{
	long long u,d;
	realnum():u(0),d(1){}
	realnum(long long num):u(num),d(1){}
	realnum(long long u,long long d):u(u),d(d){}
	realnum operator +(realnum& b){
		long long ansu=u*b.d+b.u*d;
		long long ansd=d*b.d;
		long long div=gcd(ansu,ansd);
		return realnum(ansu/div,ansd/div);
	}
};
const int MAXN=100000,MAXM=500000;
struct edge{
	int u,v,nex;
	//long long w;
}e[MAXN+5];
int head[MAXN+5],cnt;
int deg[MAXN+5],out[MAXN+5];
void add_e(int u,int v){
	cnt++;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int n,m;
int tb_li[MAXN+3],tb_cnt,d_begin;
realnum dp[MAXN+3];
void tobo(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			q.push(i);
			dp[i]=realnum(1,1);
		}
	}
	d_begin=q.size();
	while(!q.empty()){
		int u=q.front();
		q.pop();
		tb_li[tb_cnt++]=u;
		for(int i=head[u];i;i=e[i].nex){
			deg[e[i].v]--;
			if(deg[e[i].v]==0){
				q.push(e[i].v);
			}
		}
	}
	
}
int main(){
	//cout<<(realnum(2,6)+realnum(2,6)).d<<endl;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int d;
		cin>>d;
		out[i]=d;
		for(int j=0;j<d;j++){
			int v;
			cin>>v;
			add_e(i,v);
			deg[v]++;
		}
	}
	tobo();
	for(int i=0;i<tb_cnt;i++){
		int u=tb_li[i];
		if(out[u]==0)continue;
		realnum put_out=realnum(dp[u].u,dp[u].d*out[u]);
		for(int j=head[u];j;j=e[j].nex){
			dp[e[j].v]=dp[e[j].v]+put_out;
		}
	}
	realnum tmp=realnum(0,1);
	for(int i=1;i<=n;i++){
		if(out[i]==0){
			dp[i]=dp[i]+tmp;
			cout<<dp[i].u<<" "<<dp[i].d<<endl;
		}
	}
	return 0;
}

