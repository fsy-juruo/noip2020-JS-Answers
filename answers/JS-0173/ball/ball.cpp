#include <bits/stdc++.h>
using namespace std;

const int maxn=55,maxm=410;

/*
  . . . .
  3 3 3 3
  2 2 2 2
  1 1 1 1
  =======
a 1 2 3 4 ...

*/

int n,m,a[maxn][maxm],num[maxn],cnt[maxn][maxn],pre[maxn];
vector<pair<int,int> > ans;

inline void calcpre(int i)
{
	for(int j=1;j<=num[i];j++)
	{
		pre[i]=j;
		if(a[i][j+1]!=a[i][1]) break;
	}
}

inline void actmov(int i,int j)
{
	if(num[i]>0&&num[j]<m)
	{
		cnt[i][a[i][num[i]]]--;
		cnt[j][a[i][num[i]]]++;
		a[j][++num[j]]=a[i][num[i]--];
		
		ans.push_back(make_pair(i,j));
	}
	else
	{
		cerr<<"ERROR\n";
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		num[i]=m;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			cnt[i][a[i][j]]++;
		}
	}
	
	for(int i=1;i<=n;)
	{
		calcpre(i);
		if(pre[i]==m)
		{
			i++;
			continue;
		}
		
		int c=a[i][1];
		
		for(int j=i+1;j<=n;)
		{
			if(cnt[j][c]==0)
			{
				j++;
				continue;
			}
			
			while(num[i]>pre[i]) actmov(i,n+1);
			
			while(cnt[j][c]>0)
			{
				while(a[j][num[j]]!=c&&num[n+1]<m-1) actmov(j,n+1);
				while(a[j][num[j]]!=c) actmov(j,i);
				
				actmov(j,n+1);
				
				while(num[i]>pre[i]) actmov(i,j);
				
				actmov(n+1,i);
				pre[i]++;
			}
			
			while(num[n+1]>0&&num[j]<m) actmov(n+1,j);
		}
		
		while(num[n+1]>0) actmov(n+1,i);
		
		/*
		for(int ii=1;ii<=n;ii++)
		{
			for(int jj=1;jj<=num[ii];jj++) cerr<<a[ii][jj]<<' ';
			cerr<<"| "<<pre[ii]<<" | ";
			for(int jj=1;jj<=n;jj++) cerr<<cnt[ii][jj]<<' ';cerr<<endl;
		}
		*/
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}

