#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)
#define pb push_back
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vii;

const int maxn=1100007;

char s[maxn];
int n,T,f[maxn][27],cnt[maxn],o[maxn][27],nxt[maxn],d[maxn],g[maxn];

int getcnt(int l,int r){
	static int rt;rt=0;
	for(int i=0;i<26;++i){
		if(o[r][i]^o[l-1][i])
			++rt;
	}
	return rt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int p=0;
		for(int i=2;i<=n;++i){
			while(p&&s[p+1]!=s[i])p=nxt[p];
			if(s[p+1]==s[i])++p;
			nxt[i]=p;
		}
		for(int i=1;i<=n;++i)
			for(int j=0;j<26;++j)	
				f[i][j]=0;
		memset(o,0,sizeof(o));
		for(int i=1;i<=n;++i){
			for(int j=0;j<26;++j)
				o[i][j]=o[i-1][j];
			o[i][s[i]-'a']^=1;
			cnt[i]=0;
			for(int j=0;j<26;++j)
				cnt[i]+=o[i][j];
			for(int j=0;j<=26;++j)
				f[i][j]=f[i-1][j]+(cnt[i]<=j);
		}
		for(int i=1;i<=n;++i)
			g[i]=getcnt(i,n);
		ll res=0;
		for(int j=n-1;j>=2;--j){
			for(int k=1;j*k<n;++k){
				while(nxt[j*k]>j)
					nxt[j*k]=nxt[nxt[j*k]];
				if(k>1&&nxt[j*k]<j)break;
//				res+=f[j-1][getcnt(j*k+1,n)];
				res+=f[j-1][g[j*k+1]];
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}


