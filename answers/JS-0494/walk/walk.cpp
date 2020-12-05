#include <bits/stdc++.h>

#define LL long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pii pair <LL,LL>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,t,w[20],mn[20],mx[20],fin[20],coo[20],sv[20],ans=0;
pii x[500010];

void dfs(LL pos)
{
	if(pos==t+1)
	{
		repn(i,t) sv[i]=coo[i];
		int times=0,ok;
		while(true)
		{
			ok=1;
			repn(i,t)
			{
				if(sv[i]+mn[i]<1||sv[i]+mx[i]>w[i])
				{
					ok=0;
					break;
				}
				sv[i]+=fin[i];
			}
			if(!ok) break;
			times++;
		}
		ans=(ans+times*n)%MOD;
		repn(i,t) sv[i]=coo[i]+times*fin[i];
		//cout<<ans<<endl;
		rep(i,n)
		{
			//cout<<sv[x[i].fi]<<' '<<x[i].se<<endl;
			if(sv[x[i].fi]+x[i].se<1||sv[x[i].fi]+x[i].se>w[x[i].fi])
			{
				ans=(ans+i+1)%MOD;
				break;
			}
			sv[x[i].fi]+=x[i].se;
		}
		//cout<<coo[1]<<' '<<coo[2]<<' '<<ans<<' '<<times<<endl<<endl;
		return;
	}
	repn(i,w[pos])
	{
		coo[pos]=i;
		dfs(pos+1);
	}
}

void bfSolve()
{
	dfs(1);
	cout<<ans<<endl;
}

LL fi_step[300000];

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>t;
	LL mxw=0;
	repn(i,t)
	{
		cin>>w[i];
		mxw=max(mxw,w[i]);
	}
	rep(i,299995) fi_step[i]=1e9;
	rep(i,n)
	{
		cin>>x[i].fi>>x[i].se;
		fin[x[i].fi]+=x[i].se;
		mn[x[i].fi]=min(mn[x[i].fi],fin[x[i].fi]);
		mx[x[i].fi]=max(mx[x[i].fi],fin[x[i].fi]);
		if(fi_step[fin[1]+150000]==1e9) fi_step[fin[1]+150000]=i;
	}
	bool imp=true;
	repn(i,t)
	{
		if(fin[i]!=0) imp=false;
		if(mx[i]-mn[i]+1>w[i]) imp=false;
	}
	if(imp)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(mxw<=10&&t<=5)
	{
		bfSolve();
		return 0;
	}
	if(t==1&&mxw<=100000)
	{
		repn(i,w[1])
		{//cout<<i<<' '<<ans<<' '<<i+mn[1]<<' '<<i+mx[1]<<endl;
			if(i+mn[1]<1||i+mx[1]>w[1])
			{
				ans=(ans+min(fi_step[-i+150000],fi_step[w[1]-i+1+150000])+1)%MOD;
				//cout<<i<<' '<<ans<<' '<<i+mn[1]<<' '<<i+mx[1]<<endl;
			}
			else
			{
				int lb=1,ub=mxw,mid,tmp;
				while(lb<ub)
				{
					mid=(lb+ub+1)/2;
					tmp=i+(mid-1)*fin[1];
					if(tmp+mn[1]<1||tmp+mx[1]>w[1]) ub=mid-1;
					else lb=mid;
				}
				ans=(ans+lb*n)%MOD;
				tmp=i+lb*fin[1];
				ans=(ans+min(fi_step[-tmp+150000],fi_step[w[1]-tmp+1+150000])+1)%MOD;
				//cout<<i<<' '<<ans<<' '<<lb<<'p'<<endl;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
/*
5 1
6
1 1
1 1
1 -1
1 -1
1 -1
*/
