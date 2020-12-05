#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s,a,b,c,h,v,x;
int t,sum;
int nu(string g)
{
	int sum=0;
	bool b[66000]={0};
	for(int i=0;i<g.size() ;i++)
	{
		while(b[i]==1)i++;
		if(i>=g.size() )break;
		b[i]=1;
		int s=1;
		for(int j=i+1;j<g.size() ;j++)
		{
			if(g[i]==g[j])
			{
				s++;
				b[j]=1;
			}
		}
		if(s%2==1)sum++;
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	getline(cin,s);
	while(t>0)
	{
		t--;
		sum=0;
		a=v;
		b=v;
		c=v;
		getline(cin,s);
		for(int i=0;i<s.size()-2 ;i++)
		{
			a+=s[i];
			b=v;
			for(int j=i+1;j<s.size()-1;j++)
			{
				b+=s[j];
				
				x=a+b;
				h=v;
				for(int l=1;l<=s.size() /x.size()  ;l++)
				{
					h+=x;
					if(h>=s)break;
		    	    c=v;
				    for(int k=h.size() ;k<s.size() ;k++)c+=s[k];
	        		if(nu(a)<=nu(c))
		        	{
	            			sum++;
		          	}	
					for(int m=h.size() ;m<h.size() *2;m++)
					{
					    
						if(h[m-h.size()]!=s[m])
				    	{
				    		l=123456789;
				    		break;
				    	}
					}
					
				}
				
			}
		}
		cout<<sum<<endl;
	}
 } 
