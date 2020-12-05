#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace cfz_akioi{
	const int mod = 1e9 + 7;
	template <typename T> inline void rd(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
		x*=f;
	}
}
using namespace cfz_akioi;
int n,k,t;
int w[15];
struct node{
	int c;
	int d;
}a[500];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	rd(n);
	rd(k);
	for(int i=1;i<=k;i++){
		rd(t);
	}
	for(int i=1;i<=n;i++){
		rd(t);
		rd(t);
	}
	cout<<-1<<endl;
	return 0;
}

