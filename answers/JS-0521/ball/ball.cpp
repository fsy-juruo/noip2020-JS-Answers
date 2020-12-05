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
int n,m,k,ans1[820010],ans2[820010];
int a[60][810],b[60][810],con[60];
map<string,bool>h;
int check(){
	int s=0;
	int c[410];
	for (int i=1;i<=n+1;i++){
		ms(c,0,sizeof(c));
		int mx=0;
		for (int j=1;j<=m;j++){
			c[b[i][j]]++;
			mx=max(mx,c[b[i][j]]);
		}
		s=s+m-mx;
	}
	
	return s;
}
void print(int f){
	k=f;
	writeln(k-1);
	for (int i=1;i<k;i++){
		write(ans1[i]); putchar(' '); writeln(ans2[i]);
	}	
}
void dfs(int dep){
	int s=check();
	if (dep+s>k) return;
	if (s==0){
		print(dep);
		exit(0);
	}
	for (int i=1;i<=n+1;i++){
		if (con[i]==0) continue;
		for (int j=1;j<=n+1;j++){
			if (i==j) continue;
			if (con[j]>=m) continue;
			swap(b[i][con[i]],b[j][con[j]+1]);
			con[i]--; con[j]++;
			ans1[dep]=i; ans2[dep]=j;
			dfs(dep+1);
			swap(b[i][con[i]+1],b[j][con[j]]);
				con[i]++; con[j]--;
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n); read(m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			read(a[i][j]);
		}
		con[i]=m;
	}
	for (k=0;k<=820000;k++){
		memcpy(b,a,sizeof(a));
		h.clear();
		dfs(1);
	}
	return 0;
}

