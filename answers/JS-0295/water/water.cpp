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

const int MAX=1e5+5;

class Fac
{
	public:
		ll a, b;
		Fac(ll _a=0, ll _b=1):a(_a), b(_b){}
		Fac operator +(const Fac&A)
		{
			ll n=__gcd(b, A.b);
			a*=A.b/n, a+=A.a*b/n, b*=A.b/n;
			ll t=__gcd(a, b);
			a/=t, b/=t;
			return *this;
		}
		Fac operator /(const int &d)
		{
			b*=d;
			ll n=__gcd(a, b);
			a/=n, b/=n;
			return *this;
		}
		void print()
		{
			printf("%lld %lld\n", a, b);
		}
}wat[MAX];

int N, M, d, t, ff[MAX], cnt, vis[MAX], ind[MAX], oud[MAX];
vi e[MAX];

void dfs(int id)
{
	vis[id]=1;
	foreach(it, e[id])
		if(!vis[*it])
			dfs(*it);
	ff[++cnt]=id;
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &N, &M);
	Forn(i, N)
	{
		scanf("%d", &d);
		oud[i]=d;
		while(d--)
		{
			scanf("%d", &t);
			e[i].pb(t);
			ind[t]++;
		}
		wat[i].a=0, wat[i].b=1;
	}
	Forn(i, N) 
	{
		if(!vis[i]) dfs(i);
		if(!ind[i]) wat[i].a=1;
	}
	for(int i=cnt; i>=1; i--) if(oud[ff[i]])
	{
		int npos=ff[i];
		wat[npos]=wat[npos]/e[npos].size();
		foreach(it, e[npos])
		{
			wat[*it]=wat[*it]+wat[npos];
		}
		wat[npos].a=0, wat[npos].b=1;
	}
	
	Forn(i, N) if(!oud[i])
		wat[i].print();
	return 0; 
}
