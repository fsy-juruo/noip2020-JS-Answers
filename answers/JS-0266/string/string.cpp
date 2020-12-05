# include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 2;
char s[N];
int cnt[N][26];
int F[N],F2[N];
int len;
long long cur = 0;
int key(char x)
{
	return x - 'a';
}

template <typename T> void write(T x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x >= 10) write(x / 10);
	char ch = (x % 10) + 48;
	putchar(ch);
	return;
}

int test;

void Getcnt(void)
{
	F[0] = 1;
	for(int i = 0; i < 26; i++) 
	{
		cnt[0][i] = (key(s[0]) == i) ? 1 : 0;
	}
	for(int i = 1; i <= len; i++)
	{
		for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j];
		if((++cnt[i][key(s[i])]) & 1) F[i] = F[i - 1] + 1;
		else F[i] = F[i - 1] - 1;
	}
	for(int i = 0; i < 26; i++)
	{
		cnt[len - 1][i] = (key(s[len - 1]) == i) ? 1 : 0;
	}
	F2[len - 1] = 1;
	for(int i = len - 2; i >= 0; i--)
	{
		for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i + 1][j];
		if((++cnt[i][key(s[i])]) & 1) F2[i] = F2[i + 1] + 1;
		else F2[i] = F2[i + 1] - 1;
	}
//	for(int i = 0; i <= len - 1; i++) 
//	{
//		printf("F[%d] = %d\n",i,F[i]);
//	}
//	for(int i = 0; i <= len - 1; i++) 
//	{
//		printf("F2[%d] = %d\n",i,F2[i]);
//	}
	return;
}

bool check(int w,int i)
{
	if((w + 1) % i != 0) return false;
	int newlen = (w + 1) / i;
	int q1 = 0,q2 = 0;
	bool flag = 0;
	while(q2 <= w)
	{
//		printf("q1 = %d,q2 = %d\n",q1,q2);
		if(s[q1] != s[q2]) 
		{
			flag = 1;
			break;
		}
		else 
		{
			q1++,q2++;
			if(q1 >= newlen) q1 = 0;
		}
	}
	return !flag;
}

void solve(void)
{
//	int len = strlen(s);
	Getcnt();
	for(int Cw = 2; Cw < len; Cw++)
	{
		int FC = F2[Cw];
//		printf("Cw = %d,FC = %d\n",Cw,FC);
		for(int j = 1; j <= Cw / 2; j++)
		{
			if(!check(Cw - 1,j)) continue;
//			printf("Cw = %d,j = %d\n",Cw,j);
			int newlen = Cw / j;
			newlen = 0 + newlen - 1;
			for(int k = 0; k < newlen; k++)
			{
				if(F[k] <= FC) cur++;
			}
		}
	}
	return;
}

int main(void)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		len = strlen(s);
//		printf("len = %d\n",len);
		cur = 0;
//		memset(F,0,sizeof(F));
//		memset(F2,0,sizeof(F2));
//		memset(cnt,0,sizeof(cnt));
		solve();
		write(cur);
		putchar('\n');
	}
	return 0;
}
