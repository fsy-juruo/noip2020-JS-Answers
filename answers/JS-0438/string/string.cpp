#include<bits/stdc++.h>
using namespace std;
int t,s1,s2,ans,b[125],f[125];
string st;
void read(int &s)
{
	s=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
void reads()
{
	st="";
	char c=getchar();
	while(!islower(c))c=getchar();
	while(islower(c))
	{
		st.push_back(c);
		c=getchar();
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		ans=0;
		reads();
		if(st.size()==1)
		{
			puts("0");
			continue;
		}
		string A="";
		for(int i=0;i<st.size()-2;i++)
		{
			s1=0;
			A.push_back(st[i]);
			f[st[i]]++;
			for(int k=97;k<=122;k++)s1+=f[k]%2;
			for(int j=i+1;j<st.size()-1;j++)
			{
				string C=A+st.substr(i+1,j-i);
				for(int k=1;k<=st.size()/C.size();k++)
				{
					s2=0;
					string D=st.substr(C.size()*(k-1),C.size());
					if(C!=D||C.size()*k==st.size())break;
					memset(b,0,sizeof(b));
					for(int l=C.size()*k;l<st.size();l++)b[st[l]]++;
					for(int l=97;l<=122;l++)s2+=b[l]%2;
					if(s2>=s1)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
