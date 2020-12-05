#include<bits/stdc++.h>
using namespace std;
int t;
string s;
bool vis1[305],vis2[305];
int sumc,suma;
long long ans;
bool panduan(int x,int y)
{
	if(x==y)
	{
		return true;
	}
	for(int i=0; i<x; i++)
	{
		int a=i;
		while(i<x-y)
		{
			if(s[i]!=s[i+y])
			{
				return false;
			}
			i+=y;
		}
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		cin>>s;
		for(int j=s.size()-1; j>2; --j)
		{
			sumc-=vis1[s[j]];
			vis1[s[j]]=!vis1[s[j]];
			sumc+=vis1[s[j]];
			for(int k=1; k<=j; ++k)
			{
				if(j%k==0)
				{
					if(panduan(j,j/k))
					{
						for(int l=0; l<j/k-1; ++l)
						{
							suma-=vis2[s[l]];
							vis2[s[l]]=!vis2[s[l]];
							suma+=vis2[s[l]];
							if(suma<=sumc)
							{
								ans++;
							}

						}
					}

				}
			}
		}
		printf("%lld\n",ans);
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		suma=0;
		sumc=0;
		ans=0;
	}

	return 0;
}
