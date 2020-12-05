#include<bits/stdc++.h>
#define N 1100000
using namespace std;
int T,cnt[1005],Suf[N],n,Pre[N],p,sum,pre[N][30],xh[N],Max;
char s[N];
long long ans;
inline void update(int len) {
	for(int i=1+len; i<=n; i+=len) {
		if(xh[i+len-1])return;
		for(register int j=i; j<i+len; j++)
			if(s[j]!=s[j-i+1])return;
		xh[i+len-1]=len;
	}
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1; i<=n; i++) {
			Suf[i]=Pre[i]=xh[i]=0;
			for(int j=0; j<=26; j++)pre[i][j]=0;
		}
		for(int i=1; i<=1000; i++)cnt[i]=0;
		for(int i=n; i>=1; i--) {
			cnt[s[i]]++;
			if(cnt[s[i]]&1)Suf[i]=Suf[i+1]+1;
			else Suf[i]=Suf[i+1]-1;
		}
		for(int i=1; i<=1000; i++)cnt[i]=0;
		sum=0;
		for(int i=1; i<=n; i++) {
			cnt[s[i]]++;
			if(cnt[s[i]]&1)Pre[i]=Pre[i-1]+1;
			else Pre[i]=Pre[i-1]-1;
		}
		for(int i=1; i<=n; i++) {
			for(register int j=0; j<=26; j++) {
				pre[i][j]=pre[i-1][j];
				if(j>=Pre[i])pre[i][j]++;
			}
		}
		for(int i=1; i<n; i++)if(!xh[i])xh[i]=i,update(i);
		for(int i=1; i<n; i++) {
			for(int j=i; j<n; j+=i) {
				p=xh[j];
				sum=j/p;
				if(sum%i)continue;
				ans+=pre[i*xh[j]-1][Suf[j+1]];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
