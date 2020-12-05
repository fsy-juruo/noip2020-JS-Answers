#include<bits/stdc++.h>
#define N 1050010
#define M 30
#define ll long long 
#define DEBUG printf("vzyx and tqzer AK!\n")

using namespace std;

int T;
string s;

int f[N],b[N],cnt[N];
void init() {
	int len=s.size();
	memset(cnt,0,sizeof(cnt));
	cnt[s[0]-'a']++;
	f[1]=1;
	for(int i=1;i<len;i++) {
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1) f[i]=f[i-1]+1;
		else f[i]=f[i-1]-1;
	}
	memset(cnt,0,sizeof(cnt));
	cnt[s[len-1]-'a']++;
	b[len-1]=1;
	for(int i=len-2;~i;i--) {
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']&1) b[i]=b[i+1]+1;
		else b[i]=b[i+1]-1;
	}
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	
	while(T--) {
		s.clear();
		cin>>s;
		init();
		ll ans=0;
		int len=s.size();
		for(int i=0;i<len;i++) {
			for(int j=i+1;j<len;j++) {
				int l=j+1,js=1;
				for(int k=l;k+l<len;k+=l) {
					bool flag=true;
					for(int q=k;q<k+l;q++) {
						if(s[q]!=s[q-k]) {
							flag=false;
							break;
						}
					}
					if(flag) js++;
					else break;
				}
				for(int q=1;q<=js&&q*l<len;q++) if(f[i]<b[l*q]) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
