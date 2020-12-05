#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair

typedef long long ll;

ll INF=1000000000000000000ll;
ll MOD=1000000007;
int n,k;
ll sum[15];
ll minx[15];
ll maxx[15];
ll L[15];
ll tot;
ll d[15];
vector<pair<ll,int> > mo[15];

void dfs(ll* A,int lvl)
{
	if(lvl==k)
	{
		ll st=INF;
		vector<ll> mpos;mpos.clear();
		
		for(int i=0;i<k;i++)
		{
			if(maxx[i]+A[i]<L[i]&&minx[i]+A[i]>=0)
			{
				if(sum[i]>0){if(st>=(int)((L[i]-A[i])/sum[i])){st=(int)((L[i]-A[i])/sum[i]);mpos.pb(i);}}
				else if(sum[i]<0){if(st>=(int)(A[i]/abs(sum[i]))){st=(int)(A[i]/abs(sum[i]));mpos.pb(i);}}
			}
			else{st=INF;break;}
		}
		
		if(st==INF)st=0ll;
		
		tot=(tot+(st*n)%MOD)%MOD;
		
		ll tt[15];
		for(int i=0;i<k;i++)tt[i]=A[i]+st*sum[i];
		
		ll minv=INF;
		
		if(!mpos.size())
		{
			for(int id=0;id<k;id++)
			{
				ll ret=0ll;
				ll t=tt[id];
				
				for(int j=0;j<mo[id].size();j++)
				{
					t+=mo[id][j].first;
					ret=1ll*mo[id][j].second;
					
					if(t<0||t>=L[id])break;
				}
				
				minv=min(minv,ret);
			}
		}
		else for(int i=0;i<mpos.size();i++)
		{
			int id=mpos[i];
			ll ret=0ll;
			ll t=tt[id];
			
			for(int j=0;j<mo[id].size();j++)
			{
				t+=mo[id][j].first;
				ret=1ll*mo[id][j].second;
				
				if(t<0||t>=L[id])break;
			}
			
			minv=min(minv,ret);
		}
		
		if(minv==INF)minv=0ll;
		
		tot+=minv;
		tot%=MOD;
		
	//	cout<<endl;
	//	for(int i=0;i<k;i++)cout<<A[i]<<' ';
	//	cout<<endl<<st<<' '<<minv<<' '<<st*n+minv<<endl;
		
		return;
	}
	
	for(int i=0;i<L[lvl];i++)
	{
		A[lvl]=i;
		dfs(A,lvl+1);
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	for(int i=0;i<15;i++){minx[i]=INF;maxx[i]=-INF;}
	
	cin>>n>>k;
	for(int i=0;i<k;i++)cin>>L[i];
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		sum[x]+=y;
		maxx[x]=max(maxx[x],sum[x]);
		minx[x]=min(minx[x],sum[x]);
		mo[x].pb(mp(y,i+1));
	}
	
	bool f=1;
	for(int i=0;i<k;i++)if(sum[i]){f=0;break;}
	
	if(f){cout<<-1;return 0;}
	
	dfs(d,0);
	
	cout<<tot%MOD+1;
	
	return 0;
}

/*
3 2
3 3
1 1
2 -1
1 1




5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
