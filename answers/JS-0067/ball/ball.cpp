#include<bits/stdc++.h>

using namespace std;

const int MAXN=100;

int n,m;

int a[MAXN][MAXN];
int tp[MAXN];

void _pop(int i)
{
	int j=i+1;
	while(tp[j]==m)
	{
		++j;
	}
	cout<<i<<' '<<j<<endl;
	a[j][++tp[j]] = a[i][tp[i]] ;
	a[i][tp[i]--]=0;	
}

int has_(int x,int target)
{
	for(int i=1;i<=tp[x];++i)
	{
		if(a[x][i]==target) return i;
	}
	return tp[x]+1;
} 


void work(int i)
{
	
	if(tp[i]==0)
	{
		if(i==n+1) return ; 
		tp[i]=1;
		cout<<i+1<<' '<<i<<endl;
		a[i][1]=a[i+1][tp[i+1]];
		a[i+1][tp[i+1]--]=0;
		
	}
	
	int target=a[i][1];
	int lim;  
	for(lim=1;lim<=tp[i];++lim)
	{
		if(a[i][lim]!=target) break;
	}
	--lim;
	
	while(tp[i]!=lim)
	{
	//	cout<<tp[i]<<endl;
		//system("pause");
		_pop(i);
	}
	
	for(int j=i+1;j<=n+1;++j)
	{
		int pos=has_(j,target);
		if(pos!=tp[j]+1) 
		{
			for(int k=tp[j];k>=pos;--k)
			{
				if(a[j][k]==target)
				{
					cout<<j<<' '<<i<<endl;
					--tp[j];
				}
				else _pop(j);
			}
		} 
	} 
	
}


int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
		tp[i]=m;
		
	}
	
	for(int i=1;i<=n+1;++i)
	{
		work(i);
	}
	
	
	
	return 0;
}
