#include<bits/stdc++.h>
using namespace std;
inline int R(){
	int x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-48;
	return x*f;
}
int head[100010],co[100010],next[100010],val[100010],v[100010],b[100010];
bool f[100010];
int cnte=0,cntv=0,n,m;
struct fs{
	int x;
	long long p;
	long long q;
};
queue <fs> q;
fs l[100010];
void ad(int x,int y){
	co[++cnte]=y;
	next[cnte]=head[x];
	head[x]=cnte;
}
int gcd(int a,int b){
	int r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
long long gcd(long long a,long long b){
	long long r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
void lj(int x,long long p,long long q){
	if(l[x].q==0)l[x].q=1;
	long long s=gcd(max(l[x].q,q),min(l[x].q,q));
	l[x].p=l[x].p*(q/s)+p*(l[x].q/s);
	l[x].q=l[x].q*q/s;
}
void bfs(){
	while(!q.empty()){
		fs t=q.front();
		q.pop();
		int p=head[t.x];
		long long s=val[t.x];
		while(p!=0){
			v[co[p]]--;
			long long ss=gcd(max(s,t.p),min(s,t.p));
			lj(co[p],t.p/ss,t.q*s/ss);
			if(v[co[p]]==0)q.push((fs){co[p],l[co[p]].p,l[co[p]].q});
			p=next[p];
		}
	}
}
void ot(int x){
	long long s=gcd(max(l[x].p,l[x].q),min(l[x].p,l[x].q));
	cout<<l[x].p/s<<" "<<l[x].q/s<<endl;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	for(int i=1;i<=100000;i++)f[i]=true;
	n=R();
	m=R();
	for(int i=1;i<=n;i++){
		int x;
		x=R();
		val[i]=x;
		if(x==0){
			b[++cntv]=i;
		}
		for(int j=1;j<=x;j++){
			int y;
			y=R();
			ad(i,y);
			v[y]++;
			f[y]=false;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i])q.push((fs){i,1,1});
	}
	bfs();
	for(int i=1;i<=cntv;i++){
		ot(b[i]);
	}
	return 0;
}

