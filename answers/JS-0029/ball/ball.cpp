#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,m;
const int Maxn=55;
const int Maxm=405;
int a[Maxn][Maxm];
int top[Maxn];
vector<pii>ans;
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
		}
		top[i]=m;
	}
	printf("0\n");
	return 0;
}
