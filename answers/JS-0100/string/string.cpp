#include<bits/stdc++.h>
using namespace std;
bool AC_AK=true;
int T;
string st;
int l;
int num[30];
int c[1010];
int a[1010];
int tmp[30];
int ans;
int ab[1010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cin>>st;
		ans=0;
		l=st.size();
		for(int i=1;i<=26;i++)
			num[i]=0;
		c[l]=0;
		for(int i=l-1;i>=0;i--)
		{
			++num[st[i]-'a'+1];
			if(num[st[i]-'a'+1]&1)
				c[i]=c[i+1]+1;
			else c[i]=c[i+1]-1;
		}
		for(int i=1;i<=26;i++)
			num[i]=0;
		for(int j=0;j<l-1;j++)
		{
			int p=j;
			while(p+j+1<l-1)
			{
				bool fl=1;
				for(int k=0;k<=j;k++)
				{
					if(st[k]!=st[p+k+1])
					{
						fl=0;
						break;
					}
				}
				if(!fl) break;
				else p=p+j+1;
			}
			ab[j]=p;
		}
		a[0]=0;
		for(int i=0;i<=26;i++)
			tmp[i]=0;
		for(int i=0;i<l-2;i++)
		{
			++num[st[i]-'a'+1];
			if(num[st[i]-'a'+1]&1)
				a[i+1]=a[i]+1;
			else a[i+1]=a[i]-1;
			for(int j=a[i+1];j<=26;j++)
				++tmp[j];
			int j=i+1;
			for(int k=j;k<=ab[j];k+=(j+1))
			{
				ans+=tmp[c[k+1]];
//					printf("%d %d %d %d\n",i,j,k,tmp[c[k+1]]);
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}
