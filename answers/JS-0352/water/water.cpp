#include<bits/stdc++.h>
#define io_speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e5+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
int n,m,N;
int in[MAXN],rec[MAXN];
int pos[15];
bool toi[MAXN][15];
struct Edge
{
	int v,nxt;
	Edge(){}
	Edge(int _v,int _nxt)
	{
		v=_v,nxt=_nxt;
	}
}edge[MAXN*5];
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
inline ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
struct Divide
{
	ll p,q;
	void div()
	{
		while(p%2==0&&q%2==0) {p>>=1;q>>=1;}
		while(p%3==0&&q%3==0) {p/=3;q/=3;}
		while(p%5==0&&q%5==0) {p/=5;q/=5;}
	}
	Divide(){p=0,q=1;}
	Divide(ll _p,ll _q)
	{
		p=_p,q=_q;div();
	}
	Divide(const Divide &rhs)
	{
		p=rhs.p;q=rhs.q;div();
	}
	Divide operator+(const Divide &rhs) const
	{
		ll l=lcm(q,rhs.q);
		ll pp1=p*l/q,pp2=rhs.p*l/rhs.q;
//		cout<<p<<" "<<q<<" "<<rhs.p<<" "<<rhs.q<<" ";
		Divide ret=Divide(pp1+pp2,l);ret.div();
//		cout<<ret.p<<" "<<ret.q<<endl;
		return ret;
	}
	Divide operator*(int k) const
	{
		Divide ret=Divide(p,q*k);ret.div();
		return ret;
	}
};
int head[MAXN],tot;
void init()
{
	memset(head,-1,sizeof head);
	tot=0;
}
void addedge(int u,int v)
{
	edge[tot]=Edge(v,head[u]);
	head[u]=tot++;
}
vector<int> V[15];
Divide bfs(int s)
{
	Divide ans,end[MAXN];
	int out[MAXN];memset(out,0,sizeof out);
	queue<int> qu;
	qu.push(s);
	end[s]=Divide(1,1);
	while(!qu.empty())
	{
		int u=qu.front();qu.pop();
		ans=ans+end[u];
		for(int i=head[u];i!=-1;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(in[v]==0) continue;
//			cout<<u<<"->"<<v<<endl;
			end[v]=end[v]+(end[u]*rec[i]);
			if(++out[v]==in[v])
			{
				qu.push(v);
//				cout<<"push"<<v<<endl;
			}
		}
	}
//	for(int k=1;k<=n;k++)
//	{s
//		end[k].div();
//		cout<<end[k].p<<" "<<end[k].q<<endl;
//	}
	return ans;
}
int main()
{
	io_speed_up;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];rec[i]=in[i];
		for(int j=1;j<=in[i];j++)
		{
			int v;cin>>v;
			addedge(v,i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0) pos[++N]=i;
	}
	for(int i=1;i<=N;i++)
	{
		for(int k=head[pos[i]];k!=-1;k=edge[k].nxt)
		{
			in[edge[k].v]--;
			V[i].push_back(edge[k].v);
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(vector<int>::iterator k=V[i].begin();k<V[i].end();k++)
		{
			in[*k]++;
		}
		Divide ans;
		ans=bfs(pos[i]);
		ans=ans*N;
		cout<<ans.p<<" "<<ans.q<<endl;
		for(vector<int>::iterator k=V[i].begin();k<V[i].end();k++)
		{
			in[*k]--;
		}
	}
	return 0;
}

