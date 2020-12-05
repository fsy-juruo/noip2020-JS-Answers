#include<bits/stdc++.h>
using namespace std;
int n,m,w[110],x[110],y[110],l,t[12];
bool a[12][12][12][12][12],f;
long long s,ss;
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
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(m);
	if (n>100)
	{
		writeln(-1);
		return 0;
	}
	for (int i=1;i<=m;i++) read(w[i]);
	for (int i=1;i<=n;i++)
	{
		read(x[i]);
		read(y[i]);
	}
	for (int i=m+1;i<=5;i++) w[i]=1;
	for (int i=1;i<=w[1];i++)
		for (int j=1;j<=w[2];j++)
			for (int k=1;k<=w[3];k++)
				for (int o=1;o<=w[4];o++)
					for (int p=1;p<=w[5];p++)
					{
						memset(a,0,sizeof(a));
						a[i][j][k][o][p]=1;t[1]=i;t[2]=j;t[3]=k;t[4]=o;t[5]=p;
						s=0;f=0;
						for (int q=1;q<=n;q++)
						{
							if (x[q]==1)
							{
								a[t[1]+y[q]][t[2]][t[3]][t[4]][t[5]]=1;
								t[1]+=y[q];
								s++;
								if ((t[1]>w[1])||(t[1]==0))
								{
									f=1;
									break;
								}
							}
							if (x[q]==2)
							{
								a[t[1]][t[2]+y[q]][t[3]][t[4]][t[5]]=1;
								t[2]+=y[q];
								s++;
								if ((t[2]>w[2])||(t[2]==0))
								{
									f=1;
									break;
								}
							}
							if (x[q]==3)
							{
								a[t[1]][t[2]][t[3]+y[q]][t[4]][t[5]]=1;
								t[3]+=y[q];
								s++;
								if ((t[3]>w[3])||(t[3]==0))
								{
									f=1;
									break;
								}
							}
							if (x[q]==4)
							{
								a[t[1]][t[2]][t[3]][t[4]+y[q]][t[5]]=1;
								t[4]+=y[q];
								s++;
								if ((t[4]>w[4])||(t[4]==0))
								{
									f=1;
									break;
								}
							}
							if (x[q]==5)
							{
								a[t[1]][t[2]][t[3]][t[4]][t[5]+y[q]]=1;
								t[5]+=y[q];
								s++;
								if ((t[5]>w[5])||(t[5]==0))
								{
									f=1;
									break;
								}
							}							
						}
						if (f) ss=(ss+s)%1000000007;
						else
						{
							l=1;
							while (1)
							{
								if (s>100000)
								{
									writeln(-1);
									return 0;
								}
								if (x[l]==1)
								{
									a[t[1]+y[l]][t[2]][t[3]][t[4]][t[5]]=1;
									t[1]+=y[l];
									s++;
									if ((t[1]>w[1])||(t[1]==0))
									{
										f=1;
										break;
									}
								}
								if (x[l]==2)
								{
									a[t[1]][t[2]+y[l]][t[3]][t[4]][t[5]]=1;
									t[2]+=y[l];
									s++;
									if ((t[2]>w[2])||(t[2]==0))
									{
										f=1;
										break;
									}
								}
								if (x[l]==3)
								{
									a[t[1]][t[2]][t[3]+y[l]][t[4]][t[5]]=1;
									t[3]+=y[l];
									s++;
									if ((t[3]>w[3])||(t[3]==0))
									{
										f=1;
										break;
									}
								}
								if (x[l]==4)
								{
									a[t[1]][t[2]][t[3]][t[4]+y[l]][t[5]]=1;
									t[4]+=y[l];
									s++;
									if ((t[4]>w[4])||(t[4]==0))
									{
										f=1;
										break;
									}
								}
								if (x[l]==5)
								{
									a[t[1]][t[2]][t[3]][t[4]][t[5]+y[l]]=1;
									t[5]+=y[l];
									s++;
									if ((t[5]>w[5])||(t[5]==0))
									{
										f=1;
										break;
									}
								}
								l++;
								if (l>n) l=1;									
							}
							ss=(ss+s)%1000000007;
						}
					}
	writeln(ss);
	return 0;
}

