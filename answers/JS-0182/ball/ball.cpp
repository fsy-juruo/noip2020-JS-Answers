#include <bits/stdc++.h>
#define LL long long
using namespace std;

int pan[55][405], cnt[55];

int n, m;

struct Node
{
	int from, to;
}c[820005];

bool check2(int x)
{
	//cout << 1 << endl;
	if (cnt[x] != m) return false;
	for (int i = 1; i <= cnt[x]; i++)
		if (x != pan[x][i]) return false;
	return true;
}

bool check()
{
	for (int i = 1; i <= n; i++)
		if (!check2(i)) return false; 
	return true;
} 

void move(int step)
{
//	if (step > 820000) return;
	if (check() || step == 1000) 
	{
		printf("%d\n", step - 1);
		for (int i = 1; i < step; i++)
			printf("%d %d\n", c[i].from, c[i].to);
		exit(0);
	}
	//system("pause");
	for (int i = 1; i <= n + 1; i++)
	{
		if (i == n + 1)
		{
			while (cnt[i])
			{
				if (cnt[pan[i][cnt[i]]] < m) 
				{
					pan[pan[i][cnt[i]]][++cnt[pan[i][cnt[i]]]] = pan[i][cnt[i]--]; 
					c[step].from = n + 1;
					c[step].to = pan[i][cnt[i]];
					move(step + 1);
					pan[pan[i][cnt[i]]][++cnt[pan[i][cnt[i]]]] = pan[i][cnt[i]--];
				}
				else break;
			}
		}
		else
		{
		while (cnt[i])
		{
		//	cout << i << endl;
		//	cout << pan[i][0] << check2(i) << endl;
					
			if (cnt[pan[i][cnt[i]]] < m && i != pan[i][cnt[i]]) 
			{
				pan[pan[i][cnt[i]]][++cnt[pan[i][cnt[i]]]] = pan[i][cnt[i]--];
				c[step].from = i;
				c[step].to = pan[i][cnt[i]];
				move(step + 1);
				pan[pan[i][cnt[i]]][++cnt[pan[i][cnt[i]]]] = pan[i][cnt[i]--];
			}
			else if (cnt[n + 1] < m)
			{
				pan[n + 1][++cnt[n + 1]] = pan[i][cnt[i]--];
				c[step].from = i;
				c[step].to = n + 1;
				move(step + 1);
				pan[i][++cnt[i]] = pan[n + 1][cnt[n + 1]--];
			}
			else break;
		}}
	}		
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = m;
		for (int j = 1; j <= m; j++)
			scanf("%d", &pan[i][j]);
	}
	move(1);
	return 0;
}

