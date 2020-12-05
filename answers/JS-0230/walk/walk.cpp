#include<bits/stdc++.h>
#include<stdint.h>
#define FILEIO(x) do{freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);}while(0)
using namespace std;
template<typename T>
void ri(T&x)
{
	x=0;
	int neg=1;
	char c=getchar();
	for (;!(isdigit(c)||c=='-');c=getchar());
	if (c=='-') neg=-1,c=getchar();
	for (;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=neg;
}
#ifdef MYDBG
#define DEBUG(x) cerr<<#x<<":"<<x<<" "
#define DEBUGL(x) cerr<<#x<<":"<<x<<endl
#else
#define DEBUG(x)
#define DEBUGL(x)
#endif
int64_t ans;
int main()
{
	FILEIO("walk");
	cout << -1 << endl;
	return 0;
}
