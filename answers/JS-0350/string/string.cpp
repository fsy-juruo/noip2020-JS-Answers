#include<bits/stdc++.h>
using namespace std;
string s;
int t,len=0,ans=0,cnt1[2000],cnt2[2000];
bool check(int start,int L,int n)
{	
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	bool flag=1;
	string a,b,c;
	a.clear();
	b.clear();
	c.clear();
	for(int i=0;i<start;i++)a+=s[i],cnt1[s[i]-'a'+1]++;
	for(int i=start;i<L;i++)b+=s[i]; 
	for(int i=n*L;i<len;i++)c+=s[i],cnt2[s[i]-'a'+1]++;	
	if(a==b||b==c||c==a)return 0;
	for(int i=2;i<=n;i++)
	{
		string a1,b1;
		a1.clear();
		b1.clear();
		for(int j=(i-1)*L-1;j<=(i-1)*L+start-1;j++)a1+=s[j];
		for(int j=(i-1)*L+start;j<=i*L-1;j++)b1+=s[i];
	//	cout<<" "<<a1<<"----"<<b1<<"----"<<endl;
		if(a!=a1||b!=b1)
		{
			flag=0;
			break;
		}		
	}
	int t1=0,t2=0;
	for(int i=1;i<=26;i++)
	{
		if(cnt1[i]%2==1)t1+=cnt1[i];
		if(cnt2[i]%2==1)t2+=cnt2[i];		
	}
	if(t1>t2)flag=0;
	return flag;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>s;
		len=s.length();
		for(int lab=2;lab<=len-1;lab++)//AB总长度 
			for(int num=1;num<=lab/2;num++)//AB个数 
				if(lab%num==0)
				{

					int l=lab/num;//AB长度 
					for(int k=1;k<l;k++)
						if(check(k,l,num))ans++;
				}
		cout<<ans<<endl;
	} 
	return 0;
}
