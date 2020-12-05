#include<bits/stdc++.h>
using namespace std;
struct pipe
{
	int num;
	int de[1005];
}p[1005];
struct fs
{
	int fz;
	int fm;
};
//struct edge
//{
//	int v,w,nxt;
//}e[100005];

int n,m,minn=0x3f3f3f3f,cnt=1,head[1005],tx=3,book[1005],cnt1,flag,fla[1005];
bool bok[1005];
fs pc[1005];
//void add(int u,int v,int w)
//{
//	e[cnt].v=v;
//	e[cnt].w=w;
//	e[cnt].nxt=head[u];
//	head[u]=cnt++;
//}

int t1,t2;
bool lca(int a,int b)
{
	t1=0;
	t2=0;
	int t=a,tt=b;
	if(a%b==0)
	{
		t1=a/b;
		t2=1;
		return 1;
	}
	if(b%a==0)
	{
		t1=1;
		t2=b/a;
		return 1;
	}
	for(int i=1;i<=sqrt(a);i++)
	{
		for(int j=1;j<=sqrt(b);j++)
		{
			if(a%i==0&&b%j==0&&i!=1&&j!=1&&i==j)
			{
				a/=i;
				b/=j;
			}
		}
	}
//	printf("%d %d %d %d\n",t,tt,a,b);
	t1=a;
	t2=b;
//	if(t1==t||tt==b)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//	printf("%d  %d\n",a,b);
}
fs yf(fs a,fs b)
{
	t1=0,t2=0;
	fs temp;
	int fl;
//	if(a.fz==0)
//	{
//		fl=a.fm;
//		a.fz=1;
//		yf(a,b);
//		temp.fm=fl;
//		temp.fz=-1;
//		yf(temp,a);
//	}
//	if(b.fz==0)
//	{
//		fl=b.fm;
//		b.fz=1;
//		yf(a,b);
//		temp.fm=fl;
//		temp.fz=-1;
//		yf(temp,a);
//	}
//	if(a.fz==0)
//	{
//		lca()
//	}
	if(a.fm%b.fm==0)
	{
		temp.fm=a.fm;
		temp.fz=a.fz+a.fm/b.fm*b.fz;
		return temp;
	}
	if(b.fm%a.fm==0)
	{
		temp.fm=b.fm;
		temp.fz=b.fz+b.fm/a.fm*a.fz;
		return temp;
	}
	if(a.fm==b.fm)
	{
		temp.fm=a.fm;
		temp.fz=a.fz+b.fz;
	}
	else
	{
		lca(a.fm,a.fz);
		a.fm=t1;
		a.fz=t2;
//		cout<<"f"<<a.fz<<" "<<a.fm<<endl;
		lca(b.fm,b.fz);
		b.fm=t1;
		b.fz=t2;
//		cout<<"f"<<b.fz<<" "<<b.fm<<endl;
		yf(a,b);
	}
	lca(temp.fm,temp.fz);
	temp.fm=t1;
	temp.fz=t2;
	return temp;
}
void dfs(int pre,int s,fs val)
{
	
	if(p[s].num==0)//ееЁЖ
	{
//		printf("%d %d %d/%d\n",pre,s,val.fz,val.fm);
//		for(int i=1;i<=5;i++)
//		{
//			printf("%d/%d \n",pc[i].fz,pc[i].fm);
//		}
//		cout<<endl;
//		if(step<minn)
//		{
//			minn=step;
//		}
		pc[s]=yf(pc[s],val);
		return;
	}
	else if(p[s].num==1)
	{
		dfs(s,p[s].de[1],val);
	}
	else if(p[s].num>1)
	{
		fs tmp;
		tmp.fm=val.fm*p[s].num;
		tmp.fz=val.fz;
		for(int i=1;i<=p[s].num;i++)
		{
			dfs(s,p[s].de[i],tmp);
		}
	}
//	for(int i=head[s];i;i=e[i].nxt)
//	{
//		int v=e[i].v;
//		if(!book[i])
//		{
//			book[i]=1;
//			dfs(e[i].v,step+1);
//			book[i]=0;
//		}	
//	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+10;i++)
	{
		pc[i].fm=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		p[i].num=x;
		if(x==0)
		{
//			cout<<i<<" ";
			cnt1++;
			fla[cnt1]=i;
		}
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&p[i].de[j]);
			bok[p[i].de[j]]=1;
		}
//		p[i].num=x;
		
//		add(x,y,z);
//		add(y,x,z);
	}

	fs start;
	start.fm=1;
	start.fz=1;
	for(int i=1;i<=n;i++)
	{
		if(bok[i]==0)
		{
			flag=i;
		}
	}
	dfs(1, flag,start);
//	cout<<"y1"<<endl;
//	cout<<cnt1;
//	for(int i=1;i<=10;i++)
//	{
//		cout<<fla[i]<<endl;
//	}
	for(int i=1;i<=cnt1;i++)
	{
		lca(pc[fla[i]].fz,pc[fla[i]].fm);
		printf("%d %d\n",t1,t2);
	}
	return 0;
//	printf("%d",minn);
//	fs aaaa,bbbb;
//	aaaa.fm=2,aaaa.fz=0;
//	bbbb.fm=2,bbbb.fz=1;
//	aaaa=yf(aaaa,bbbb);
//	cout<<aaaa.fz<<"/"<<aaaa.fm;
}
