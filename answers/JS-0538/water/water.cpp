#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> void read(T&x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int MAXN=100005;
vector<int>a[MAXN];
int n,m,rsk[105],csk[MAXN],cs=0;
ll dis1[MAXN],dis2[MAXN];
queue<int>q_;
ll gcd(ll P,ll Q)
{
	if(Q==0)return P;
	return gcd(Q,P%Q);
}
ll gbs(ll P,ll Q)
{
	return P*Q/gcd(P,Q);
}
void add(ll P1,ll Q1,ll &P2,ll &Q2)
{
	ll g=gbs(Q1,Q2);
	P2=g/Q2*P2;
	P1=g/Q1*P1;
	Q2=g;
	P2+=P1;
	ll y=gcd(P2,Q2);
	P2/=y;
	Q2/=y;
}
void clear()
{
	while(!q_.empty())q_.pop();
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		int k;
		read(k);
		if(k==0)csk[i]=1;
		while(k--)
		{
			int x;read(x);a[i].push_back(x);
		}
		dis2[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		dis1[i]=1;
		clear();
		q_.push(i);
		while(!q_.empty())
		{
			int x=q_.front();
			q_.pop();
			if(csk[x]==1)continue;
			ll siz=(ll)a[x].size();
			for(int j=0;j<a[x].size();j++)
			{
				int v=a[x][j];
				add(dis1[x],dis2[x]*siz,dis1[v],dis2[v]);
				q_.push(v);	
			}
			dis1[x]=0;dis2[x]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(csk[i])printf("%lld %lld\n",dis1[i],dis2[i]);
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
