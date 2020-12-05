#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
template <typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template <typename T>inline void write(T x){
	ull y=0;ull t=x;int l=0;
	if(x<0){putchar('-');x++;t=-x;t++;}
	if(!t){putchar('0');return;}
	while(t){y=y*10+t%10;t/=10;l++;}
	while(l){putchar(y%10+'0');y/=10;l--;}
}
template <typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template <typename T>inline void writeln(T x){
	write(x);
	puts("");
}
const int MAXN=1e5+10;
ll d[MAXN],a[MAXN],b[MAXN],r[MAXN];
vector<int> son[MAXN];
queue<int> q;
void plu(ll x,ll y,ll wz){
	x*=b[wz];
	a[wz]*=y;
	b[wz]*=y;
	a[wz]+=x;
}
ll zdgys(ll x,ll y){
	if(y==0)return x;
	return zdgys(y,x%y);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,x,to;
	read(n);read(m);
	for(int i=1;i<=n;i++){
		b[i]=1;
	}
	for(int i=1;i<=m;i++){
		a[i]=1;
		q.push(i);
	}
	for(int i=1;i<=n;i++){
		read(d[i]);
		for(int j=1;j<=d[i];j++){
			read(x);
			r[x]++;
			son[i].pb(x);
		}
	}
	ll xx;
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=0;i<d[x];i++){
			to=son[x][i];
			r[to]--;
			if(r[to]==0)q.push(to);
			plu(a[x],b[x]*d[x],to);
			xx=zdgys(a[to],b[to]);
			a[to]/=xx;
			b[to]/=xx;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			xx=zdgys(a[i],b[i]);
			a[i]/=xx;
			b[i]/=xx;
			writes(a[i]);
			writeln(b[i]);
		}
	}
	return 0;
}




