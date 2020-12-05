#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1048577;
int a[N],cnt[N][30],s1[N],s2[N];
int g[N][30],tot[N];
ll ans;
string st;
bool check(int l1,int r1,int l2,int r2) {
	for(int i=1;i<=26;i++) {
		if(cnt[r1][i]-cnt[l1-1][i]!=cnt[r2][i]-cnt[l2-1][i]) return false;
	}
    string st1=st.substr(l1,r1-l1+1);
    string st2=st.substr(l2,r2-l2+1);
    if(st1==st2) return true;
    return false;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T; cin>>T;
	while(T--) {
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(tot,0,sizeof(tot));
		ans=0;
		cin>>st;
		int n=st.size();
		st=" "+st;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=26;j++) cnt[i][j]=cnt[i-1][j];
			int x=(int)(st[i])-96;
			cnt[i][x]++;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=26;j++) {
				if(cnt[i][j]%2==1) s1[i]++;
			}
		}
		for(int i=n;i>=1;i--) {
			for(int j=1;j<=26;j++) {
				if((cnt[n][j]-cnt[i-1][j])%2==1) s2[i]++;
			}
		}
		for(int i=1;i<=n;i++) {
			tot[s1[i]]++;
			g[i][0]=tot[0];
			for(int j=1;j<=26;j++) g[i][j]=g[i][j-1]+tot[j];
		}
		for(int i=2;i<n;i++) {
			int l=1,r=i;
			ans+=g[i-1][s2[i+1]];
			/*
			for(int j=1;j<i;j++) {
				if(s1[j]<=s2[i+1]) ans++;
			}
			*/
			while(check(1,i,l+i,r+i)) {
				l+=i,r+=i;
				if(r>=n) break;
				/*
				for(int j=1;j<i;j++) {
					if(s1[j]<=s2[r+1]) ans++;
				}
				*/
				ans+=g[i-1][s2[r+1]];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
