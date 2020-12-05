#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define rg register
bool ok[MAXN+5][MAXN+5];
int s[MAXN+5];
int n;
int cc[35];//count of each letter
int oddpre[MAXN];//equal to
int rev[35];//count of each letter(rev)
int oddrev[MAXN];//equal to

void solve()
{
	for (rg int i=0;i<26;i++) cc[i]=0;
	memset(ok,false,sizeof(ok));
	for (rg int i=1;i<=n;i++)
	{
		ok[i][i]=true;
		for (rg int j=1;j<int(n/i);j++)
		{
			bool f=true;
			for (rg int k=1;k<=i;k++)
			{
				if (s[k]!=s[k+j*i]) {f=false;break;}
			}
			if (f) ok[i][i+i*j]=true;else break;
		}
	}
//	cout<<ok[1][1]<<endl;
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=i;j<=n;j++)
//		{
//			cout<<'('<<i<<" , "<<j<<") :"<<ok[i][j]<<endl;
//		}
//	}
//	
	memset(rev,0,sizeof(rev));memset(oddrev,0,sizeof(oddrev));
	oddrev[n]=1;rev[s[n]]++;
	for (int i=n-1;i>=1;i--) 
	{
		rev[s[i]]++;
		if (rev[s[i]]%2==1) oddrev[i]=oddrev[i+1]+1;else oddrev[i]=oddrev[i+1]-1;
	}
	memset(oddpre,0,sizeof(oddpre));memset(cc,0,sizeof(cc));
	for (int i=1;i<=n;i++)
	{
		cc[s[i]]++;
		if (cc[s[i]]%2==1) oddpre[i]=oddpre[i-1]+1;else oddpre[i]=oddpre[i-1]-1;
	}
	long long ans=0;
	for (int i=3;i<=n;i++)//c:i....n
	{
		long long sum=0;
		for (int j=2;j<=i-1;j++)
		{
			if (oddpre[j-1]<=oddrev[i]) sum++;
			if (ok[j][i-1]) ans+=sum;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;cin>>T;char c;
	string str;
	while (T--)
	{
		cin>>str;
		for (int i=0;i<str.length();i++) s[i+1]=int(str[i])-97;
		n=str.length();
		solve();
	}
	return 0;
}

