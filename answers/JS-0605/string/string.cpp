#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5e4;
char s[N];
int p[N];
bool pd[N];
int f(int,int);
int cz(int,int);
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>(s+1);
		int ls=strlen(s+1);

		int j=0;
		for(int i=2;i<=ls;++i)
		{
			while(j>0&&s[i]!=s[j+1])
			{
				j=p[j];
			}
			if(s[i]==s[j+1])
			{
				j++;
			}
			p[i]=j;
		}
//		if(ls%(ls-p[ls])==0)cout<<ls/(ls-p[ls]);

		for(int i=1;i<=ls-2;++i)
		{
			int f1=f(ls-i+1,ls);
			ans+=cz(ls-i,f1);
			if((ls-i)%(ls-i-p[ls-i])==0&&p[ls-i]!=0)
			{
				ans+=cz(ls-i-p[ls-i],f1);
				int u=(ls-i)/(ls-i-p[ls-i]);
//				if(u%2==0)
//				{
					for(int j=2;j*j<=u;++j)
					{
						if(u%j==0)
						{
							ans+=cz((ls-i-p[ls-i])*j,f1);
							if(j!=(u/j))
							ans+=cz((ls-i-p[ls-i])*(u/j),f1);
						}
					}
				}
//			}
/*			for(int j=1;j<=ls-i-1;++j)
			{
				int f2=f(1,j);
				if(f2<=f1)
				{
					ans++;
					cout<<f1<<" "<<f2<<"   ";
					for(int k=1;k<=ls;++k)
					{
						cout<<s[k];
						if(k==j||k==ls-i)cout<<" ";
					}
					cout<<"\n";

				}
				
			}
*/			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
int f(int l,int r)
{
	int z[30];
	memset(z,0,sizeof(z));
	for(int i=l;i<=r;++i)
	{
		z[s[i]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;++i)
	{
		if(z[i]%2!=0)
		{
			ans++;	
		}	
	}
	return ans;
}
int cz(int r,int f1)
{
	int ans=0;
	for(int j=1;j<=r-1;++j)
	{
		int f2=f(1,j);
		if(f2<=f1)
		{
			ans++;
		}
	}
	
	return ans;
}
