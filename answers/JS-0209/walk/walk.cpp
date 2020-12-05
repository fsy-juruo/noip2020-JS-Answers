#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;
const int mo=100000007;
long long ans;
int n,k;
int w[17],wei[500007],zou[500007],wz[17];
void work() {
	for(int i=1; i<=w[1]; i++) {
		for(int j=1; j<=w[2]; j++) {
			wz[1]=i;wz[2]=j;
			for(int l=1; l<=n; l++) {
				wz[wei[l]]+=zou[l];
				ans++;
				if(wz[wei[l]]<=0||wz[wei[l]]>w[wei[l]]) break;
				if(l==n&&wz[wei[l]]>0&&wz[wei[l]]<=w[wei[l]]) l=1;
			}
			ans%=mo;
		}
	}

}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; i++) {
		scanf("%d",&w[i]);
		wz[i]=1;
	}
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&wei[i],&zou[i]);
	}
	work();
	printf ("%lld",ans-1);
	return 0;
}

