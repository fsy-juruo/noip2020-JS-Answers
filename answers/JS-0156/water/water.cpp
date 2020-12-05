#include<cstdio>
#include<cctype>
#include<set>
#include<vector>
using namespace std;
long long qr()
{
	long long f=1,r=0;
	char ch;
	do
		ch=getchar();
	while (!isdigit(ch)&&ch!='-');
	if (ch=='-')
		f=-1;
	else
		r=ch-48;
	ch=getchar();
	while (isdigit(ch))
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return f*r;
}
struct node
{
	long long x,y;
};
node a[100005];
set <long long> st;
set <long long>::iterator it;
vector <long long> v[100005];
long long gcd(long long x1,long long y1)
{
	if (!y1)
		return x1;
	return gcd(y1,x1%y1);
}
long long lcm(long long x1,long long y1)
{
	return x1*y1/gcd(x1,y1);
}
void dfs(long long cur)
{
	long long i,len,fin,tx1,ty1,tx2,ty2,mpt,g1,c1,c2;
	len=v[cur].size();
	tx1=a[cur].x;
	ty1=a[cur].y*len;
	for (i=0;i<len;i++)
	{
		fin=v[cur][i];
		if (a[fin].x+a[fin].y==0)
		{
			a[fin].x=tx1;
			a[fin].y=ty1;
		}
		else
		{
			mpt=lcm(a[fin].y,ty1);
			c1=mpt/a[fin].y;
			c2=mpt/ty1;
			tx2=tx1*c2+a[fin].x*c1;
			a[fin].x=tx2;
			a[fin].y=mpt;
			g1=gcd(a[fin].x,a[fin].y);
			a[fin].x/=g1;
			a[fin].y/=g1;
		}
		dfs(fin);
	}
	if (len)
		a[cur].x=a[cur].y=0;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	long long i,j,n,m,g,p,x2,tx3,ty3;
	n=qr();
	m=qr();
	for (i=1;i<=m;i++)
		a[i].x=a[i].y=1;
	for (i=1;i<=n;i++)
	{
		p=qr();
		for (j=1;j<=p;j++)
		{
			x2=qr();
			v[i].push_back(x2);
		}
		if (!p)
			st.insert(i);
	}
	for (i=1;i<=m;i++)
		dfs(i);
	for (it=st.begin();it!=st.end();it++)
	{
		tx3=a[*it].x;
		ty3=a[*it].y;
		g=gcd(tx3,ty3);
		tx3/=g;
		ty3/=g;
		printf("%lld %lld\n",tx3,ty3);
	}
	return 0;
}
