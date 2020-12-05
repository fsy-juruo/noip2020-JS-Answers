#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long w[11], ans;
int n, k, v;
short c[500010], d[500010];
int main()
{
    freopen("walk.in", "r", stdin);
  	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> d[i];
	}
	if (k == 1)
	{
		bool flag = 1;
		for (int i = 1; i <= w[1]; i++)
		{
			v = i;
			flag = 1;
			while (1)
			{
			    for (int j = 1; j <= n; j++)
			    {
			    	v += d[j];
			    	ans++;
			    	if (v < 1 || v > w[1])
			    	{
			    		flag = 0;
			    		break;
					}
				}
				if (i == v)
				{
					cout << "-1";
					return 0;
				}
				if (flag == 0)
				{
					break;
				}
			}
			ans %= MOD;
		}
		cout << ans;
		return 0;
	}
	if (k == 2)
	{
		int x, y;
		bool flag = 1;
		for (int i = 1; i <= w[1]; i++)
		{
			for (int f = 1; f <= w[2]; f++)
		    {
		    	x = i;
		    	y = f;
			    flag = 1;
		    	while (1)
		    	{
		    	    for (int j = 1; j <= n; j++)
    			    {
	    		    	if (c[i] == 2)
	    		    	{
	    		    		y += d[i];
						}
						else
						{
							x += d[i];
						}
		    	    	ans++;
			        	if (x < 1 || x > w[1] or y > w[2] or y < 1)
			        	{
    			    		flag = 0;
	    		    		break;
		    			}
				    }
		    		if (i == x and y == f)
    				{
			    		cout << "-1";
			    		return 0;
			    	}
			    	if (flag == 0)
			    	{
			    		break;
			    	}
		    	}
			    ans %= MOD;
		    }
		}
		cout << ans;
		return 0;
	}
	return 0;
}
