#include<bits/stdc++.h>
using namespace std;
int a,b,n[61][410],s[61][410],l[61],sss,ss,x[820010],y[820010],v;
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
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(a);read(b);
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
		{
			read(n[i][j]);
			s[i][n[i][j]]++;
		}
	for (int i=1;i<=a;i++) l[i]=b;
	for (int p=1;p<=5;p++)
	{
		for (int i=1;i<a;i++)
		{
			sss=0;
			for (int j=a;j>=a-s[i][i]+1;j--)
			{
				ss++;
				x[ss]=i+1;y[ss]=a+1;
				l[i+1]--;l[a+1]++;
				n[a+1][l[a+1]]=n[i+1][l[i+1]+1];
				n[i+1][l[i+1]+1]=0;
				s[a+1][n[a+1][l[a+1]]]++;
				s[i+1][n[a+1][l[a+1]]]--;
			}
			for (int j=b;j>=1;j--)
			if (n[i][j]==i)
			{
				ss++;sss++;
				x[ss]=i;y[ss]=i+1;
				l[i]--;l[i+1]++;
				n[i+1][l[i+1]]=n[i][l[i]+1];
				n[i][l[i]+1]=0;
				s[i+1][n[i+1][l[i+1]]]++;
				s[i][n[i+1][l[i+1]]]--;
			}
			else
			{
				ss++;
				x[ss]=i;y[ss]=a+1;
				l[i]--;l[a+1]++;
				n[a+1][l[a+1]]=n[i][l[i]+1];
				n[i][l[i]+1]=0;
				s[a+1][n[a+1][l[a+1]]]++;
				s[i][n[a+1][l[a+1]]]--;			
			}
			for (int j=b;j>=1;j--)
			{
				ss++;
				x[ss]=i+1;y[ss]=i;
				l[i]++;l[i+1]--;
				n[i][l[i]]=n[i+1][l[i+1]+1];
				n[i+1][l[i+1]+1]=0;
				s[i][n[i][l[i]]]++;
				s[i+1][n[i][l[i]]]--;		
			}
			for (int j=b;j>=1;j--)
			{
				ss++;
				x[ss]=a+1;y[ss]=i+1;
				l[i+1]++;l[a+1]--;
				n[i+1][l[i+1]]=n[a+1][l[a+1]+1];
				n[a+1][l[a+1]+1]=0;
				s[i+1][n[i+1][l[i+1]]]++;
				s[a+1][n[i+1][l[i+1]]]--;			
			}
			for (int j=b;j>sss;j--)
			if (n[i][j]==i)
			{
				for (int k=b;k>j;k--)
				{
					ss++;
					x[ss]=i;y[ss]=a+1;
					l[i]--;l[a+1]++;
					n[a+1][l[a+1]]=n[i][l[i]+1];
					n[i][l[i]+1]=0;
					s[a+1][n[a+1][l[a+1]]]++;
					s[i][n[a+1][l[a+1]]]--;					
				}
				ss++;
				x[ss]=i+1;y[ss]=a+1;
				l[i+1]--;l[a+1]++;
				n[a+1][l[a+1]]=n[i+1][l[i+1]+1];
				n[i+1][l[i+1]+1]=0;
				s[a+1][n[a+1][l[a+1]]]++;
				s[i+1][n[a+1][l[a+1]]]--;
				ss++;
				x[ss]=i;y[ss]=i+1;
				l[i]--;l[i+1]++;
				n[i+1][l[i+1]]=n[i][l[i]+1];
				n[i][l[i]+1]=0;
				s[i+1][n[i+1][l[i+1]]]++;
				s[i][n[i+1][l[i+1]]]--;	
				for (int k=j-1;k>sss;k--)
				{
					ss++;
					x[ss]=i;y[ss]=a+1;
					l[i]--;l[a+1]++;
					n[a+1][l[a+1]]=n[i][l[i]+1];
					n[i][l[i]+1]=0;
					s[a+1][n[a+1][l[a+1]]]++;
					s[i][n[a+1][l[a+1]]]--;					
				}
				ss++;
				x[ss]=i+1;y[ss]=i;
				l[i]++;l[i+1]--;
				n[i][l[i]]=n[i+1][l[i+1]+1];
				n[i+1][l[i+1]+1]=0;
				s[i][n[i][l[i]]]++;
				s[i+1][n[i][l[i]]]--;
				while (l[i]<b)
				{
					ss++;
					x[ss]=a+1;y[ss]=i;
					l[i]++;l[a+1]--;
					n[i][l[i]]=n[a+1][l[a+1]+1];
					n[a+1][l[a+1]+1]=0;
					s[i][n[i][l[i]]]++;
					s[a+1][n[i][l[i]]]--;				
				}	
				while (l[i+1]<b)
				{
					ss++;
					x[ss]=a+1;y[ss]=i+1;
					l[i+1]++;l[a+1]--;
					n[i+1][l[i+1]]=n[a+1][l[a+1]+1];
					n[a+1][l[a+1]+1]=0;
					s[i+1][n[i+1][l[i+1]]]++;
					s[a+1][n[i+1][l[i+1]]]--;				
				}	
				sss++;								
			}
			for (int j=i+1;j<=a;j++)	
				for (int k=b;k>=1;k--)
				if (n[j][k]==i)
				{
					for (int m=b;m>k;m--)
					{
						ss++;
						x[ss]=j;y[ss]=a+1;
						l[j]--;l[a+1]++;
						n[a+1][l[a+1]]=n[j][l[j]+1];
						n[j][l[j]+1]=0;
						s[a+1][n[a+1][l[a+1]]]++;
						s[j][n[a+1][l[a+1]]]--;						
					}
					if (sss>=l[a+1])
					{
						for (int m=b;m>sss;m--)
						{
							ss++;
							x[ss]=i;y[ss]=a+1;
							l[i]--;l[a+1]++;
							n[a+1][l[a+1]]=n[i][l[i]+1];
							n[i][l[i]+1]=0;
							s[a+1][n[a+1][l[a+1]]]++;
							s[i][n[a+1][l[a+1]]]--;							
						}
						ss++;
						x[ss]=j;y[ss]=i;
						l[i]++;l[j]--;
						n[i][l[i]]=n[j][l[j]+1];
						n[j][l[j]+1]=0;
						s[i][n[i][l[i]]]++;
						s[j][n[i][l[i]]]--;
						while (l[i]<b)
						{
							ss++;
							x[ss]=a+1;y[ss]=i;
							l[i]++;l[a+1]--;
							n[i][l[i]]=n[a+1][l[a+1]+1];
							n[a+1][l[a+1]+1]=0;
							s[i][n[i][l[i]]]++;
							s[a+1][n[i][l[i]]]--;				
						}	
						while (l[j]<b)
						{
							ss++;
							x[ss]=a+1;y[ss]=j;
							l[j]++;l[a+1]--;
							n[j][l[j]]=n[a+1][l[a+1]+1];
							n[a+1][l[a+1]+1]=0;
							s[j][n[j][l[j]]]++;
							s[a+1][n[j][l[j]]]--;				
						}							
					}
					else
					{
						v=l[a+1];
						for (int m=b-1;m>v;m--)
						{
							ss++;
							x[ss]=i;y[ss]=a+1;
							l[i]--;l[a+1]++;
							n[a+1][l[a+1]]=n[i][l[i]+1];
							n[i][l[i]+1]=0;
							s[a+1][n[a+1][l[a+1]]]++;
							s[i][n[a+1][l[a+1]]]--;							
						}
						ss++;
						x[ss]=j;y[ss]=a+1;
						l[j]--;l[a+1]++;
						n[a+1][l[a+1]]=n[j][l[j]+1];
						n[j][l[j]+1]=0;
						s[a+1][n[a+1][l[a+1]]]++;
						s[j][n[a+1][l[a+1]]]--;	
						v=l[i];
						for (int m=v;m>sss;m--)	
						{
							ss++;
							x[ss]=i;y[ss]=j;
							l[i]--;l[j]++;
							n[j][l[j]]=n[i][l[i]+1];
							n[i][l[i]+1]=0;
							s[j][n[j][l[j]]]++;
							s[i][n[j][l[j]]]--;							
						}
						ss++;
						x[ss]=a+1;y[ss]=i;
						l[i]++;l[a+1]--;
						n[i][l[i]]=n[a+1][l[a+1]+1];
						n[a+1][l[a+1]+1]=0;
						s[i][n[i][l[i]]]++;
						s[a+1][n[i][l[i]]]--;
						while (l[i]<b)
						{
							ss++;
							x[ss]=a+1;y[ss]=i;
							l[i]++;l[a+1]--;
							n[i][l[i]]=n[a+1][l[a+1]+1];
							n[a+1][l[a+1]+1]=0;
							s[i][n[i][l[i]]]++;
							s[a+1][n[i][l[i]]]--;				
						}	
						while (l[j]<b)
						{
							ss++;
							x[ss]=a+1;y[ss]=j;
							l[j]++;l[a+1]--;
							n[j][l[j]]=n[a+1][l[a+1]+1];
							n[a+1][l[a+1]+1]=0;
							s[j][n[j][l[j]]]++;
							s[a+1][n[j][l[j]]]--;				
						}														
					}
					sss++;
				}		
		}			
	}
	writeln(ss);
	for (int i=1;i<=ss;i++)
	{
		write(x[i]);putchar(' ');writeln(y[i]);
	}
	return 0;
}

