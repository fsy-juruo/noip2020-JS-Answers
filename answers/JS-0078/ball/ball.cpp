#include<bits/stdc++.h>
using namespace std;
int n,m,stk[55][405],vis[55],vis2[55],t[55],cnt[55];
vector <int> ans1,ans2;
int F(int x)
{
	if(x==1) return 2;
	return 1;
}
void solve()
{
	int tmp=stk[1][t[1]],cur=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=t[i];j>=1;j--)
		{
			if(stk[i][j]!=tmp) break;
			ans1.push_back(i),ans2.push_back(n+1),cur++;
			t[i]--;
		}
	}
	int x=1;
	while(cur<m)
	{
		bool flg=1;
		for(int i=t[x];i>=1&&cur<m;i--)
		{
			if(stk[x][i]==tmp) 
			{
				if(t[x]-i>m-t[F(x)]) 
				{
					x=F(x);
					flg=0;
					break;
				}
				for(int j=1;j<=t[x]-i;j++) ans1.push_back(x),ans2.push_back(F(x)),stk[F(x)][++t[F(x)]]=stk[x][t[x]--];
				ans1.push_back(x),ans2.push_back(n+1),cur++;
			}
		}
		if(flg) x=F(x);
	}
	for(int i=1;i<=t[1];i++) 
		ans1.push_back(1),ans2.push_back(2);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>stk[i][j];
		t[i]=m;
	}
	solve();
	cout<<ans1.size()<<endl;
	for(int i=0;i<ans1.size();i++) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}
