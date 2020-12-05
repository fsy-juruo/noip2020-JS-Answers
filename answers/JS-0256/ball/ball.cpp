#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n,m;
int m1[N],m2[N],m3[N],step=0,tot1,tot2,tot3=0;
string a[10005];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
bool check()
{
	for(int i=2;i<=m;++i)
	    if(m1[i]!=m1[i-1]) return false;
	return true;
}
void work2()
{
	for(int i=1;i<=n;++i)
	    for(int j=1;j<=m;++j)
	        if(i==1) m1[j]=read();
	        else m2[j]=read();
	if(check()) cout<<0<<endl;
	else
	{
	    int j=2;
	    while(j<=m&&m1[j]==m1[j-1])
	    	j++;
	    for(int k=m;k>=j;--k)
	    {
	    	a[++step]="1 3";
	    	m3[tot3++]=m1[tot1--];
		}
		while(tot2!=0)
		{
			if(m2[tot2]==m1[tot1])
			{
				a[++step]="2 1";
				m1[++tot1]=m2[tot2--];
			}
			else
			{
				a[++step]="2 3";
				m3[++tot3]=m2[tot2--];
			}
		}
		while(tot3!=0)
		{
			if(m3[tot3]==m1[tot1])
			{
				a[++step]="3 1";
				m1[++tot1]=m3[tot3--];
			}
			else
			{
				a[++step]="3 2";
				m2[++tot2]=m3[tot3--];
			}
		}
    }
    printf("%d\n",step);
	for(int i=1;i<=step;++i)
	    cout<<a[i]<<endl;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	tot1=m;tot2=m;
	if(n==2) work2();
	else cout<<0<<endl;
	return 0;
}
