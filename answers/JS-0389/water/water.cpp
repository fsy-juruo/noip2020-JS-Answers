#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int N=1e5+10;

int n,m;
int d[N];
vector<int> gv[N];
vector<int> out;
queue<int> q;
int in[N];

ull gcd(ull x,ull y){if (!y)return x;return gcd(y,x%y);}

class frac{
public:
	ull p,q;
	void minify(){
		ll tmp=gcd(p,q);
		p/=tmp;q/=tmp;
	}
	void print(){
		printf("%llu %llu\n",p,q);
	}
}ans[N];

frac add(frac x,frac y){
	frac ret;
	ret.q=x.q*y.q;
//	cerr<<ret.q<<' '<<x.q<<' '<<y.q<<endl;
	ret.p=x.q*y.p+x.p*y.q;
	ret.minify();
	return ret;
}

frac div(frac x,ull y){
	frac ret;ret.p=x.p;ret.q=x.q*y;
	ret.minify();
	return ret;
}

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){ans[i].p=0;ans[i].q=1;}
	for (int i=1;i<=n;i++){
		d[i]=read();
		for (int j=1;j<=d[i];j++){
			int x=read();
			gv[i].push_back(x);
			in[x]++;
		}
		if (!d[i])out.push_back(i);
	}
	
	for (int i=1;i<=m;i++){q.push(i);ans[i].p=1;}
	
	while (!q.empty()){
		int u=q.front();q.pop();
		if (d[u]){
			ans[u]=div(ans[u],d[u]);
			for (int i=0;i<d[u];i++){
				int v=gv[u][i];
				ans[v]=add(ans[v],ans[u]);in[v]--;
				if (!in[v]){q.push(v);}
			}
		}
	}
	
	int sz=out.size();
	for (int i=0;i<sz;i++)ans[out[i]].print();
	
	return 0;
}

