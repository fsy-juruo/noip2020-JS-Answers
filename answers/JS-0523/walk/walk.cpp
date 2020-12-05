#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mo = 1000000007, k, n;
int asn = 0;
int w[20];
int lo[20];
int mxi[20];
int mni[20];
int mi = 100010;
int bu[6][200020];//ÁãµãÊÇ100010
int ac[10];
inline int f(int c, int b)
{
	if(bu[c][b +mi] != 1061109567)return bu[c][b +mi];
	if(lo[c] >= 0 && mni[c] > b)return INT_MAX;
	if(lo[c] <= 0 && mxi[c] < b)return INT_MAX;
	int t = f(c, b -lo[c]) +n;
	bu[c][b +mi] =t;
	return t; 
}
inline void bl(int p)
{
	int i;
	if(p == 1)
	{	
		int j;int s = INT_MAX;
		for(j = 2;j <= k;j++)
		{
			s = min(s, f(j, w[j] -ac[j] +1));
			s = min(s, f(j, 0 -ac[j]));
		}
		for(i = 1;i <= w[p];i++)
		{
			s = min(s, f(1, w[1] -i +1));
			s = min(s, f(1, 0 -i));
			asn +=s;
			asn %= mo;
		}
		return;
	}
	for(i = 1;i <= w[p];i++)
	{
		ac[p] = i;
		bl(p -1);
	}
 } 
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int i, j;
	cin >> n >> k;
	memset(bu, 63, sizeof(bu));
	for(i = 1;i <= k;i++)
	{
		scanf("%d", &w[i]);
		bu[i][0 +mi] = 0; 
	}
	int c;int f;
	memset(lo, 0, sizeof(lo));
	memset(mxi, 0, sizeof(mxi));
	memset(mni, 0, sizeof(mni));
	for(i = 1;i <= n;i++)
	{
		scanf("%d%d", &c, &f);
		lo[c] +=f;
		mxi[c] = max(mxi[c], lo[c]);
		mni[c] = min(mni[c], lo[c]);
		if(i < bu[c][lo[c] +mi])bu[c][lo[c] +mi] = i;
	}
	int lp;
	for(i = 1;i <= k;i++)
	{
		if(lo[i] == 0 && mxi[i] -mni[i] +1 <= w[i])lp++;
	}
	if(lp == k)
	{
		cout << -1;
		return 0;
	}
	bl(k);
	//cout << f()
	cout << asn << endl;
	
 	return 0;
}

