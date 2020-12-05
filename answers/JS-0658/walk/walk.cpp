//start:10:05
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int N=2e5+100;
int w[N],a[N],c[N],d[N],b[N];
int walk(){
	for (int i=1;i<=n;i++){
		a[c[i]]+=d[i];
		if (a[c[i]]<1 || a[c[i]]>w[c[i]]) return i-1;
	}
	return n;
}
void work1(){
	for (int i=1;i<=k;i++) b[i]=1;
	int ans=0;
	while (!b[0]){
		int p=k;
		while (b[p]==w[p]) b[p--]=1;
		b[p]++;
		for (int i=1;i<=k;i++) a[i]=b[i];
		int s=walk()+1;
		if (s<=n){
			ans+=s;continue;
		}else{
			bool flag=true;
			for (int i=1;i<=n;i++) if (a[i]!=b[i]) flag=false;
			if (flag){
				cout << -1 << endl;return;
			}
		}
		while (true){
			int tmp=walk();s+=tmp;
			if (tmp<n){
				ans+=s;break;
			}
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=k;i++) cin >> w[i];
	for (int i=1;i<=n;i++) cin >> c[i] >> d[i];
	work1();
	return 0;
}
