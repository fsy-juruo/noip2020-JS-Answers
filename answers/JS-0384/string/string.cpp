#include<bits/stdc++.h>
using namespace std;
int t;
int ds(string s)
{
	int a[26]={};
	for(int i=0;i<s.size();i++)
		a[s[i]-'a']++;
	int b=0;
	for(int i=0;i<26;i++)
		b+=a[i]%2;
	return b;
}
string check(string s,int a)
{
	if(s.size()%a!=0)
		return "-";
	int a1=s.size()/a;
	for(int i=a1;i<=s.size()-a1;i+=a1)
	{
		if(s.substr(i,a1)!=s.substr(i-a1,a1))
			return "-";
	}
	return s.substr(0,a1);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int o=0;o<t;o++)
	{
		int ans=0;
		string s;
		cin>>s;
		int s1=s.size();
		for(int i=1;i<=s1-2;i++)
		{
			int c1=ds(s.substr(s1-i,i));
			string h=s.substr(0,s1-i);
			for(int j=1;j<=h.size()/2;j++)
			{
				if(check(h,j)!="-")
				{
					string y=check(h,j);
					for(int v=1;v<y.size();v++)
					{
						if(ds(y.substr(0,v))<=c1)
							ans++;
						//cout<<y.substr(0,v)<<' '<<y.substr(v,y.size()-v)<<' '<<ds(y.substr(0,v))<<' '<<c1<<endl;
					}		
				}
			}
		}
		cout<<ans<<endl;
	}
 	return 0;
}

