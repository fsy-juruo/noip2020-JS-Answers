#include<bits/stdc++.h>
using namespace std;
int totchfor13[30],otfor13[2000000];
inline int read()
{
	char c=getchar();
	int x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
inline void write(long long x)
{
	if(!x)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int sta[20],tp=0;
	while(x)
	{
		sta[++tp]=x%10;
		x/=10;
	}
	while(tp)
		putchar(sta[tp--]+'0');
	putchar('\n');
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read(),n,i,j,k;
	long long ans;
	string s;
	while(T--)
	{
		cin>>s;
		n=s.size();
		s="#"+s;
		ans=0;
		for(i=2;i<=n;i++)
			if(s[i]!=s[i-1])
				break;
		if(i>n)
		{
			for(i=n;i>2;i--)
			{
				if((n-i)&1)
				{
					for(j=1;j*j<=i-1;j++)
						if((i-1)%j==0)
						{
							if(j!=(i-1)/j)
								ans+=(j-1ll)/2+((i-1)/j-1ll)/2;
							else
								ans+=(j-1ll)/2;
						}
				}
				else
				{
					for(j=1;j*j<=i-1;j++)
						if((i-1)%j==0)
						{
							if(j!=(i-1)/j)
								ans+=j-1ll+(i-1)/j-1ll;
							else
								ans+=j-1ll;
						}
				}
			}
			write(ans);
			continue;
		}
		for(i=0;i<27;i++)
			totchfor13[i]=0;
		otfor13[n+1]=0;
		for(i=n;i;i--)
		{
			totchfor13[s[i]-'a']++;
			if(totchfor13[s[i]-'a']&1)
				otfor13[i]=otfor13[i+1]+1;
			else
				otfor13[i]=otfor13[i+1]-1;
		}
		for(i=0;i<27;i++)
			totchfor13[i]=0;
		int tof13i=0;
		string A="",B,tt;
		for(i=1;i<=n;i++)
		{
			totchfor13[s[i]-'a']++;
			if(totchfor13[s[i]-'a']&1)
				tof13i++;
			else
				tof13i--;
			A+=s[i];
			B="";
			for(j=i+1;j<=n;j++)
			{
				B+=s[j];
				tt=A+B;
				for(k=j+1;k<=n;k+=tt.size())
				{
					if(tof13i<=otfor13[k])
						ans++;
					int ne;
					for(ne=0;ne<tt.size();ne++)
						if(s[k+ne]!=tt[ne])
							break;
					if(ne<tt.size())
						break;
				}
			}
		}
		write(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
