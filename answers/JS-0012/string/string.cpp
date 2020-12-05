#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1e5+5;
int nxt[N];
int T,l;
char str[N];
int cy[N],cnt[26],odd[N],dodd[N];
ll c[35];
ll ans=0;
int gcd(int a,int b)
{
	if (a<b) swap(a,b);
	if (b==0) return a;
	return gcd(b,a%b);
}
void add(int p,int val)
{
	for (;p<=30;p+=lowbit(p)) c[p]+=val;	
}
ll query(int p)
{
	ll ans=0;
	for (;p;p-=lowbit(p)) ans+=c[p];
	return ans;
}
void KMP()
{
	nxt[1]=0;
	for (int i=2;i<=l;i++)
	{
		int j=nxt[i-1];
		while (j>0&&str[i]!=str[j+1]) j=nxt[j];
		if (str[i]==str[j+1]) nxt[i]=j+1;
		else nxt[i]=0;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(nxt,0,sizeof(nxt));
		memset(c,0,sizeof(c));
		scanf("%s",str);
		l=strlen(str);
		for (int i=l;i>=1;i--) str[i]=str[i-1];
		KMP();
		for (int i=1;i<=l;i++)
		{
			cnt[str[i]-'a']++;
			int num=0;
			for (int j=0;j<26;j++) 
				if (cnt[j]&1) num++;
			odd[i]=num;
		}
		memset(cnt,0,sizeof(cnt));	
		for (int i=l;i>=1;i--)
		{
			cnt[str[i]-'a']++;
			int num=0;
			for (int j=0;j<26;j++) 
				if (cnt[j]&1) num++;
			dodd[i]=num;
		}
		for (int i=1;i<=l;i++)
		{
			for (int j=1;j<=l;j++)
			{
				if (i%j!=0) continue;
				bool flag=true;
				for (int k=2;k<=i/j;k++)
					if (nxt[k*j]!=(k-1)*j) {flag=false;break;}
				if (flag) {cy[i]=j;break;} 
			}
		}
		for (int i=2;i<l;i++)
		{
			memset(c,0,sizeof(c));
			int r=i/cy[i];
			for (int j=1;j<cy[i];j++) add(odd[j]+1,1);
			for (int j=1;j<=r;j++)
			{
				if (r%j==0&&j*cy[i]>1) 
					ans+=query(dodd[i+1]+1);
				for (int k=j*cy[i];k<min((j+1)*cy[i],i);k++)
					add(odd[k]+1,1);
			}
		}	
		printf("%lld\n",ans);
	}
	return 0;
}

