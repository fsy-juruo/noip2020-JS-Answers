#include<bits/stdc++.h>
#define N 100100
#define ll long long 
using namespace std;
template<typename T>inline void read(T &x)
{ x=0;
  T f=1;
  char c=getchar();
  while (!isdigit(c))
  {  if (c=='-') f=-1;
	 c=getchar();}
  while (isdigit(c))
  {  x=(x<<3)+(x<<1)+(c^48);
	c=getchar();}
  x*=f;}
template<typename T>inline void write(T x)
{  if (x<0) x=-x,putchar('-');
   if (x/10) write(x/10);
   putchar(x%10+48);}
template<typename T>inline void writeln(T x)
{  write(x);
   puts("");}
int n,m,out[N],head[N],cnt=1;
ll ansl[N],ansr[N];
struct node{
	int to,mark;
}pre[N<<3];
inline void add(int a,int b)
{ pre[++cnt].to=b;
   pre[cnt].mark=head[a];
   head[a]=cnt;
}
inline ll Gcd(long long a,long long b)
{  if (b==0) return a;
   return Gcd(b,a%b);
}
inline void dfs(int u,long long p,long long q)
{  ll np=p,nq=q*out[u];
   if (!out[u])
      { ll x=ansl[u],y=ansr[u];
        ll LCM=q*y/Gcd(q,y);
        x=x*(LCM/y);
        p=p*(LCM/q);
        ansl[u]=x+p;
        ansr[u]=LCM;
        ll P=Gcd(ansl[u],ansr[u]);
        ansl[u]/=P;
        ansr[u]/=P;
        return;
	  }
   for (int i=head[u];i;i=pre[i].mark)
   {  int to=pre[i].to;
      dfs(to,np,nq);
   }
}
int main()
{ freopen("water.in","r",stdin);
  freopen("water.out","w",stdout);
  read(n);read(m);
  for (int i=1;i<=n;i++)  ansl[i]=0,ansr[i]=1;
  for (int i=1;i<=n;i++)
  { read(out[i]);
    for (int j=1;j<=out[i];j++)
    {  int v;
      read(v);
      add(i,v);
	}
  }
  for (int i=1;i<=m;i++)
   dfs(i,1,1);
  for (int i=1;i<=n;i++)
    if (!out[i])  write(ansl[i]),putchar(' '),writeln(ansr[i]);
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
