#include<bits/stdc++.h>
using namespace std;
int T,l,xy[140000][27],x,ba[140000],fr[140000],cnt;
string s,a;
map<char,int> m1,m2;
int mth(string s1,int k)
{
	int ass=0;
	for(int i=0;i+k<l;i+=k)
	{
		int flag=0;
		for(int j=0;j<k;j++)
		{
			if(s1[j]!=s[j+i])
			{
				flag=1;
				break;
			}
		}
		if(flag!=0)
		break;
		ass+=xy[k-2][ba[i+k]];
		//cout<<s1<<' '<<i+k<<' '<<xy[k-2][ba[i+k]]<<endl;
	}
	//hf(s1,k,ass);
	return ass;
}
//int hf(string s1,int k,int cs)
//{
//	int ass=0;
//	
//}
int doo()
{
	int qw=0;
	for(int i=2;i<l;i++)
	{
		int tt=0;
		if(i%2==0)
		{
			if((l-i)%2==0)
			{
				tt=((i-1)/2)*((l-1)/i);
			}
			else
			{
				tt=(i-1)*((l-1)/i);
			}
		}
		else
		{
			if((l-i)%2==0)
			{
				tt=((i-1)/2)*((l-1)/i-(l-1)/(2*i))+(i-1)*((l-1)/(2*i));
			}
			else
			{
				tt=(i-1)*((l-1)/i-(l-1)/(2*i))+((i-1)/2)*((l-1)/(2*i));
			}
		}
		//cout<<tt<<' '<<i<<endl;
		qw+=tt;
	}
	cout<<qw<<endl;
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(;T>0;T--)
	{
		int ans=0;
		cnt=0;
		cin>>s;
		a=s[0];
		l=s.size();
		m1.clear();
		m2.clear();
		fr[0]=1;
		m1[s[0]]++;
		cnt++;
		for(int i=1;i<l;i++)
		{
			m1[s[i]]++;
			if(m1[s[i]]%2==0)
			fr[i]=fr[i-1]-1;
			else
			fr[i]=fr[i-1]+1;
			if(m1[s[i]]==1)
			cnt++;
		}
//		for(int i=0;i<l;i++)
//		{
//			cout<<fr[i]<<' ';
//		}
//		cout<<endl;
		
		
		if(cnt==1)
		{
			doo();
			continue;
		}
		
		
		ba[l-1]=1;
		m2[s[l-1]]++;
		for(int i=l-2;i>=0;i--)
		{
			m2[s[i]]++;
			if(m2[s[i]]%2==0)
			ba[i]=ba[i+1]-1;
			else
			ba[i]=ba[i+1]+1;
		}
//		for(int i=0;i<l;i++)
//		{
//			cout<<ba[i]<<' ';
//		}
//		cout<<endl;
		xy[0][0]=0;
		for(int j=1;j<=26;j++)
		{
			if(fr[0]<=j)
			xy[0][j]=1;
			else
			xy[0][j]=0;
		}
		for(int i=1;i<l;i++)
		{
			for(int j=0;j<=26;j++)
			{
				if(fr[i]<=j)
				xy[i][j]=xy[i-1][j]+1;
				else
				xy[i][j]=xy[i-1][j];
			}
		}
//		for(int i=0;i<l;i++)
//		{
//			for(int j=0;j<=l;j++)
//			{
//				cout<<xy[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for(int i=1;i<l-1;i++)
		{
			a+=s[i];
			ans+=mth(a,i+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
