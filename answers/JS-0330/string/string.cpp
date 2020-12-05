#include<bits/stdc++.h>
using namespace std;
string s;
int qzh[1100000][26];
long long ans;
string jq(int start,int len,string w)
{
	string re="";
	for(int i=start;i<start+len;i++)
	{
		re+=w[i];
	}
	return re;
}
int work(int clen,int piece)
{
	int cji=0,aji=0,re=0;//ab=s.size()-i
	for(int i=0;i<26;i++)
	{
		int tmp=qzh[s.size()-1][i]-qzh[s.size()-1-clen][i];
		if(tmp&1)
		{
			cji++;
		}
	}
	for(int i=0;i<(s.size()-clen)/piece-1;i++)//make a
	{
		for(int j=0;j<26;j++)
		{
			int tmp=qzh[i][j];
			if(tmp&1)
			{
				aji++;
			}
		}
		if(aji<=cji)
		{
			re++;
		}
		aji=0;
	}
	//cout<<clen<<"cji"<<cji<<" "<<piece<<" "<<re<<endl;
	return re;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{	
		ans=0;
		cin>>s;
		if(s.size()>1001)
		{
			for(int i=1;i<=s.size()-2;i++)//c:s.size()-1 to s.size()-i
			{
				int ab=s.size()-i;
				if(i&1)
				{
					for(int j=1;j<=ab/2;j++)
					{
						if(ab%j==0)
						{
							ans+=ab/j-1;						
						}
					}	
				}
				else
				{
					for(int j=1;j<=ab/2;j++)
					{
						if(ab%j==0)
						{
							ans+=(ab/j-1)/2;						
						}
					}					
				}
			//cout<<"main:"<<i<<" "<<ans<<endl;
			}			
		}
		else
		{
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<26;j++)
			{
				qzh[i][j]=0;
				if(i!=0)
				{
					qzh[i][j]=qzh[i-1][j];
				}
			}
			qzh[i][s[i]-'a']++;
		}
		for(int i=1;i<=s.size()-2;i++)//c:s.size()-1 to s.size()-i
		{
			int ab=s.size()-i;
			for(int j=1;j<=ab/2;j++)
			{
				if(ab%j==0)
				{
					bool flag=true;
					string fst=jq(0,ab/j,s);
					for(int k=1;k<j;k++)
					{
						string tmp=jq(ab/j*k,ab/j,s);
						if(fst!=tmp)
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						ans+=work(i,j);//¿ªÊ¼·ÖÅä 
					}
				}
			}
			//cout<<"main:"<<i<<" "<<ans<<endl;
		}				
		}
		cout<<ans<<endl;
	}
}
