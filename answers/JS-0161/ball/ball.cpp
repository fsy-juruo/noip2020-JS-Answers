#include<bits/stdc++.h>
using namespace std;
int n,m,o[55][450],an;
string s;
int sear(int r,int co)
{
	int i,j;	
	for(int i=1;i<=n;i++)
	{
		if(i==r)
			continue;
		for(j=1;j<=m;j++)
		{
			if(o[i][j]==co)
			{
				return i*m+j;
			}
		}
	}
	return -1;
}
void dewo(int a,int le,int b)
{
	an+=le;
	for(int i=0;i<le;i++)
	{
		s=s+char(a+'0')+char(b+'0');
	}
	return;
}
void deap(int ai,int aj,int mo,int fe)
{
	int bi=mo/m,bj=mo%m;
	if(bj<m/2+1)
	{
		dewo(bi,m,fe);
		swap(bi,fe);
	}
	if(aj<m/2+1)
	{
		dewo(ai,m,fe);
		swap(ai,fe);
	}
	dewo(ai,m-aj+1,fe);
	dewo(bi,m-bj,ai);
	dewo(fe,1,ai);
	dewo(bi,1,fe);
	dewo(ai,m-bj+1,bi);
	dewo(fe,m-aj+1,ai);
	return;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int i,j;
	an=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>o[i][j];
		}
	}
	int pi=2,pj=1,fe=n+1;
	for(i=1;i<n;i++)
	{
		int th=o[i][1];
		for(j=2;j<=m;j++)
		{
			if(o[i][j]!=th)
			{
				int p=sear(i,th);
				if(p==-1)
					continue;
				pi=p/m;pj=p%m;
				if(pj==0)
				{
					pi--;
					pj=m;
				}
//				cout<<i<<"."<<j<<"&"<<pi<<"."<<pj<<"("<<p<<")  !!"<<endl;
				deap(i,j,p,fe);
				swap(o[i][j],o[pi][pj]);
			}
		}
	}
	cout<<an<<endl;
	for(i=0;i<s.size();i+=2)
	{
		cout<<s[i]<<" "<<s[i+1]<<endl;
	}
	return 0;
}
