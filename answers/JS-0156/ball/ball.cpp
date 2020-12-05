#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
using namespace std;
int qr()
{
	int f=1,r=0;
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
vector <int> a[56];
int n,m;
const int LIM=820000;
const int P=1000000007;
struct node
{
	int x,y;
};
node b[820005];
set <int> tp;
set <long long> stps;
bool suc;
bool check()
{
	int i,j;
	for (i=1;i<=n+1;i++)
	{
		if (a[i].size()>0&&a[i].size()<m)
			return false;
		if (a[i].size())
		{
			tp.clear();
			for (j=0;j<m;j++)
				tp.insert(a[i][j]);
			if (tp.size()>1)
				return false;
		}
	}
	return true;
}
void dfs(int dep)
{
	int i,j,i1,j1,tmp2,len;
	long long tmp3,sum=0,muls=1;
	for (i=1;i<=n+1;i++)
	{
		len=a[i].size();
		for (j=0;j<len;j++)
		{
			tmp3=muls*(i*m+j)*a[i][j];
			sum=(sum+tmp3)%P;
			muls=(muls*37)%P;
		}
	}
	stps.insert(sum);
	if (suc)
		return;
	if (check())
	{
		printf("%d\n",dep-1);
		for (i=1;i<dep;i++)
			printf("%d %d\n",b[i].x,b[i].y);
		suc=true;
		return;
	}
	if (dep>LIM)
		return;
	for (i=1;i<=n+1;i++)
		if (a[i].size())
			for (j=1;j<=n+1;j++)
				if (j!=i&&a[j].size()<m)
				{
					if (i>n+1||j>n+1)
						break;
					tmp2=a[i].back();
					a[i].pop_back();
					a[j].push_back(tmp2);
					b[dep].x=i;
					b[dep].y=j;
					sum=0;
					muls=1;
					for (i1=1;i1<=n+1;i1++)
					{
						len=a[i1].size();
						for (j1=0;j1<len;j1++)
						{
							tmp3=muls*(i1*m+j1)*a[i1][j1];
							sum=(sum+tmp3)%P;
							muls=(muls*37)%P;
						}
					}
					if (stps.count(sum)==0)
						dfs(dep+1);
					a[i].push_back(tmp2);
					a[j].pop_back();
				}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j,x;
	n=qr();
	m=qr();
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			x=qr();
			a[i].push_back(x);
		}
	dfs(1);
	return 0;
}
