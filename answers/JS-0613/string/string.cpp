#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return flag?x:~(x-1);
}
void fre()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int T,n,num[26],pe[1100000],su[1100000];
string s;
signed main()
{
	fre();
	T=read();
	while(T--)
	{
		cin>>s;
		n=s.size();
		int ans=0;
		pe[0]=su[n+1]=0;
		for(int i=0;i<26;i++)
			num[i]=0;
		for(int i=1;i<=n;i++)
		{
			num[s[i-1]-'a']++;
//			cout<<num[s[i-1]-'0']<<endl;
			if(num[s[i-1]-'a']&1)
				pe[i]=pe[i-1]+1;
			else
				pe[i]=pe[i-1]-1;
		}
		for(int i=0;i<26;i++)
			num[i]=0;
		for(int i=n;i>=1;i--)
		{
			num[s[i-1]-'a']++;
//			cout<<num[s[i-1]-'a']<<endl;
			if(num[s[i-1]-'a']&1)
				su[i]=su[i+1]+1;
			else
				su[i]=su[i+1]-1;
		}
/*		for(int i=1;i<=n;i++)
			cout<<pe[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<su[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=n-2;i++)
			for(int l=i+2;l<=n;l++)
				if(pe[i]<=su[l])
				{
//					cout<<i<<" "<<l<<endl;
					ans++;
					int rest=l-1;
					for(int j=2;j*(i+1)<=rest;j++)
						if(rest%j==0)
						{
							string ab=s.substr(0,rest/j);
							bool flag=1;
							for(int k=rest/j;k<rest;k+=rest/j)
								if(s.substr(k,rest/j)!=ab)
								{
									flag=0;
									break;
								}
							ans+=flag;
						}
				}
		cout<<ans<<endl;
	}
	return 0;
}

