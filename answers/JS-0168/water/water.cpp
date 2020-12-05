#include<bits/stdc++.h>
using namespace std;
const int SIZE=100005*3;
struct node{
	long long p,q;
	int data;
}a[SIZE];
int tot,TOT;
int n,m;
int inn[SIZE];
int out[SIZE];
long long p[SIZE],q[SIZE];
bool v[SIZE],vis[SIZE];
int ver1[SIZE],ver2[SIZE],first1[SIZE],first2[SIZE],Next1[SIZE],Next2[SIZE];
inline void add(int x,int y){
	ver1[++TOT]=y,Next1[TOT]=first1[x],first1[x]=TOT;
	ver2[TOT]=x,Next2[TOT]=first2[y],first2[y]=TOT;
}
inline bool cmp(node a,node b){
	return a.data<b.data;
}
inline long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
inline long long read(){
	long long x=0;int m=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') m=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*m;
}
void tp(int x){	
	if(vis[x]) return;
	vis[x]=1;
	for(int i=first2[x];i;i=Next2[i]){
			int y=ver2[i];
			if(p[x]==0||q[x]==0){			
				p[x]=p[y];
				q[x]=q[y]*out[y];
			}else{
				p[x]=p[x]*q[y]*out[y]+q[x]*p[y];
				q[x]=q[x]*q[y]*out[y];
			}
			long long d=gcd(p[x],q[x]);
			p[x]/=d,q[x]/=d;
	}
	if(v[x]){
		a[++tot].p=p[x],a[tot].q=q[x],a[tot].data=x;
	}
	for(int i=first1[x];i;i=Next1[i]){
		int y=ver1[i];
		inn[y]--;
		if(inn[y]==0) tp(y);
	}
	
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		out[i]=read();
		if(out[i]==0) v[i]=1;
		for(int j=1;j<=out[i];j++){
			int x=read();
			inn[x]++;
			add(i,x);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(inn[i]==0){
			p[i]=1,q[i]=1;
			tp(i);
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		printf("%lld %lld\n",a[i].p,a[i].q);
	}
	return 0;
}
