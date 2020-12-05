#include<bits/stdc++.h>
using namespace std;
const int MAXN=101000;
struct AC{
	long long u;
	long long d;
}m[MAXN];
int s[MAXN],v[MAXN],a[MAXN][10],ou[MAXN],tot,n,f;
queue<int>q;
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1*f;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0';
	return f*x;
}
long long gcd(long long x,long long y){
	if(x==0)return y;
	if(x>y)swap(x,y); 
	return gcd(y%x,x);
}
long long lcm(long long x,long long y){return (x*y)/gcd(x,y);}
AC yuef(AC x){
	long long y=gcd(x.u,x.d);
	x.u/=y;
	x.d/=y;
	return x;
}
void prin(AC x){
	x=yuef(x);
	printf("%lld %lld\n",x.u,x.d);
}
void bfs(){
	while(q.size()){
		int x=q.front();q.pop();v[x]=0;
		if(s[x]==0)continue;
		AC y;
		y.u=m[x].u;
		y.d=m[x].d*s[x];
		for(int i=1;i<=s[x];i++){
			int k=a[x][i];AC z=m[k];
			if(m[k].u==0)m[k]=y;
			else{
				long long p=lcm(z.d,y.d);
				long long pz=p/z.d,py=p/y.d;
				z.u=z.u*pz+y.u*py;z.d=p;
				m[k]=yuef(z);
			}
			if(!v[k]){q.push(k);v[k]=1;}
		}
		m[x].u=0;
		m[x].d=0;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&f);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++)
		{
			scanf("%d",&a[i][j]);
			v[a[i][j]]=1;
		}
		if(s[i]==0)ou[++tot]=i;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			q.push(i);
			m[i].u=1;
			m[i].d=1;
			v[i]=1;
		}
		else v[i]=0;
	}
	bfs();
	for(int i=1;i<=tot;i++)
	prin(m[ou[i]]);
	return 0;
}

