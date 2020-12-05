#include <bits/stdc++.h>
#define maxn 100007
using namespace std;

int n,k;
int c[maxn],d[maxn],w[maxn];
namespace brute {
	int mtk[maxn],b[maxn],t[maxn];
	bool mkk() {
		for (int i=1; i<=n; i++) {
			mtk[c[i]] += d[i];
		}

		for (int i=1; i<=k; i++)
			if (mtk[i] != 0) return true;

		return false;
	}

	void solve() {
		if (!mkk()) {
			cout<<-1;
			exit(0);
		}

		memset(b,0,sizeof(b));
		long long ans = 0;
		for (int i=1; i<=k; i++) b[i] = 1;
		b[k] = 0;

		while (b[0] == 0) {
			int j = k;
			while (j >= 1 && b[j] == w[j]) {
				b[j] = 1;
				j--;
			}
			b[j]++;
			if (j == 0) break;

			//for (int i=1;i<=k;i++) cout<<b[i]<<' ';
			//cout<<endl;

//			int lcr = 214748364;
//			for (int i=1;i<=k;i++)
//				if (mtk[i] !=  0) {
//					lcr = min(lcr,(mtk[i]<0?(b[i]-1)/(-mtk[i]):(w[i]-b[i])/mtk[i]));
//				}
			//cout<<"lcr="<<lcr<<endl;

			for (int i=1; i<=k; i++) t[i] = b[i] /*+ lcr * mtk[i]*/;
//			ans += lcr*n;
			while (true) {
				for (int i=1; i<=n; i++) {
					t[c[i]] += d[i];
					ans++;
					//cout<<t[1]<<' '<<t[2]<<endl;
					if (t[c[i]] < 1 || t[c[i]] > w[c[i]]) goto out;
				}
			}
			
			out:
			int a = 0;
			//cout<<ans<<endl;
		}

		cout<<ans;
		exit(0);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	cin>>n>>k;
	for (int i=1; i<=k; i++) cin>>w[i];
	for (int i=1; i<=n; i++) cin>>c[i]>>d[i];

	if (n <= 100) brute::solve();
	return 0;
}
