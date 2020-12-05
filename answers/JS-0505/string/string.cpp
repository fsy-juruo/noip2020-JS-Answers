#include<bits/stdc++.h>
using namespace std;
int t,sum[30];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s;
		string ab="",c="",s2="",a="";
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			c="";
			int cnt=0;
			for(int j=i;j<s.size();j++)
			{
				c+=s[j];
				sum[s[j]-'a']++;
			}
			for(int j=0;j<26;j++)
			{
				if(sum[j]%2==1)
					cnt++;
				sum[j]=0;
			}
			for(int k=1;k<s.size()-c.size();k++)
			{
				if((s.size()-c.size())%(k+1)!=0) continue;
				s2="";
				ab="";
				int flag=0;
				for(int l=0;l<=k;l++)
					ab+=s[l];
				for(int l=ab.size();l<s.size()-c.size();l++)
				{
					s2+=s[l];
					if(s2.size()==ab.size())
					{
//						cout<<s2<<' '<<ab<<endl;
						if(s2!=ab)
						{
							
							flag=1;
							break;
						}
						s2="";
					}
					
				}
				if(flag==1) continue;
				a="";
				
				int cnt2=0;
				for(int l=0;l<ab.size()-1;l++)
				{
					sum[s[l]-'a']++;
					a+=s[l];
					if(sum[s[l]-'a']%2==1)
						cnt2++;
					else
						cnt2--;
					if(cnt2<=cnt)
					{

//						cout<<c<<' '<<ab<<' '<<a<<endl;
						ans++;
					}
				}
				for(int i=0;i<26;i++)
					sum[i]=0;
			}
		}
		cout<<ans<<endl;
	}
}
