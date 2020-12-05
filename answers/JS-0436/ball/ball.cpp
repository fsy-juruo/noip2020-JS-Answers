#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,cnt;
int s[55][205];
int tp[55],ans[1001000][2];

template<typename Tp>
void read(Tp &x)
{
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}

void add(int l,int r)
{
	tp[r]++;
	s[r][tp[r]]=s[l][tp[l]];
	tp[l]--;
}

void solve(int l)
{
	if(l==n) return;
	int js=0,pos=0,ret=0,las=0;
	for(int i=tp[l];i>=1;i--)
	{
		if(s[l][i]!=l) 
		{
			js++;
			pos=i;
		}
	}
	if(pos==0) 
	{
		solve(l+1);
		return;
	}
	ret=tp[l]-pos+1;//js sum
	las=ret-js;//js =
	//cout<<ret<<" "<<las<<endl;
	for(int i=1;i<=las;i++)
	{
		ans[++cnt][0]=l+1,ans[cnt][1]=n+1;
		add(l+1,n+1);
	}
	for(int i=1;i<=ret;i++)
	{
		if(s[l][tp[l]]==l)
		{
			ans[++cnt][0]=l,ans[cnt][1]=l+1;
			add(l,l+1);
		}
		else
		{
			ans[++cnt][0]=l,ans[cnt][1]=n+1;
			add(l,n+1);
		}
	}
	for(int i=1;i<=las;i++)
	{
		ans[++cnt][0]=l+1,ans[cnt][1]=l;
		add(l+1,l);
	}
	for(int i=1;i<=ret;i++)
	{
		if(s[n+1][tp[n+1]]==l||tp[l]==m)
		{
			ans[++cnt][0]=n+1,ans[cnt][1]=l+1;
			add(n+1,l+1);
		}
		else
		{
			ans[++cnt][0]=n+1,ans[cnt][1]=l;
			add(n+1,l);
		}
	}
	//
	//
	for(int i=l+1;i<=n;i++)
	{
		int ps=0,js1=0;
		for(int j=tp[i];j>=1;j--)
		{
			if(s[i][j]==l)
			{
				ps=j;
				js1++;
			}
		}
		if(js==0) continue;
		int rt=tp[i]-ps+1;//js sum
//		int ls=rt-js1;//js no
		while(tp[n+1]<m-js1&&s[l][tp[l]]!=l)
		{
			ans[++cnt][0]=l,ans[cnt][1]=n+1;
			add(l,n+1);
		}
		int clc=0;
		for(int j=1;j<=rt;j++)
		{
			if(s[i][tp[i]]==l)
			{
				if(tp[n+1]<m-js1) 
				{
					ans[++cnt][0]=i,ans[cnt][1]=l;
					add(i,l);
					clc++;
				}
				else 
				{
					ans[++cnt][0]=i,ans[cnt][1]=n+1;
					add(i,n+1);
				}
			}
			else
			{
				if(tp[n+1]<m-js1)
				{
					ans[++cnt][0]=i,ans[cnt][1]=n+1;
					add(i,n+1);
					if(tp[n+1]==m-js1)
					{
						while(clc--)
						{
							ans[++cnt][0]=l,ans[cnt][1]=n+1;
							add(l,n+1);
						}
					}
				}
				else
				{
					ans[++cnt][0]=i,ans[cnt][1]=l;
					add(i,l);
				}
			}
		}
		while(s[l][tp[l]]!=l&&tp[l]>=1&&tp[i]<m)
		{
			ans[++cnt][0]=l,ans[cnt][1]=i;
			add(l,i);
		}
		while(tp[l]<m) 
		{
			ans[++cnt][0]=n+1,ans[cnt][1]=l;
			add(n+1,l);
		}
		while(tp[i]<m)
		{
			ans[++cnt][0]=n+1,ans[cnt][1]=i;
			add(n+1,i);
		}
	}
	solve(l+1);
	return;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			read(x);
			s[i][j]=x;
		}
		tp[i]=m;
	}
	solve(1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
