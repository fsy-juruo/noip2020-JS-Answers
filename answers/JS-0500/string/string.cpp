#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
#define N (1<<17)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const ll INF64=1e18;
inline char nc(){
	static char buf[100005],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=getchar(); int sum=0; int f=0;
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) sum=(sum<<3)+(sum<<1)+(ch^48),ch=getchar();
	return f?-sum:sum;
}
const int maxn=(1<<17)+5;
const int P=20050103;
const int MOD=19260817;
int T,prime[maxn],cnt,v[maxn];
char s[maxn];
vector<int>vec[maxn];
vector<int>p[maxn];
ll f[maxn][28],g[maxn][28];
int sum[maxn][28];
int n,pre[maxn];
int H[maxn],power[maxn];
inline int Sub(int x,int y){
	int res=x-y; if(res<0) res+=MOD;
	return res;
}
inline int Add(int x,int y){
	int res=x+y; if(res>MOD) res-=MOD;
	return res;
}
inline int getHash(int l,int r){
	return Sub(H[r],1ll*H[l-1]*power[r-l+1]%MOD);
}
set<int>ss[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	for(int i=2;i<=N;i++){
		if(!v[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(prime[j]*i>N) break;
			v[prime[j]*i]=1;
			if(!(i%prime[j])) break;
		} 
	}
	vec[1].pb(1);
//	for(int i=1;i<=cnt;i++) cout<<prime[i]<<' ';
//	puts("FUCK");
	for(int i=2;i<=N;i++){
//		cout<<i<<endl;
		vec[i].pb(1);
		if(!v[i]){
			vec[i].pb(i); continue;
		}
		for(int j=1;j<=cnt;j++){
//			cout<<j<<endl;
			if(i%prime[j]) continue;
			int num=0,tmp=i; while(!(tmp%prime[j])) num++,tmp/=prime[j];
			int len2=vec[tmp].size();
			for(int k=0;k<len2;k++)
				for(int l=0,temp=1;l<=num;l++,temp*=prime[j])
					if(vec[tmp][k]*temp!=1) 
						vec[i].pb(vec[tmp][k]*temp);
			break;
		}
	}
	while(T--){
		scanf("%s",s+1); n=strlen(s+1);
		for(int i=1;i<=n;i++) ss[i].clear();
		for(int i=1;i<=n;i++){
			pre[i]=0;
			for(int j=0;j<=26;j++) f[i][j]=g[i][j]=0;
		}
		power[0]=1;
		for(int i=1;i<=n;i++) power[i]=1ll*power[i-1]*P%MOD;
		for(int i=1;i<=n;i++) H[i]=Add(1ll*H[i-1]*P%MOD,s[i]-'a');
//		if(getHash(1,1)==getHash(2,2)) cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			for(int j=0;j<26;j++){
				sum[i][j]=sum[i-1][j]+((s[i]-'a')==j);
				if(sum[i][j]&1) pre[i]++;
			}	
//		for(int i=1;i<=n;i++) cout<<pre[i]<<' ';
//		cout<<endl;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=26;j++){
				g[i][j]=g[i-1][j]+(pre[i-1]==j);
			}
		ss[1].insert(H[1]);
		for(int i=2;i<=n;i++){
			int len=vec[i].size();
			for(int j=0;j<len;j++){
				int x=vec[i][j]; int tmp=i-x;
				int temp=getHash(tmp+1,i);
//				cout<<i<<' '<<x<<' '<<tmp<<' '<<temp<<endl;				 
				if(tmp){
//					puts("FUCK");
					if(ss[tmp].find(temp)!=ss[tmp].end()){
//						puts("FUCK");
						for(int k=0;k<=26;k++) f[i][k]+=g[x][k];
						ss[i].insert(temp);
					}
				}else{
					for(int k=0;k<=26;k++) f[i][k]+=g[x][k];
					ss[i].insert(temp);
				}
			}
		}
		ll ans=0;
		/*for(int i=1;i<=n;i++){
			for(int j=0;j<=5;j++)
				cout<<f[i][j]<<' ';
			cout<<endl;
		}*/
		for(int i=1;i<=n;i++)
			for(int j=1;j<=26;j++)
				f[i][j]+=f[i][j-1];
		for(int i=2;i<=n-1;i++){
			int tot=0;
			for(int j=0;j<26;j++) if((sum[n][j]-sum[i][j])&1) tot++;
			ans+=f[i][tot];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
