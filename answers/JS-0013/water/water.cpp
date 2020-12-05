#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,a,d,s[1005],sum,lu=1;
bool b[1005],bo[1005];
queue<int> p;
vector<int> q[1005];
int gcd(int x,int y)
{
	int t;
	if(x%y==0)return y;
	else 
	{
		t=x;
		x=y;
		y=t%y;
		return gcd(x,y);
	}
}
void bfs(int u)
{
	while(!p.empty())
	{
		if(s[p.front()]!=0)
		{
			sum=s[p.front() ]/q[p.front() ].size();
			for(int i=0;i<q[p.front() ].size()  ;i++)
	        {
        		s[q[p.front() ][i]]+= sum;
        		if(bo[q[p.front() ][i]]==0)
        		{
        			p.push(q[p.front() ][i]);
        			bo[q[p.front() ][i]]=1;
				}
        	}
        	s[p.front() ]=0;
		}
		bo[p.front() ]=0;
		p.pop() ;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		if(d==0)bo[i]=1;
		if(d!=0)lu*=d;
		for(int j=1;j<=d;j++)
		{
			cin>>a;
			q[i].push_back(a);
			b[a]=1; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			s[i]=lu;
			p.push(i); 
			bo[i]=1;
		}
	}
	bfs(1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=0)
		{
			int h=gcd(s[i],lu*m);
			cout<<s[i]/h<<" "<<lu/h<<endl;
		}
	}
	return 0;
}
