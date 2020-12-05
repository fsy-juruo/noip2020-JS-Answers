#include<bits/stdc++.h>
#define MAXN 1258291
typedef long long ll;
using namespace std;
template <typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for  (;!isdigit(c);c=getchar())	if  (c=='-')	x=-x;
	for  (;isdigit(c);a=a*10+c-48,c=getchar());a*=x;
}
struct sss{
	int num[27];
} ss[MAXN];
char a[MAXN];
int kmp[MAXN];
bool sum[27];
int C[MAXN];
int A[MAXN];
void work()
{
	int N=0;
	char c=getchar();
	while (c>='a'&&c<='z')	a[++N]=c,c=getchar();
	if  (N<=2)
		{
			cout<<0<<endl;
			return;
		}
	int now=0;
	memset(ss,0,sizeof(ss));
	memset(sum,0,sizeof(sum));
	for  (int i=1;i<=N;i++)
		{
			sum[a[i]-97]^=1;
			if  (sum[a[i]-97])	now++;
					else	now--;	A[i]=now;
			ss[i]=ss[i-1];
			for  (int j=A[i];j<=26;j++)
				ss[i].num[j]++;
		}
	memset(sum,0,sizeof(sum));
	now=0;
	for  (int i=N;i>=1;i--)
		{
			sum[a[i]-97]^=1;
			if  (sum[a[i]-97])	now++;
					else	now--;	C[i]=now;}
	
	
	memset(kmp,0,sizeof(kmp));
	int K=1;
	for (int i=2;i<=N;i++)
		{
			while  (K>1&&a[K]!=a[i])	K=kmp[K];
			if  (a[K]==a[i])	kmp[i]=K,K++;
			if  (K==0)	K++;
		}
	int len=0;
	for  (int i=2;2*i<=N;i++)
		if  (kmp[2*i]==i)	
			{
				len=i;
				break;
			}
	if  (len==0&&a[1]==a[2])	len=1;
	int ii=2;
	if  (len)	for  (ii=2;kmp[len*ii]==(ii-1)*len&&ii*len<=N;ii++);
	ii--;
	int ABlen=len*ii;
	ll ans=0;
	for  (int mw=N;mw>=3;mw--)
		{
			if  (mw-1>ABlen)
				{
					ans+=ss[mw-2].num[C[mw]];
					continue;
				}
			if  ((mw-1)%len)
				{
					ans+=ss[mw-2].num[C[mw]];
					continue;
				}
			int iii=(mw-1)/len;
			for  (int j=1;j*j<=iii;j++)
				{
					if  (iii%j)	continue;
					int jj=iii/j;
					if  (j*len>1)	ans+=ss[j*len-1].num[C[mw]];
					if  (jj*len>1&&j!=jj)	ans+=ss[jj*len-1].num[C[mw]];
				}
		}
	cout<<ans<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;read(T);
	for  (int i=1;i<=T;i++)
		work();
	return 0;
}

