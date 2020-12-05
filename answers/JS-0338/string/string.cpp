#include <bits/stdc++.h>
using namespace std;
int t,ans;
map<char,int>a,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for (int i=0;i<t;i++)
	{
		string st;
		int atot,ctot;
		cin>>st;
		ans=0;
		for (int j=2;j<st.size();j++)
		{
			int cbegin=j,t=1;
			for (int k=j;k<st.size();k++)
			{
				if (k-cbegin==j)
				{
					cbegin=k;
					t++;
				}
				if (st[k-cbegin]!=st[k])
				break;
			}
			for (int k=0;k<t;k++)
			{
				c.clear();
				ctot=0;
				for (int l=k*j+j;l<st.size();l++)
				c[st[l]]++;
				for (map<char,int>::iterator l=c.begin();l!=c.end();l++)
				if (l->second%2==1)
				ctot++;
				for (int l=1;l<j;l++)
				{
					a.clear();
					atot=0;
					for (int m=0;m<l;m++)
					a[st[m]]++;
					for (map<char,int>::iterator m=a.begin();m!=a.end();m++)
					if (m->second%2==1)
					atot++;
					if (atot<=ctot)
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
