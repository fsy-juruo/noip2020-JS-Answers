#include<bits/stdc++.h>
using namespace std;

long long A[1010],C[1010],numA[30],numC[30],T,ans,will;
bool l,l2 = 1;
string a;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		l2 = 1;
		cin>>a;
		if(a.size() > 1000)
		for(long long i = 1;i < a.size();i++)
		{
			if(a[i] != a[i - 1])
			{
				l2 = 0;
				break;
			}
		}
		if(l2 == 1 && a.size() > 1000)
		{
			for(long long i = 2;i < a.size();i++)
			{
				int j = a.size() / i;
				if(i * j == a.size())
				j--;
				if(i % 2 == 0)
				{
					if((a.size() - i * j) % 2 == 1)
					ans += j * (i - 1);
					else ans += j * ((i - 1) / 2);
				}
				else
				{
					if(a.size() % 2 == 0)
					ans += (j / 2 + j % 2) * (i - 1) + (j / 2) * ((i - 1) / 2);
					else ans += (j / 2 + j % 2) * ((i - 1) / 2) + (j / 2) * (i - 1);
				}
			}
			cout<<ans<<endl;
			ans = 0;
		}
		else
		{
			for(long long i = 1,j = a.size();i <= a.size();i++,j--)
			{
				int now = a[i - 1] - 'a';
				numA[now]++;
				if(numA[now] % 2 == 0)
				A[i] = A[i - 1] - 1;
				else A[i] = A[i - 1] + 1;
				now = a[j - 1] - 'a';
				numC[now]++;
				if(numC[now] % 2 == 0)
				C[j] = C[j + 1] - 1;
				else C[j] = C[j + 1] + 1;
			}
			
			for(long long i = 2;i <= a.size() - 1;i++)
			{
				l = 1;
				for(long long j = 1;j * i <= a.size() - 1;j++)
				{
					int ci = i * j + 1;
					if(a[i * j - 1] != a[i - 1]) l = 0;
					for(int z = 1;z < i;z++)
					{	
						if(A[z] <= C[ci])
							will++;
						if(a[i * (j - 1) + z - 1] != a[z - 1] || l == 0)
						{
							will = 0;
							l = 0;
							break;
						}
					}
					
					if(l == 1)
					{
						ans += will,will = 0;
					}
					else break;
				}
			}
			cout<<ans<<endl;
			for(long long i = 0;i < 26;i++)
			{
				numA[i] = 0,numC[i] = 0;
			}
			ans = 0,will = 0;
		}
		
	}
	return 0;
} 
