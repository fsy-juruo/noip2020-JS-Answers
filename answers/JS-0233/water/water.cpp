#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<queue>
#define PLL pair<long long,long long>
#define mk make_pair
#define fr first
#define sc second
#define N 100100
#define ll long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
PLL val[N];
int head[N],to[2*N],nxt[2*N];
ll in[N],out[N],end[N];
int cnt,n,m,siz;
queue<int> q;
void init(){
	memset(head,-1,sizeof(head));
	cnt=-1;
}
void add_e(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	in[b]++;
}
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		out[i]=read();
		if(!out[i])end[++siz]=i;
		val[i].sc=1;
		for(int j=0;j<out[i];j++)add_e(i,read());
	}
	for(int i=1;i<=n;i++){
		if(!in[i])val[i].fr=1,q.push(i);
	}
	int cur;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(!out[cur])continue;
		val[cur].sc*=out[cur];
		for(int i=head[cur];~i;i=nxt[i]){
			int aft=to[i];
			ll up=val[cur].fr*val[aft].sc+val[cur].sc*val[aft].fr;
			ll down=val[cur].sc*val[aft].sc;
			ll g=gcd(up,down);
			val[aft].fr=up/g,val[aft].sc=down/g;
			if(--in[aft]==0)q.push(aft);
		}
	}
	for(int i=1;i<=siz;i++){
		printf("%lld %lld\n",val[end[i]].fr,val[end[i]].sc);
	}
	return 0;
}
