#include<bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const ll Infll=1e18+7;
const int MAXN=(1<<20)+10;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
int T,n,m,K;
ll ans,bit[30];
int nxt[MAXN];
int f[MAXN],g[MAXN];
int sum[MAXN][30];
int a[MAXN];
char s[MAXN];
vector<int> v;
inline void Update(int x,int v){
	for(int i=x;i<=27;i+=(i&(-i))) bit[i]+=v;
}
inline ll Query(int x){
	ll res=0;
	for(int i=x;i;i-=(i&(-i))) res+=bit[i]; 
	return res;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);ans=0;m=0;
		for(int i=1;i<=n;++i) a[i]=s[i]-'a';a[n+1]=-1;
		for(int i=2;i<=n+1;++i){if(a[i]!=a[i-1]){m=i-1;break;}}
		memset(bit,0,sizeof(bit));bool flag=false;
		v.clear();
		
		
		int j=0;nxt[1]=0;
		for(int i=2;i<=n;++i){
			while(j&&s[j+1]!=s[i]) j=nxt[j];
			if(s[j+1]==s[i]) ++j;
			nxt[i]=j;
			
			if(i%2==0&&nxt[i]==i/2&&i>=4&&i>m){
				flag=true;
				v.pb(i/2);
			}
		}
//		for(int i=1;i<=n;++i) cout<<nxt[i]<<' ';cout<<endl;

		for(int i=1;i<=n;++i) for(int j=0;j<26;++j) sum[i][j]=0; 
		for(int i=1,cnt;i<=n;++i){
			sum[i][a[i]]=1;cnt=0;
			for(int j=0;j<26;++j){
				sum[i][j]+=sum[i-1][j];
				if(sum[i][j]%2==1) ++cnt;
			}
			f[i]=cnt;
		}
		
		for(int i=1;i<=n;++i) for(int j=0;j<26;++j) sum[i][j]=0; 
		for(int i=n,cnt;i>=1;--i){
			sum[i][a[i]]=1;cnt=0;
			for(int j=0;j<26;++j){
				sum[i][j]+=sum[i+1][j];
				if(sum[i][j]%2==1) ++cnt;
			}
			g[i]=cnt;
		}
		

		for(int i=2;i<n;++i){
			Update(f[i-1]+1,1);
			ans+=Query(g[i+1]+1);
		}


		if(m>=4){
			for(int len=2;len<=m/2;++len){
				K=m/len;
				
				for(int i=2,pos;i<=K;++i){
					pos=i*len+1;if(pos>n) break;
					if(g[pos]==0) ans+=1ll*(len-1)/2;
					else ans+=1ll*len-1;
				}
			}
		}
//		cout<<"size "<<v.size()<<endl;
		if(flag){
			for(int p=0;p<(int)v.size();++p){
				K=0;
				for(int i=1;i<=n;++i){
					if(a[i]!=a[(i-1)%v[p]+1]) break;
					if(i%v[p]==0) ++K;
				}
			
				
				
				for(int i=1,pos;i<=K/2;++i){
					memset(bit,0,sizeof(bit));
					for(int j=2;j<=i*v[p];++j) Update(f[j-1]+1,1);
					for(int j=2;i*j<=K;++j){
						pos=i*v[p]*j+1;if(pos>n) break;
						if(j%2==0) ans+=1ll*(i*v[p]-1);
						else ans+=Query(g[pos]+1);
					}
				}			
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2
buxbvbuxbvasd
*/

