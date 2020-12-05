#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
const int M=2e7+50;
int head[N],nxt[M],ver[M];
int k[N],d[N],f[N];
int c[12],a[N],b[N];
bool v[N];
int l;
int tot,n,m;
void add(int x,int y)
{
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
	f[y]++;
}

queue<int >q;
int read()
{
	int x=0,y=1; char ch=getchar();
	while(ch>'9' || ch<'0') {if(ch=='-') y=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*y;
}
int gcd(int x,int y)
{   

	int r=x%y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
void jia(int i,int j)
{
	b[i]*=d[i];
	a[j]=a[j]*b[i]+a[i]*b[j];
	b[j]=b[i]*b[j];
	int o=gcd(a[j],b[j]);
	a[j]=a[j]/o;
	b[j]=b[j]/o;
	b[i]/=d[i];

}
void topport()
{
	for(int i=1;i<=n;i++)if(f[i]==0) {
	q.push(i);  a[i]=1; }
	while(q.size())
	{
		int x=q.front();   q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			f[y]--;
			jia(x,y);
		   if(f[y]==0) 
		   q.push(y);
		   
		}

	}
	
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	l=0,tot=0;
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
		n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=0,b[i]=1;
	}

	for(int i=1;i<=n;i++)
	{
		d[i]=read(); 
		if(d[i]==0) c[++l]=i;
		for(int j=1;j<=d[i];j++)
		{
		  int o=read();
		  add(i,o);
		  
		}
	}
		
	topport();
    for(int i=1;i<=l;i++)
    { 
     cout<<a[c[i]]<<" "<<b[c[i]]<<endl;
	}
	
	return 0;
}
