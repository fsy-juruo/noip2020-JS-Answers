#include<bits/stdc++.h>
#include<string>
using namespace std;

inline int f(string s)
{
	int ans=0;
	map<char,int> num;
	for(int i=0; i<s.length(); i++)
	{
		num[s[i]]++;
	}
	for(map<char,int>::iterator it=num.begin(); it!=num.end(); it++)
	{
		if(it->second%2==1)
		{
			//cout<<it->first<<" "<<it->second<<endl;
			ans++;
		}
	}
	return ans;
}

inline string sn(string s,int n)
{
	string ans;
	for(int i=1; i<=n; i++)
	{
		ans+=s;
	}
	return ans;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	//cout<<f("aaabcc")<<endl;
	for(int z=1; z<=n; z++)
	{
		int ans=0;
		string s;
		cin>>s;
		for(int i=1; i<s.length()-1; i++)
		{
			string a = s.substr(0,i);
			string sa = s.substr(i);

			for(int j=1; j<sa.length(); j++)
			{
				string b = sa.substr(0,j);
				//string c = sa.substr(j);
				//cout<<a<<" "<<b<<" "<<c<<endl;
				//if(f(a)<=f(c))

				string ab=a+b;
				for(int k=1;; k++)
				{
					int len=ab.length()*k;
					if(len>=s.length())
					{
						break;
					}
					string c = s.substr(len);
					
					if(f(a)<=f(c))
					{
						if(s.substr(0,len)==sn(ab,k))
						{
							
							//cout<<a<<" "<<b<<" "<<c<<endl;
							ans++;
						}
					}

				}

			}

		}
		cout<<ans<<endl;

	}
	return 0;
}
