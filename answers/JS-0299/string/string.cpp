#include<bits/stdc++.h>
using namespace std;
int yinshu[1030][100],yinshucnt[1030];
int tmp[10480580],cnt;
char s[1048580];
int xunhuan[1048580],len,aa[30],jishu,f[1048580],gg[1048580][30],revf[1048580];
long long ans=0;
void g(int a)
{
	cnt=0;
	if(a<=1024)
	{
		for(int i=0;i<yinshucnt[a];++i)
			tmp[cnt++]=yinshu[a][i];
		sort(tmp,tmp+cnt);
		unique(tmp,tmp+cnt);
		return;
	}
	else
		for(int i=1024;i*1024>=a;--i)
			if(a%i==0)
			{
				for(int j=0;j<yinshucnt[i];++j)
					for(int k=0;k<yinshucnt[a/i];++k)
						tmp[cnt++]=yinshu[i][j],tmp[cnt++]=yinshu[a/i][k],tmp[cnt++]=yinshu[i][j]*yinshu[a/i][k];
				sort(tmp,tmp+cnt);
				unique(tmp,tmp+cnt);
				return;
			}
	tmp[cnt++]=1,tmp[cnt++]=a;
	return;
}
void pre()
{
	ans=0;
	memset(aa,0,sizeof(aa));
	xunhuan[1]=1;
	for(int i=2;i<=len;++i)
	{
		g(i);
		int fl=0;
		for(int j=0;j<cnt-1;++j)
		{
			int flag=1;
			if(xunhuan[i-tmp[j]]!=tmp[j])
				continue;
			for(int k=1;k<=tmp[j];++k)
				if(s[k]!=s[i-tmp[j]+k])
				{
					flag=0;
					break;
				}
			if(flag)
			{
				xunhuan[i]=tmp[j];
				if(xunhuan[i]==0)
				xunhuan[i]=xunhuan[i];
				fl=1;
				break;
			}
		}
		if(!fl)
			xunhuan[i]=i;
		
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _;
	scanf("%d",&_);
	for(int i=1;i<=1024;++i)
	{
		for(int j=1;j*j<=i;++j)
			if(i%j==0)
				if(i/j!=j)
					yinshu[i][yinshucnt[i]++]=j,yinshu[i][yinshucnt[i]++]=i/j;
				else
					yinshu[i][yinshucnt[i]++]=j;
		sort(yinshu[i],yinshu[i]+yinshucnt[i]);
	}
	while(_--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		pre();
		for(int i=1;i<=len;++i)
		{
			if(aa[s[i]-'a']&1)
				--jishu;
			else
				++jishu;
			++aa[s[i]-'a'];
			f[i]=jishu;//0<=f[i]<=26
		}
		jishu=0;
		memset(aa,0,sizeof(aa));
		for(int i=len;i>=1;--i)
		{
			if(aa[s[i]-'a']&1)
				--jishu;
			else
				++jishu;
			++aa[s[i]-'a'];
			revf[i]=jishu;//0<=f[i]<=26
		}
		jishu=0;
		for(int i=1;i<=len;++i)
		{
			for(int j=0;j<26;++j)
				gg[i][j]=gg[i-1][j];
			++gg[i][f[i]];
		}
		for(int i=1;i<=len;++i)
			for(int j=1;j<26;++j)
				gg[i][j]+=gg[i][j-1];
		for(int i=len-1;i>=2;--i)//[1,i]->AB (i,len]->C
		{
			//printf("%d\n",i);
			g(i/xunhuan[i]);
			for(int j=0;j<cnt&&tmp[j-1]!=i/xunhuan[i];++j)
					ans+=gg[xunhuan[i]*tmp[j]-1][revf[i+1]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
