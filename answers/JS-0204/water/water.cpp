#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
const int maxn=1e5+100;
int n,m;
int Head[maxn],Next[maxn*10],to[maxn*10],tot;
queue<int> q;
struct node{
	LL p,q,ru,chu;
}a[maxn];
LL gcd(LL x,LL y){
	if(y==0)return x;
	else return gcd(y,x%y);
}

void addnd(int u,int v){
	++tot;
	Next[tot]=Head[u];
	Head[u]=tot;
	to[tot]=v;
	a[v].ru++;
}

node add(node x,node y){
	LL p1=x.p;LL q1=x.q;LL p2=y.p;LL q2=y.q;
	node gt;
	gt.p=p1*q2+p2*q1;
	gt.q=q1*q2;
	LL yue=gcd(gt.p,gt.q);
	gt.p/=yue;
	gt.q/=yue;
	gt.ru=y.ru;
	gt.chu=y.chu;
	return gt;
}

void topsort(){
	int u,v;
	for(int i=1;i<=n;i++){
		if(a[i].ru==0)q.push(i);
	}
	while(!q.empty()){
		u=q.front();q.pop();
		node gt=a[u];
		if(a[u].chu==0)continue;
		gt.q*=a[u].chu;
		for(int i=Head[u];i;i=Next[i]){
			v=to[i];
			a[v]=add(gt,a[v]);
			a[v].ru--;
			if(a[v].ru==0)q.push(v); 
		}
	}
	return;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int u,v;
	read(n);read(m);
	for(int i=1;i<=m;i++){
		a[i].p=1;
		a[i].q=1;
	}
	for(int i=m+1;i<=n;i++){
		a[i].p=0;
		a[i].q=1;
	}
	for(u=1;u<=n;u++){
		read(a[u].chu);
		for(int i=1;i<=a[u].chu;i++){
			read(v);
			addnd(u,v); 
		}
	}
	topsort();
	for(int i=1;i<=n;i++){
		if(a[i].chu==0){
			LL yue=gcd(a[i].p,a[i].q);
			a[i].p/=yue;
			a[i].q/=yue;
			printf("%lld %lld\n",a[i].p,a[i].q);
		}
	}
	return 0;
}
