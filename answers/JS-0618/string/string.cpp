#include<bits/stdc++.h>
#define N   140010
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
int T,n;
long long sum[N][30],sum_ni[N];
string st;
bool f=true;
long long num[30]={0};
bool check(string  a,int l,int r)
{ if (f) return true;
  for (int i=1;i<=r-l+1;i++)
    if (st[l+i-1]!=a[i-1]) return false;
  return true;
}
long long ans=0;
bool Check()
{ for (int i=1;i<n;i++)
    if (st[i]!=st[i+1]) return false;
 return true;
}
inline void baoli()
{ memset(num,0,sizeof(num));
  memset(sum,0,sizeof(sum));
  memset(sum_ni,0,sizeof(sum_ni)); 
  memset(num,0,sizeof(num));
  f=Check();
  int cnt=0;
  for (int j=1;j<=n;j++)
  {  int now=st[j]-'a'+1; 
	 num[now]++;
     if(num[now]&1) cnt++;
         else cnt--;
     sum[j][cnt]++;
  }
  for (int i=1;i<=n;i++)
    for (int j=0;j<=26;j++)
      sum[i][j]+=sum[i-1][j];
  for (int i=1;i<=n;i++)
    for (int j=1;j<=26;j++)
      sum[i][j]+=sum[i][j-1];
  memset(num,0,sizeof(num));
  for (int i=n;i>=1;i--)
  {  int now=st[i]-'a'+1;
     sum_ni[i]=sum_ni[i+1]; 
     num[now]++;
     if (num[now]&1)  sum_ni[i]++;
     else  sum_ni[i]--; 
  }
  string  ab="";
  ans=0;
  ab+=st[1];
  for (int i=2;i<n;i++)
  {  ab+=st[i];
    ans+=sum[i-1][sum_ni[i+1]];
     for (int k=2;k*i<n;k++)
      if (check(ab,i*(k-1)+1,i*k)==true)
          {ans+=sum[i-1][sum_ni[i*k+1]];}
         else break;
  }
  writeln(ans);
}
int main()
{ freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  read(T);
  while (T--)
  { cin>>st;n=st.size();st="&"+st;
    baoli();
  }
  return 0;
}
/*
3 
nnrnnr
zzzaab
mmlmmlo
*/
