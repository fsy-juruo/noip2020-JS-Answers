#include<bits/stdc++.h>
using namespace std;
struct ins{
	template<typename T>void read(T &n)
	{
		n=0;char c=getchar();bool f=1;
		while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(isdigit(c)){n=n*10+c-'0';c=getchar();}
		if(f==0)n=-n;
	}
	template<typename T>ins operator >>(T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
vector<int> c;
const int maxn=411;
vector<int> v[maxn];
int x[maxn];
int y[maxn];
int yy[maxn];
int n,m;
int tot,optx[maxn],opty[maxn];
int f[maxn][maxn],frm[maxn][maxn];
int vv[maxn];
void dfs()
{
	if(c.size()==2)
	{
		while(v[c[0]].size())
		{
			optx[++tot]=c[0];opty[tot]=c[1];
			v[c[0]].pop_back();
		}
		return ;
	}
	int ansd=c[0];
	for(int i=0;i<c.size();i++)
	{
		if((v[c[i]].size())<(v[ansd].size()))ansd=c[i];
	}
	for(int i=0;i<c.size();i++)
	{
		if(c[i]==ansd)continue;
		while(v[ansd].size()&&v[c[i]].size()<m)
		{
			optx[++tot]=ansd;opty[tot]=c[i];
			v[c[i]].push_back(v[ansd].back());
			v[ansd].pop_back();
		}
	}
	for(int i=0;i<=n;i++)x[i]=0;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]==ansd)continue;
		for(int i=1;i<=n;i++)yy[i]=0;
		for(int j=0;j<v[c[i]].size();j++)
		{
			if(!yy[v[c[i]][j]])
				x[v[c[i]][j]]+=v[c[i]].size()-j-1,
			yy[v[c[i]][j]]=j;
		}
	}
	int ans=0;x[ans]=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		if(!y[i]&&x[i]<x[ans])ans=i;
	}
	int tot1=m;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]==ansd)continue;
		for(int i=1;i<=n;i++)yy[i]=0;
		for(int j=0;j<v[c[i]].size();j++)
		{
			if(v[c[i]][j]==ans)
			{
				++j;
				for(;j<v[c[i]].size();j++)
				{
					optx[++tot]=c[i];
					opty[tot]=ansd;
					v[ansd].push_back(v[c[i]].back());
					v[c[i]].pop_back();
				}
				break;
			}
		}
	}
	memset(f,0,sizeof(f));
	memset(frm,0,sizeof(frm));
	f[0][0]=1;frm[0][0]=0;
	for(int i=0;i<c.size();i++)
	{
		for(int j=0;j<=tot1;j++)
			if(f[i][j])
			{
				f[i+1][j]=1;
				frm[i+1][j]=j;
			}
		if(c[i]!=ansd)
		for(int j=m-v[c[i]].size();j<=tot1;j++)
		{
			if(f[i][j-m+v[c[i]].size()-1])
				f[i+1][j]=1,frm[i+1][j]=j-m+v[c[i]].size()-1;
		}
	}
	memset(vv,0,sizeof(vv));
	for(int j=tot1,i=c.size();j;i--)
	{
		if(j!=frm[i][j])
		{
			vv[i-1]=1;
		}
		j=frm[i][j];
	}
	queue<int> q,q1;
	for(int i=0;i<c.size();i++)
	{
		if(vv[i])
		{
			if(ansd!=c[i])
				q.push(c[i]);
		}
		else 
		if(ansd!=c[i])q1.push(c[i]);
	}
	for(int i=0;i<c.size();i++)
	{
		if(!vv[i])
		{
			while(!q.empty()&&v[q.front()].size()==m)q.pop();
			optx[++tot]=c[i];opty[tot]=q.front();
			v[q.front()].push_back(v[c[i]].back());
			v[c[i]].pop_back();
		}
	}
	while(!v[ansd].empty())
	{
		if(v[ansd].back()==ans)
		{
			while(!q.empty()&&v[q.front()].size()==m)q.pop();
			optx[++tot]=ansd;opty[tot]=q.front();
			v[q.front()].push_back(v[ansd].back());
			v[ansd].pop_back();
		}
		else 
		{
			while(!q1.empty()&&v[q1.front()].size()==m)q1.pop();
			optx[++tot]=ansd;opty[tot]=q1.front();
			v[q1.front()].push_back(v[ansd].back());
			v[ansd].pop_back();
		}
	}
	for(int i=0;i<c.size();i++)
	if(ansd==c[i]){
	c.erase(c.begin()+i);break;}
	dfs();
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	yin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			yin>>x;
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=n+1;i++)c.push_back(i);
	dfs();
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
	{
		printf("%d %d\n",optx[i],opty[i]);
	}
	return 0;
}

