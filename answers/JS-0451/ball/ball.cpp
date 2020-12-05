#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
const int maxn=57;
using namespace std;
stack <int>q[maxn];
int n,m,k;
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i(1); i<=n; ++i) {
		for(int j(1); j<=m; ++j) {
			int u;
			scanf("%d",&u),q[i].push(u);
		}
	}
	return 0;
}

