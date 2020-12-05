#include <bits/stdc++.h>
using namespace std;
ifstream fin("string.in");
ofstream fout("string.out");
typedef long long ll;
const int N=(1<<20)+8;
const int base=131,mod=200701087;
int T;//clear!!!
char s[N];
int xsum[N],valp[N],vals[N];
ll pw[N],h[N];
int f[N][30];
vector<int> di[N];
inline int PopCount(int x){
	int res=0;
	for(;x;x-=x&-x) ++res;
	return res;
}
inline ll ssubstr(int l,int r){
	return (h[r]-h[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
	fin>>T;//clear!!
	while(T--){//clear!! S* CCF.
		fin>>(s+1);
		int n=strlen(s+1);
		pw[0]=1;
		for(int i=1;i<=n;++i){
			xsum[i]=xsum[i-1]^(1<<(s[i]-'a'));
			pw[i]=pw[i-1]*base%mod;
			h[i]=(h[i-1]*base+s[i])%mod;
		}
		for(int i=1;i<=n;++i){
			valp[i]=PopCount(xsum[i]);
			vals[i]=PopCount(xsum[n]^xsum[i-1]);
		}
		for(int i=1;i<=n;++i) ++f[i][valp[i]];
		for(int i=1;i<=n;++i)
			for(int j=0;j<=26;++j) 
				f[i][j]+=f[i-1][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=26;++j)
				f[i][j]+=f[i][j-1];
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;j+=i)
				di[j].push_back(i);
		ll ans=0;
		for(int i=2;i<n;++i){//B end & (AB)^i len
			int ss=di[i].size();
			for(int j=0;j<ss;++j){
				int x=di[i][j];//AB len
				if(ssubstr(1,i-x)==ssubstr(1+x,i))
					ans+=f[x-1][vals[i+1]];
			}
		}
		fout<<ans<<'\n';
		for(int i=1;i<=n;++i){
			for(int j=0;j<=26;++j) f[i][j]=0;
			di[i].clear();
		}
	}
	return 0;
}
