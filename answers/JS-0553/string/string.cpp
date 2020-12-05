#include<bits/stdc++.h>
using namespace std;

int T;

int jo[1050010][200];

bool check(string s,int o,int p)
{
	if (s.size()<=o*p) return false;
	
	for(int i=0;i<o;i++)
	{
		if (s[i]!=s[i+o*(p-1)])
		{
			return false;
		}
	}
	
	return true;
}

int ji(int l,int r)
{
	int cnt=0;
	
	for(char i='a';i<='z';i++)
	{
		if ((jo[r][i]-jo[l-1][i])%2==1)
		{
			cnt++;
		}
	}
	
	return cnt;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>T;
	
	while(T--)
	{
		string str;
		cin>>str;
		
		memset(jo,0,sizeof(jo));
		
		for(int i=0;i<str.size();i++)
		{
			for(char j='a';j<='z';j++)
			{
				jo[i+1][j]=jo[i][j];
			}
			
			jo[i+1][str[i]]++;
		}
		
		int cnt=0;
		
		for(char i='a';i<='z';i++)
		{
			if (jo[str.size()][i]>0)
			{
				cnt++;
			}
		}
		
//		if (cnt==1)
//		{
//			long long sum=0;
//			
//			bool flag[1050010];
//			memset(flag,0,sizeof(flag));
//			
//			for(int i=str.size()-1;i>=2;i--)
//			{
//				int c_long=str.size()-i;
//				
//				for(int j=1;j*j<=i;j++)
//				{
//					if (i%j==0)
//					{
//						int h;
//						int ab_long;
//						
//						bool hhhh=0;
//						
//						if (j>=2&&flag[j]==0)
//						{
//							h=i/j;
//							ab_long=j;
//							
//							flag[j]=1;
//							hhhh=1;
//						}
//						
//						if (i/j>=2&&i/j!=j&&flag[i/j]==0)
//						{
//							h=j;
//							ab_long=i/j;
//							
//							flag[i/j]=1;
//							hhhh=1;
//						}
//						
//						if (hhhh==1)
//						{
//							if (ab_long%2==0)
//							{
//								if (c_long%2!=0)
//								{
//									sum+=(ab_long-1)*h;
//								}
//								
//								else
//								{
//									sum+=((ab_long+1)/2-1)*h;
//								}
//							}
//							
//							else
//							{
//								if (c_long%2==0)
//								{
//									sum+=(ab_long-1)*(h/2);
//									sum+=((ab_long+1)/2-1)*((h+1)/2);
//								}
//								
//								else
//								{
//									sum+=(ab_long-1)*((h+1)/2);
//									sum+=((ab_long+1)/2-1)*(h/2);
//								}
//							}
//						}
//					}
//				}
//				
//				cout<<c_long<<" "<<sum<<'\n';
//			}
//			
//			cout<<sum<<'\n';
//			return 0;
//		}
		
		long long sum=0;
		
		for(int i=2;i<str.size();i++)
		{
			int h=1;
			
			while(check(str,i,h+1))
			{
				h++;
			}
			
			for(int j=1;j<=h;j++)
			{
				int C=ji(i*j+1,str.size());
				
				for(int k=1;i-k>=1;k++)
				{
					int A=ji(1,k);
					
					if (A<=C)
					{
						sum++;
					}
				}
			}
		}
		
		cout<<sum<<'\n';
	}
	
	return 0;
}
