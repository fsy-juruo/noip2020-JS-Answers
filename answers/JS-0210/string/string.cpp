#include<bits/stdc++.h>
using namespace std;
int t,ans;
string s;
char st[(1<<20)+100];
int gs[30][(1<<20)+100];
bool visi[200];
int numa,numc;
bool check(int length,int cs)
{
	for(int i=0;i<length;i++)
		st[i]=s[i];
	int top=length*cs-1;	
	for(int i=1;i<cs;i++)
	{
		for(int j=length-1;j>=0;j--)
		{
			if(s[top]!=st[j])
				return false;
			top--;	
		}
	}	
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		ans=0;
		cin>>s;
		int l=s.size();
		for(int i=0;i<=25;i++)
			gs[i][0]=0;
		gs[s[0]-'a'][0]++;
		for(int i=1;i<l;i++)
			for(int j=0;j<=25;j++)
			{
				gs[j][i]=gs[j][i-1];
				if((s[i]-'a')==j)
					gs[j][i]++;
			}
		for(int k=1;k<=l;k++)
			for(int len=2;len<=(l-1)/k;len++)
			{
				numc=0;
				memset(visi,0,sizeof(visi));
				for(int i=len*k;i<l;i++)
				if(!visi[s[i]])
				{
					int sjz=s[i]-'a';
					if((gs[sjz][l-1]-gs[sjz][len*k-1])%2==1)
					{
						numc++;
						visi[s[i]]=true;
					}
					else
					{
						visi[s[i]]=true;
					}			
				}
				if(check(len,k))
				for(int i=0;i<len-1;i++)
				{
					numa=0;
					memset(visi,0,sizeof(visi));
					for(int j=0;j<=i;j++)
					{
						if(!visi[s[j]])
						{
							if(gs[s[j]-'a'][i]%2==1)
							{
								numa++;
								visi[s[j]]=true;
							}
							else
							{
								visi[s[j]]=true;
							}	
						}
							
					}
					if(numa<=numc)
						ans++;
				}
			}					
		cout<<ans<<endl;
	}
	return 0;
}
