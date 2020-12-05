#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int t,A[27][1<<20],C[1<<20],f[1<<20];string s;
/*草草草 做个鸡掰题目*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s;int b[50]={0},v[50]={0},ans=0,cnt=1,g=0;
		b[s[0]-'a']=v[s[s.size()-1]-'a']=1,C[s.size()-1]=1;
		for(int i=1;i<=26;i++)A[i][0]=1;
		for(int i=1,j=s.size()-2;i<s.size();i++,j--)
		{
			b[s[i]-'a']++,v[s[j]-'a']++;int p=1;
			for(int k=0;k<=26;k++)A[k][i]=A[k][i-1];
			if(b[s[i]-'a']%2)
			for(int l=++cnt;l<=26;l++)A[l][i]++;
			else for(int l=--cnt;l<=26;l++)A[l][i]++;
			if(v[s[j]-'a']%2)C[j]=C[j+1]+1;
			else C[j]=C[j+1]-1;
			if(s[i]!=s[i-1])g=1;
		}
		if(g)
		for(int i=2;i<s.size();i++)
		{
			if(i-1>=s.size()/2)
			{
				ans+=A[C[i]][i-2];
				continue;
			}
			string tmp=s.substr(0,i);
			int now=i;
			while(now<s.size()&&tmp==s.substr(now-i,i))
			{
				ans+=A[C[now]][i-2];
				now+=i;
			//	cout<<tmp<<" "<<s.substr(now-i,i)<<endl;
			}
		}
		else
		for(int i=2;i<s.size();i++)
		{
			int now=i;
			while(now<s.size())
			{
				ans+=A[C[now]][i-2];
				now+=i;
			//	cout<<tmp<<" "<<s.substr(now-i,i)<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
