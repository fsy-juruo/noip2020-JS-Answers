#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;
int t;
string str;
int sum = 0;
char a[N], b[N], c[N];

void dfs(int num1, int num2, int num3)
{
	if(num1 + num2 + num3 == str.length())
	{
		sum ++;
		return;
	}
	
	for (int i = 0; i < str.length(); i ++ )
	{
		if(num1 == 0)
		{
			a[num1 ++ ] = str[i];
			dfs(num1 + 1, num2, num3);
		}
		else
		{
			if(num2 == 0)
			{
				b[num2 ++ ] = str[i];
				dfs(num1, num2 + 1, num3);
			}
			else
			{
				c[num3 ++ ] = str[i];
				dfs(num1, num2, num3 + 1);
			}
		}
	}
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++ )
	{
		scanf("%s", &str);
		dfs(0, 0, 0);
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}
