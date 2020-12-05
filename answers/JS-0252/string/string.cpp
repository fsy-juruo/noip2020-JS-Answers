#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;cin>>t;
	int i,j,k,l,m,n;
	for(i=0; i<t; i++)
	{
		string s;
		cin>>s;
		int len=s.length();
		int ans=0;int z;
		string a="",b="",c="";
		for(j=0; j<len-2; j++)
		{
			a+=s[j];
			for(k=j+1; k<len-1; k++)
			{
				b+=s[k];
				//cout<<a<<" "<<b<<endl;
				string g=a+b;
				int leng=g.length();
				int cmp=0;
				for(l=leng; l<len-leng-1; l+=leng)
				{
					string kkk="";
					for(m=l; m<=l+leng-1; m+=1)
						kkk+=s[m];
					//cout<<"123"<<kkk<<" "<<g<<endl;
					c="";
					if(kkk==g)
					{
						for(m=l+leng; m<len; m++)
						{
							c+=s[m];
						}
						int y[26]={};
						int cnta=0;
						for(m=0; m<a.length(); m++)
							y[a[m]-'a']++;
						for(z=0; z<26; z+=1)
							if(y[z]%2==1)
							{
								cnta++;
							}
						memset(y,0,sizeof(y));
						int cntc=0;
						for(m=0; m<c.length(); m++)
							y[c[m]-'a']++;
						for(z=0; z<26; z+=1)
							if(y[z]%2==1)
							{
								cntc++;
							}
						if(cntc>=cnta)
							ans++;
					}
					else
					{
						break;
					}
					for(m=l; m<len; m++)
					{
						c+=s[m];
					}
					int y[26]={};
					int cnta=0;
					for(m=0; m<a.length(); m++)
						y[a[m]-'a']++;
					for(z=0; z<26; z+=1)
						if(y[z]%2==1)
						{
							cnta++;
						}
					memset(y,0,sizeof(y));
					int cntc=0;
					for(m=0; m<c.length(); m++)
						y[c[m]-'a']++;
					for(z=0; z<26; i+=1)
						if(y[z]%2==1)
						{
							cntc++;
						}
					if(cntc>=cnta)
						ans++;
				}
				
			}
			b="";
		}
		cout<<ans;
	}
	
	return 0;
}
