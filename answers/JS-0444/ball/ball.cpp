#include<bits/stdc++.h>
#define X a[i].x
using namespace std;
inline void read(int &x)
{
	char ch;int f=1;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f;
}
inline void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x,char ch)
{
	write(x);
	putchar(ch);
}
struct node{
	int num,x[1001];
};
struct node1{
	int x,y;
};
node a[1001];
node1 step[10000001];
int c,n,f[100001],m,v[100001],f1[100001];
void record(int x,int y)
{
	c++;
	step[c].x=x,step[c].y=y;
}
void Throw(int x,int y)
{
	a[x].num--,a[y].num++;
	a[y].x[a[y].num]=a[x].x[a[x].num+1];
	a[x].x[a[x].num+1]=0;
	record(x,y);
}
void solve_up(int x,int y,int z)
{
	int k=1;
	if(y==a[x].num)
	{
		Throw(x,z);
		return;
	}
	while(1)
	{
		if(y==a[x].num)
		{
			Throw(x,z);
			return;
		}
		if(a[k].num<m&&k!=x&&v[k]==0&&k!=z)
		{
		//	 <<k<<"???"<<a[k].num<<endl;
		//	for(int i=1;i<=m;i++)
		//	{
		//		 <<a[k].x[i]<<' ';
		//	}
		//	 <<endl;
			Throw(x,k);
		}
		else k++;
		if(k>n+1)
		{
			f1[k]=1;
			break;
		}
	}
}
void solve(int dep)
{
	//int h=rand()%n+1;
	//while(v[h]!=0)h=rand()%n+1;
	if(dep==n)return;
	for(int i=1;i<=n;i++)
	{
	    //if(v[i]==1)continue;
	    for(int j=1;j<=m;j++)
	      f[a[i].x[j]]+=a[i].num-j+1;
	}
	int Min=INT_MAX,cnt;
	for(int i=1;i<=n;i++)
	{
		if(f[i]<Min&&v[i]==0)
		{
			Min=f[i];
			cnt=i;
		}
	}
//	 <<dep<<' '<<cnt<<endl;
int nc=0;
	while(1)
	{
		int fl=1;
	for(int i=1;i<=n+1;i++)
	{
		if(f1[i]!=0)
		{
			fl=0;
			break;
		}
	}
	if(fl==1&&nc!=0)break;
	for(int i=1;i<=n;i++)
	{
		if(i==n+1-dep)continue;
		for(int j=a[i].num;j>=1;j--)
		{
			/// <<i<<' '<<j<<'?'<<endl;
		    if(X[j]==cnt)
		    {
		    //	 <<i<<' '<<j<<' '<<n+1-dep<<endl;
		    	solve_up(i,j,n+1-dep);
		    	if(f1[i]==1)
		    	{
		    		
		    		break;
				}
			}
		}
	}
	nc=1;
    }
	v[cnt]=1;
	solve(dep+1);
}
int check()
{
	int f=0;
	for(int i=1;i<=n+1;i++)
	{
		//if(a[i].num!=m)return 0;
		if(a[i].num==0)f=1;
		for(int j=1;j<=m;j++)
		{
			if(a[i].x[j]!=a[i].x[1])
			{
		//		 <<"?"<<endl;
			return 0;
		    }
		}
	}
	if(f==0)return 0;
	return 1;
}
int main()
{
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	a[i].num=m;
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i].x[j];
		}
	}
	while(!check())
	solve(0);
	cout<<c<<endl;
	for(int i=1;i<=c;i++)
	{
		cout<<step[i].x<<' '<<step[i].y<<endl;
	}
//	for(int i=1;i<=n+1;i++)
//	{
//		for(int j=1;j<=m;j++)
	//	{
	//		cout<<a[i].x[j]<<' ';
	//	}
	//	cout<<endl;
//	}
	return 0;
}

