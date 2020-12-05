//T4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
const int Mod=1e9+7;
inline int Read() {
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n,k,w[N],c[N],d[N];
ll ans;
int s[50],b[50];
void dfs(int x) {
	if(x==k+1) {
		for(int i=1;i<=k;i++) b[i]=s[i];
		ll sum=0;                
		while(1) {
			for(int i=1;i<=n;i++) {
				b[c[i]]+=d[i]; sum++;
				//if(s[1]==1&&s[2]==3) {
				//	printf("%d %d\n",b[1],b[2]);
				//}
				if(b[c[i]]>w[c[i]]||b[c[i]]<1) {
				//	printf("%d %d %lld\n",s[1],s[2],sum);
					ans+=sum; ans%=Mod; return;
				}
			}
		}
	}
	for(int i=1;i<=w[x];i++) {
		s[x]=i; dfs(x+1); s[x]=0;
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
    n=Read(); k=Read();
    for(int i=1;i<=k;i++) w[i]=Read();
    for(int i=1;i<=n;i++) c[i]=Read(),d[i]=Read();
    dfs(1);
    printf("%lld\n",ans);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
