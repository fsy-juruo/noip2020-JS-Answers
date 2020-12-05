#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (1 << 20) + 5;
char s[maxn];
int n;
int sum[30],ans[maxn];
ll sum2[maxn][30],sumsum[30],last;
void init()
{
	ans[0] = 0;
	memset(sum,0x00,sizeof(sum));
	for(int i = 1;i <= n; ++i)
	{
		int v = s[i] - 'a';
//		printf("hsh[%d] = %d\n",i,hsh[i]);
		ans[i] = ans[i - 1];
		if(sum[v] & 1)
		{
			ans[i]--;
		}
		else
		{
			ans[i]++;
		}
		sum[v]++;
	}
	for(int j = 0;j <= 26; ++j)
	{
		sum2[0][j] = 0ll;
	}
	for(int i = 1;i <= n; ++i)
	{
//		cerr << i << " " << ans[i] << endl;
		for(int j = 0;j <= 26; ++j)
		{
			sum2[i][j] = sum2[i - 1][j];
		}
//		memcpy(sum2[i],sum2[i - 1],sizeof(sum2[i - 1]));
		sum2[i][ans[i]]++;
//		if(i < 5)
//		{
//			printf("ans[%d] = %d\n",i,ans[i]);
//			printf("sum2[%d][%d] = %lld\n",i,ans[i],sum2[i][ans[i]]);
//		}
	}
//	exit(0);
//	while(1);
//	for(int i = 1;i <= n; ++i)
//	{
//		for(int j = 1;j <= n; ++j)
//		{
//			sum2[i][j] += sum2[i][j - 1];
////			if(i <= 5)
////			{
////				printf("sum2[%d][%d] = %lld\n",i,j,sum2[i][j]);
////			}
////			if(sum2[i][j] > 1000000)
////			{
////				exit(0);
////			}
////			cerr << "hi"<<sum2[i][j] << endl;
//		}
//	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
//	printf("T = %d\n",T);
//	printf("hi\n");
	while(T--)
	{
		scanf("%s",s + 1);
//		printf("%s\n",s + 1);
		n = strlen(s + 1);
		if(n <= 1000)
		{
			memset(sumsum,0x00,sizeof(sumsum));
//		cerr << n << endl;
//		while(1);
		init();
//		printf("%d\n",check(6,3));
		last = 0;
		ll trueans = 0;
		for(int len = 1;len < n - 1; ++len)
		{
//			printf("len = %d\n",len);
			int v = s[n - len + 1] - 'a';
			if(sumsum[v] & 1)
			{
				last--;
			}
			else
			{
				last++;
			}
			sumsum[v]++;
			int t = n - len;
//			printf("t = %d\n",t);
			for(int i = 1;i <= t; ++i)
			{
				if(t % i == 0)
				{
					int fg = 1;
					for(int k = 1;k <= t; ++k)
					{
						if(s[k] != s[(k - 1) % i + 1])
						{
							fg = 0;
							break;
						}
					}
					if(fg == 1)
					{
						for(int k = 0;k <= last; ++k)
						{
							trueans += sum2[i - 1][k];
						}
					}
				}
			}
//			printf("trueans = %lld\n",trueans);
		}
		printf("%lld\n",trueans);
		}
		else
		{
			ll trueans = 0;
//			printf("hi\n");
			for(int len = 1;len < n - 1; ++len)
			{
				int t = n - len;
				for(int i = 1;i <= t; ++i)
				{
					if(t % i == 0)
					{
						trueans += min(i - 1,len + 1);
					}
				}
//				printf("trueans = %d\n",trueans);
			}
			printf("%lld\n",trueans);
		}
	}
	return 0;
}
