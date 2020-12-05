#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=1e6;

struct Heapnode
{
	int u,d;
	bool operator < (const Heapnode& a) const {
		return d>a.d;
	}
	Heapnode(int u,int d):u(u),d(d) {}
};

struct Fac //faction structure
{
	int p,q;
};

Fac ans[maxn]; // 节点i处的流入总量 
int n,m; //n,m
vector<int> S[maxn];  //每个节点的son
int p_cnt[maxn]; //每个节点的父亲数量 
int s_cnt[maxn];//the son_sum of each node
int dis[maxn]; //single source longest path
int cnt[maxn]; //a counter used for bfs


int Gcd(int x,int y)  //gcd
{
	if(y==0) return x;
	x=x%y;
	Gcd(y,x);
}
Fac yue(Fac a)  //约分 
{
	int gong=Gcd(a.p,a.q); //公因数
	a.p=a.p/gong;
	a.q=a.q/gong; 
	return a;
}
Fac Divide(Fac x,int y)
{
	x.q*=y;
	x=yue(x);
	return x;
}
Fac Add(Fac x,Fac y)
{
	Fac ans;
	int gong; //两个分母的公因数
	if(y.p==0) gong=1;
	else gong=Gcd(x.q,y.q);
	ans.q=x.q/gong*y.q;
	int bei1=ans.q/x.q,bei2=ans.q/y.q;
	ans.p=x.p*bei1+y.p*bei2;
	ans=yue(ans);
	return ans;
}
void Output(Fac x) //out put a Fac struct
{
//	nwah;
	cout<<x.p<<" "<<x.q<<endl;
}

void init()
{
	ans[1].p=1;
	ans[1].q=1;
	for(int i=0;i<maxn;i++) p_cnt[i]=0;
	for(int i=0;i<n;i++) dis[i]=-INF;
	dis[1]=1;
	for(int i=0;i<maxn;i++) cnt[i]=0;
}
void ReadIn() //checked
{
	cin>>n>>m;
	int ru;
	for(int i=1;i<=n;i++)
	{
		cin>>s_cnt[i];
		for(int j=0;j<s_cnt[i];j++)
		{
			cin>>ru;
			S[i].push_back(ru);
			p_cnt[ru]++;  //checked
		}
	}
}
void bfs() //solve the single source longest path cheked
{
	queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int u=Q.front(); Q.pop();
		int v;
		for(int i=0;i<S[u].size();i++)
		{
			v=S[u][i];
			cnt[v]++;
			if(cnt[v]==p_cnt[v])
			{
				dis[v]=dis[u]+1;
				Q.push(v);
			}
		}
	}
}
priority_queue <Heapnode> Que;  //确保逐层流水 
void solve_init()
{
	for(int i=1;i<=n;i++) Que.push(Heapnode(i,dis[i]));
	for(int i=2;i<=n;i++)
	{
		ans[i].p=0;
		ans[i].q=1;
	}
}
void divide_flow(int x)
{
	//test
//	if(x==7||x==9) Output(ans[x]); 
	
	Fac tot=ans[x];
	Fac nxt=Divide(tot,s_cnt[x]); //往下分的流量 
//	Output(nxt);
	for(int i=0;i<S[x].size();i++)
	{
/*		if(S[x][i]==10)
		{
			cout<<"base:";
			Output(ans[10]);
			cout<<"add:";
			Output(nxt);
		}*/
		 ans[S[x][i]]=yue(Add(ans[S[x][i]],nxt));
	}
//	Output(ans[10]);
}
void Solve()
{
	while(!Que.empty())
	{
		Heapnode x=Que.top(); Que.pop();
		if(s_cnt[x.u]!=0) divide_flow(x.u);
	}
}
void print_ans()
{
//	nwah;
	for(int i=1;i<=n;i++) 
	{
//		cout<<s_cnt[i]<<endl;
		if(s_cnt[i]==0) Output(ans[i]);
//		 Output(ans[i]);
	}
}
int main()
{
//	ios::sync_with_stdio(false);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
		init();
	ReadIn();
	bfs();
	solve_init();
	Solve();
	print_ans();
//	for(int i=1;i<=n;i++) cout<<dis[i]<<endl;
	return 0;
}

//10:00 pass the little example1
//10:48 pass sample2 I'm stupid






















