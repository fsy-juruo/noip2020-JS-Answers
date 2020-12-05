#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

#define mp make_pair
#define X first
#define Y second

lint n, m; lint a[55][805];
lint rowcolor[55], colorrow[55], down[55];

lint reads()
{
	char c; lint returns;
	c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	returns=c-'0';
	
	c=getchar();
	while(c>='0' && c<='9') returns=returns*10+c-'0', c=getchar();
	
	return returns;
}

void work1()
{
	vector<int> v; int i, k, i1, k1, i2, k2; lint ans=0;
	for(i=1; i<=n; i++) if(rowcolor[i]==0) v.push_back(i);
	for(i=1; i<=n; i++) if(colorrow[i]==0) colorrow[i]=v[k], rowcolor[v[k]]=i;
	for(i1=1; i1<=n; i1++) for(lint l=1; l<100; l++) for(k1=down[i]+1; k1<=m; k1++)
	{
		int i2=colorrow[a[i][k]], k2=down[i2]+1;
		if(i2==i1)
			continue;
		int temp=a[i1][k1];
		ans+=(2*m-k2-k1)*2+3;
		for(k=k1; k<m; k++) a[i1][k]=a[i1][k+1]; a[i1][m]=a[i2][k2]; a[i2][k2]=temp; down[i2]++;
	}
	cout<<ans<<endl;
	return ;
}



int main()
{
	
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	priority_queue<pii, vector<pii>, less<pii> > q;
	lint i, j;
	
	n=reads(), m=reads();
	for(i=1; i<=n; i++) for(j=1; j<=m; j++) a[i][j]=reads();
	/*
	E 1 1 2
	E 2 1 2
	*/
	for(i=1; i<=n; i++)
	{
		for(j=1; j<m; j++) if(a[i][j]!=a[i][j+1]) break;
		down[i]=j; q.push(mp(j, i));
	}
	while(!q.empty())
	{
		lint k=q.top().Y; q.pop();
		if(colorrow[a[k][1]]!=0) continue;
		colorrow[a[k][1]]=k;
		rowcolor[k]=a[k][1];
	}
	
	work1();
	return 0;
}
