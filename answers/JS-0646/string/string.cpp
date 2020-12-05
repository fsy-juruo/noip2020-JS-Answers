#include<bits/stdc++.h>
using namespace std;
string s;
int a1[2000010],a2[2000010],k1[500]={0},k2[500]={0},ans=0,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(k1,0,sizeof(k1));
		memset(k2,0,sizeof(k2));
		cin>>s;
		a1[0]=0;
		a2[s.length()+1]=0;
		ans=0;
		for(int j=1;j<=s.length();j++)
		{
			k1[s[j-1]]++;
			if(k1[s[j-1]]%2==1)
			a1[j]=a1[j-1]+1;
			else
			a1[j]=a1[j-1]-1;
			k2[s[s.length()-j]]++;
			if(k2[s[s.length()-j]]%2==1)
			a2[s.length()-j+1]=a2[s.length()-j+2]+1;
			else
			a2[s.length()-j+1]=a2[s.length()-j+2]-1;
		}
		for(int j=1;j<=s.length()-2;j++)
		{
			for(int k=j+1;k<=s.length()-1;k++)
			{
				if(a1[j]<=a2[k+1])
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
