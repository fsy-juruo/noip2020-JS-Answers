#include <bits/stdc++.h>
using namespace std;
string s;
int siz,ans,compf[1100000];
bool f[30],fa[30],fb[30];
void init()
{
	int index;
	compf[0]=0;
	for(int i=1;i<siz;++i)
	{
		index=0;
		while(i+index<siz&&s[index]==s[i+index]&&index<i) index++;
		compf[i]=index;
	}
}
bool comp(int x,int l)
{
//	if(x+l-1>=siz) return 0;
//	for(int i=0;i<l;++i)
//	{
//		if(s[i]!=s[x+i]) return 0;
//	}
//	return 1;
	if(compf[x]>=l) return 1;
	return 0;
}
void check(int tm)
{
	int a=0,c=0;
	for(int i=0;i<26;++i) if(fa[i]) ++a;
	if(tm%2)
	{
		for(int i=0;i<26;++i) if(f[i]^fa[i]^fb[i]) ++c;
	}
	else
	{
		for(int i=0;i<26;++i) if(f[i]) ++c;
	}
	if(a<=c) ++ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=0,index,tt;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		cin>>s;
		siz=s.size();
		ans=0;
		init();
		for(int i=0;i<26;++i)
		{
			f[i]=0; fa[i]=0;
		}
		for(int i=0;i<siz;++i) f[s[i]-'a']=!f[s[i]-'a'];
		for(int i=0;i<siz-2;++i)
		{
			fa[s[i]-'a']=!fa[s[i]-'a'];
			for(int j=0;j<26;++j) fb[j]=0;		
			for(int j=i+1;j<siz-1;++j)
			{
				fb[s[j]-'a']=!fb[s[j]-'a'];
				check(1);
				tt=j+1;
				index=2;
				while(comp(tt,j+1))
				{
					if(tt+j>=siz-1) break;
					check(index);
					++index;
					tt+=j+1;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
