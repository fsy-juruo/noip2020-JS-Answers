#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
ll readll()
{
	char c=getchar(); ll neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c)
{
	writeint(x); putchar(c); return;
}
void Writell(ll x,char c)
{
	writell(x); putchar(c); return;
}
const int maxn=60;
const int maxm=405;
int n,m,balls[maxn][maxm],top[maxn],tot;
vector<pair<int,int> > ans;
void add(pair<int,int> cur)
{
	if((int)ans.size())
	{
		pair<int,int> pre=ans[(int)ans.size()-1];
		if(pre.first==cur.second&&cur.first==pre.second)
		{
			ans.pop_back();
			return;
		}
	}
	ans.push_back(cur);
	return;
}
void move(int row,int col,int aim)
{
	int need=tot-(col-1),valid=(aim-2)*m,ext=need-valid;
	for(int i=1;i<=ext;i++)
	{
		balls[aim][++top[aim]]=balls[row][top[row]--];
		add(make_pair(row,aim));
	}
	int lst=1;
	for(int i=top[row];i>=col;i--)
	{
		while(top[lst]==m||lst==row) lst++;
		balls[lst][++top[lst]]=balls[row][top[row]--];
		add(make_pair(row,lst));
	}
	for(int i=1;i<=ext;i++)
	{
		balls[row][++top[row]]=balls[aim][top[aim]--];
		add(make_pair(aim,row));
	}
	balls[aim][++top[aim]]=balls[lst][top[lst]--];
	add(make_pair(lst,aim));
	return;
}
void fl()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
}
int main()
{
//	printf("%.24lf\n",(sizeof(balls)+sizeof(m)+sizeof(maxm)+sizeof(maxn)+sizeof(n)+sizeof(top)+sizeof(tot)+sizeof(int)*3*820000*2)/1024.0/1024.0);
	fl();
	n=readint(); m=readint();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			balls[i][++top[i]]=readint();
	for(int t=1;t<=n;t++)
	{
		int aim=n-t+2,lst=1;
		while(top[aim])
		{
			while(top[lst]==m) lst++;
			balls[lst][++top[lst]]=balls[aim][top[aim]--];
			add(make_pair(aim,lst));
		}
		tot=(aim-1)*m;
		int i=balls[1][m];
		int nxt_r=-1,nxt_c=-1;
		for(int j=2;j<aim;j++)
		{
			for(int k=top[j];k>=0;k--)
				if(balls[j][k]==i)
				{
					nxt_r=j;
					nxt_c=k;
					break;
				}
			if(~nxt_r) break;
		}
		if(nxt_r==-1)
		{
			while(top[1])
			{
				balls[aim][++top[aim]]=balls[1][top[1]--];
				add(make_pair(1,aim));
			}
			continue;
		}
		move(1,i,aim); tot--;
		move(nxt_r,nxt_c,aim); tot--;
		for(int j=1;j<aim;j++)
			for(int k=top[j];k>=0;k--)
				if(balls[j][k]==i)
				{
					move(j,k,aim);
					tot--;
				}
	}
	Writeint((int)ans.size(),'\n');
	for(int i=0;i<(int)ans.size();i++)
	{
		Writeint(ans[i].first,' ');
		Writeint(ans[i].second,'\n');
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/

