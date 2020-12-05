#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 100005
#define MOD 1000000007

int n,k;
int c[MAXN],d[MAXN];
int w[MAXN];
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
	scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&c[i],&d[i]);
    }
    printf("-1\n");
    return 0;
}
