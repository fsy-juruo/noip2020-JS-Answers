#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f,MAXN=(1<<20)+10,MAXC=30;
int T,N;
char str[MAXN];
int buc[MAXC],a[MAXN],fa[MAXN],fc[MAXN];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%s",str+1);
		N=strlen(str+1);
		int op=0,var=0;
		memset(fa,0,sizeof buc);
		memset(fc,0,sizeof buc);
		memset(buc,0,sizeof buc);
		for(int i=1; i<=N; i++) {
			a[i]=str[i]-'a';
			if(!buc[a[i]]) {
				var++;
			}
			buc[a[i]]++;
		}
		LL ans=0;
		if(var==1) {
			for(int lab=2; lab<N; lab++) {
				for(int j=lab; j<N; j+=lab) {
					if((N-j)&1) {
						ans+=lab-1;
					} else {
						ans+=(lab-1)/2;
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		memset(buc,0,sizeof buc);
		for(int i=1; i<=N; i++) {
			buc[a[i]]++;
			if(buc[a[i]]&1) {
				fa[i]=fa[i-1]+1;
			} else {
				fa[i]=fa[i-1]-1;
			}
		}
		memset(buc,0,sizeof buc);
		for(int i=N; i>=1; i--) {
			buc[a[i]]++;
			if(buc[a[i]]&1) {
				fc[i]=fc[i+1]+1;
			} else {
				fc[i]=fc[i+1]-1;
			}
		}
		for(int i=2; i<N; i++) {
//			printf("len(AB)=%d\n",i);
			for(int j=i+1; j<=N; j+=i) {
				// match
				int flag=1;
				for(int k=1; k<=i; k++) {
					if(a[k]!=a[j-i+k-1]) {
						flag=0;
						break;
					}
				}
				if(!flag) {
					break;
				}
				LL tmp=0;
				for(int k=1; k<i; k++) {
					if(fa[k]<=fc[j]) {
						tmp++;
						ans++;
					}
				}
//				printf("j=%d tmp=%lld\n",j,tmp);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
