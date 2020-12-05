#include<bits/stdc++.h>
using namespace std;
int t,l,he=0;
string s;
int shu(int x)
{
	for(int i=1;i<x/3;i++)
	{
		for(int j=i+1;j<=(x-i)/2;j++)
		{
			if(j<x-i-j)
			{
				he++;
			}
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cin>>s;
	//	cout<<s;
		l=s.size();
		shu(l);
		printf("%d\n",he*6);
	}
	return 0;
}
