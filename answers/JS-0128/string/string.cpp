#include <stdio.h>
#include <string.h>

int ans;
char str[3000000];

int cnt[128];

bool check(int lena,int lenb,int lenc)
{
	int l=strlen(str);
	if((l-lenc)%(lena+lenb)!=0)
		return false;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<lena;i++)
		cnt[str[i]]++;
	int ca=0,cc=0;
	for(int i=0;i<128;i++)
		if(cnt[i]%2==1)
			ca++;
	memset(cnt,0,sizeof(cnt));
	for(int i=l-lenc;i<l;i++)
		cnt[str[i]]++;
	for(int i=0;i<128;i++)
		if(cnt[i]%2==1)
			cc++;
	if(ca>cc)
		return false;
	for(int i=lena+lenb;i<l-lenc;i++)
		if(str[i]!=str[i-lena-lenb])
			return false;
	return true;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		ans=0;
		scanf("%s",str);
		int l=strlen(str);
		for(int a=1;a<l-1;a++)
			for(int b=1;b<=l-a-1;b++)
				for(int c=1;c<=l-a-b;c++)
					if(check(a,b,c))
						ans++;
		printf("%d\n",ans);
	}
}
