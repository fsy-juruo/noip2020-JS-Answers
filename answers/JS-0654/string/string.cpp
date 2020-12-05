#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
const int mod=1000000007;
const int inf=1000000000;
const ll infll=1000000000000000000ll;
const ll modll=1000000007ll;


const int maxn=100005;
string str;

int suma[maxn],sumc[maxn],sum[maxn][35],f[35];

void mem() {
	memset(suma,0,sizeof(suma));
	memset(sumc,0,sizeof(sumc));
	memset(sum,0,sizeof(sum));
	return;
}

void solve2() {
	int ans=0;
	for(int i=2;i<sz(str);i++)
		for(int j=i;j<sz(str);j+=i)			
			ans+=sum[i-2][sumc[j]];
	printf("%d\n",ans);
	return;
}

void solve() {
	mem();
	cin>>str;
	
	bool flag=true;
	for(int i=0;i<sz(str)-1;i++)
		if(str[i]!=str[i+1]) {
			flag=false;
			break;
		}
	memset(f,0,sizeof(f));
	int cnt=0;
	for(int i=0;i<sz(str);i++) {
		if(!f[str[i]-'a']) cnt++;
		else cnt--;
		f[str[i]-'a']^=1;
		suma[i]=cnt;
	}
	
	for(int j=suma[0];j<26;j++)
		sum[0][j]++;
	for(int i=1;i<sz(str);i++) {
		for(int j=suma[i];j<26;j++)
			sum[i][j]++;
		for(int j=0;j<26;j++)
			sum[i][j]+=sum[i-1][j];
	}
	
	memset(f,0,sizeof(f));
	cnt=0;
	for(int i=sz(str)-1;i>=0;i--) {
		if(!f[str[i]-'a']) cnt++;
		else cnt--;
		f[str[i]-'a']^=1;
		sumc[i]=cnt;
	}
	
	if(f) {
		solve2();
		return;
	}
	
	int ans=0;
	string p="";
	p+=str[0];
	
	for(int i=2;i<sz(str);i++) {
		p+=str[i-1];
		for(int j=i;j<sz(str);j+=i) {			
			ans+=sum[i-2][sumc[j]];
			if(str.substr(j,i)!=p) break;
		}
	}
	printf("%d\n",ans);
	return;
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
