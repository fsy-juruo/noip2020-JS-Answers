#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
map<char,bool> pan;
char a1,a2;
int T,t,ans;
string str;
int ys[40000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			if(i==0) a1=str[i];
			if(str[i]!=a1) a2=str[i];
			m[str[i]]++;
			if(!pan[str[i]]) t++;
			pan[str[i]]=true;
		}
		if(t==1)
		{
			for(int i=1;i<=str.length()-2;i+=2)
			{
				ans+=str.length()-i-1;
			}
			for(int i=2;i<=str.length()-2;i+=2)
			{
				ans+=(str.length()-i)>>1;
				ans--;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
