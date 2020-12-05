#include<bits/stdc++.h>
using namespace std;
bool cmpsng(string a,string b)
{
	int apr[29]={0},bpr[29]={0},asum=0,bsum=0;
	for(int i=0;i<a.length();i++)
	apr[a[i]-96]++;
	for(int i=0;i<b.length();i++)
	bpr[b[i]-96]++;
	for(int i=1;i<=26;i++)
	{
		if(apr[i]&1)asum++;
		if(bpr[i]&1)bsum++;
	}
	if(asum<=bsum)return true;
	else return false;	
}
bool single(string a)
{
	char s=a[0];
	for(int i=1;i<a.length();i++)
	if(a[i]!=a[0])return false;
	else return true;
}
void Workon(string s)
{
	int len=s.length();
	string A="",B="",C="";
	int ans=0;
	for(int i=0;i<len-2;++i)
	{
		A+=s[i];
		B="";
		for(int j=i+1;j<len-1;j++)
		{
			B+=s[j];
			C="";
			int td=j+1;
			for(int k=j+1;k<len;k++)
				C+=s[k];
			if(cmpsng(A,C))ans++;
			for(int k=0;;k++)
			{
				if(td+A.length()+B.length()>=len)break;
				string copyA="",copyB="";
				C="";
				for(int l=td;l<=td+A.length()-1;l++)
					copyA+=s[l];
				if(copyA!=A)break;
				td=td+A.length();
				for(int l=td;l<=td+B.length()-1;l++)
					copyB+=s[l];
				if(copyB!=B)break;
				td=td+B.length();
				for(int l=td;l<len;l++)
				C=C+s[l];
				if(cmpsng(A,C))ans++;
			}
		}	
	}
	cout<<ans<<endl;
}
long long sum1(long long x)
{
	return (1+x)*x/2;
}
long long sum2(long long x)
{
	return (1+x)*((x-1)/2+1)/2;
}
int T;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>s;
		Workon(s);
	}
}
