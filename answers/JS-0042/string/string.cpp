#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
template <typename T> int read(T &x)
{
		 x=0;
		 int f=1;
		 char c=getchar();
		 for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		 for(;isdigit(c);c=getchar())x=x*10+c-'0';
		 x*=f;
}
int T;
int t;
string A;
string B;
string C;
int tot[1050010];
char s[1050010];
int vis[1050010][30];
ll ans;
bool flag=0;
void daan(int i,int j)
{
	int tot2=0;
	for(int k=1;k<=26;k++)
	{
		int x=vis[t-1][k]-vis[j][k];
		if(x%2)
		{
			tot2++;
		}
	}	
	if(tot2>=tot[i])
	{
		ans++;	
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(tot,0,sizeof(tot));
		ans=0;
		A.clear();
		t=0;
		scanf("%s",s);
		for(int i=0;s[i]>='a'&&s[i]<='z';i++)
		{
			t++;
			int x=s[i]-'a'+1;
			vis[i][x]++;
			for(int j=1;j<=26;j++)
			{
				if(i!=0)
				vis[i][j]+=vis[i-1][j];
				if(vis[i][j]%2)
				tot[i]++;
			}
		}
		if(t<=1000)
		{
			for(int i=0;i<t-2;i++)
			{
				A+=s[i];
				for(int j=i+1;j<t-1;j++)	
				{	
					B.clear();
					for(int k=i+1;k<=j;k++)
						B+=s[k];
					string S=A+B;
					int x=j+1;
					daan(i,j);
					while(x+j<t-1)
					{
						for(int k=x;k<=x+j;k++)
						{
							if(S[k-x]!=s[k])
							{
								flag=1;
								break;
							}
						}
						if(flag==1)
						{
							flag=0;
							break;
						}
						daan(i,x+j);
						x+=j+1;						
					}
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			
		}	
	}
	return 0;
}
