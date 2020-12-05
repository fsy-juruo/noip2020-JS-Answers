#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define ms memset
#define LD long double
#define STOP system("pause")

template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template <typename T> inline void write(T x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
LL n,m;
vector <LL> e[100010];
LL gcd(LL a,LL b){
	if (b==0) return a;
	return gcd(b,a%b);
}
LL ans1[100010],ans2[100010],in[100010];
queue <LL> q;
void yf(LL x){
	LL k=gcd(ans1[x],ans2[x]);
	ans1[x]/=k;
	ans2[x]/=k;
}
void add(LL a,LL b,LL x){
	if (ans1[x]==0){
		ans1[x]=a;
		ans2[x]=b;
		return;
	}
	LL k=b*ans2[x];
	ans1[x]=a*ans2[x]+ans1[x]*b;
	ans2[x]=k;
	yf(x);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n); read(m);
	for (LL i=1;i<=n;i++){
		LL k,x;
		read(k);
		for (LL j=1;j<=k;j++){
			read(x); e[i].push_back(x);
			in[x]++;
		}
	}
	for (LL i=1;i<=n;i++){
		if (in[i]==0) ans1[i]=ans2[i]=1,q.push(i);
	}
	while (q.size()){
		LL x=q.front(); q.pop();
		if (e[x].size()==0) continue;
		LL a=ans1[x],b=ans2[x];
		b*=(LL)e[x].size();
		ans1[x]=0; ans2[x]=0;
		for (LL i=0;i<e[x].size();i++){
			LL y=e[x][i];
			in[y]--;
			if (in[y]==0) q.push(y);
			add(a,b,y);
		}
	}
	for (LL i=1;i<=n;i++){
		if (ans1[i]){
			yf(i);
			write(ans1[i]),putchar(' '),writeln(ans2[i]);
		}
	}
	return 0;
}

