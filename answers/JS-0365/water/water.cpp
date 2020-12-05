#include<bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) rep2(i,0,n)
#define rep1(i,n) rep2(i,1,n+1)
#define pb push_back
#define mp make_pair
#define re(x) {cout<<x<<endl;return 0;}
#define all(x) x.begin(),x.end()
#define ll long long
#define x first
#define y second

using namespace std;
int n,m;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int a[111111][8];
int b[111111]={0};
pair<ll,ll>out[111111];
vector<int>ans;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>a[i][0];
		if(a[i][0]==0) ans.pb(i);
		rep1(j,a[i][0])
		{
			cin>>a[i][j];
			b[--a[i][j]]++;
		}
	}
	rep(i,ans.size()) out[ans[i]]=mp(0,1);
	rep(p,n)
	{
		if(b[p]==0)
		{
		queue<pair<int,pair<ll,ll> > >q;
		q.push(mp(p,mp(1,1)));
		while(!q.empty())
		{
			int i=q.front().x;
			pair<ll,ll>k=q.front().y;
			q.pop();
			if(a[i][0]==0)
			{
				ll g=gcd(k.x,k.y);
				k.x/=g;
				k.y/=g;
				g=gcd(k.y,out[i].y);
				out[i].x=(out[i].x)*(k.y/g)+(k.x)*(out[i].y/g);
				out[i].y=(k.y)*(out[i].y)/g;
				g=gcd(out[i].x,out[i].y);
				out[i].x/=g;
				out[i].y/=g;
				continue;
			}
			k.y*=a[i][0];
			rep1(j,a[i][0])
			{
				q.push(mp(a[i][j],k));
			}
		}
		}
	}
	rep(i,ans.size())
	{
		cout<<out[ans[i]].x<<" "<<out[ans[i]].y<<endl;
	}
	return 0;}
