#include<cstdio>
#include<cstring>
using namespace std;
char a[1000008];
int n,m,i,j,k,x,y,z,fail[1000008],Q,now,d[27];
int p[1200008][27];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&Q);
	while(Q--)
	{
		char ch;n=0;ans=0;
		for(ch=getchar();(ch<'a')||(ch>'z');ch=getchar());
		for(;(ch>='a')&&(ch<='z');ch=getchar())a[++n]=ch;
		//n=130000;
		j=0;
		for(i=2;i<=n;i++)
		{
			if(a[i]==a[j+1])j++;
			else while(a[i]!=a[j+1]&&j!=0)j=fail[j];
			fail[i]=j;
			//printf("%d ",fail[i]);
		}
		memset(d,0,sizeof(d));now=0;
		memset(p,0,sizeof(p));
		for(i=1;i<=n;i++)
		{
			d[a[i]-'a'+1]++;
			if(d[a[i]-'a'+1]%2==0)now--;else now++;
			p[i][now]=1;
		}
		for(i=1;i<=n;i++)
		{
		  p[i][0]+=p[i-1][0];
		  for(j=1;j<=26;j++)
		    p[i][j]=p[i][j]+p[i][j-1]+p[i-1][j]-p[i-1][j-1];
		}
		memset(d,0,sizeof(d));now=0;
		for(i=n;i>=3;i--)
		{
		//	printf("%d\n",i);
			d[a[i]-'a'+1]++;if(d[a[i]-'a'+1]%2==0)now--;else now++;
			int k=i-1-fail[i-1];
			if((i-1)%k!=0||fail[i-1]==0){
			  ans+=p[i-2][now];
			  continue;
			}
			int d=(i-1)/k;
			for(j=1;j*j<=d;j+=1)
			{
			  if(d%j==0){
			    if(j*j!=d)ans+=p[j*k-1][now];
			    ans+=p[(i-1)/j-1][now];
			   // printf("%d %d\n",p[j*k-1][now],p[(i-1)/j-1][now]);
			  }
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
先处理出长度为i的循环节最大长度
然后k[i][j]i之前字母为奇数小于j的数量
从后往前枚举c，根据 
*/
