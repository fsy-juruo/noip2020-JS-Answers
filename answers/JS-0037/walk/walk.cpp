#include <bits/stdc++.h>
#define int long long
const int MAXN=500005;
const int MAXK=12;
const int p=1e9+7;
struct node
{
	int c,d;
}r[MAXN];
int n,k,i,j,ans,res=1,a[MAXK],w[MAXK],f[MAXK][2],m[MAXK];
inline int max(int x,int y){return x>y?x:y;}
inline void read(int &x)
{
	short negative=1;
	x=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')
			negative=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=negative;
}
inline void print(int x)
{
	if (x<0)
		putchar('-'),x=-x;
	if (x>9)
		print(x/10);
	putchar(x%10+'0');
}
inline int ksm(int a,int n,int p)
{
	int Ret(1);
	while (n)
	{
		if (n&1)
			(Ret*=a)%=p;
		(a*=a)%=p,n>>=1;
	}
	return Ret;
}
inline void workrun(void)
{
	while (true)
	{
		for (i=1;i<=n;i++)
		{
			res*=ksm(a[r[i].c],p-2,p);
			m[r[i].c]+=r[i].d;
			if (m[r[i].c]<0)
				f[r[i].c][0]=max(f[r[i].c][0],-m[r[i].c]);
			else
				f[r[i].c][1]=max(f[r[i].c][1],m[r[i].c]);
			a[r[i].c]=w[r[i].c]-f[r[i].c][0]-f[r[i].c][1];
			(res*=a[r[i].c])%=p;
			if (a[r[i].c]<=0)
				return;
			(ans+=res)%=p;
		}
		bool flag=true;
		for (i=1;i<=k && flag;i++)
			if (m[i])
				flag=false;
		if (flag)
		{
			printf("-1");
			exit(0);
		}
	}
}
signed main(void)
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	for (i=1;i<=k;i++)
		read(w[i]),a[i]=w[i];
	for (i=1;i<=n;i++)
		read(r[i].c),read(r[i].d);
	for (i=1;i<=k;i++)
		(res*=w[i])%=p;
	ans=res;
	workrun();
	print(ans%p);
	return 0;
}
