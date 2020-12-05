#include<bits/stdc++.h>
using namespace std;

int t;
string s;
long long len;

int count(string a,char b)
{
	int cnt=0;
	for(int i=0;i<a.size();i++)
	if(a[i]==b) cnt++;
	return cnt;
}

int prime[10000],cnt=0;
bool isprime[100000];

int ysfj(int x)
{
	int ans=1;
	for(int i=1;prime[i]*prime[i]<=x;i++)
	{
		int tot=0;
		while(x%prime[i]==0)
		{
			tot++;
			x=x/prime[i];
		}
		ans=ans*(tot+1);
	}
	return ans;
}

bool check(int a,int b)
{
	vector <char> va,vb;
	map <char,bool> insa,insb; 
	map <char,int> mpa,mpb;
	int cnta=0,cntb=0;
	for(int i=0;i<a;i++)
	{
		mpa[s[i]]++;
		if(!insa[s[i]]) va.push_back(s[i]);
	}
	for(int i=s.size()-b-1;i<s.size();i++)
	{
		mpb[s[i]]++;
		if(!insb[s[i]]) vb.push_back(s[i]);
	}
	for(int i=0;i<va.size();i++)
		if(mpa[va[i]]%2==1) cnta++;
	for(int i=0;i<vb.size();i++)
		if(mpb[vb[i]]%2==1) cntb++;
	return cnta<=cntb;
}

string str(int x,int y)
{
	string mmp;
	for(int i=x;i<=y;i++) mmp+=s[i];
	return mmp;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	memset(isprime,1,sizeof(isprime));
	isprime[1]=0;
	isprime[2]=1;
	for(int i=2;i<=65536;i++)
	{
		if(isprime[i])
		{
			prime[++cnt]=i;
			for(int j=2;j<=65536/i;j++)
			{
				isprime[j*i]=0;
			}
		}
	}
while(t--)
{
	cin>>s;
	int ans=0;
	len=s.size();
	if(len<=100)
	{
		for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
		for(int k=1;k<=len-2;k++)
		{
			if((len-k)%(i+j)!=0||i+j+k>len) continue;
			if(!check(i,k)) continue;
			string a=str(0,i-1),b=str(i,i+j-1),c=str(len-k,len-1);
//			cout<<a<<" "<<b<<" "<<c<<endl;
			bool pd=1;
			for(int p=1;p<(len-k)/(i+j);p++)
			{
				string d=str((i+j)*p,(i+j)*(p+1)-1);
//				cout<<d<<" & "<<a+b<<endl;
				if(d!=a+b) pd=0;
			}
			if(pd) ans++;
		}
		cout<<ans<<endl;
		continue;
	}
	if(count(s,s[0])==len)
	{
		for(int i=1;i<=len-2;i++)
		{
			for(int j=2;j<=len-i;j++)
			{
				if((len-i)%j==0) ans+=(j-1);
			}
		}
	}
	cout<<ans<<endl;
}
	return 0;
}
