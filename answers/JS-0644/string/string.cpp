#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define D(i,r,l) for(int i=(r);i>=(l);--i)
#define FF(i,ST,ED,DEL) for(int i=(ST);i!=(ED);DEL)
#define MEM(x,a) memset(x,a,sizeof(x))
#define N 1919810
#define int long long
#define base 100
#define mod 998244353
#define md2 1000000007
namespace Flandre_Scarlet
{
	char a[N]; int n;
	inline void Input()
	{
		scanf("%s",a+1); n=strlen(a+1);
	}
	
	class BIT
	{
	public:
		int tree[N];
		void clear() {MEM(tree,0);}
		void Add(int pos,int val)
		{
			++pos;
			for(int i=pos;i<=n;i+=(i&(-i))) tree[i]+=val;
		}	
		int  Query(int pos)
		{
			++pos;
			int ans=0;
			FF(i,pos,0,i-=(i&(-i))) ans+=tree[i];
			return ans;
		}
	}T;
	int pre_F[N],suf_F[N];
	int cnt[26],cur=0;
	
	struct hval
	{
		int h1,h2;
		hval(int a1,int a2) {h1=a1%mod; h2=a2%md2;}
		hval(int x) {h1=x%mod; h2=x%md2;}
		hval() {h1=h2=0;}
	};
	hval operator*(hval a,hval b)
	{
		return hval(a.h1*b.h1,a.h2*b.h2);
	}
	hval operator+(hval a,hval b)
	{
		return hval(a.h1+b.h1,a.h2+b.h2);
	}
	hval operator-(hval a,hval b)
	{
		return hval(a.h1-b.h1+mod,a.h2-b.h2+md2);
	}
	bool operator==(hval a,hval b)
	{
		return a.h1==b.h1 and a.h2==b.h2;
	}
	bool operator!=(hval a,hval b)
	{
		return !(a==b);
	}
	hval Add(hval a,char c) 
	{
		return a*base+(c-'a');
	}
	
	hval hs[N],bpw[N];
	void Init_Hash()
	{
		F(i,1,n) hs[i]=Add(hs[i-1],a[i]);
		bpw[0]=1; F(i,1,n) bpw[i]=bpw[i-1]*base;
	}
	hval rhash(int l,int r)
	{
		return hs[r]-hs[l-1]*bpw[r-l+1];
	}
	int  mx(int len)
	{
		hval fir=rhash(1,len);
		F(i,1,n/len)
		{
			int ll=(i-1)*len+1,rr=i*len;
			hval cur=rhash(ll,rr);
			
			if (cur!=fir) return i-1;
		}
		return n/len;
	}
	inline void Solve()
	{
		MEM(cnt,0); cur=0;
		F(i,1,n)
		{
			int c=a[i]-'a';
			
			cnt[c]++;
			if (cnt[c]&1) ++cur;
			else --cur;
			
			pre_F[i]=cur;
		}
		
		MEM(cnt,0); cur=0;
		D(i,n,1)
		{
			int c=a[i]-'a';
			
			cnt[c]++;
			if (cnt[c]&1) ++cur;
			else --cur;
			
			suf_F[i]=cur;
		}
		
//		F(i,1,n) printf("%lld ",pre_F[i]); puts("");
//		F(i,1,n) printf("%lld ",suf_F[i]); puts("");
		
		Init_Hash();
		int ans=0;
		F(len,1,n)
		{
			int lim=mx(len);
//			printf("len=%lld\n",len);
			
			int tmp[2];
			int p=lim*len+1;
			tmp[0]=suf_F[p];
			tmp[1]=suf_F[p-len];
			int cnt[2];
			cnt[0]=T.Query(tmp[0]);
			cnt[1]=T.Query(tmp[1]);
			
//			printf(" tmp=%lld,%lld\n",tmp[0],tmp[1]);
//			printf(" cnt=%lld,%lld\n",cnt[0],cnt[1]);
			
			int cur=0,aans=0;
			while(p>len)
			{
				if (p!=n+1) aans+=cnt[cur];
				p-=len; cur^=1;
			}
//			printf(" cur=%lld\n",aans);
			ans+=aans;
			
			T.Add(pre_F[len],1);
//			printf(" Add: %lld\n",pre_F[len]);
		}
		printf("%lld\n",ans);
	}
	
	void clear()
	{
		MEM(hs,0); MEM(bpw,0);
		T.clear();
	}
	inline void Main()
	{
		int t; scanf("%lld",&t);
		while(t-->0)
		{
			Input();
			Solve();
			clear();
		}
	}
}
#undef int // long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	Flandre_Scarlet::Main();
	return 0;
}


