#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define D(i,r,l) for(int i=(r);i>=(l);--i)
#define FF(i,ST,ED,DEL) for(int i=(ST);i!=(ED);DEL)
#define Tra(i,u) FF(i,G.st(u),-1,i=G.nx(i))
#define MEM(x,a) memset(x,a,sizeof(x))
#define int long long
#define N 200005

namespace Flandre_Scarlet
{
	class Graph
	{
	public:
		int head[N];
		struct Edge{int v,nx;} E[N*30]; int ecnt;
		void AddEdge(int u,int v) 
		{
			++ecnt; E[ecnt]=(Edge){v,head[u]}; head[u]=ecnt;
		}
		void Add2(int u,int v) 
		{
			AddEdge(u,v); AddEdge(v,u);
		}
		int st(int u) 
		{
			return head[u];
		}
		int nx(int i)
		{
			return E[i].nx;	
		}	
		int to(int i)
		{
			return E[i].v;
		}
		
		void clear()
		{
			MEM(head,-1); MEM(E,-1); ecnt=-1;
		}
		Graph() {clear();}
	}G;

	int n,m;
	inline void Input()
	{
		scanf("%lld%lld",&n,&m);
		G.clear();
		F(i,1,n)
		{
			int c; scanf("%lld",&c);
			F(j,1,c)
			{
				int v; scanf("%lld",&v);
				G.AddEdge(i,v);
			}
		}
	}
	
	inline int gcd(int a,int b)
	{
		while(b) swap(a,b),b%=a;
		return a;
	}
	struct frac
	{
		int u,d;
		frac() 
		{
			u=0; d=1;
		}
		frac(int uu,int dd)
		{
			u=uu; d=dd;
		}
		inline void f()
		{
			int g=gcd(u,d); u/=g; d/=g;
		}
	};
	frac operator+(frac a,frac b) 
	{
		frac ans; 
		ans.d=a.d*b.d; ans.u=a.u*b.d+a.d*b.u;
		ans.f();
		return ans;
	}
	
	frac val[N];
	int ideg[N],odeg[N];
	queue<int> Q;
	void TopoSort()
	{
		F(u,1,n) Tra(i,u)
		{
			int v=G.to(i);
			++ideg[v]; ++odeg[u];
		}
		
		F(i,1,n) if (!ideg[i]) 
		{
			Q.push(i); val[i]=(frac){1,1};
		}
			
		while(!Q.empty())
		{
			int u=Q.front(); Q.pop();
			if (!odeg[u]) continue;
			frac nx=val[u]; nx.d*=odeg[u]; nx.f();
			
//			printf("u=%lld nx=%lld/%lld\n",u,nx.u,nx.d);
			
			Tra(i,u)
			{
//				printf(" i=%lld\n",i);
				int v=G.to(i);
//				printf(" v=%lld\n",v);
				
				--ideg[v]; val[v]=val[v]+nx;
				if (!ideg[v]) Q.push(v);
			}
		}
	}
	inline void Solve()
	{
		TopoSort();
		F(i,1,n) if (!odeg[i]) printf("%lld %lld\n",val[i].u,val[i].d);
	}

	inline void Main()
	{
		Input();
		Solve();
	}
}
#undef int
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Flandre_Scarlet::Main();
	return 0;
}


