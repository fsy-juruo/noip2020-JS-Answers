#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5;
typedef long long ll;
vector<int> to[N];
ll in[N],ansp[N],ansq[N];
int n,m;
int gcd(int a,int b)
{
	if (a<b) swap(a,b);
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		int sz,y;
		scanf("%d",&sz);
		for (int j=1;j<=sz;j++)
		{
			scanf("%d",&y);
			to[i].push_back(y);
			in[y]++;
		}
	}
	queue<int> q;
	for (int i=1;i<=n;i++) ansp[i]=0,ansq[i]=1;
	for (int i=1;i<=n;i++) 
		if (in[i]==0) 
		{
			ansp[i]=1;
			q.push(i);
		}	
	while (!q.empty())
	{
		int u=q.front();
//		cout<<u<<endl;
		q.pop();
		int S=to[u].size();
		if (S==0) continue;
		ll r=ansp[u],t=ansq[u]*S;
		ll k=gcd(r,t);r/=k,t/=k;
//		cout<<u<<" "<<r<<" "<<t<<endl;
		for (int i=0;i<S;i++)
		{
			int v=to[u][i];
			in[v]--;
			ll b=ansq[v]*t/gcd(ansq[v],t);
			ll a=b/ansq[v]*ansp[v]+b/t*r;
			k=gcd(a,b);
			ansq[v]=b/k,ansp[v]=a/k;
			if (in[v]==0) q.push(v);
		}
	}
//	for (int i=1;i<=n;i++) cout<<ansp[i]<<" "<<ansq[i]<<endl;
	for (int i=1;i<=n;i++)
		if (to[i].size()==0) printf("%lld %lld\n",ansp[i],ansq[i]);
	return 0;
}

