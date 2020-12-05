#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int n;
int pr[35220][30];
int num[30]; 
int nm[35220],nm2[35220];
bool canF(int r,int len)
{
	for(int i=len;i<=r;i++)
	{
		if(s[i]!=s[i-len])return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>s;
		int ji=0;
		long long ans=0;
		n=s.size();
		for(int i=0;i<=26;i++)num[i]=0;
		for(int i=0;i<n;i++)
		{
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==1)
			{
				ji++;	
			}	
			else ji--;
			nm[i]=ji;
		}
		ji=0;
		for(int i=0;i<=26;i++)num[i]=0;
		for(int i=n-1;i>=0;i--)
		{
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==1)ji++;
			else ji--;
			nm2[i]=ji;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=26;j++)
			{
				if(i==0&&j>=nm[i])pr[i][j]=1;
				if(i==0)continue;
				if(j>=nm[i])pr[i][j]=pr[i-1][j]+1;
				else pr[i][j]=pr[i-1][j];
			}
		}
		bool pts=0;
		for(int i=0;i<n;i++)if(s[i]!=s[0])pts=1;
		if(pts==0)
		{
			for(int c=n-1;c>=2;c--)
			{
				int leng=c;
				for(int i=1;i*i<=leng;i++)
				{
					if(leng%i!=0)continue;
					int j=leng/i;
					ans+=pr[i-2][nm2[c]];
					if(i!=j)
					{
						ans+=pr[j-2][nm2[c]];
					}
				}
			
			}
			cout<<ans<<endl;
			continue;
		}
		for(int c=n-1;c>=2;c--)
		{
			int leng=c;
			for(int i=1;i*i<=leng;i++)
			{
				if(leng%i!=0)continue;
				int j=leng/i;
				if(canF(c-1,i))
				{
					ans+=pr[i-2][nm2[c]];
				}
				if(i!=j&&canF(c-1,j))
				{
					ans+=pr[j-2][nm2[c]];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


