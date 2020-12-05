#include<bits/stdc++.h>
using namespace std;
int n,l;
long long tot=0;
string st,sta,stb,stc,stab,sth;
int check(string st1,string st2)
{
	int h1[30],h2[30];
	int s1=0,s2=0;
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for(int i=0;i<st1.size();i++)
	h1[int(st1[i])-96]++;
	for(int i=0;i<st2.size();i++)
	h2[int(st2[i])-96]++;
	for(int i=1;i<=26;i++)
	{
		if(h1[i]%2==1)s1++;
		if(h2[i]%2==1)s2++;
	}
	if(s1<=s2)return 1;
	return 0;
}
int check1(string st)
{
	for(int i=0;i<st.size();i++)
	if(st[i]!=st[1])return 0;
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st;
		sta="";tot=0;
		l=st.size();
		for(int j=0;j<st.size()-2;j++)
		{
			stb="";
			sta+=st[j];
			for(int k=j+1;k<st.size()-1;k++)	
			{
				stc="";stab="";
				stb+=st[k];
				for(int p=k+1;p<st.size();p++)
				stc+=st[p];
				if(check(sta,stc))tot++;
				if(stab.size()*2<st.size())
				{
					stab=sta+stb;
					for(int p=stab.size();p<st.size()-stab.size();p=p+stab.size())
					{
						sth="";stc="";
						for(int q=p;q<p+stab.size();q++)
						sth+=st[q];
						if(sth!=stab)break;
						for(int q=p+stab.size();q<st.size();q++)
						stc+=st[q];
						if(check(sta,stc))tot++;
				 	}
				}
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}

