#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

long long T,odd[1010][2],canuse[1010][30],cnt[1010][26][2];
bool isok[1010][1010];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(odd,0,sizeof odd);
		memset(canuse,0,sizeof canuse);
		memset(cnt,0,sizeof cnt);
		cin>>s;
		int ss=s.size();
		cnt[0][s[0]-'a'][0]=1;
		odd[0][0]=odd[0][1]=1;
		for(int i=1;i<ss;i++)
			for(int j=0;j<26;j++)
			{
				cnt[i][j][0]=cnt[i-1][j][0]+(s[i]=='a'+j);
				odd[i][0]+=cnt[i][j][0]%2;
			}
		cnt[0][s[ss-1]-'a'][1]=1;
		for(int i=1;i<ss;i++)
			for(int j=0;j<26;j++)
			{
				cnt[i][j][1]=cnt[i-1][j][1]+(s[ss-i-1]=='a'+j);
				odd[i][1]+=cnt[i][j][1]%2;
			}
		/*for(int k=0;k<2;k++)
		{
			for(int i=0;i<ss;i++)
			{
				for(int j=0;j<26;j++)
					cout<<cnt[i][j][k]<<' ';
				cout<<endl;
			}
			cout<<endl;
		}
		cout<<endl;
		for(int k=0;k<2;k++)
		{
			for(int i=0;i<ss;i++)
				cout<<odd[i][k]<<' ';
			cout<<endl;
		}*/
		for(int i=0;i<ss;i++)
			for(int j=0;j<26;j++)
				for(int k=0;k<=i;k++)
					if(odd[k][0]<=j)
						canuse[i][j]++;
		/*for(int i=0;i<ss;i++)
		{
			for(int j=0;j<26;j++)
				cout<<canuse[i][j]<<' ';
			cout<<endl;
		}*/
		long long ans=0;
		for(int i=2;i<ss;i++)
		{
			string str=s.substr(0,i);
			ans+=canuse[i-2][odd[ss-i-1][1]];
			int j=i;
			while(1)
			{
				if(j+i>=ss || str!=s.substr(j,i))
					break;
				j+=i;
				ans+=canuse[i-2][odd[ss-j-1][1]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

