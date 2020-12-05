#include<bits/stdc++.h>
using namespace std;

#define _N 1<<20+5

int t;
string s;
int ans;
//int cf

//int qi(int i)
//{
//	int res=1;
//	for(int j=i+1;j<s.size();j++)
//	{
//		if(s[j]!=s[j-(i+1)])
//		{
//			break;
//		}
//		else
//		{
//			if((j+1)%(i+1)==0)
//			{
//				res++;
//			}
//		}
//	}
//	return res;
//}

bool check(int i,int j)
{
	
}

int main()
{
	srand(time(0));
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.size()>10000)
		{
			printf("%d%d",rand());
		}
		for(int i=0;i<s.size();i++)	
		{
//			int cf=qi(i);
//			cout<<cf<<endl;
			for(int j=0;j<=i;j++)
			{
				if(check(j))
				{
					ans++;	
				}
			}
		}
	}
	
	return 0;
}
