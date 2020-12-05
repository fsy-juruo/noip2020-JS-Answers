#include <bits/stdc++.h>
using namespace std;

long long n,m,s,i,j,s1,s2,k,i1,j2,p,s3,s4;
int a[51][401],b[820001],c[820001];

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	}
	k=0;
	s1=0;s2=2;
	s3=-1;
	s4=-1;
	for(i=1;i<=m;i++)
		a[n+1][i]=0;
	while(k<=820000)
	{
		p=0;
		for(i=1;i<=n+1;i++)
		{
			for(j=1;j<=m-1;j++)
				if(a[i][j]!=a[i][j+1])
				{
					p=1; 
					break;
				}
		}
		if(p==0)
		{
			break;
		}
		if(k>0)
			s1=n+1+rand()%7;
		s2+=rand()%4;
		if(s2>n+1)
			while(s2>n+1)
				s2-=n+1;
				while(s1>n+1)
				s1-=n+1;
			while(a[s1][1]==0)
			{
				s1++;
				while(s1>n+1)
				s1-=n+1;
		}
			
		while(a[s2][m]!=0 || s2==s1 || (s2==s3 && s1==s4))
		{
			s2+=323;
		while(s2>n+1)
				s2-=n+1;
		}
		s3=s1;
		s4=s2;
		for(i=m;i>=1;i--)
			if(a[s1][i]!=0)
			{
				i1=i;
				break;
			}
		for(i=1;i<m;i++)
			if(a[s2][i]==0)
			{
				a[s2][i]=a[s1][i1];
				j2=i;
				break;
			}
		a[s1][i1]=0;
		k++;
		b[k]=s1;
		c[k]=s2;
	
	}
	cout<<k<<endl;
	for(i=1;i<=k;i++)
	{
		cout<<b[i]<<" "<<c[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
