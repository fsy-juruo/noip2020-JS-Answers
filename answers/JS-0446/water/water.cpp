#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	return x*f;
}
void write_q(long long x){
	if(x==0) return;
	write_q(x/10);putchar(x%10+48);
}
void write(long long x){
    if(x==0) {cout<<0;}
	else { if(x<0) {putchar('-');x=-x;write_q(x);} else {write_q(x);} }
}
long long n,m,l,r,h,k;
long long d[100010],w[100010][10];
long long p[100010],q[100010],vis[100010],v[100010],qwq[100010];
long long gcd(long long a,long long b){
	if(a%b==0)	return b;
	return gcd(b,a%b);
}
long long gm(long long a,long long b){
	return a*b/gcd(a,b);
}
void fenjia(long long p,long long q,long long cp,long long cq){
	long long fenmu=gm(q,cq);
	long long fenzi=fenmu/q*p+fenmu/cq*cp;
	long long yue=gcd(fenmu,fenzi);
	h=fenzi/yue,k=fenmu/yue;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		d[i]=read();
		q[i]=1;
		for(int j=1;j<=d[i];j++){
			w[i][j]=read();
			v[w[i][j]]++;
		}	
	}
	l=1;r=m;
	for(int i=1;i<=m;i++){
		qwq[i]=i;
		p[i]=1;q[i]=1;
	}
	while(l<=r)
	{
		int cx=qwq[l];
	    l++;
		if(d[cx]==0) continue;
		long long cp=p[cx],cq=q[cx];
		long long e=gcd(d[cx],cp);
		cq=cq*d[cx]/e;cp=cp/e;
		for(int i=1;i<=d[cx];i++)
		{
			int y=w[cx][i];
			vis[y]++;
			fenjia(p[y],q[y],cp,cq);
			p[y]=h;q[y]=k;
			h=0,k=0;
			if(vis[y]==v[y]){
				if(d[y]==0) continue;
				r++;
				qwq[r]=y;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			write(p[i]);cout<<" ";write(q[i]);cout<<endl;
		}
		
	}
	return 0;
}
