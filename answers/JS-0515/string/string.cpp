#include<bits/stdc++.h>
using namespace std;
template<typename T>void Read(T &cn)
{
	char ch;
	int f=0;
	cn=0;
	while(!isdigit(ch=getchar()))if(ch=='-')f=1;
	if(f){cn=cn*10+48-ch;while(isdigit(ch=getchar()))cn=cn*10+48-ch;}
	else {cn=cn*10+ch-48;while(isdigit(ch=getchar()))cn=cn*10+ch-48;}
}
long long  h[50],pr[100010],su[100010],pl[100010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,tt;
	Read(T);
	while(T--)
	{
		ans=0;
		string s;
		cin>>s;
		long long n=s.size();
		if(n<3)
		{
			cout<<0<<endl;continue;
		}
		memset(pr,0,sizeof(pr));
		memset(h,0,sizeof(h));
		memset(su,0,sizeof(su));
		for(int i=0;i<n;i++)
		{
			h[s[i]-'a'+1]++;
			for(int j=1;j<=26;j++)if(h[j]&1)pr[i]++;
		}
		tt=0;
		for(int i=1;i<=26;i++)tt+=(h[i]>=1);
		if(tt>=2)
		{
			
			memset(h,0,sizeof(h));
			for(int i=n-1;i>=0;i--)
			{
				h[s[i]-'a'+1]++;
				for(int j=1;j<=26;j++)if(h[j]&1)su[i]++;
			}
	//		for(int i=0;i<n;i++)cout<<pr[i]<<' ';
	//		cout<<endl;
	//		for(int i=0;i<n;i++)cout<<su[i]<<' ';
	//		cout<<endl;
			int f;
			for(int i=0;i<n-2;i++)
			{
				for(int j=i+1;j<n-1;j++)
				{
					f=0;
					for(int k=1;k<=(n-1)/(j+1);k++)
					{
						if(pr[i]>su[(j+1)*k])continue;
						if(k!=1)
						for(int l=1;l<=j+1;l++)
						if(s[l-1]!=s[(j+1)*(k-1)+l-1]){f=1;break;}
						if(f)break;
						cout<<i<<' '<<j<<' '<<k<<endl;
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			long long qk;
			if(n%2==1)
			{
				if((n-1)%4==0)
				{
					qk=3*n-5;
					qk/=2;
					long long l=n-1;
					l/=4;
					qk*=l;
				}
				else
				{
					qk=3*n-5;
					qk/=4;
					long long l=n-1;
					l/=2;
					qk*=l;
				}
				long long res,ans=0;
				for(int i=3;i<n;i++)
				{
					res=0;
					for(int j=2;j*j<=i;j++)
					{
						if(i%j==0)
						{
							if(j*j==i)
							{
								if(i%2==1)res+=(j-1)/2;
								else res+=j-1;
							}
							else if(i%2==1)res+=(j-1)/2+(i/j-1)/2;
								 else res+=j-1+(i/j)-1;
						}
						if(res!=0)
						{
							ans+=res;
							res=0;
						}
					}
				}
				ans+=qk;
				cout<<ans<<endl;
			}
			else
			{
				if((n-2)%4==0)
				{
					qk=3*n-4;
					qk/=2;
					long long l=n-2;
					l/=4;
					qk*=l;
				}
				else
				{
					qk=3*n-4;
					qk/=4;
					long long l=n-2;
					l/=2;
					qk*=l;
				}
				long long res1,ans1=0;
				for(int i=3;i<n;i++)
				{
					res1=0;
					for(int j=2;j*j<=i;j++)
					{
						if(i%j==0)
						{
							if(j*j==i)
							{
								if(i%2==0)res1+=(j-1)/2;
								else res1+=j-1;
							}
							else if(i%2==0)res1+=(j-1)/2+(i/j-1)/2;
								 else res1+=j-1+i/j-1;
						}
						if(res1!=0)
						{
							ans1+=res1;
							res1=0;
						}
					}
				}
				ans1+=qk;
				cout<<ans1<<endl;
			}
		}
	}
	return 0;
}
/*
1
aaaaaaaaaaaaaaaa
*/

