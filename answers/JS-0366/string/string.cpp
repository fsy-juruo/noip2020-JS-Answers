#include<bits/stdc++.h>
using namespace std;
long long f[1005],b[1005],c[1005],d[1005];
bool pd(int p, string s1, string s2)
{
	string ss1="",ss2="";
	for(int i=1;i<=p;i++) ss1=ss1+s1;
	for(int i=0;i<p*s1.size();i++) ss2=ss2+s2[i];
	if(ss1==ss2) return 1;
	return 0;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	cin>>T;
	string s;
	unsigned long long ans;
	for(int i=1;i<=T;i++)
	{
		ans=0;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			c[s[j]]++;
			for(int k=97;k<=122;k++)
			{
				if(c[k]%2==1) f[j]++;
			}
		}
		for(int j=s.size()-1;j>=0;j--)
		{
			d[s[j]]++;
			for(int k=97;k<=122;k++)
			{
				if(d[k]%2==1) b[j]++;
			}
		}
		/*for(int i=0;i<s.size();i++) cout<<f[i]<<" ";
		cout<<endl;
		for(int i=0;i<s.size();i++) cout<<b[i]<<" ";
		cout<<endl;	*/	
		string ss="";
		long long js,q,p;
		for(int j=0;j<s.size();j++)
		{
			string sss="";
			ss=ss+s[j];
			sss=ss;
			for(int k=j+1;k<s.size();k++)
			{
				sss=sss+s[k];
				js=sss.size();
				q=1;
				p=js;
				while(p<s.size())
				{
					if(f[j]<=b[p]&&pd(q,sss,s)==1) 
					{
						ans++;
					}
					q++;
					p=js*q;
				}
			}
		}
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		cout<<ans<<endl;
	}
 	return 0;
}
