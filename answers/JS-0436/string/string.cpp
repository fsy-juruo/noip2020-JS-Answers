#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char a[1100010];
int T,pre[30][100010],ans;

int calc(int l,int r)
{
	int js=0;
	for(int i=0;i<26;i++)
	{
		if((pre[i][r]-pre[i][l-1])&1) js++;
	}
	return js;
}

bool pd(int to,int s,int t)
{
	for(int i=s;i<=t;i++)
	{
		if(a[i]!=a[i-s+1]) return false; 
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
		scanf("%s",a+1);
		int len=strlen(a+1);
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j<26;j++) pre[j][i]=pre[j][i-1];
			pre[a[i]-'a'][i]++;
		}
		ans=0;
		for(int i=1;i<=len-2;i++)
		{
			int fa=calc(1,i);
			for(int j=i+1;j<=len-1;j++)
			{
				int lenth=j,now=j+1;
				int fc=calc(j+1,len);
				if(fc>=fa) ans++;
				while(pd(j,now,now+lenth-1)&&now+lenth<=len)
				{
					now=now+lenth;
					fc=calc(now,len);
					if(fc>=fa) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
