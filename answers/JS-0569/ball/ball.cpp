#include <bits/stdc++.h>

using namespace std;
int n,m;
int rec[53][403];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> rec[i][j];
		}
	}
	cout << n*m;
	for (int i = 1; i <= n*m; ++i)
	{
		cout << rand() % n << ' ' << (rand() + 1)% n << endl; 
	}
	return 0;
}
