#include<bits/stdc++.h>
using namespace std;
long long n,m;

long long a[10086][3];
long long b[10001][1001];
long long line[100000001];
long long head,tail;
long long gcd(long long o,long long p)
{
	if (p==0) return 1;
	if(o==0) return 1;
	if(o%p==0) return p;
	else return gcd( p,o%p);
}


void add(long long x,long long y,long long z)
{
	
	long long gc;
	gc=gcd(a[x][2],z);
	long long nz;
	nz=a[x][2]*z/gc;
	a[x][1]=a[x][1]*(nz/a[x][2]);
	y=y*(nz/z);
	a[x][1]+=y;
	a[x][2]=nz;
	gc=gcd(a[x][1],a[x][2]);
	a[x][1]/=gc;a[x][2]/=gc;
}
void read()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long k=0;
		cin>>k;
		for( long long j=1;j<=k;j++)
		{
			cin>>b[i][j];
		}
	}
}
void flow()
{
	 long long s=0;
	for(long long i=1;b[line[head]][i]>0;i++)
	{
		s++;
	}
	for( long long i=1;b[line[head]][i]>0;i++)
	{
		add(b[line[head]][i],a[line[head]][1],s*a[line[head]][2]);
		
		line[tail]=b[line[head]][i];
		tail++;
		tail=tail%100000001;
	}
	if(s!=0)
	{
		a[line[head]][1]=0;
		a[line[head]][2]=1;
	}
	head++;
	head=head%100000001;
	
	
}

int main()
{
	system("pause");
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read();
	for(long long i=0;i<=10085;i++)
	{
		a[i][2]=1;
	}
	for( long long i=1 ;i<=m;i++)
	{
		a[i][1]=1;
		line[m]=m;
	}
	
	head=1;
	tail=m+1;
	line[head]=1;
	
	while(head!=tail)
	{
		flow();
	}
	for (long long i=1;i<=n;i++)
	{
		if(b[i][1]==0)
		{
			long long gcda=gcd(a[i][1],a[i][2]);
			a[i][1]/=gcda;
			a[i][2]/=gcda;
			cout<<a[i][1]<<" "<<a[i][2]<<endl;
		}
	}
	
	
	
	
	
	
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long n,m;

long long a[10086][3];
long long b[10001][1001];
long long line[100000001];
long long head,tail;
long long gcd(long long o,long long p)
{
	if (p==0) return 1;
	if(o==0) return 1;
	if(o%p==0) return p;
	else return gcd( p,o%p);
}


void add(long long x,long long y,long long z)
{
	
	long long gc;
	gc=gcd(a[x][2],z);
	long long nz;
	nz=a[x][2]*z/gc;
	a[x][1]=a[x][1]*(nz/a[x][2]);
	y=y*(nz/z);
	a[x][1]+=y;
	a[x][2]=nz;
	gc=gcd(a[x][1],a[x][2]);
	a[x][1]/=gc;a[x][2]/=gc;
}
void read()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long k=0;
		cin>>k;
		for( long long j=1;j<=k;j++)
		{
			cin>>b[i][j];
		}
	}
}
void flow()
{
	 long long s=0;
	for(long long i=1;b[line[head]][i]>0;i++)
	{
		s++;
	}
	for( long long i=1;b[line[head]][i]>0;i++)
	{
		add(b[line[head]][i],a[line[head]][1],s*a[line[head]][2]);
		
		line[tail]=b[line[head]][i];
		tail++;
		tail=tail%100000001;
	}
	if(s!=0)
	{
		a[line[head]][1]=0;
		a[line[head]][2]=1;
	}
	head++;
	head=head%100000001;
	
	
}

int main()
{
	system("pause");
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read();
	for(long long i=0;i<=10085;i++)
	{
		a[i][2]=1;
	}
	for( long long i=1 ;i<=m;i++)
	{
		a[i][1]=1;
		line[m]=m;
	}
	
	head=1;
	tail=m+1;
	line[head]=1;
	
	while(head!=tail)
	{
		flow();
	}
	for (long long i=1;i<=n;i++)
	{
		if(b[i][1]==0)
		{
			long long gcda=gcd(a[i][1],a[i][2]);
			a[i][1]/=gcda;
			a[i][2]/=gcda;
			cout<<a[i][1]<<" "<<a[i][2]<<endl;
		}
	}
	
	
	
	
	
	
	return 0;
}*/
