#include<bits/stdc++.h>
using namespace std;
int n,t,p[150],w,sz,q[150],x,hs[1505],qz[1505],ans;
string s,a,b,c,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s;w=0;sz=s.size()-1;ans=0;
		memset(q,0,sizeof(q));x=0;
		for(int i=sz;i>=0;i--)
		{
			q[s[i]]++;
			if(q[s[i]]%2==0) x--;
			else x++;
			hs[i]=x;
		}
		memset(q,0,sizeof(q));x=0;
		for(int i=0;i<=sz;i++)
		{
			q[s[i]]++;
			if(q[s[i]]%2==0) x--;
			else x++;
			qz[i]=x;
		}a="";
		for(int i=0;i<=sz-2;i++)
		{
			a=a+s[i];b="";
			for(int j=i+1;j<=sz-1;j++)
			{
				b=b+s[j];
				if(qz[i]<=hs[j+1]) ans++;
				c=a+b;w=j;
				while(w+c.size()<sz&&s.substr(w+1,c.size())==c)
				{
					w+=c.size();if(hs[w+1]>=qz[i]) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
