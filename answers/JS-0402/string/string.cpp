#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define RE return
#define V vector
#define FILL(x,y) memset(x,y,sizeof(x))
using namespace std;
int readint(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int s=c-'0';c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+c-'0';
		c=getchar();
	}
	RE s;
}
void output(int x){
	if(x>=10)output(x/10);
	putchar((char)(x%10+'0'));
}
string s;
int p[1100000];
int sum[30],n,l[1100000],r[1100000];
struct hash_string{
	int h[1100000],pow_B[1100000],B,mod;
	void init(int m){
		B=37;mod=m;pow_B[0]=1;
		FOR(i,1,n){
			h[i]=(h[i-1]*B+p[i])%mod;
			pow_B[i]=pow_B[i-1]*B%mod;
		}
	}
	int get(int x,int y){
		RE ((h[y]-h[x-1]*pow_B[y-x+1])%mod+mod)%mod;
	}
}H1,H2;
void solve(){
	cin>>s;
	n=s.size();
	FOR(i,1,n){
		p[i]=s[i-1]-'a';
	}
	FILL(sum,0);
	FOR(i,1,n){
		l[i]=0;
		sum[p[i]]++;
		rep(j,0,26)if(sum[j]&1)l[i]++;
	}
	FILL(sum,0);
	for(int i=n;i>=1;i--){
		r[i]=0;
		sum[p[i]]++;
		rep(j,0,26)if(sum[j]&1)r[i]++;
	}
	H1.init(1000000007);
	H2.init(1000000009);
	FILL(sum,0);
	int ans=0;
	FOR(i,1,n){
		int h1,h2;
		h1=H1.get(1,i);
		h2=H2.get(1,i);
		for(int j=i;j<n;j+=i){
			if(h1!=H1.get(j-i+1,j)||h2!=H2.get(j-i+1,j)){
				break;
			}else{
				ans+=sum[r[j+1]];
			}
		}
		FOR(j,l[i],26){
			sum[j]++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}

