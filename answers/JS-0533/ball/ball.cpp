//give me two bottle of water and a hard question
#include<iostream>
#include<fstream>
#include<stack>
#define F(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,r,l) for(int i = r; i >= l; --i)
#define LL long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
stack<int> s[N];
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	F(i,1,n) {
		F(i,1,m) {
			int c;
			scanf("%d",&c);
			s[i].push(c);
		}
	}
	printf("0");
	return 0;
}
//all goes well
//$hanker_007$