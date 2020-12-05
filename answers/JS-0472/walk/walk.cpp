#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define isnum(c) (c>='0'&&c<='9')
#define re register
const int MAXN=1e6;
const int mod=1e9+7;
struct walk{
	int dire,pos;
}walk[MAXN];
int bushu,n,k,w[12],now_x,now_y;
bool flag=0;
inline int read()
{
	bool flag1=0;char c=0;int A=0;
	c=getchar();
	while(!isnum(c))
	{
		flag1=(c=='-');
		c=getchar();
	}
	while(isnum(c))
	{
		A=(A<<3)+(A<<1)+c-'0';
		c=getchar();
	}
	A=flag1?-A:A;
	return A;
}
inline void input()
{
	n=read();k=read();
	for(int i=1;i<=k;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
		{
			int c,d;
			c=read();d=read();
			walk[i].pos=c;
			walk[i].dire=d;
			}
	//for(int i=1;i<=n;++i) printf("%d|",walk[i].pos);
}
inline void work1()
{
	for(int x=1;x<=w[1];++x)
	{
		for(int i=1;i<=n;++i)
		{
			now_x+=walk[i].dire;
			bushu++; 
			if(now_x>w[1]||now_x<1) {flag=1;break;}
		}
	if(!flag) printf("-1");	 
	}
	printf("%d",bushu);
}
inline void work2()
{
	for(int x=1;x<=w[1];++x)
	{
		for(int y=1;y<=w[2];++y)
		{	now_x=x,now_y=y;flag=0;int i=1;
			while(i<=n&&flag==0)
			{
				if(walk[i].pos==1) now_x+=walk[i].dire;
				else if(walk[i].pos==2) now_y+=walk[i].dire;
				bushu++; 
				if(now_x>w[1]||now_x<1||now_y>w[2]||now_y<1) {flag=1;break;}
				if(i>=n&&flag==0) {i=1;continue;}
				i++;
			}	 
			bushu%=mod;
			//if(flag) break;
		}
	}
	printf("%d",bushu);
}
inline void work()
{
	if(k==1) work1();
	else if(k==2) work2();
		
	
}
int main()
{
	freopen("walk3.in","r",stdin);
	freopen("walk.out","w",stdout);
	input();
	work();
	//print();
	return 0;
}
