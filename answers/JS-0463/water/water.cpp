#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

vector<int> a[maxn];
queue<int> que;
int indu[maxn]={},outdu[maxn]={},sx[maxn]={};
int g[maxn][2];
int n,m,d,tot=1;

int gcd(int aa,int bb)
{
	if(bb==0)return aa;
	return gcd(bb,aa%bb);
	
}

int qread()
{
	char ch=getchar();
	int f=1;
	int res=0;
	for(;ch<'0' || ch>'9';ch=getchar())if(ch=='-')f=0;
	for(;ch>='0' && ch<='9';ch=getchar())res=res*10+ch-'0';
	return f?res:-res;
}

int sor()
{
	
	for(int i=1;i<=m;i++)
	que.push(i);
	while(que.size())
	{
		int x=que.front();
		que.pop();
		sx[tot++]=x;
		for(int i=1;i<=outdu[x];i++)
	    {
		     indu[a[x][i-1]]--;
		     if(indu[a[x][i-1]]==0)que.push(a[x][i-1]);
	    }
	}
}

int chufa1(int aa,int bb,int ww)
{
	int cc=gcd(aa,ww);
	aa/=cc;
	return aa;
}
int chufa2(int aa,int bb,int ww)
{
	int cc=gcd(aa,ww);
	ww=ww/cc;
	bb*=ww;
	return bb;
}
int jiafa1(int aa,int bb,int cc,int dd)
{
	int ww=gcd(bb,dd);
	bb/=ww,dd/=ww;
	return (aa*dd+cc*bb);
}
int jiafa2(int aa,int bb,int cc,int dd)
{
	int ww=gcd(bb,dd);
	bb/=ww,dd/=ww;
	return (bb*dd*ww);
}
int solve()
{
	for(int i=1;i<=m;i++)
	 g[i][1]=1,g[i][2]=1;
//	for(int i=1;i<=n;i++)
	//cout<< g[i][1]<<' '<<g[i][2]<<endl;
	for(int i=1;i<=n;i++)
	{
		int ty=sx[i];
		int u1=g[ty][1],u2=g[ty][2];
		int w1=chufa1(u1,u2,outdu[sx[i]]),w2=chufa2(u1,u2,outdu[sx[i]]);
		//cout<<w1<<' '<<w2<<endl;
		for(int j=1;j<=outdu[sx[i]];j++)
		{
			int u=g[a[sx[i]][j-1]][1],v=g[a[sx[i]][j-1]][2];
			if(u==0 ||v==0)
			{
			g[a[sx[i]][j-1]][1]=w1;
			g[a[sx[i]][j-1]][2]=w2;
			}
			else
			{
			g[a[sx[i]][j-1]][1]=jiafa1(w1,w2,u,v);
			g[a[sx[i]][j-1]][2]=jiafa2(w1,w2,u,v);
			int y=gcd(g[a[sx[i]][j-1]][1],g[a[sx[i]][j-1]][2]);
			g[a[sx[i]][j-1]][1]/=y;
			g[a[sx[i]][j-1]][2]/=y;
		    }
		}
		
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=qread(),m=qread();
	for(int i=1;i<=n;i++)
	{
		int x;
		d=qread();
		outdu[i]=d;
		for(int j=1;j<=d;j++)
		{
			x=qread();
			indu[x]++;
			a[i].push_back(x);
		}		
	}
	sor();
/*	for(int i=1;i<=n;i++)
	cout<<sx[i]<<' ';*/
  solve();
    for(int i=m;i<=n;i++)
    {
    	if(outdu[i]==0)  cout<<g[i][1]<<' '<<g[i][2]<<endl;
	}
	//cout<<jiafa1(1,3,2,3)<<' '<<jiafa2(1,3,2,3);
	return 0;
}
