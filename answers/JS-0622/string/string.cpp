#include<bits/stdc++.h>

using namespace std;
int t,l;
string s;
string gets(string a,int p,int q)
{
	string b;
	for (int i=p;i<=q;i++)
	b=b+a[i];
	return b;
}
int getj(string c)
{
	int nc=0,word[30]={0};
	for (int j=0;j<c.length();j++)
	{
		word[c[j]-'a']++;
	}
	for (int j=0;j<26;j++)
	if (word[j]%2==1)
	nc++;
	return nc;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&t);
	while (t--)
	{
		int ans=0,leftl,nc,na;
		bool b;
		getline(cin,s);
		l=s.length();
		s=' '+s;
		for (int i=l;i>=3;i--)
		{
			string c=gets(s,i,l);
			leftl=i-1;
			nc=getj(c);
			for (int j=1;j<=leftl/2;j++)
			{
				if (leftl%j!=0) continue;
				int x=leftl/j;
				string ab=gets(s,1,x);
				b=true;
				for (int k=1;k<j;k++)
				{
					string ab1=gets(s,1+k*x,(k+1)*x);
					if (ab!=ab1)
					{
						b=false;
						break;
					}
				} 
				if (b==false) continue;
				for (int k=0;k<ab.length()-1;k++)
				{
					string a=gets(ab,0,k);
					if (getj(a)<=nc) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
