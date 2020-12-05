#include<bits/stdc++.h>
using namespace std;
string s,a,b,c;
char lin[1505];
int l,la,lb,lc;
int apr[30],cpr[30];
int tot;
string gs(int top,int end)
{
	memset(lin,'\0',sizeof(lin));
	for(int i=top;i<=end;i++)
	{
		lin[i-top]=s[i];
	}
	return lin;	
}
bool check()
{
	memset(apr,0,sizeof(apr));
	memset(cpr,0,sizeof(cpr));
	for(int i=0;i<la;i++)
	{
		int x=a[i]-'a'+1;
		apr[x]++; 
	}
	for(int i=1;i<=26;i++)
	{
		if(apr[i]%2==1)  apr[0]++;
	}
	for(int i=0;i<lc;i++)
	{
		int x=c[i]-'a'+1;
		cpr[x]++; 
	}
	for(int i=1;i<=26;i++)
	{
		if(cpr[i]%2==1)  cpr[0]++;
	}
	return apr[0]<=cpr[0];
}
bool compare(string a1,string a2)
{
	return a1==a2;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		tot=0;
		cin>>s;
		l=s.length();
		for(int j=0;j<l-2;j++)//a 长 
		{
			for(int k=j+1;k<l-1;k++)//b 长 
			{
				a=gs(0,j);
				b=gs(j+1,k);
				la=a.length();
				lb=b.length();
//				cout<<a<<" "<<b<<"\n";
 
				for(int n=1;;n++)
				{
					if((la*n)+(lb*n)>=l)  break;
					bool oka=true;
					for(int m=1;m<n;m++)
					{
						oka=compare(gs((la+lb)*m,(la+lb)*m+la-1),a);
						if(oka==false)  break;
						oka=compare(gs((la+lb)*m+la,(la+lb)*m+la+lb-1),b);
						if(oka==false)  break;
					}
					if(oka==false)  continue;//检查符合abab…… 
					c=gs((la+lb)*n,l);
					lc=c.length();
					oka=check(); 
					if(oka==true&&(a!=b||a!=c||b!=c))
					{
						tot++;
//						cout<<"A="<<a<<" B="<<b<<" C="<<c<<endl;
					} 
				}
			}
		}
		
		
		cout<<tot<<endl;
	}
	
	
	return 0;
}
