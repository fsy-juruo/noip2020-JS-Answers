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

char R_C; int R_POS;
inline int read(char s[])
{
	R_C='!'; R_POS=0;
	while(R_C<'a' || R_C>'z')
	{
		R_C=getchar();
	}
	while(R_C>='a' && R_C<='z')
	{
		s[R_POS++]=R_C;
		R_C=getchar();
	}
	return R_POS;
}

const int maxn=3000000;

bool usp[maxn];
signed P[maxn],pcnt;

void init_p()
{
	usp[1]=true;
	for(int i=2;i<maxn;i++)
	{
		if(!usp[i]) P[++pcnt]=i;
		for(int j=1;j<=pcnt && i*P[j]<maxn;j++)
		{
			usp[i*P[j]]=true;
			if(i%P[j]==0) break;
		}
	}
}

struct SegTree
{
	int dat[maxn<<2];
	int tag[maxn<<2];
	
	inline void pushup(int o)
	{
		dat[o]=dat[o<<1]+dat[o<<1|1];
	}
	
	inline void pushdown(int o,int l,int r)
	{
		int mid=(l+r)>>1;
		dat[o<<1]+=tag[o]*(mid-l+1);
		dat[o<<1|1]+=tag[o]*(r-mid);
		tag[o<<1]+=tag[o];
		tag[o<<1|1]+=tag[o];
		
		tag[o]=0;
	}
	
	void build(int o,int l,int r)
	{
		tag[o]=0;
		if(l==r)
		{
			dat[o]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		pushup(o);
	}
	
	int query(int o,int l,int r,int ql,int qr)
	{
		if(ql>qr) return 0;
		if(l==r)
		{
			return dat[o];
		}
		pushdown(o,l,r);
		if(ql<=l && r<=qr)
		{
			return dat[o];
		}
		int mid=(l+r)>>1,res=0;
		if(ql<=mid)
		{
			res+=query(o<<1,l,mid,ql,qr);
		}
		if(mid+1<=qr)
		{
			res+=query(o<<1|1,mid+1,r,ql,qr);
		}
		return res;
	}
	
	void update(int o,int l,int r,int ul,int ur,int v)
	{
		if(l==r)
		{
			dat[o]+=v;
			return;
		}
		pushdown(o,l,r);
		if(ul<=l && r<=ur)
		{
			dat[o]+=(r-l+1)*v;
			tag[o]+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(ul<=mid)
		{
			update(o<<1,l,mid,ul,ur,v);
		}
		if(mid+1<=ur)
		{
			update(o<<1|1,mid+1,r,ul,ur,v);
		}
		pushup(o);
	}
};

const int mod=2004120647;
const int mul=23459;
const int add=1926;

//const int mul=100;
//const int add=1;

int mulP[1100000];
SegTree t;

int N;
char s[1100000];
int H[1100000];
int oc[28];
int Fa[1100000],Fc[1100000];
int ans[1100000],ans1[1100000],ans2[1100000];

inline void init_h()
{
	for(int i=0;i<N;i++)
	{
		if(i)H[i]=(H[i-1]*mul+s[i]-'a'+add)%mod;
		else H[i]=(           s[i]-'a'+add)%mod;
	}
	mulP[0]=1;
	for(int i=1;i<=N;i++)
	{
		mulP[i]=mulP[i-1]*mul%mod;
	}
}

inline bool eq(int l1,int r1,int l2,int r2)
{
	if(r1-l1!=r2-l2) return false;
	if(l1>l2) swap(l1,l2),swap(r1,r2);
	int v1=H[r1];
	if(l1) v1=(v1-H[l1-1]*mulP[r1-l1+1]%mod+mod)%mod;
	int v2=H[r2];
	if(l2) v2=(v2-H[l2-1]*mulP[r2-l2+1]%mod+mod)%mod;
	return (v1==v2);
}

inline void solve()
{
//	cout<<"Solving : "<<N<<" "; for(int i=0;i<N;i++) cout<<s[i];cout<<endl;
	
	int L=N;
	while(L&(L-1)) ++L;
	init_h();
	t.build(1,1,L);
	memset(Fa,0,sizeof(Fa));
	memset(Fc,0,sizeof(Fc));
	memset(ans,0,sizeof(ans));
	memset(ans1,0,sizeof(ans1));
	memset(ans2,0,sizeof(ans2));
	
	memset(oc,0,sizeof(oc));
	for(int i=0;i<N;i++)
	{
		oc[s[i]-'a']++;
		for(int j=0;j<26;j++)
		{
			if(oc[j]&1) Fa[i]++;
		}
	}
	memset(oc,0,sizeof(oc));
	for(int i=N-1;i>=0;i--)
	{
		oc[s[i]-'a']++;
		for(int j=0;j<26;j++)
		{
			if(oc[j]&1) Fc[i]++;
		}
	}
	
//	cout<<"BruteForce: ";
//	for(int i=2;i<N;i++)
//	{
//		int tmp=0;
//		for(int j=2;j<=i;j++) if(i%j==0)
//		{
//			bool ok=true;
//			for(int k=j;k+j-1<i;k+=j)
//			{
//				ok&=eq(0,j-1,k,k+j-1);
//			}
//			if(!ok) continue;
//			for(int k=0;k+1<j;k++)
//			{
//				if(Fa[k]<=Fc[i]) tmp++;
//			}
//		}
//		cout<<tmp<<" ";
//	}
//	cout<<endl;
	
	for(int i=2;i<N;i++)
	{
		t.update(1,1,L,Fa[i-2]+2,Fa[i-2]+2,1);
		ans[i]=ans1[i]=t.query(1,1,L,0+2,Fc[i]+2);
		if((i<<1)<N) ans2[i]+=t.query(1,1,L,0+2,Fc[i<<1]+2);
	}

	for(int i=1;i<=N;i++)
	{
		for(int j=i;j+i<N;j+=i)
		{
			if(eq(j,j+i-1,0,i-1))
			{
				if((j/i)&1) ans[j+i]+=ans2[i];
				else ans[j+i]+=ans1[i];
			}
			else break;
		}
	}
	
//	for(int i=0;i<N;i++) cout<<ans[i]<<" "; cout<<endl;
//	for(int i=0;i<N;i++) cout<<P[i]<<"="<<ans1[i]<<" "; cout<<endl;
//	for(int i=0;i<N;i++) cout<<P[i]<<"="<<ans2[i]<<" "; cout<<endl;
	
	int rans=0;
	for(int i=2;i<N;i++)
	{
		rans+=ans[i];
	}
	printf("%lld\n",rans);
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	init_p();
	
	signed T; scanf("%d",&T);
	while(T--)
	{
		N=read(s);
		solve();
	}
	
	return 0;
}











