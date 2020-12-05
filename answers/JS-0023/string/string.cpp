#include <bits/stdc++.h>
#include <string>
#define MAXN 2000000
#define MAXD 30
#define INF 0x7fffffff
#define MOD 1000000007
using namespace std;
set<int> strfind[MAXN];
int Sum[MAXN][MAXD],times[MAXD],A[MAXN];
int inline read(void)
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
string inline readchar(void)
{
	char c=getchar();
	string s;s.push_back(' ');
	while(c>='a'&&c<='z'){s.push_back(c);c=getchar();}
	return s;
}
int main()
{
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int t=read(),k,x;
	set<int> start,se;
	string s;
	for(;t>0;t--)
	{
		s=readchar();
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<MAXD;j++)
				Sum[i][j]=0;
			strfind[i].clear();
			A[0]=0;
		}
		for(int i=0;i<MAXD;i++)	times[i]=0;
		k=0;
		start.clear();
		for(int i=1;i<s.size();i++)
		{
			x=s[i]-'a';
			
			if(i>2)
			{
				//zhaozichuan
				se=start;
				for(set<int>::iterator it=start.begin();it!=start.end();it++)
				{
					if(s[i]!=s[i-*it+1]&&i-*it+1!=*it-1)
						se.erase(*it);
				}
				start=se;
				for(set<int>::iterator it=start.begin();it!=start.end();it++)
				{
					if(strfind[*it-1].find(i-*it+2)!=strfind[*it-1].end()||i-*it+1==*it-1)
					{
						strfind[i].insert(i-*it+2);
						se.erase(*it);
					}
				}
				start=se;
				if(s[i]==s[1])	start.insert(i);
			}
			times[x]++;
			if(times[x]%2==0)	k--;
			else	k++;
			A[i]=k;
		//	cout<<i<<":"<<k<<endl;
			for(int j=0;j<MAXD;j++)
				if(j>=k)	Sum[i][j]=Sum[i-1][j]+1;
				else	Sum[i][j]=Sum[i-1][j];	
		}
		long long ans=0;
		k=0;for(int i=0;i<MAXD;i++)	times[i]=0;
	/*	for(int i=1;i<s.size();i++)
		{
			for(int j=0;j<5;j++)
				cout<<Sum[i][j]<<" ";
			cout<<endl;
		}
*/
		for(int i=s.size()-1;i>2;i--)
		{
			x=s[i]-'a';
			times[x]++;
			if(times[x]%2==0)
				k--;
			else
				k++;
			for(set<int>::iterator it=strfind[i-1].begin();it!=strfind[i-1].end();it++)
			{
				ans+=Sum[*it-2][k];
		//	cout<<i-1<<" "<<*it<<" "<<k<<" "<<A[*it]<<" "<<Sum[*it-2][k]<<" "<<ans<<endl;
			}
			ans+=Sum[i-2][k];
		//	cout<<i-1<<" "<<k<<" "<<A[i-2]<<" "<<Sum[i-2][k]<<" "<<ans<<endl;

		}
		printf("%lld\n",ans);
	//	cout<<endl;
	}	
	return 0;
}
