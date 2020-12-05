#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long g(long long a,long long b){
	if(b==0) return a;
	return g(b,a%b);
}
struct fs{
	long long p;
	long long q;
	fs():p(0),q(1){}
	fs& operator = (fs b){
		p=b.p;q=b.q;
	}
	void fx(){
		long long l=g(p,q);
		p/=l;q/=l;
	}
};
fs ad(fs a,fs b){
	long long x=g(a.q,b.q);
	long long dq=a.q/x*b.q;
	long long dp=a.p*(dq/a.q)+b.p*(dq/b.q);
	fs l;l.p=dp;l.q=dq;
	return l;
}
fs ch(fs a,int b){
	long long l=g(a.p,b);
	a.p/=l;b/=l;
	a.q*=b;
	return a;
}
struct eg{
	int y;
	eg* nxt;
	eg():nxt(0){}
}*hd[MAXN];
void lk(int x,int y){
	eg *p=new eg;
	p->y=y;
	p->nxt=hd[x]->nxt;
	hd[x]->nxt=p;
}
int n,m,cd[MAXN];
bool fn[MAXN],stt[MAXN];
fs s[MAXN];
void f(int i)
{
	fs ls=ch(s[i],cd[i]);
	for(eg *h=hd[i]->nxt;h;h=h->nxt)
	{
		if(!fn[h->y]&&s[h->y].p!=0&&stt[h->y]==0)
		f(h->y);
		s[h->y]=ad(s[h->y],ls);
		s[h->y].fx();
		stt[h->y]=1;
	}
	s[i].p=0;s[i].q=1;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) hd[i]=new eg;
	for(int i=1;i<=n;++i){
		int k;scanf("%d",&k);
		cd[i]=k;
		if(k==0){
			fn[i]=1;
		}
		while(k--){
			int y;
			scanf("%d",&y);
			lk(i,y);
		}
	}
	for(int i=1;i<=m;++i) s[i].p=s[i].q=1;
	for(int k=1;k<=20;++k){
		memset(stt,0,sizeof(stt));
		for(int i=1;i<=n;++i)
		if(!fn[i]&&s[i].p!=0) f(i);
	}
	for(int i=1;i<=n;++i) if(fn[i])
	printf("%lld %lld\n",s[i].p,s[i].q);
	return 0;
}

