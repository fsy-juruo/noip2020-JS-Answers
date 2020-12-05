#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#define int long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template<typename T> void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template<typename T> void writeln(T x){
	write(x);
	puts("");
}
int n,m;
vector<int> col[55];
vector<pair<int,int> > path;
bool check()
{
	int cnt=0;
	for(register int i=1;i<=n+1;++i)
	{
		if(col[i].size()==0)
		{
			cnt++;
			if(cnt>1) return false;
			continue;
		}
		for(register int j=1;j<col[i].size();++j)
			if(col[i][j]!=col[i][0]) return false;
	}
	if(cnt==0) return false;
	return true;
}
void dfs()
{
	if(path.size()>10) return;
	if(check())
	{
		writeln(path.size());
		for(register int i=0;i<path.size();++i)
		{
			write(path[i].first);putchar(' ');writeln(path[i].second);
		}
		exit(0);
	}
	else
	{
		vector<int> from,to;
		for(register int i=1;i<=n+1;++i)
		{
			if(col[i].size()>=1) from.push_back(i);
			if(col[i].size()<=m-1) to.push_back(i);
		}
		for(register int i=0;i<from.size();++i)
			for(register int j=0;j<to.size();++j)
				if((path.size()==0||path[path.size()-1]!=make_pair(to[j],from[i]))&&from[i]!=to[j])
				{
					int tmp=col[from[i]][col[from[i]].size()-1];
					col[from[i]].pop_back();
					col[to[j]].push_back(tmp);
					path.push_back(make_pair(from[i],to[j]));
					dfs();
					col[to[j]].pop_back();
					col[from[i]].push_back(tmp);
					path.pop_back();
				}
	}
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=m;++j)
		{
			int a;
			read(a);
			col[i].push_back(a);
		}
	}
	dfs();
	return 0;
}

