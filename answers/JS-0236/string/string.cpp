#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x;
	cin>>x;
	for(int p=0;p<x;p++)
	{
		string s;
		cin>>s;
		int len=s.length();
		if(len%2==0)
		{
			cout<<(len*len-3*len-10)/2;
			
		}
		else 
		{
			cout<<(len*len-3*len-10)/2;
			
		}
	}
	return 0;
}
