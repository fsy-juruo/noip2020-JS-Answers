#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+5;
int T;
int num[26],l,a,b,c,fc,fa[N],na[26];
long long ans;
string s;
int fi(int k)
{
	int S=1;
	while(S*k<=l)
	{
		for(int i=1;i<=k;i++)
		{	
			if(s[i]!=s[i+k*S]) return S;
		}
		S++;
	}
	return S;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cin>>s;
		l=s.size();
		fc=0;
		ans=0;
		if(l<=2) 
		{
			cout<<0<<endl;
			continue;
		}
		s=" "+s;
		for(int i=1;i<=l;i++)
		{
			num[s[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			if(num[i]%2==1) fc++;
		}
		for(int i=1;i<l;i++)
		{
			int e=s[i]-'a';
			na[e]++;
			if((num[e]-na[e])%2==1) fc++;
			else fc--;
			if(na[e]%2==1) fa[i]=fa[i-1]+1;
			else fa[i]=fa[i-1]-1;
			if(i==1) continue;
			int d=0;
			int n;
			if(i<=l/2) n=fi(i);
			else n=1;
			while(n*i>=l) n--;
			for(int q=1;q<=n;q++)
			{
				int sc=0;
				for(int k=0;k<26;k++)
				{
					if((num[k]-na[k]*q>0)&&((num[k]-na[k]*q)%2==1)) sc++;
				}
				for(int j=1;j<i;j++)
				{
					if(fa[j]<=sc) 
					{
						d++;
						//cout<<j<<" "<<i<<" "<<q<<" "<<sc<<endl;
					}
				} 
			}
			ans+=d;
			//cout<<ans<<endl;		
		} 
		cout<<ans<<endl;
	}
	return 0;
}


