#include<bits/stdc++.h>
using namespace std;
queue<int> qe;
int tot,head[100010],next[400010],ver[400010],inc[100010],ouc[100010],p[100010],q[100010],t[100010];
void ad(int x,int y)
{
	next[++tot]=head[x];
	ver[tot]=y;
	head[x]=tot;
	inc[y]++;
	return;
}
inline int ggu(int u,int v)
{
	if(u<v)
	return ggu(v,u);
	if(v==0)
	return u;
	return ggu(v,u%v);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int a,b,c,d,i,m,n;
	scanf("%d%d",&n,&m);
	for(a=1;a<=n;a++)
	{
		scanf("%d",&b);
		ouc[a]=b;
		q[a]=1;
		for(c=1;c<=b;c++)
		{
			scanf("%d",&d);
			ad(a,d);
		}
	}
	for(a=1;a<=n;a++)
	{
		if(inc[a]==0)
		{
			t[++t[0]]=a;
			qe.push(a);
			p[a]=1;
		}
	}
	while(qe.size())
	{
		a=qe.front();
		qe.pop();
		for(i=head[a];i;i=next[i])
		{
			inc[ver[i]]--;
			if(inc[ver[i]]==0)
			{
				t[++t[0]]=ver[i];
				qe.push(ver[i]);
			}
		}
	}
	for(a=1;a<=n;a++)
	{
		if(ouc[t[a]]!=0)
		{
			c=p[t[a]];
			d=q[t[a]]*ouc[t[a]];
			b=ggu(c,d);
			c/=b;
			d/=b;
			for(i=head[t[a]];i;i=next[i])
			{
				p[ver[i]]=d*p[ver[i]]+c*q[ver[i]];
				q[ver[i]]=q[ver[i]]*d;
				b=ggu(p[ver[i]],q[ver[i]]);
				p[ver[i]]/=b;
				q[ver[i]]/=b;
			}
		}
		else
		inc[++inc[0]]=t[a];
	}
	sort(inc+1,inc+inc[0]+1);
	for(a=1;a<=inc[0];a++)
	printf("%d %d\n",p[inc[a]],q[inc[a]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
