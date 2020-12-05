#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=(1<<21);

inline int read() { char ch=getchar(); int f=1; while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
	int x=0; while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar(); return x*f;}

int T,n; char a[N];
ll ans=0; int g[N];

inline int gt(int l,int r) {
	int cishu[256]={0},s=0;
	for(int i=l;i<=r;i++) cishu[a[i]]++;
	for(int i='a';i<='z';i++) s+=(cishu[i]%2==1);
	return s;
}

inline void print(int l,int r) {
	for(int i=l;i<=r;i++) putchar(a[i]);
//	puts("");
}

inline bool check(int l,int r,int k) {
//	l = 0
//	if(k==(r-l+1)) return 1;
	for(int i=(r-l+1)/k;i<=r;i++)
		if(a[i] != a[i%((r-l+1)/k)]) return 0;
//	printf("%d %d %d\n",l,r,k);
//	print(l,r);
	return 1;	
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read(); while(T--) {
		scanf("%s",a); n=strlen(a);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++) {
			g[i]=gt(0,i);
//			printf("%d %d\n",i,g[i]);
		} ans=0ll;
		for(int i=1;i<n-1;i++) {
			// (ab)^? = (0 - i) , c = (i+1 - n-1)
			int p=gt(i+1,n-1);
			for(int j=1;j*j<=(i+1);j++)
				if((i+1)%j==0) {
//					if(i==5 && j==2) puts("!");
					if(check(0,i,j)) {
//						if(i==5 && j==2) puts("!");
						for(int k=0;k<(i+1)/j-1;k++)
							if(g[k]<=p) {
//								print(0,k); putchar(' '); print(k+1,(i+1)/j-1); putchar(' '); print(i+1,n-1); puts("");
								ans++;
							}
					}
					if(j*j!=i+1 && check(0,i,(i+1)/j)) {
//						if(i==5 && j==2) printf("%d\n",j-1);
						int jj=(i+1)/j;
						for(int k=0;k<(i+1)/jj-1;k++)
							if(g[k]<=p) {
//								print(0,k); putchar(' '); print(k+1,(i+1)/jj-1); putchar(' '); print(i+1,n-1); puts("");
								ans++;
							}
					}
				}
//			printf("%lld\n",ans);	
		} printf("%lld\n",ans);
	}
	return 0;
}

