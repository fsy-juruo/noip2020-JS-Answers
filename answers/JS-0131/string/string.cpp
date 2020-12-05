#include<bits/stdc++.h>
using namespace std;
long long t,ans,l,flag,a[30],fro[1010],beh[1010],cnt,s1[2010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s;
		ans=0;
		l=s.size();
		for(int i=0;i<l;i++)
		s1[i+1]=s[i];
		for(int i=1;i<=l;i++)
		{
			int b=s1[i]-'a';
			a[b]++;
			if(a[b]%2!=0)fro[i]=fro[i-1]+1;
			else fro[i]=fro[i-1]-1;
		}
		memset(a,0,sizeof(a));
		for(int i=l;i>0;i--)
		{
			int b=s1[i]-'a';
			a[b]++;
			if(a[b]%2!=0)beh[i]=beh[i+1]+1;
			else beh[i]=beh[i+1]-1;
		}
		for(int i=1;i<l-1;i++)
		for(int j=i+1;j<l;j++)
		for(int k=j+1;k<=l;k+=j)
		{
			flag=0;cnt=j;
			if(fro[i]>beh[k])continue;
			char c[2010];
			for(int p=1;p<=j;p++)
			{
				c[p-1]=s1[p];
			}
			for(int p=j+1;p<k;p++)
			{
				if(s1[p]!=c[(p-1)%cnt]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
