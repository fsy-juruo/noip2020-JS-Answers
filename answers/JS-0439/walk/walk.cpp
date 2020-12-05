#include <bits/stdc++.h>
using namespace std;
int n,k,p[50],pos[50],c[100100],d[100100],w[50],cnt[50],ans;
void dfs (int dep) {
	if (dep>k) {
		for (int i=1;i<=k;i++) p[i]=pos[i];
		int num=0;
		while (true){
			
				for (int i=1;i<=n;i++) {
				num++;
				p[c[i]]+=d[i];
				if (p[c[i]]<1||p[c[i]]>w[c[i]]) {
					ans+=num;
					return;
				}
			}
		}
		
	}
	for (int i=1;i<=w[dep];i++) {
		pos[dep]=i;
		dfs(dep+1);
	}
}
int main () {
//	freopen("walk.in","r",stdin);
//	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>w[i];
	for (int i=1;i<=n;i++) cin>>c[i]>>d[i],cnt[c[i]]+=d[i];
	bool f=0;
	for (int i=1;i<=k;i++) 
		if (cnt[i]) {
			f=1;
			break;
		}
	if (!f) {
		for (int i=1;i<=k;i++) {
			if (abs(cnt[i])<w[i]) {
				f=1;
				break;
			}
		}
		if (f) {
			puts("-1");
			return 0;
		}	
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

