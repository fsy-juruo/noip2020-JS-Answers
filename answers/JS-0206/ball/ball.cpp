#include<cstdio>
#include<vector>

#define _N 510

struct Mov
{
	int from;
	int to;
	Mov()
	{
		from=to=0;
	}
	Mov(int a,int b)
	{
		from=a;
		to=b;
	}
};

int n,m;

int empty;
bool solved[_N];
std::vector<int> balls[_N];

std::vector<Mov> ops;

void mov(int from,int to)
{
	ops.push_back(Mov(from,to));
	balls[to].push_back(balls[from].back());
	balls[from].pop_back();
}

void moverange(int i,int jfrom,int jto,int to)
{
//	printf("moverange: %d %d %d %d\n",i,jfrom,jto,to);
	for(int k=jfrom;k<=jto;k++)
	{
		mov(to,empty);
	}
	for(int k=m-1;k>jto;k--)
	{
		mov(i,empty);
	}
	for(int k=jfrom;k<=jto;k++)
	{
		mov(i,to);
	}
	while(balls[i].size()<m)
	{
		mov(empty,i);
	}
}
void downrange(int i,int jfrom,int jto)
{
//	printf("downrange: %d %d %d\n",i,jfrom,jto);
	if(jfrom==0||balls[i][jfrom-1]==balls[i][jfrom])
	{
		return;
	}
	int help=-1;
	for(int k=1;k<=n;k++)
	{
		if(k!=i&&k!=empty&&!solved[k])
		{
			help=k;
			break;
		}
	}
	for(int k=jfrom;k<=jto;k++)
	{
 	    mov(help,empty);
	}
	int cnt=0;
	for(int k=m-1;k>jto;k--)
	{
		mov(i,empty);
	}
	for(int k=jfrom;k<=jto;k++)
	{
 	    mov(i,help);
	}
	for(int k=jfrom-1;k>=0;k--)
	{
		if(balls[i][k]==balls[help].back())
		{
			break;
		}
		mov(i,empty);
	}
	for(int k=jfrom;k<=jto;k++)
	{
 	    mov(help,i);
	}
	while(balls[i].size()<m)
	{
		mov(empty,i);
	}
	for(int k=jfrom;k<=jto;k++)
	{
 	    mov(empty,help);
	}
}

void print_balls()
{
	printf("opcount: %d\n",ops.size());
	for(int i=1;i<=n;i++)
	{
		printf("ball%d: ",i);
		for(int j=0;j<m;j++)
		{
			printf("%d ",balls[i][j]);
		}
		puts("");
	}
}

void solve(int color)
{
	int low=-1,vlow=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		if(!solved[i]&&i!=empty)
		{
			for(int j=0;j<m;j++)
			{
				if(balls[i][j]==color)
				{
					if(j<vlow)
					{
						vlow=j;
						low=i;
					}
					break;
				}
			}
		}
	}
//	printf("solve: %d %d\n",color, low);
	int begin=-1;
	for(int j=0;j<m;j++)
	{
		if(balls[low][j]==color)
		{
			if(begin==-1)
			{
 	 		    begin=j;
			}
		}
		else
		{
			if(begin!=-1)
			{
				downrange(low,begin,j-1);
				begin=-1;
			}
		}
	}
	if(begin!=-1)
	{
		downrange(low,begin,m-1);
		begin=-1;
	}
//	print_balls();
	for(int i=1;i<=n;i++)
	{
		if(!solved[i]&&i!=empty&&i!=low)
		{
			for(int j=0;j<m;j++)
			{
				if(balls[i][j]==color)
				{
					if(begin==-1)
					{
		 	 		    begin=j;
					}
				}
				else
				{
					if(begin!=-1)
					{
						moverange(i,begin,j-1,low);
						downrange(low,m-j+begin,m-1);
//						print_balls();
						j-=j-begin;
						begin=-1;
					}
				}
			}
			if(begin!=-1)
			{
				moverange(i,begin,m-1,low);
				downrange(low,begin,m-1);
//				print_balls();
				begin=-1;
			}
		}
	}
	solved[low]=true;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			balls[i].push_back(x);
		}
	}
	empty=n+1;
	for(int i=1;i<=n;i++)
	{
		solve(i);
//		print_balls();
	}
	printf("%d\n",ops.size());
	for(int i=0;i<ops.size();i++)
	{
		printf("%d %d\n",ops[i].from,ops[i].to);
	}
	return 0;
}
