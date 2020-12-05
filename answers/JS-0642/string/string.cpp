#include<bits/stdc++.h>
#define ll long long
#define str string
#define dou double
#define ull unsigned long long
#define fi first
#define se second
using namespace std;

const int maxn=2e7+10;
int T;
int len;
str s;
int ta,tb;
int zm[30];
ll ans;

bool check(int st,int l)
{
	for(int i=0,q=st;i<=l;i++,q++)
	{
		if(s[i]!=s[q])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		cin>>s;
		len=s.size();
		for(int i=1;i<len;i++)
		{
			int w=0;
			while(check(w,i))
			{
				if(w+i+1>=len)
				{
					break;
				}
				memset(zm,0,sizeof(zm));
				tb=0;
				for(int q=w+i+1;q<len;q++)
				{
					if(zm[s[q]-'a']==1)
					{
						zm[s[q]-'a']=0;
					}
					else
					{
						zm[s[q]-'a']=1;
					}
					if(zm[s[q]-'a'])
					{
						tb++;
					}
					else
					{
						tb--;
					}
				}
				for(int q=0;q<i;q++)
				{
					ta=0;
					memset(zm,0,sizeof(zm));
					for(int j=0;j<=q;j++)
					{
						if(zm[s[j]-'a']==1)
						{
							zm[s[j]-'a']=0;
						}
						else
						{
							zm[s[j]-'a']=1;
						}
						if(zm[s[j]-'a'])
						{
							ta++;
						}
						else
						{
							ta--;
						}
					}
					if(ta<=tb)
					{
						ans++;
//						cout<<q<<" "<<i<<" "<<w<<" "<<w+i+1<<endl;
					}
				}
				w+=i+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

