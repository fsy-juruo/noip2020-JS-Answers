#include<bits/stdc++.h>
using namespace std;
int a,b,len[100010],l,r,m[100010];
long long x,g,o,p[100010],q[100010],t[100010][11];
template <typename T> void read(T &x)
{
	 x=0;char c=getchar();bool flg=0;
	 for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	 for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	 if (flg) x=-x;
}
void write(long long x)
{
	if (x<0)
	{
		x=-x;
		putchar('-');
	}
	if (x>=10) write(x/10);
	putchar(x%10+48);
}
void writeln(long long x)
{
	write(x);
	puts("");
}
long long gcd(long long x,long long y)
{
	long long z=x%y;
	while (z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(a);read(b);
	for (int i=1;i<=a;i++)
	{
		read(t[i][0]);
		for (int j=1;j<=t[i][0];j++) 
		{
			read(t[i][j]);
			len[t[i][j]]++;
		}
	}
	for (int i=1;i<=a;i++)
	if (len[i]==0)
	{
		l=1;r=1;m[1]=i;p[i]=1;q[i]=1;
		while (l<=r)
		{
			len[m[l]]=-1;g=gcd(p[m[l]],q[m[l]]);p[m[l]]/=g;q[m[l]]/=g;
			for (int j=1;j<=t[m[l]][0];j++)
			{
				if (q[t[m[l]][j]]==0)
				{
					p[t[m[l]][j]]=p[m[l]];
					q[t[m[l]][j]]=q[m[l]]*t[m[l]][0];
				}
				else
				{
					g=gcd(q[m[l]]*t[m[l]][0],q[t[m[l]][j]]);
					o=q[m[l]]*t[m[l]][0]*q[t[m[l]][j]]/g;
					p[t[m[l]][j]]=p[t[m[l]][j]]*(o/q[t[m[l]][j]])+p[m[l]]*(o/q[m[l]]/t[m[l]][0]);
					q[t[m[l]][j]]=o;					
				}
				len[t[m[l]][j]]--;
				if (len[t[m[l]][j]]==0) 
				{
					r++;
					m[r]=t[m[l]][j];
				}
			}
			l++;
		}
	}
	for (int i=1;i<=a;i++)
	if (t[i][0]==0)
	{
		g=gcd(p[i],q[i]);
		p[i]/=g;q[i]/=g;
		write(p[i]);putchar(' ');writeln(q[i]);
	}
	return 0;
}

