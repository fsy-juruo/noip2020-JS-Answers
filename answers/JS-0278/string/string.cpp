#include<bits/stdc++.h>
using namespace std;

const int N=1<<20+3;
int nxt[N],c[N],a[N],sum[N];
bool zm[30];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;s='0'+s;
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(zm,0,sizeof(zm));
		for(int i=s.size()-1;i>=1;i--)
		    if(zm[s[i]-'a']) 
               c[i]=c[i+1]-1,zm[s[i]-'a']=0;
		    else zm[s[i]-'a']=1,c[i]=c[i+1]+1;
		memset(zm,0,sizeof(zm));
	    for(int i=1;i<s.size();i++)
		    if(zm[s[i]-'a']) 
               a[i]=a[i-1]-1,zm[s[i]-'a']=0;
		    else zm[s[i]-'a']=1,a[i]=a[i-1]+1;
		memset(nxt,0,sizeof(nxt));
		nxt[1]=0;
		for(int i=2,j=0;i<s.size();i++)
		{
			for(;s[j+1]!=s[i]&&j;j=nxt[j]);
			if(s[j+1]==s[i]) nxt[i]=j+1;
			j=nxt[i];
		}
		int ans=0;
	    for(int i=2;i<s.size()-1;++i)
	    {
	    	memset(sum,0,sizeof(sum));
	    	for(int k=1;k<=i;k++) 
	    	    if(a[k]<=c[i+1]) sum[k]=sum[k-1]+1;
	    	    else sum[k]=sum[k-1];
	    	ans+=sum[i-1];
	    	int j=nxt[i];bool flag=1;
	    	while(flag&&j)
	    	{
	    		if(i%(j-nxt[j])==0) 
				{
				    ans+=sum[j-nxt[j]-1];
				    j=nxt[j];
				}
				else flag=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
