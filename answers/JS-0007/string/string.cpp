#include<bits/stdc++.h>
using namespace std;
//2^20=1048576
int /*jishu[1050000][26],*/sz,ans,sm,sss;
bitset<26>jishu[1050000];
set<pair<int,int> >S;
char s[1050000];
inline bool ok(int x,int y)
{
//	sss++;
	int s1=jishu[x].count(),s2=(jishu[sz]^jishu[y-1]).count();
//	for(int i=0;i<26;i++)
//	{
//		if(jishu[x][i]&1)
//			s1++;
//		if((jishu[sz][i]-jishu[y-1][i])&1)
//			s2++;
//	}
	return s1<=s2;
}
inline int sushu(int x)
{
	if(x==2)return 0;
	for(register int i=2;i*i<=x;++i)
	{
		if(x%i==0)
			return x;
	}
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		S.clear();
		sm=1;
		ans=0;
		char ch;
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		for(register int i=1;ch>='a'&&ch<='z';++i)
		{
			s[i]=ch;
			if(ch!=s[1])sm=0;
			jishu[i]=jishu[i-1];
			jishu[i][ch-'a']=(~jishu[i][ch-'a']);
			ch=getchar();
			sz=i;
		}
		if(sm)
		{
			for(int i=2;i<sz;++i)
			{
				for(int j=1;i*j<sz;++j)
				{
					if((sz-i*j)&1)
					{
						ans+=i-1;
					}
					else
					{
						ans+=int((i-1)/2);
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=2;i<sz;++i)
		{
			for(int j=1;i*j<sz;++j)
			{
				int ss=sushu(i);
				if(ss!=0&&S.find(make_pair(i/ss,j*ss))!=S.end())
				{
					S.insert(make_pair(i/ss,j*ss));
					for(int k=1;k<i;k++)
						if(ok(k,i*j+1))
							ans++;
				}
				bool f=1;
				for(int l=i+1;l<=i*j;++l)
				{
					if(s[l]!=s[l-i])
					{
						f=0;
						break;
					}
				}
				if(!f)
					continue;
				S.insert(make_pair(i,j));
				for(int k=1;k<i;++k)
					if(ok(k,i*j+1))
						ans++;
			}
		}
		cout<<ans<<endl;
	}
//	cout<<sss;
	return 0;
}
//2519708

