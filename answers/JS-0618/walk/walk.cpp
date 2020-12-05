#include<bits/stdc++.h>
#define N 500100
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
const int Maxn=12;
long long w[Maxn],Max[Maxn],Min[Maxn],n,k,final[Maxn],pre[Maxn],pos[Maxn][N],c[N],d[N];
const long long mod=1e9+7;
long long ans=0;
bool check()
{  for (int i=1;i<=k;i++)
   {  if (final[i]!=0) return false;
      if (w[i]-Max[i]<1-Min[i]) return false;
   }
   return true;
}
inline void init()
{  memset(final,0,sizeof(final));
   memset(pos,0,sizeof(pos));
   for (int i=1;i<=k;i++)
     Max[i]=-INT_MAX,Min[i]=INT_MAX;
   for (int i=1;i<=n;i++)
   {  final[c[i]]+=d[i];
      Max[c[i]]=max(Max[c[i]],final[c[i]]);
	  Min[c[i]]=min(Min[c[i]],final[c[i]]);
   }
   memset(final,0,sizeof(final));
   memset(pre,0,sizeof(pre));
   for (int i=1;i<=k;i++)
     if (Min[i]<0)  pre[i]=-Min[i];
   for (int i=1;i<=n;i++)
   {   final[c[i]]+=d[i];
       if (!pos[c[i]][pre[c[i]]+final[c[i]]])  pos[c[i]][pre[c[i]]+final[c[i]]]=i;
   }
}
long long nw[Maxn];
bool Check()
{  for (int i=1;i<=k;i++)
     if (nw[i]+Max[i]>w[i]||nw[i]+Min[i]<1) return false;
  return true;
}
long long last[20];
inline void Work()
{  memcpy(last,nw,sizeof(last));
   while (Check()==true)
   { for (int i=1;i<=k;i++)
       nw[i]+=final[i];
      ans=(ans+n)%mod;
   }  
   long long  maxn=LONG_LONG_MAX;
   for (int i=1;i<=k;i++)
    {  if (nw[i]+Max[i]>w[i])  maxn=min(maxn,pos[i][pre[i]+w[i]-nw[i]+1]);
	   if (nw[i]+Min[i]<1)  maxn=min(maxn,pos[i][pre[i]-nw[i]]);
	}
	ans=(ans+maxn)%mod;
	memcpy(nw,last,sizeof(nw));
}
inline void dfs(int dep)
{  if (dep>k)
      {Work();
       return;}
  for (long long i=1;i<=w[dep];i++)
     {nw[dep]=i;dfs(dep+1);}
}
inline void baoli()
{ dfs(1); 
  writeln(ans);
  exit(0);
}
int main()
{ freopen("walk.in","r",stdin);
  freopen("walk.out","w",stdout);
  read(n);read(k);
  for (int i=1;i<=k;i++)
     read(w[i]);
  for (int i=1;i<=n;i++)
    read(c[i]),read(d[i]);
  init();
  if (check()) {puts("-1");return 0;} 
  baoli();
  return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
/*
5 4
6 8 6 5
3 1
2  1
1 1
2 1
2 -1
*/
