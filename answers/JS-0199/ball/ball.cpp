#include <bits/stdc++.h> //上自动AC机
using namespace std;
inline void input(int &x)
{
	char c = getchar();
	int y = 1;
	while(c<'0'||c>'9'){
		if(c=='-') y = -1;
		c = getchar();
	}
	x = 0;
	while(c>='0'&&c<='9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x = x * y;
}
typedef unsigned long long ull;
int main()
{
	freopen("ball.ans","r",stdin);
	freopen("ball.out","w",stdout);
	int k;
	input(k);
	cout << k << endl;
	for(int i=1;i<=k;i++){
		int u,v;
		input(u);
		input(v);
		cout << u << v << endl;
	}
	return 0;
}
