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

int N,M;
vi a[55];
int used[55],en[55];
vp ans;

inline void go(int x,int y,int t)
{
	ans.pb(mpr(x,y));
	for(int i=1;i<=t;i++)
	{
		a[y].pb(EN(a[x]));
		a[x].pop_back();
	}
}

inline void op()
{
//	cout<<"     ======================== "<<endl;
//	for(int t=1;t<=N+1;t++)
//	{
//		cout<<t<<" : ";
//		for(int l=0;l<a[t].size();l++)
//		{
//			cout<<a[t][l]<<" ";
//		}
//		cout<<endl;
//	}
}

inline void Swap(int i,int t,int j,int k)
{
	go(i,N+1,M-t);
	go(j,i,M-k);
	go(N+1,j,1); go(i,N+1,1);
	go(i,j,M-k-1);
	go(N+1,i,M-t);
}

void solve_simp()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++) if(j!=i) for(int k=0;k<M;k++) if(a[j][k]==i)
		{
			for(int t=0;t<M;t++)
			{
				if(a[i][t]!=i)
				{
					Swap(i,t,j,k);
					break;
				}
			}
//			op();
		}
	}
}

void solve_norm()
{
	for(int i=1;i<=N;i++)
	{
		int mincst=1145141919810ll,id=-1;
		for(int j=1;j<=N;j++) if(!used[j])
		{
			int cst=0;
			vi v; int pos=0;
			for(int l=0;l<M;l++) if(a[j][l]!=i)
			{
				v.pb(l);
			}
			for(int k=1;k<=N;k++) if(k!=j) for(int l=0;l<M;l++) if(a[k][l]==i)
			{
				cst+=M*4-v[pos]*2-l*2+1;
				pos++;
			}
			if(cst<mincst)
			{
				mincst=cst;
				id=j;
			}
		}
		used[id]=true;
		en[i]=id;
	}
	while(true)
	{
		bool fd=false;
		for(int i=1;i<=N;i++) for(int j=0;j<M;j++) if(en[a[i][j]]!=i)
		{
			for(int k=1;k<=N;k++) if(k!=i) for(int l=0;l<M;l++) if(en[a[k][l]]!=k)
			{
				if(en[a[i][j]]==k && en[a[k][l]]==i)
				{
					Swap(i,j,k,l);
					fd=true;
				}
			}
		}
		if(!fd) break;
	}
//	for(int i=1;i<=N;i++) cout<<en[i]<<" "; cout<<"...."<<endl;
	while(true)
	{
		bool fd=false;
		for(int j=M-1;j>=0;j--) for(int i=1;i<=N;i++) if(en[a[i][j]]!=i)
		{
			for(int l=0;l<M;l++) if(en[a[en[a[i][j]]][l]]!=en[a[i][j]])
			{
				fd=true;
				Swap(i,j,en[a[i][j]],l);
			}
		}
		if(!fd) break;
	}
//	op();
}

signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	N=read(),M=read();
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			int col=read();
			a[i].pb(col);
		}
	}
	if(N<=10 && M<=20)
	{
		solve_simp();
	}
	else
	{
		solve_norm();
	}
	cout<<SZ(ans)<<endl;
	for(int i=0;i<SZ(ans);i++)
	{
		printf("%lld %lld\n",ans[i].fs,ans[i].sc);
	}
	
	return 0;
}











