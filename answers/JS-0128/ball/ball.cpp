#include <stdio.h>

int n,m;
int stack[55][410];

int top,from[820010],to[820010];
int ans;

void move(int fx,int fy,int tx,int ty);
void remove(int sta,int deepth,int nostack);

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&stack[i][j]);
	for(int i=1;i<=n;i++)
		stack[i][0]=m;
	stack[0][0]=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			bool flag=true;
			if(stack[i][0]>=j&&stack[i][j]==i)
				continue;
			for(int k=i;k<=n+1;k++)
			{
				if(!flag)
					break;
				for(int l=stack[k][0];l>=((k==i)?j+1:1);l--)
				{
					if(!flag)
						break;
					if(stack[k][l]==i)
					{
						flag=false;
						move(k,l,i,j);
					}
				}
			}
		}
	printf("%d\n",ans);
	for(int i=1;i<=top;i++)
		printf("%d %d\n",from[i],to[i]);
	return 0;
}

void move(int fx,int fy,int tx,int ty)
{
	if(fy==stack[fx][0]&&stack[tx][0]+1==ty)
	{
		ans++;
		from[++top]=fx;to[top]=tx;
		stack[tx][++stack[tx][0]]=stack[fx][stack[fx][0]--];
		return;
	}
	int mp=0;
	for(int i=tx+1;i<=n+1;i++)
		if(i!=fx&&i!=tx&&stack[i][0]>stack[mp][0])
			mp=i;
	if(stack[mp][0]==m)
		remove(mp,m-1,0);
	remove(fx,fy,mp);
	stack[mp][++stack[mp][0]]=stack[fx][fy];
	stack[fx][0]--;
	from[++top]=fx;to[top]=mp;ans++;
	remove(tx,ty-1,mp);
	stack[tx][++stack[tx][0]]=stack[mp][stack[mp][0]--];
	from[++top]=mp;to[top]=tx;ans++;
	return;
}
void remove(int sta,int deepth,int nostack)
{
	for(int i=1;i<=n+1;i++)
		while(stack[sta][0]>deepth&&i!=sta&&i!=nostack&&stack[i][0]<m)
		{
			stack[i][++stack[i][0]]=stack[sta][stack[sta][0]--];
			from[++top]=sta;to[top]=i;ans++;
		}
	for(int i=1;i<=n+1;i++)
		while(stack[sta][0]>deepth&&i!=sta&&stack[i][0]<m)
		{
			stack[i][++stack[i][0]]=stack[sta][stack[sta][0]--];
			from[++top]=sta;to[top]=i;ans++;
		}
	return;
}
