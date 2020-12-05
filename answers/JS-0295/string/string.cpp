#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define Forn(i, n) for(int i=1; i<=(n); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define foreach(it, a) for(__typeof((a).begin()) it=a.begin(); it!=a.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;

const int MAX=1048600;

int T, n, sum[MAX][26];
char s[MAX];

class Hash
{
	public:
		int dat[MAX], md[MAX], H, M;
		Hash(int _h, int _m):H(_h), M(_m){}
		void init()
		{
			md[0]=1;
			Forn(i, n)
			{
				md[i]=1LL*md[i-1]*H%M;
				dat[i]=(1LL*dat[i-1]*H+s[i]-'a'+1)%M;
//				cout<<dat[i]<<" ";
			}
//			puts("");
		}
		int query(int l, int r)//[l, r]
		{
			int ret=dat[r]-1LL*dat[l-1]*md[r-l+1]%M;
			ret%=M, ret=(ret+M)%M;
//			cout<<"query "<<dat[r]-dat[l-1]*md[r-l+1]<<" "<<ret<<endl;
			return ret;
		}
}H1(623, 1e9+7), H2(4451, 1e9+9);

int F(int l, int r)
{
	int ret=0;
	forn(i, 26) if((sum[r][i]-sum[l-1][i])&1)
		ret++;
	return ret;
}

int ft[MAX];
void solve1()
{
	H1.init(), H2.init();
	ll ans=0;
	Forn(i, n) ft[i]=F(1, i);
	for(int i=n; i>=3; i--)
	{
		int len=i-1;
		Forn(M, i-2)
		{
			if(H1.query(1, i-1-M)==H1.query(M+1, i-1)
			 &&H1.query(1, M)==H1.query(i-1-M+1, i-1)
		 	 &&H2.query(1, i-1-M)==H2.query(M+1, i-1)
			 &&H2.query(1, M)==H2.query(i-1-M+1, i-1))
			 {
		 		len=M;
		 		break;
			 }
		}
		int Fc=F(i, n), rep=(i-1)/len;
		for(int tim=1; tim*len<=i-1; tim++) if(rep%tim==0)
		{
			for(int np=1; np<=tim*len-1; np++)
				if(ft[np]<=Fc)
					ans++;
		}
//		printf("[1, %d]=%d %d\n", i-1, len, rep);
	}
	printf("%lld\n", ans);
}

void solve2()
{
	ll ans=0;
	for(int i=n; i>=3; i--)
	{
		int Fc=(n-i+1)%2, rep=(i-1);
		for(int tim=1; tim<=rep&&tim*tim<=rep; tim++) if(rep%tim==0)
		{
			if(rep/tim!=tim)
			{
				if(Fc==1) ans+=tim-1, ans+=rep/tim-1;
				else ans+=(tim-1)/2, ans+=(rep/tim-1)/2;	
			}
			else
			{
				if(Fc==1) ans+=tim-1;
				else ans+=(tim-1)/2;
			}
		}
	}
	printf("%lld\n", ans);
}

void solve3()
{
	H1.init(), H2.init();
	ll ans=0;
	Forn(i, n) ft[i]=F(1, i);
	for(int i=n; i>=3; i--)
	{
		int len=i-1;
		Forn(M, i-2)
		{
			if(H1.query(1, i-1-M)==H1.query(M+1, i-1)
			 &&H1.query(1, M)==H1.query(i-1-M+1, i-1)
		 	 &&H2.query(1, i-1-M)==H2.query(M+1, i-1)
			 &&H2.query(1, M)==H2.query(i-1-M+1, i-1))
			 {
		 		len=M;
		 		break;
			 }
		}
		int Fc=F(i, n), rep=(i-1)/len;
		for(int tim=1; tim*len<=i-1; tim++) if(rep%tim==0)
		{
			for(int np=1; np<=tim*len-1; np++)
				if(ft[np]<=Fc)
					ans++;
		}
//		printf("[1, %d]=%d %d\n", i-1, len, rep);
	}
	printf("%lld\n", ans);
}

int main()
{
//	cout<<(1<<20)<<endl;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	cout<<(1<<20)*26<<endl;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1);
		n=strlen(s+1);
		int apper=0;
		Forn(i, n)
		{
			int c=s[i]-'a';
			forn(j, 26)
				sum[i][j]=sum[i-1][j];
			sum[i][c]++;
			apper |=(1<<c);
		}
		if(n<=1000) solve1();
		else if(__builtin_popcount(n)==1)
			solve2();
		else solve3();
	}
	return 0; 
}
