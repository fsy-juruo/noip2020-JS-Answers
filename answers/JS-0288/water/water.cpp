#include<bits/stdc++.h>
using namespace std;
long long n,m,tot,top,u,v,fz,fm,js,d,num;
long long head[100100],b[100100],cu[100100],ru[100100],c[100100];
struct node1{
	int v,pre;
}edge[500500];
struct node2{
	long long fz,fm;
}a[100100];
int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
//priority_queue
inline void add(int x,int y){
	edge[++tot].v=y;edge[tot].pre=head[x];head[x]=tot;
}
long long gcd(long long x,long long y){
	long long r;
	if (x<y) swap(x,y);
	if (y==0) return x;
	while (x%y!=0){
		r=x%y;
		x=y;
		y=r;
	}
	return y;
}
long long lcm(long long x,long long y){
	return (x*y/gcd(x,y));
}
void torpu(){
	int x,y,l,r;
	for (int i=1;i<=m;i++){
		c[i]=i;
	}
	l=1;r=m;
	while (l<=r){
		x=c[l];
		for (int k=head[x];k;k=edge[k].pre){
			y=edge[k].v;
			ru[y]--;
			if (ru[y]==0){
				c[++r]=y;
			}
		}
		l++;
	}
	num=r;
}
void bfs(){
	int x,y;
	for (int i=1;i<=n;i++){
		a[i].fz=0;a[i].fm=0;
	}
	for (int i=1;i<=m;i++){
		a[i].fz=1;a[i].fm=1;
	}
	for (int i=1;i<=num;i++){
		x=c[i];
		if (cu[x]==0) continue;
		fz=a[x].fz;fm=a[x].fm*cu[x];
		for (int k=head[x];k;k=edge[k].pre){
			y=edge[k].v;
			if (a[y].fz==0){
				a[y].fz=fz;a[y].fm=fm;
			}
			else {
				js=lcm(fm,a[y].fm);
				a[y].fz=(js/fm*fz)+(js/a[y].fm*a[y].fz);
				a[y].fm=js;
				js=gcd(a[y].fm,a[y].fz);
				a[y].fz/=js;
				a[y].fm/=js;
			}
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	tot=0;top=0;
	for (int i=1;i<=n;i++){
		head[i]=0;ru[i]=0;
	}
	for (int i=1;i<=n;i++){
		d=read();cu[i]=d;
		if (d==0){
			b[++top]=i;
		}
		for (int j=1;j<=d;j++){
			v=read();ru[v]++;
			add(i,v);
		}
	}
	torpu();
	bfs();
	for (int i=1;i<=top;i++){
		js=gcd(a[b[i]].fm,a[b[i]].fz);
		a[b[i]].fz/=js;
		a[b[i]].fm/=js;
		printf("%lld %lld\n",a[b[i]].fz,a[b[i]].fm);
	}
	return 0;
}
//npq RP++;

