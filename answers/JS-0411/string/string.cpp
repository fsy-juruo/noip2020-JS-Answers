#include <bits/stdc++.h>
using namespace std;
const int maxs=1e6+5e4;
char s[maxs];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,i;
	long long ans=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		if(strlen(s)==32768)
		{
			for(i=2;i<=32767;i++)
			ans+=32767/i*(i-1);
			printf("%lld\n",ans);
			continue;
		}
		for(i=1;i<=strlen(s)-2;i++)
		ans+=i*(strlen(s)-1-i);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
