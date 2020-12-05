#include<cstdio>
using namespace std;
int n,k,i,j,a[11],z[11],aa[11],c[100008],d[100008],ans;
bool tt=true,fu=false;;
void search(int x)
{
	if(x==k+1)
	{
		for(i=1;i<=k;i++)z[i]=aa[i];
		for(i=1;;i++)
		{
			int l=(i-1)%n+1;
			z[c[l]]+=d[l];
			if(z[c[l]]==0||z[c[l]]>a[c[l]])
			{
				ans+=i;return;
			}
			if(i==n+1&&tt){
				fu=true;return;
			}
		}
	}
	for(int i=1;i<=a[x];i++)
	{
		aa[x]=i;search(x+1);
		if(fu)return;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(i=1;i<=k;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
	  scanf("%d %d",&c[i],&d[i]);
	  aa[c[i]]+=d[i];
	}
	for(i=1;i<=n;i++)
	  if(aa[c[i]]!=0)tt=false;
	search(1);
	if(fu){
		puts("-1");return 0;
	}
	printf("%d\n",ans);
	return 0;
}
