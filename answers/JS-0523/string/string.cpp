#include<bits/stdc++.h>
#define ll long long
using namespace std;
int hs[30];
int h[30];
int hq[30];
int ht[30];
int a[100010];
inline bool check(int m, int k)//一组为k
{
	int i, j;
	int n = m /k;
	for(i = 1;i <= 26;i++)
	{
		if(hq[i] %n != 0)return 0;
	}
	for(i = 1;i <= k;i++)
	{
		for(j = 1;j < n;j++)
		{
			if(a[i] != a[i +j *k])return 0;
		}
	}
	return 1;
} 
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int i, j, n, t, l;
	int k;
	cin >> t;
	string ci;
	getline(cin, ci);
	for(i = 1;i <= t;i++)
	{
		ll asn = 0;
		string st;
		getline(cin, st);
		int n = st.size();
		for(j = 0;j < n;j++)
		{
			a[j +1] = st[j] -'a' +1;
		}
		memset(hs, 0, sizeof((hs)));
		for(j = 1;j <= n;j++)
		{
			hs[a[j]] ++;
		}
		int x = 0;
		for(j = 1;j <= 26;j++)
		{
			if(hs[j] == 0) x++;
		}
		if(x == 25)
		{
			for(j = n;j > 2;j--)
			{
				int lp;
				int wf;
				lp = (n -j +1) %2;
				for(k = 1;k *k <= j -1;k++)
				{
					if((j -1) %k == 0)
					{
						if(lp == 1)asn += k -1;
						else asn += (k -1) /2;
						if((j -1) /k != k)
						{
							int yln = (j -1) /k;
							if(lp == 1)asn += yln -1;
							else asn += (yln -1) /2;
						}
					}
				}
			}
			cout << asn << endl;
			continue;
		}
		int ji = 0;
		memset(h, 0, sizeof(h));
		for(j = n;j > 2;j--)
		{
			h[a[j]]++;
			if(h[a[j]] %2 == 1)ji++;
			else ji --;
			for(k = 1;k <= 26;k++)
			{
				hq[k] = hs[k] -h[k];
			}
			for(k = 1;k *k <= j -1;k++)
			{
				if((j -1) %k == 0)//一个以k，一个以（j-1） %k 
				{
					if(check(j -1, k))
					{
						int jb = 0;
						memset(ht, 0, sizeof(ht));
						for(l = 1;l < k;l++)
						{
							ht[a[l]]++;
							if(ht[a[l]] %2 == 1)jb++;
							else jb --;
							if(jb <= ji) asn++;
						}
					}
					if((j -1) /k != k)
					{
						if(check(j -1, (j -1) /k))
						{
							int jb = 0;
							memset(ht, 0, sizeof(ht));
							for(l = 1;l < (j -1) /k;l++)
							{
								ht[a[l]]++;
								if(ht[a[l]] %2 == 1)jb++;
								else jb --;
								if(jb <= ji) asn++;
							}
						}
					}
					
				}
			}
		}
		cout << asn << endl;
	}
 	return 0;
}

