#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define D(i,r,l) for(int i=(r);i>=(l);--i)
#define FF(i,ST,ED,DEL) for(int i=(ST);i!=(ED);DEL)
#define MEM(x,a) memset(x,a,sizeof(x))
#define N 1000006
#define int long long
#define mod 1000000007
namespace Flandre_Scarlet
{
	inline void Init()
	{
	}
	
	int n,k,w[N];
	int pos[N],dt[N];
	struct vec
	{
		int d[12];
		vec() {MEM(d,0);}
		void input()
		{
			F(i,1,k) scanf("%d",&d[i]);
		}
		int& operator[](int id)
		{
			return *(d+id);
		}
	}v[N];
	bool operator<(vec a,vec b)
	{
		F(i,1,k) if (a[i]!=b[i]) return a[i]<b[i];
		return false;
	}
	vec operator+(vec a,vec b)
	{
		vec ans; F(i,1,k) ans[i]=a[i]+b[i]; return ans;
	}
	vec operator-(vec a,vec b)
	{
		vec ans; F(i,1,k) ans[i]=a[i]-b[i]; return ans;
	}
	vec operator*(vec a,int b)
	{
		vec ans; F(i,1,k) ans[i]=a[i]*b; return ans;
	}
	void up_mx(vec &a,vec b)
	{
		F(i,1,k) a[i]=max(a[i],b[i]);
	}
	
	inline void Input()
	{
		scanf("%lld%lld\n",&n,&k);
		F(i,1,k) scanf("%lld",&w[i]);
		F(i,1,n)
		{
			scanf("%lld%lld",&pos[i],&dt[i]);
			v[i][pos[i]]=dt[i];
		}
	}
	
	vec s[N],mx_a,mx_d;
	bool in(vec x)
	{
		F(i,1,k) if (x[i]<=0 or x[i]>w[i]) return false;
		return true;
	}
	bool cxk_inf()
	{
		vec S=s[n];
		F(i,1,k) if (S[i]!=0) return false;
		F(i,1,k) if (mx_a[i]>=w[i] or mx_d[i]>=w[i]) return false;
		return true; 
	}
	namespace Line // O(n+w)
	{
		int out[N];
		int rec[N];
		void Main()
		{
			F(i,1,n) // zou i-1 bu dao bian jie, zai zou yi bu chu qu
			{
				int D=s[i-1][1];
				if (dt[i]==-1)
				{
					int pos=1-D;
					if (1<=pos and pos<=w[1] and !out[pos]) 
					{
						out[pos]=i;
					}
				}
				else if (dt[i]==1)
				{
					int pos=w[1]-D;
					if (1<=pos and pos<=w[1] and !out[pos]) 
					{
						out[pos]=i;
					}
				}
			}
			int S=s[n][1];
			int ans=0;
			
			if (S<0)
			{
				F(i,1,w[1])
				{
					if (out[i]) ans+=out[i];
					else
					{
						int cur=i,step=0;
						while(!rec[cur] and !out[cur] and 1<=cur and cur<=w[1]) cur+=S,step+=n;
						if (1<=cur and cur<=w[1])
						{
							if (rec[cur]) step+=rec[cur];
							if (out[cur]) step+=out[cur];
						}
						rec[i]=step;
						ans+=step;
					}
				}
			}
			else
			{
				D(i,w[1],1)
				{
					if (out[i]) ans+=out[i];
					else
					{
						int cur=i,step=0;
						while(!rec[cur] and !out[cur] and 1<=cur and cur<=w[1]) cur+=S,step+=n;
						if (1<=cur and cur<=w[1])
						{
							if (rec[cur]) step+=rec[cur];
							if (out[cur]) step+=out[cur];
						}
						rec[i]=step;
						ans+=step;
					}
				}
			}
			
			printf("%lld\n",ans);
		}
	}
	namespace O_w_k // O(w^k*blablabla)
	{
		int ans=0;
		vec st;
		map<vec,int> rec;
		void DFS(int pp)
		{
			if (pp==k+1)
			{
				vec cur=st;
//				printf("cur: ");
//				F(i,1,k) printf("%lld ",cur[i]); puts("");
				int step=0;
				int p=1;
				while(in(cur))
				{
					cur[pos[p]]+=dt[p];
					
//					printf(" cur: ");
//					F(i,1,k) printf("%lld ",cur[i]); puts("");
					++step;
					++p;
					if (p==n+1) p=1;
					if (rec[cur]) 
					{
						step+=rec[cur];
						break;
					}
				}
//				printf("step=%lld\n",step);
				rec[st]=step;
				ans+=step;
				return;
			}
			else
			{
				F(i,1,w[pp])
				{
					st[pp]=i;
					DFS(pp+1);
				}
			}
		}
		void Main()
		{
			DFS(1);
			printf("%lld\n",ans);
			return;
		}
	}
	namespace Planar // k=2
	{
		void Main()
		{
			puts("i dont know");
		}
	}
	inline void Solve()
	{
		F(i,1,n) s[i]=s[i-1]+v[i],up_mx(mx_a,s[i]),up_mx(mx_d,s[i]*(-1));
		if (cxk_inf()) 
		{
			puts("-1");
			return;
		}
		
		int mxw=*max_element(w+1,w+k+1);
		if (k==1)
		{
			Line::Main();
		}
		else if ((mxw<=10 and k<=4 and n<=1000))
		{
			O_w_k::Main();
		}
		else if (k==2)
		{
			Planar::Main();
		}
	}

	inline void Main()
	{
		Init();
		Input();
		Solve();
	}
}
#undef int // long long
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	Flandre_Scarlet::Main();
	return 0;
}


