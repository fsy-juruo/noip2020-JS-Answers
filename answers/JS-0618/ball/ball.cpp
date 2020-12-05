#include<bits/stdc++.h>
#define N 12
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
int n,m,col[N][N<<1],tot=0,top[N];
pair<int,int> opt[83000];
bool check()
{ if (top[n+1]>0) return false; 
  for (int i=1;i<=n;i++)
   { if (top[i]!=m) return false;
	 for (int j=1;j<m;j++)
      if (col[i][j]!=col[i][j+1]) return false;}
    return true;
}
struct node{
	int last,Col[N][N<<1],top[N];
	pair<int,int> Opt;
};
node  que[1001000];
int l,r;
int num=0;
struct Node{
	int tree[N*N*N*N][30];
    inline void add(string st)
    {  int now=0;
       for (int i=0;i<st.size();i++)
       { int p; 
	     if (st[i]=='&') p=28;
	     else p=st[i]-'A'+1;
	      if (!tree[now][p]) tree[now][p]=++num;
	      now=tree[now][p];
	   }
	}
	inline bool ask(string st)
	{ int now=0;
	  for (int i=0;i<st.size();i++)
	  {  int p;
	    if (st[i]=='&') p=28;
	    else p=st[i]-'A'+1;
	    if (!tree[now][p]) return true;
	    now=tree[now][p];
	  }
	  return false;
	}
}Tree;
bool Check()
{ string st;
  for (int i=1;i<=n+1;i++)
  { for (int j=1;j<=top[i];j++)
      st+=char(col[i][j]+'A'-1);
    st+='&';
  }
  return  Tree.ask(st);
}
inline void Hash()
{ string st;
  for (int i=1;i<=n+1;i++)
  { for (int j=1;j<=top[i];j++)
      st+=char(col[i][j]+'A'-1);
    st+='&';
  }
   Tree.add(st);
}
inline void bfs()
{  node  now;
   now.last=0;
   memcpy(now.Col,col,sizeof(now.Col));
   for (int i=1;i<=n;i++)
     now.top[i]=m;
   now.top[n+1]=0;
   que[l=r=1]=now;
   while(l<=r)
   {  now=que[l++];
   
      memcpy(col,now.Col,sizeof(col));
      memcpy(top,now.top,sizeof(top));
      
      if (check())
         { int id=l-1;
           while (id!=1)
           { opt[++tot]=que[id].Opt;  
		     id=que[id].last;
		   }
           break;
		 }
	   node ne;
	   ne.last=l-1;
	   for (int i=1;i<=n+1;i++)
	     for (int j=1;j<=n+1;j++)
	     { memcpy(ne.top,now.top,sizeof(ne.top));
	       memcpy(ne.Col,now.Col,sizeof(ne.Col));
		   if (i==j) continue;
		   if(ne.top[i]<1||ne.top[j]>=m) continue;
		   ne.Col[j][ne.top[j]+1]=ne.Col[i][ne.top[i]];
		   ne.top[i]--;
		   ne.top[j]++;
		   ne.Opt=make_pair(i,j); 
		   memcpy(col,ne.Col,sizeof(col));
		   memcpy(top,ne.top,sizeof(top));
		   if (Check())
		       {  que[++r]=ne;
			      Hash(); 
			   }
		 }
   }
}
int main()
{ freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  read(n);read(m);
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
     read(col[i][j]),top[i]=m;
  bfs();
  writeln(tot);
  for (int i=tot;i>=1;i--)
    write(opt[i].first),putchar(' '),writeln(opt[i].second);
  return 0;
}

