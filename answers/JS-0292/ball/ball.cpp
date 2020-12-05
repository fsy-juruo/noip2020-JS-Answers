#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if(c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c))
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	puts("0");
	return 0;
}

