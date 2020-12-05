#include<bits/stdc++.h>
using namespace std;
int T;
int F(string s)
{
	int ans=0;
	int a[27]={0};
	for(int i=0;i<s.size();i++)
	{
		a[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(a[i]%2==1)ans++;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		long long ans=0;
		for(int i=1;i<s.size();i++)
		{
			string l=s.substr(0,i);
			string c=s.substr(i,s.size()-1);
//			cout<<l<<" "<<c<<endl;
			for(int j=2;j<l.size();j++)
			{
				bool flag=true;
				if(l.size()%j==0)
				{
					string ss=l.substr(0,j);
//					cout<<ss<<endl;
					for(int k=j;k<l.size();k+=j)
					{
//						cout<<l.substr(k,k+j)<<endl;
						if(l.substr(k,k+j)!=ss)
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						string ll=l.substr(0,j);
//						cout<<ll<<endl;
						for(int k=1;k<ll.size();k++)
						{
							string a=ll.substr(0,k);
//							cout<<a<<" "<<c<<endl;
							if(F(a)<=F(c))
							{
//								cout<<a<<" "<<c<<endl;
								ans++;
							}
						}
					}
				}
			}
			for(int j=i+1;j<s.size();j++)
			{
				string a=s.substr(0,i);
//				string b=s.substr(i,j-i);
				string c=s.substr(j,s.size()-1);
				if(F(a)<=F(c))
				{
					ans++;
//					cout<<a<<" "<<c<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

