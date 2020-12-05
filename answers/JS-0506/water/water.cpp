#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll gcd(ll x,ll y){
	return !y?x:gcd(y,x%y);
}
struct number{
	ll a,b;
	void operator ~(){
		if(!a){b=1;return;}
		ll GCD=gcd(a,b);
		a/=GCD,b/=GCD;
	}
	number(){a=0,b=1;}
	number(int A,int B){a=A,b=B,~(*this);}
	friend number operator/(const number &x,const int &y){
		number z=number(x.a,x.b*y);
		~z;
		return z;
	}
	void operator +=(const number &x){
		a=a*x.b+x.a*b;
		b*=x.b;
		~(*this);
	}
	void print()const{
		printf("%lld %lld\n",a,b);
	}
}a[100100];
int head[100100],cnt,in[100100],sz[100100];
struct node{
	int to,next;
}edge[1000100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
queue<int>q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x),sz[i]=x;
		while(x--)scanf("%d",&y),ae(i,y),in[y]++;
	}
	for(int i=1;i<=m;i++)a[i]=number(1,1);
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=edge[i].next){
			a[edge[i].to]+=a[x]/sz[x];
			if(!--in[edge[i].to])q.push(edge[i].to);
		}
	}
	for(int i=1;i<=n;i++)if(!sz[i])a[i].print();
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
