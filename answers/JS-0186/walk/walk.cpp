#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mpr make_pair
#define pii pair<int,int>  /**/
#define fs first
#define sc second
#define vi vector<int>  /**/
#define vp vector<pii>  /**/
#define iter iterator
#define SZ(V) ((int)V.size())
#define EN(V) (V[SZ(V)-1])

template<typename T>
inline void cmax(T& x,T y)
{
	if(x<y) x=y;
}

template<typename T>
inline void cmin(T& x,T y)
{
	if(x>y) x=y;
}

char R_C; int R_RES; int R_F;
inline int read()
{
	R_C='!'; R_RES=0; R_F=0;
	while(R_C<'0' || R_C>'9')
	{
		R_C=getchar();
		if(R_C=='-') R_F=1;
	}
	while(R_C>='0' && R_C<='9')
	{
		R_RES=(R_RES<<1)+(R_RES<<3)+(R_C^48);
		R_C=getchar();
	}
	return R_F?(-R_RES):R_RES;
}

const int mod=1000000007;

int N,k;
int w[15];
vi rl;
int e[100010];
bool vis[1010];
int res[100010];
int c[100010],d[100010];
int Mx[100010][15],Mn[100010][15];

void DFS(int u)
{
	if(e[u]==-1) return;
	vis[u]=true;
	if(vis[e[u]])
	{
		cout<<"-1"<<endl;
		exit(0);
	}
	DFS(e[u]);
}

void DFS2(int u)
{
	if(res[u]!=-1) return;
	DFS2(e[u]);
	res[u]=res[e[u]]+N;
}

void solve_1()
{
	memset(e,-1,sizeof(e));
	vector<vi> vs;
	if(k==1)
	{
		for(int i=1;i<=w[0];i++)
		{
			vi v;
			v.pb(i);
			vs.pb(v);
		}
	}
	else if(k==2)
	{
		for(int i=1;i<=w[0];i++) for(int j=1;j<=w[1];j++)
		{
			vi v;
			v.pb(i);v.pb(j);
			vs.pb(v);
		}
	}
	else if(k==3)
	{
		for(int i=1;i<=w[0];i++) for(int j=1;j<=w[1];j++) for(int t=1;t<=w[2];t++)
		{
			vi v;
			v.pb(i);v.pb(j);v.pb(t);
			vs.pb(v);
		}
	}
	else if(k==4)
	{
		for(int i=1;i<=w[0];i++) for(int j=1;j<=w[1];j++) for(int t=1;t<=w[2];t++) for(int u=1;u<=w[3];u++) 
		{
			vi v;
			v.pb(i);v.pb(j);v.pb(t);v.pb(u);
			vs.pb(v);
		}
	}
	else if(k==5)
	{
		for(int i=1;i<=w[0];i++) for(int j=1;j<=w[1];j++) for(int t=1;t<=w[2];t++) for(int u=1;u<=w[3];u++) for(int s=1;s<=w[4];s++)
		{
			vi v;
			v.pb(i);v.pb(j);v.pb(t);v.pb(u);v.pb(s);
			vs.pb(v);
		}
	}
	for(int i=0;i<vs.size();i++)
	{
		vi cur=vs[i]; int t; bool f=false;
//		cout<<i<<" ==================== "<<endl;
		for(t=1;t<=N;t++)
		{
			cur[c[t]]+=d[t];
//			for(int j=0;j<k;j++) cout<<cur[j]<<" "; cout<<endl;
			if(cur[c[t]]<1 || cur[c[t]]>w[c[t]])
			{
				f=true;
				break;
			}
		}
		if(!f)
		{
//			cout<<"sp ="<<i<<endl;
			res[i]=-1;
			for(int j=0;j<vs.size();j++)
			{
				if(vs[j]==cur)
				{
					e[i]=j;
					break;
				}
			}
		}
		else
		{
			res[i]=t;
		}
//		vi nxtx=vs[i],nxtn[vs[i]];
//		for(int j=0;j<k;j++) nxtx[j]+=Mx[N][j],nxtn[j]+=Mn[N][j];
//		bool ok=true;
//		for(int j=0;j<k;j++)
//		{
//			if(nxtn[j]<1 || nxtx[j]>w[j]) ok=false;
//		}
//		if(ok)
//		{
//			for(int j=0;j<k;j++) cur[j]+=rl[j];
//		}
	}
	for(int i=0;i<vs.size();i++)
	{
		if(res[i]==-1)
		{
			memset(vis,0,sizeof(vis));
			DFS(i);
		}
	}
	for(int i=0;i<vs.size();i++)
	{
		if(res[i]==-1)
		{
			memset(vis,0,sizeof(vis));
			DFS2(i);
		}
	}
	int ans=0;
	for(int i=0;i<vs.size();i++)
	{
//		cout<<res[i]<<" ";
		ans+=res[i];
		ans%=mod;
	}//cout<<endl;
	cout<<ans<<endl;
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	N=read(),k=read();
	for(int i=0;i<k;i++) w[i]=read();
	vi cur(k,0);
	for(int i=1;i<=N;i++)
	{
		c[i]=read()-1; d[i]=read();
		cur[c[i]]+=d[i];
		for(int j=0;j<k;j++)
		{
			Mx[i][j]=max(Mx[i-1][j],cur[j]);
			Mn[i][j]=min(Mn[i-1][j],cur[j]);
		}
	}
	rl=cur;
	solve_1();
	
	
	return 0;
}











