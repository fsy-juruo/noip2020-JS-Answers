#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N=(1<<20)+7;
int n, Pre[N], God[N], SumP[N], SumG[N];
char ch[N];
ll H[N], bas=133ull, w[N];
#define rg register

inline bool check(int ed, int l,int r) {
	for(rg int i=0;i<ed;i++) if(ch[l+i] != ch[1+i]) return false ;
	return true ;
}

int T[N], del;
inline void add(int x) { if(!x) { del++; return ; } for(rg int i=x;i<=n;i+=i&-i) T[i]++; }
inline int ask(int x) { int ans=0; for(rg int i=x;i;i-=i&-i) ans+=T[i]; return ans+del; }

inline void solve() {
	ch[0]='a';
	scanf("%s", ch+1); n=strlen(ch); n--;
//	printf("%d\n",n);
	
//	H[0]=0ull; w[1]=1ull;
//	for(rg int i=2;i<=n;i++) w[i]=w[i-1] * bas;
//	for(rg int i=1;i<=n;i++) H[i]=w[i] * (ll) ch[i-1] + H[i-1];
	
	for(rg int i=1;i<=n;i++) God[i]=God[i-1] ^ ( 1<< ((int)(ch[i]-'a')) );
	for(rg int i=n;i>=1;i--) Pre[i]=Pre[i+1] ^ ( 1<< ((int)(ch[i]-'a')) );
	
	for(rg int i=1, j=God[i];i<=n;i++, j=God[i]) while(j) SumG[i]++, j-=j&-j;
	for(rg int i=1, j=Pre[i];i<=n;i++, j=Pre[i]) while(j) SumP[i]++, j-=j&-j;
	
//	for(rg int i=1;i<=n;i++) printf("%d  ",SumG[i]);
//	printf("\n");
//	for(rg int i=1;i<=n;i++) printf("%d  ",SumP[i]);
//	printf("\n");
	
//	printf("%c  %c",ch[13],ch[14]);
	
	add(SumG[1]); ll ans=0ull;
	for(rg int i=2;i<n;i++) {
		
		int Len=0;
		while((ll) (Len+1)*i+1<=n && check(i, Len*i+1, (Len+1)*i)) Len++;
		
		ans+=(ll) ask(SumP[i*Len+1]) * (ll) ((Len+1)/2);
		
		int S=(Pre[i*Len+1] ^ God[i]), cnt=0;
		while(S) cnt++, S-=S&-S;
		ans+=(ll) (Len/2) * (ll) ask(cnt);
		
//		printf("%d:  %d     ask:SumP   %d     %d\n",i,Len,ask(SumP[i*Len+1]),SumG[i]);
		add(SumG[i]);
	}
	
	printf("%llu\n",ans);
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int TT; scanf("%d", &TT);
	while(TT--) {
		memset(T, 0, sizeof T);
		memset(Pre, 0,sizeof Pre);
		memset(God, 0,sizeof God);
		memset(SumP, 0,sizeof SumP);
		memset(SumG, 0,sizeof SumG);
		memset(ch, 0,sizeof ch);
		del=n=0;
		
		
		solve();
	}
	
	return 0;
}
