#include <cstdio>
#include <vector>

using std::vector;

int const N = 1e5+5;

int n,m;

long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

struct fen{
	long long up,down;

	void yuefen(){
		int t = gcd(up,down);
		up /= t;
		down /= t;
	}
	
	void operator += (fen b){
		int lcm = (down * b.down) / gcd(down,b.down);
		up *= lcm / down;
		down = lcm;
		up += b.up * (lcm / b.down);
		yuefen();
	}

	void operator *= (long long t){
		up *= t;
		yuefen();
	}

	void operator /= (long long t){
		down *= t;
		yuefen();
	}
	
	void oup(){
		printf("%lld %lld\n",up,down);
	}
};

vector<int> T[N];
vector<int> dT[N];

typedef vector<int>::iterator it;

bool vis[N];
fen mem[N];

int ind[N];
int oud[N];

int pour[N];
int cnt;

fen dfs(int i){
	fen ans = (fen){0,1};
	if(vis[i]) return mem[i];

	if(!ind[i]){
		if(i <= m)
			return (fen){1,oud[i]};
		else
			return ans;
	}

	for(it j = dT[i].begin();j != dT[i].end();++j){
		ans += dfs(*j);
	}

	if(oud[i]) ans /= oud[i];
	
	mem[i]=ans;
	vis[i]=1;

	return ans;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);

	for(int i = 1;i <= n;++i){
		int di;
		int a;
		scanf("%d",&di);
		oud[i]=di;
		if(!di) pour[cnt++]=i;
		while(di--){
			scanf("%d",&a);
			T[i].push_back(a);
			++ind[a];
			dT[a].push_back(i);
		}
	}
	
	for(int i = 0;i < cnt;++i){
		dfs(pour[i]).oup();
	}

	return 0;
}
