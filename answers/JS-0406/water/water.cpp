#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+100
struct p{
	long long fz;
	long long fm;
}val[MAXN];
int id[MAXN];
int od[MAXN];
int n,m;
vector<int> G[MAXN];
queue<int> q;
long long gc(long long x,long long y)
{
	if(y==0) return x;
	return gc(y,x%y);
}
void topo()
{
	while(!q.empty())
	{
		int p_o=q.front();
		q.pop();
		for(int i=0;i<G[p_o].size();i++)
		{
			id[G[p_o][i]]--;
//			val[G[p_o][i]].fz=val[p_o].fz;
//			val[G[p_o][i]].fm=val[p_o].fm*od[p_o];
			val[p_o].fm*=od[p_o];
			long long tot=val[G[p_o][i]].fm/gc(val[p_o].fm,val[G[p_o][i]].fm)*val[p_o].fm;
			long long tot1=tot/val[G[p_o][i]].fm;
			long long tot2=tot/val[p_o].fm;
			val[G[p_o][i]].fz=val[G[p_o][i]].fz*tot1+val[p_o].fz*tot2;
			val[G[p_o][i]].fm=tot;
			long long ys=gc(val[G[p_o][i]].fz,val[G[p_o][i]].fm);
			val[G[p_o][i]].fz/=ys;
			val[G[p_o][i]].fm/=ys;
			
			val[p_o].fm/=od[p_o];
			if(id[G[p_o][i]]==0)
			{
				q.push(G[p_o][i]);
		//		cout<<"###";
		//		cout<<G[p_o][i]<<" "<<val[G[p_o][i]].fz<<" "<<val[G[p_o][i]].fm<<"\n";
			}
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		val[i].fm=1;
		val[i].fz=0;
		for(int j=0;j<a;j++)
		{
			int b;
			scanf("%d",&b);
			od[i]++;
			id[b]++;
			G[i].push_back(b);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(id[i]==0)
		{
			val[i].fz=1;
			val[i].fm=1;
			q.push(i);
		}
	}
	topo();
	for(int i=1;i<=n;i++)
	{
		if(od[i]==0)
		{
	//		cout<<i<<" ";
			cout<<val[i].fz<<" "<<val[i].fm;
			cout<<"\n";
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

*/
