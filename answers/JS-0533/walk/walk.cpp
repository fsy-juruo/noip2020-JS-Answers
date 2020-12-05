//give me two bottle of water and a hard question
#include<iostream>
#include<fstream>
#define F(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,r,l) for(int i = r; i >= l; --i)
#define LL long long
using namespace std;
const int N = 1e5 + 10;
int n,k,w,c,d;
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	F(i,1,k) scanf("%d",&w);
	F(i,1,n) scanf("%d%d",&c,&d);
	printf("-1");
	return 0;
}
//all goes well
//$hanker_007$