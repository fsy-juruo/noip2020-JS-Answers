#include<bits/stdc++.h>
using namespace std;
int n,m,a[505][505],d[505],s[505],be,sol,p[1000005],q[1000005],dick,thot;
void done(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		s[m-i+1]=a[x][i];a[x][i]=0;
		dick++;
		p[dick]=x;q[dick]=n+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				for(int k=1;k<=3;k++)
				{
					if(k!=i&&k!=x) be=k;
				}
				sol=y+1;
				for(int k=1;k<j;k++)
				{
					sol--;
					swap(a[x][sol],a[i][k]);
					dick++;
					p[dick]=i;
					q[dick]=x;
				}
				sol--;
				swap(a[be][1],a[x][sol]);
				dick++;
				p[dick]=be;q[dick]=x;
				swap(a[i][j],a[be][1]);
				dick++;
				p[dick]=i;q[dick]=be;
				sol=j+1;
				for(int k=1;k<=m;k++) if(a[x][k])
				{
					thot=k;
					break;
				}
				for(int k=thot;k<=j+thot-1;k++)
				{
					sol--;
					swap(a[i][sol],a[x][k]);
					dick++;
					p[dick]=x;q[dick]=i;
				}
				swap(a[be][1],a[x][y]);
				dick++;
				p[dick]=be;q[dick]=x;
				sol=y;
				swap(a[i][j],a[be][1]);
				dick++;
				p[dick]=i;
				q[dick]=be;
				for(int k=m-y+1;k<=m;k++)
				{
					sol--;
					if(sol>0)
					{
						swap(s[k],a[x][sol]);
						dick++;
						p[dick]=n+1;
						q[dick]=x;
					}
					else
					{
						be=k;
						sol=j+1;break;
					}
				}
				for(int k=be;k<=m;k++)
				{
					sol--;
					if(sol<=0) break;
					swap(s[k],a[i][sol]);
					dick++;
					p[dick]=n+1;
					q[dick]=i;
				}
				i=n+2;
				break;
			}
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			cin>>a[i][j];
		}
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]!=j)
			{
				done(j,i);
			}
		}
	}
	cout<<dick<<endl;
	for(int i=1;i<=dick;i++)
	{
		cout<<p[i]<<" "<<q[i]<<"\n";
	}
	return 0;
}
