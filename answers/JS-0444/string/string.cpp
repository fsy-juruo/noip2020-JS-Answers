#include<bits/stdc++.h>
using namespace std;
int v[100001];
inline void read(int &x)
{
	char ch;int f=1;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f;
}
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x,char ch)
{
	write(x);
	putchar(ch);
}
int f[100001],f1[100001],f2[100001],ans,t;
string s;
void solve(string s)
{
	ans=0;
	memset(f,0,sizeof(f));
	string s1="",s2="";
	for(int i=0;i<s.size();i++)
	{
		s1=s1+s[i];
		s2="";
		for(int j=i+1;j<s.size();j++)
		{
		    s2=s2+s[j];
		    //s3.erase(j,1);
		    for(int k=j+1;k<s.size();k++)
		    {
		    	int q=(k-j-1)%(j+1);
		    	if(q==0) {if(f2[i]<=f1[k])ans++;}
		    	if(q<=i){if(s[k]!=s1[q])break;}
			    else if(s[k]!=s2[q-i-1])break;
		    } 
		}
	}
}
void INit(string s)
{
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f,0,sizeof(f));
	for(int i=s.size()-1;i>=0;i--)
	{
		f[s[i]]++;
		if(f[s[i]]%2==0)f1[i]=f1[i+1]-1;
		else f1[i]=f1[i+1]+1;
	}
	memset(f,0,sizeof(f));
	for(int i=0;i<s.size();i++)
	{
		f[s[i]]++;
		if(f[s[i]]%2==0)f2[i]=f2[i-1]-1;
		else f2[i]=f2[i-1]+1;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	
    cin>>s;
    INit(s);
 //   for(int i=0;i<s.size();i++)cout<<f1[i]<<' ';cout<<endl;
//	for(int i=0;i<s.size();i++)cout<<f2[i]<<' ';cout<<endl;
	
    solve(s);
    cout<<ans<<endl;
	}
	
	return 0;
}

