#include<bits/stdc++.h>
using namespace std;
int T;
int len;
char ch[1048577];
int v;
int ans;

int f(int x,int y)
{
	int sum=0;
	int a[27];
	for (int i=0;i<=26;++i)
	  a[i]=0;
	for (int i=x;i<=y;++i)
	  a[ch[i]-'a'+1]++;
	for (int i=1;i<=26;++i)
	  if (a[i]!=0&&a[i]%2==1)
	    sum++;
	return sum;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	char c;
	c=getchar();
	for (v=1;v<=T;++v)
	{
		ans=0;
		len=0;
		while (1)
		{
			c=getchar();
			if (c=='\n')
			  break;
			ch[++len]=c;
		}
		for (int i=1;i<=len-1;++i)
		{
				int y=f(i+1,len);
				for (int j=1;j<i;++j)
				  if (f(1,j)<=y)
				    {
				    	ans++;
				    	/*printf("i:%d\n",i);
				    	printf("A:");
				    	for (int k=1;k<=j;++k)
				    	  printf("%c",ch[k]);
				    	printf(" B:");
				    	for (int k=j+1;k<=i;++k)
				    	  printf("%c",ch[k]);
				    	printf(" C:");
				    	for (int k=i+1;k<=len;++k)
				    	  printf("%c",ch[k]);
				    	printf("\n");*/
					}
		}
		printf("%d\n",ans);
	}
	return 0;
}

