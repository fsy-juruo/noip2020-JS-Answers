#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define Forn(i, n) for(int i=1; i<=(n); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define foreach(it, a) for((__typeof)(a.begin()) it=a.begin(); it!=a.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;

const int MOD=1e9+7;
const int MAX=5e5+5;

int N, K, wi[15], wd[MAX], dir[MAX], ttp[15], mn[15], mx[15];

int solve1(int id)
{
	int tl1=-mn[1];
	int ret1=tl1/ttp[1];
	int tmp=id;
	id+=ret1*ttp[1];
	Forn(i, N) if(id+dir[i]>wi[1]||id+dir[i]<=0)
	{
		ret1++;
		break;
	}
	else ret1++;
	int tl2=wi[1]-mx[1];
	id=tmp;
	int ret2=tl2/ttp[1];Forn(i, N) if(id+dir[i]>wi[1]||id+dir[i]<=0)
	{
		ret1++;
		break;
	}
	else ret1++;
	return min(ret1, ret2);
}


int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &N, &K);
	Forn(i, K) scanf("%d", &wi[i]), mn[i]=2e5, mx[i]=-2e5;
	Forn(i, N) 
	{
		scanf("%d%d", &wd[i], &dir[i]);
		ttp[wd[i]]+=dir[i];
		mn[wd[i]]=min(mn[wd[i]], ttp[wd[i]]);
		mx[wd[i]]=max(mx[wd[i]], ttp[wd[i]]);
	}
	int chk=0;
	Forn(i, K) chk |=ttp[i];
	if(!chk)
	{
		puts("-1");
		exit(0);
	}
	Forn(i, K) 
	{
		if(mn[i]==2e5) mn[i]=0;
		if(mx[i]==-2e5) mx[i]=0;
	}
	if(K==1)
	{
		int tot=0;
		Forn(i, wi[1])
		tot+=solve1(i);
		tot%=MOD;
		printf("%d\n", tot);
	}
	return 0;
}
