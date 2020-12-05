#include <bits/stdc++.h>

#define LL long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

int n,m,cur[100],dat[100][500];
vector <pii> ans;
vector <int> spa,spa1;

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	rep(i,n)
	{
		cur[i]=-1;
		rep(j,m)
		{
			cur[i]++;
			cin>>dat[i][cur[i]];
			dat[i][cur[i]]--;
		}
	}
	rep(col,n-1)
	{
		int ub=n-col,colNum,sv;//1~ub-1:full ub:empty
		rep(targ,ub-1)
		{
			colNum=0;
			rep(i,cur[targ]+1) if(dat[targ][i]==col) colNum++;
			sv=colNum;
			spa.clear();
			//cout<<colNum<<'p'<<endl;
			for(int i=0;i<ub;i++)
			{
				if(i==targ) continue;
				int ti=0;
				while(ti<m-colNum&&cur[i]>=0)
				{
					dat[ub][++cur[ub]]=dat[i][cur[i]--];
					spa.pb(i);
					ans.pb(mpr(i+1,ub+1));
					ti++;
				}
			}
			int spaCur=0;
			//if(targ==0&&col==0) cout<<cur[0]<<'p'<<endl;
			while(cur[targ]>=0)
			{
				//if(targ==0&&col==0) cout<<'p';
				if(dat[targ][cur[targ]]==col)
				{
					dat[ub][++cur[ub]]=dat[targ][cur[targ]--];
					ans.pb(mpr(targ+1,ub+1));
				}
				else
				{
					int to=spa[spaCur++];
					dat[to][++cur[to]]=dat[targ][cur[targ]--];
					ans.pb(mpr(targ+1,to+1));
				}
			}
			rep(i,spa.size())
			{
				int fr=spa[i];
				dat[targ][++cur[targ]]=dat[fr][cur[fr]--];
				ans.pb(mpr(fr+1,targ+1));
			}
			rep(i,sv)
			{
				dat[targ][++cur[targ]]=dat[ub][cur[ub]--];
				ans.pb(mpr(ub+1,targ+1));
			}
			rep(i,spa.size())
			{
				int to=spa[i];
				dat[to][++cur[to]]=dat[ub][cur[ub]--];
				ans.pb(mpr(ub+1,to+1));
			}
		}
		spa.clear();
		for(int i=0;i<=ub-2;i++)
		{
			while(cur[i]>=0&&dat[i][cur[i]]==col)
			{
				spa.pb(i);
				dat[ub][++cur[ub]]=dat[i][cur[i]--];
				ans.pb(mpr(i+1,ub+1));
			}
		}
		int spaCur=0;
		while(cur[ub-1]>=0)
		{
			if(dat[ub-1][cur[ub-1]]==col)
			{
				dat[ub][++cur[ub]]=dat[ub-1][cur[ub-1]--];
				ans.pb(mpr(ub,ub+1));
			}
			else
			{
				int to=spa[spaCur++];
				dat[to][++cur[to]]=dat[ub-1][cur[ub-1]--];
				ans.pb(mpr(ub,to+1));
			}
		}
	}
	cout<<ans.size()<<endl;
	rep(i,ans.size()) cout<<ans[i].fi<<' '<<ans[i].se<<endl;
	return 0;
}
