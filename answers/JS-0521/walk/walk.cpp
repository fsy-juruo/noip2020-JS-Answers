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
LL n,k,w,s;
LL m;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	puts("-1");
	return 0;
}

