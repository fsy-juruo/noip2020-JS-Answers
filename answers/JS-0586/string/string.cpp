#include <iostream>
#include <cstdio>
#include <cstring>
using std::string;
using std::cin;

int T, ans;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &T);
	for (int cnt = 1; cnt <= T; ++cnt)
	{
		cin>>s;
		for (register int i = 1; i < s.size(); ++i)
		{
			for (register int j = 1; j < s.size(); ++j)
			{
				if(i + j >= s.size())
				{
					break;
				}
				for (register int k = 1; k < s.size()/2; ++k)
				{
					if (i * k + j * k >= s.size())
					{
						break;
					}
					if (i % 2 == 1)
					{
						if ((s.size() - i * k - j * k) % 2 == 1)
						{
							++ans;
						}
					}
					else
					{
						++ans;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
//Male man, Female man, And lie score man.
