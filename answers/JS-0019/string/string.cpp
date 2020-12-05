#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int t,n,ans,a[1300000];
char s[1300000];
bool b[26][1300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,k,l;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>s;
		n=strlen(s);
		b[s[0]-97][0]=1;
		a[0]=s[0]-97;
		for(i=1;i<n;i++)
		{
			a[i]=s[i]-97;
			a[i]+=a[i-1];
			for(j=0;j<26;j++)
			b[j][i]=b[j][i-1];
			b[s[i]-97][i]=1-b[s[i]-97][i];
		}
		for(i=2;i<=n-1;i++)
		{
			for(j=2;i*j<n;j++)
			{
				bool flag=1;
				for(k=0;k<i;k++)
				if(s[k]!=s[(j-1)*i+k])
				{
					flag=0;
					break;
				}
				if(flag==0)
				{
					j--;
					break;
				}
			}
			if(i*j>=n)j--;
			for(k=1;k<=j;k++)
			{
				int v=0;
				for(l=0;l<26;l++)
				v+=(b[l][i*k-1]^b[l][n-1]);
				int u=1;
				if(u<=v)ans++;
				for(l=1;l<i-1;l++)
				{
					u=u+b[s[l]-97][l]-b[s[l]-97][l-1];
					if(u<=v)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

