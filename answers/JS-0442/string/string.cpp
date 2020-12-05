#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int b[26];
int c[26];
long long ans1[1005],ans2[1005]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int t=a.size();
		if(a.size()<3)
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<=a.size()-3;j++)
		{
			b[a[j]-97]++;
			if(j==0) ans1[j]=1;
			else if(b[a[j]-97]%2==0) ans1[j]=ans1[j-1]-1;
			else ans1[j]=ans1[j-1]+1;
		}
		for(int j=a.size()-1;j>=2;j--)
		{
			c[a[j]-97]++;
			if(j==a.size()-1) ans2[j]=1;
			else if(c[a[j]-97]%2==0) ans2[j]=ans2[j+1]-1;
			else ans2[j]=ans2[j+1]+1;
		}
		long long ans=0;
		for(int j=0;j<=a.size()-3;j++)
			for(int k=2+j;k<=a.size()-1;k++)
				if(ans2[k]>=ans1[j])
					ans++;
		if(a.size()==5)
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-1]) ans++;
		if(a.size()==6)
		{
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-2])
				ans++;
		}
		if(a.size()==7)
		{
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[1]<=ans2[t-1]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[0]<=ans2[t-1]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&ans1[0]<=ans2[t-1]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-3]) ans++;
		}
		if(t==8)
		{
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[1]<=ans2[t-2]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[0]<=ans2[t-2]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&ans1[0]<=ans2[t-2]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-4]) ans++;
		}
		if(t==9)
		{
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[2]<=ans2[t-1]) ans++;
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[1]<=ans2[t-1]) ans++;
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[0]<=ans2[t-1]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[1]<=ans2[t-3]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[0]<=ans2[t-3]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&a[0]==a[6]&&a[1]==a[7]&&ans1[0]<=ans2[t-1]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&ans1[0]<=ans2[t-3]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-5]) ans++;
		}
		if(t==10)
		{
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[2]<=ans2[t-2]) ans++;
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[1]<=ans2[t-2]) ans++;
			if(a[0]==a[4]&&a[1]==a[5]&&a[2]==a[6]&&a[3]==a[7]&&ans1[0]<=ans2[t-2]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&a[0]==a[6]&&a[1]==a[7]&&a[2]==a[8]&&ans1[1]<=ans2[t-1]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&a[0]==a[6]&&a[1]==a[7]&&a[2]==a[8]&&ans1[0]<=ans2[t-1]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[1]<=ans2[t-4]) ans++;
			if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5]&&ans1[0]<=ans2[t-4]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&a[0]==a[6]&&a[1]==a[7]&&ans1[0]<=ans2[t-2]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&a[0]==a[4]&&a[1]==a[5]&&ans1[0]<=ans2[t-4]) ans++;
			if(a[0]==a[2]&&a[1]==a[3]&&ans1[0]<=ans2[t-6]) ans++;
		}
		cout<<ans<<endl;
		for(int j=0;j<=25;j++)
			b[j]=c[j]=0;
	}
	return 0;
}
