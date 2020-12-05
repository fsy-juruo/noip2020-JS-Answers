#include<bits/stdc++.h>
using namespace std;
struct node{
	int f;
	int t;
}sta[820040];
int n,m,k,p[55][405],h[55],tar,cnt,ccnt,rub;
inline void ope(int a,int b)
{
	++k;
	sta[k].f=a;
	sta[k].t=b;
	++h[b];
	p[b][h[b]]=p[a][h[a]];
	--h[a];
}
inline void tope(int a,int b,int c)
{
	while(c>0)
	{
		ope(a,b);
		--c;
	}
}
inline int read()
{
	int a=0;
	char c;
	do
	{
		c=getchar();
	}while(c>'9'||c<'0');
	while(c<='9'&&c>='0')
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return a;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	for(register int i=1;i<=n;++i)
	{
		h[i]=m;
		for(register int j=1;j<=m;++j)
		p[i][j]=read();
	}
	for(register int i=n;i>0;--i)
	{
		tar=p[i][h[i]];
		/*for(register int j=1;j<i;++j)
		{
			while(p[j][h[j]]==tar)ope(j,i+1);
			while(h[j]!=m)ope(i,j);
		}*/
		for(register int j=1;j<=i;++j)
		{
			for(register int r=1;r<=n+1;++r)
			if(r!=i+1&&r!=j)
			{
				rub=r;
				break;
			}
			ccnt=cnt=0;
			for(register int r=1;r<=h[j];++r)
			if(p[j][r]==tar)++cnt;
			tope(rub,i+1,cnt);
			while(h[j])
			{
				if(p[j][h[j]]==tar)ope(j,rub);//cnt
				else
				{
					ope(j,i+1);
					++ccnt;
				}
			}
			tope(i+1,j,ccnt+cnt);
			tope(rub,i+1,cnt);
			tope(j,rub,cnt);
			while(h[j]!=m)
			{
				if(p[rub][h[rub]]==tar)ope(rub,i+1);
				else ope(rub,j);
			}
		}
	}
	/*
	for(register int i=1;i<k;++i)
	if(sta[i].t==sta[i+1].f)
	{}
	*/
	cout<<k<<'\n';
	for(register int i=1;i<=k;++i)
	cout<<sta[i].f<<' '<<sta[i].t<<endl;
	return 0;
}
