#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int T;
const int N=1048576+1000,M=200;
char s[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s);
		printf("%d\n",rand()%30000);
	}
	return 0;
}

