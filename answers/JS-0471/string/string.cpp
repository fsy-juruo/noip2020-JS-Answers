#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int test;
	cin>>test;
	for (int t=1;t<=test;t++)
	{
		string a;
		int letter_dan[100010][30]={0};
		long long ans=0;
		cin>>a;
		letter_dan[0][a[0]-'a']++;
		for (int i=1;i<a.size();i++)
		{
			for (int j=0;j<26;j++)
			{
				letter_dan[i][j]+=((j+'a')==a[i]);
			}
		}
		for (int i=1;i<(a.size()-1)/test;i++)
		{
			int need=false;
			string b=a.substr(0,i+1);
			for (int n=0;n<test;n++)
			{
				if (b.substr(n*3,i+1)!=b)
				{
					need=true;
					break;
				}
			}
			if (need)
			{
				continue;
			}
			for (int j=0;j<b.size()-1;j++)
			{
				int cnt_a=0,cnt_c=0;
				for (int n=0;n<26;n++)
				{
					if ((letter_dan[b.size()-1][n])%2!=0)
					{
						cnt_a++;
					}
				}
				for (int n=0;n<26;n++)
				{
					if ((letter_dan[a.size()-1][n]-letter_dan[(i+1)*t-1][n])%2!=0)
					{
						cnt_c++;
					}
				}
				if (cnt_a<=cnt_c)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
