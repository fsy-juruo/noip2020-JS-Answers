#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair

typedef long long ll;

int n,m;
vector<int> v[100010];
pair<int,int> ans[100010];

int gcd(int x,int y)
{
	if(x<y)return gcd(y,x);
	if(y==0)return x;
	return gcd(y,x%y);
}

void calc(int x,int p,int q)
{
	int curp=ans[x].first;
	int curq=ans[x].second;
	
	if(curp==0||curq==0){ans[x]=mp(p,q);return;}
	
	int ug=gcd(curq,q);
	int chq=1ll*(curq/ug)*q;
	int chp=p*(chq/q)+curp*(chq/curq);
	int uug=gcd(chp,chq);
	chp/=uug;
	chq/=uug;
	ans[x]=mp(chp,chq);
}

void dfs(int x)
{
	int ansp=0,ansq=1;
	int curp=ans[x].first;
	int curq=ans[x].second;
	int p=1;
	int q=v[x].size();
	if(q==0)return;
	if(curp>0&&curq>0)
	{
		ansp=ans[x].first;
		ansq=q*curq;
	}
	
	if(ansp==0)ansq=1;
	if(ansp>0&&ansq>0)
	{
		int ug=gcd(ansp,ansq);
		ansp/=ug;
		ansq/=ug;
	}
	
	ans[x]=mp(0,1);
	
	for(int i=0;i<v[x].size();i++)
	{
		calc(v[x][i],ansp,ansq);
		
		dfs(v[x][i]);
	}
}

vector<int> v2;

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ans[i].first=0;
		ans[i].second=1;
	}
	for(int i=0;i<m;i++)
	{
		ans[i].first=1;
		ans[i].second=1;
	}
	
	for(int i=0;i<n;i++)
	{
		int L;cin>>L;
		if(L==0)v2.pb(i);
		
		for(int j=0;j<L;j++)
		{
			int x;cin>>x;
			x--;
			
			v[i].pb(x);
		}
	}
	
	for(int i=0;i<m;i++){dfs(i);}
	
//	for(int i=0;i<n;i++)cout<<ans[i].first<<' '<<ans[i].second<<endl;
	
	for(int i=0;i<v2.size();i++)
	{
		int num=v2[i];
		int p=ans[num].first;
		int q=ans[num].second;
		
		if(p==0||q==0){cout<<0<<' '<<1<<endl;}
		else
		{
			int ug=gcd(p,q);
			p/=ug;
			q/=ug;
			
			cout<<p<<' '<<q<<endl;
		}
	}

	return 0;
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0


12 1
3 2 3 4
2 5 6
2 7 8
2 9 10
1 11
1 11
1 11
2 11 12
1 12
1 12
0
0 
*/

