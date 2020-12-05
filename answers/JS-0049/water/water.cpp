#include<bits/stdc++.h>

using namespace std;

template <class T>
inline void read(T &n)
{
	n=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	n*=f;
}

const int N=100010,M=6;

int n,m;
int e[N][M];
bool st[N];
int outp[N],outq[N];

int gcd(int x,int y)
{
	if(x>y)
		swap(x,y);
	if(x==0)
		return y;
	return gcd(x,y%x);
}

int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}

void pl(int t,int plp,int plq)
{
	int op=outp[t],oq=outq[t];
	if(op==0)
	{
		int g=gcd(plp,plq);
		outp[t]=plp/g;
		outq[t]=plq/g;
		return;
	}
	int g=gcd(oq,plq);
//	cout<<g<<endl;
	outq[t]=oq/g*plq;
	outp[t]=plq/g*op+oq/g*plp;
	g=gcd(outp[t],outq[t]);
	outq[t]/=g;
	outp[t]/=g;
}

void doit(int t,int inp,int inq)
{
	if(e[t][0]==0)
	{
//		cout<<t<<" "<<inp<<" "<<inq<<endl;
		pl(t,inp,inq);
//		cout<<outp[t]<<" "<<outq[t]<<endl;
		return;
	}
	for(int i=1;i<=e[t][0];++i)
	{
//		cout<<t<<" "<<i<<" "<<e[t][i]<<endl;
		doit(e[t][i],inp,inq*e[t][0]);
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		read(e[i][0]);
		for(int j=1;j<=e[i][0];++j)
		{
			read(e[i][j]);
			st[e[i][j]]=1;
		}
	}
	
	int x=1;
	for(int T=1;T<=m;++T)
	{
		while(st[x])
			++x;
		doit(x,1,1);
//		cout<<x<<endl;
		++x;
	}
	
//	int cnt=0;
//	for(int i=1;i<=n;++i)
//		if(!st[i])
//			cout<<i<<" ";
//	cout<<endl;
	
	for(int i=1;i<=n;++i)
		if(e[i][0]==0)
			printf("%d %d\n",outp[i],outq[i]);
	
	return 0;
}
