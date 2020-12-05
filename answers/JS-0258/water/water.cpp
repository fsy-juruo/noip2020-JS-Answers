#include <bits/stdc++.h>
#define re register
#define SIZE 100005
#define LL long long
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
struct Edge
{
	int ver,Next;
}p[500005];
struct Node
{
	LL p,q;
}node[SIZE];
int tot=0,head[SIZE];
int n,m;
int In[SIZE],d[SIZE];
queue<int> q;
inline void add(int f,int s)
{
	++tot;
	p[tot].ver=s;
	p[tot].Next=head[f];
	head[f]=tot;
}
inline LL gcd(LL x,LL y)
{
	if(x==0)
		return y;
	return gcd(y%x,x);
}
inline Node TF(Node x,Node y)
{
	LL p1,q1,p2,q2,P,Q,s;
	Node ret;
	p1=x.p;q1=x.q;p2=y.p;q2=y.q;
	if(!p1)
		return y;
	if(!p2)
		return x;
	P=p1*q2+p2*q1;Q=q1*q2;
	s=gcd(P,Q);
	P/=s;Q/=s;
	ret.p=P;ret.q=Q;
	return ret;
}
inline void TP()
{
	for(re int i=1;i<=n;++i)
		if(!In[i])
			q.push(i),node[i].p=1,node[i].q=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(!d[now])
			continue;
		Node Add;
		Add.p=node[now].p;Add.q=node[now].q*d[now];
		int P=gcd(Add.p,Add.q);
		Add.p/=P;Add.q/=P;
		for(re int i=head[now];i!=0;i=p[i].Next)
		{
			int nex=p[i].ver;
			--In[nex];
			node[nex]=TF(node[nex],Add);
			if(!In[nex])
				q.push(nex);
		}
		node[now].p=0;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(re int i=1;i<=n;++i)
	{
		read(d[i]);
		for(re int j=1,x;j<=d[i];++j)
			read(x),add(i,x),++In[x];
	}
	TP();
	for(re int i=1;i<=n;++i)
		if(node[i].p)
			printf("%lld %lld\n",node[i].p,node[i].q);
	return 0;
}
