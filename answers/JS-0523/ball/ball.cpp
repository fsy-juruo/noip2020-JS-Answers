#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ba[820010];
int bb[820010];
int a[52][410];
int c[52][410];
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int i, j, n, m;
	time(0);
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int k = 1;
	int mo = n +1;
	while(k)
	{
		memset(c, 0, sizeof(c));
		memset(ba, 0, sizeof(ba));
		memset(bb, 0, sizeof(bb));
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= m;j++)
			{
				c[i][j] = a[i][j];
			}
			c[i][0] = m;
		}
		for(i = 1;i <= 820000;i+= 0)
		{
			int x, y;
			x = rand() %mo +1;
			y = rand() %mo +1;
			if(c[x][0] != 0 && c[y][0] != m && x != y) 
			{
				ba[i] = x;
				bb[i] = y;
				i++;
				c[x][0] --;
				c[y][0] ++;
				swap(c[x][c[x][0] +1], c[y][c[y][0]]);
				int ch = 0;
				for(j = 1;j <= n +1;j++)
				{
					for(int l = 2;l <= m;l++)
					{
						if(c[j][l] != c[j][1]) ch = 1;
					}
				}
				if(ch == 0)
				{
					k = 0;
					for(j = 1;j <= i;j++)
					{
						cout << ba[j] << " " << bb[j] << endl;
					}
					break;
				}
			}
			
		}
	}
 	return 0;
}

