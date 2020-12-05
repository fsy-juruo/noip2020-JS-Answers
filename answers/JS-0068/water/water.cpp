#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int v,next;
}edge[100001];
int head[100001],tot=0;
void addedge(int u,int v)
{
	tot++;
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int rd[100001],sz[100001];
queue<int> Q;
struct Bigint{
	int n;
	long long a[55];
	Bigint(){for(int i=1;i<=50;i++)a[i]=0;}
	Bigint(int x)
	{
		for(int i=1;i<=50;i++)a[i]=0;
		a[1]=x;n=1;
	}
	friend Bigint operator*(Bigint A,int B)
	{
		for(int i=1;i<=A.n;i++)
			A.a[i]*=B;
		for(int i=1;i<=A.n;i++)
			A.a[i+1]+=A.a[i]/100000000,
			A.a[i]=A.a[i]%100000000;
		if(A.a[A.n+1])A.n++;
		return A;
	}
	friend Bigint operator*(Bigint A,Bigint B)
	{
		Bigint ans;ans.n=1;
		for(int i=1;i<=50;i++)
			ans.a[i]=0;
		for(int i=1;i<=A.n;i++)
			for(int j=1;j<=B.n;j++)
				ans.a[i+j]+=(ans.a[i+j-1]+A.a[i]*B.a[j])/100000000,
				ans.a[i+j-1]=(ans.a[i+j-1]+A.a[i]*B.a[j])%100000000;
		for(int i=1;i<=50;i++)
			if(ans.a[i]!=0) ans.n=i;
		return ans;
	}
	friend Bigint operator+(Bigint A,Bigint B)
	{
		Bigint ans;
		for(int i=1;i<=50;i++)
			ans.a[i]=0;
		for(int i=1;i<=max(50,max(A.n,B.n));i++)
			ans.a[i+1]+=(ans.a[i]+A.a[i]+B.a[i])/100000000,
			ans.a[i]=(ans.a[i]+A.a[i]+B.a[i])%100000000;
		for(int i=1;i<=50;i++)
			if(ans.a[i]!=0) ans.n=i;
		return ans;
	}
	friend Bigint operator-(Bigint A,Bigint B)
	{
		Bigint ans;ans.n=1;
		for(int i=1;i<=50;i++)
			ans.a[i]=0;
		for(int i=1;i<=A.n;i++)
		{
			ans.a[i]+=A.a[i]-B.a[i];
			if(ans.a[i]<0)ans.a[i+1]--,ans.a[i]+=100000000;
		}
		for(int i=1;i<=50;i++)
			if(ans.a[i]!=0) ans.n=i;
		return ans;
	}
	friend bool operator>=(Bigint A,Bigint B)
	{
		if(A.n>B.n)return true;
		if(A.n<B.n)return false;
		for(int i=A.n;i>=1;i--)
		{
			if(A.a[i]>B.a[i])return true;
			if(A.a[i]<B.a[i])return false;
		}
		return true;
	}
	friend Bigint operator%(Bigint A,Bigint B)
	{
		while(A>=B)
		{
			int tmp;
			if(A.n==B.n)
				tmp=A.n-B.n+1;
			else tmp=A.n-B.n;
			Bigint tt;tt.n=tmp;tt.a[tmp]=1;
			tt=tt*B;
			int l=1,r=100000000,ans=1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(A>=tt*mid)
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			tt=tt*ans;
			A=A-tt;
		}
		return A;
	}
	friend Bigint operator/(Bigint A,Bigint B)
	{
		Bigint a;a=0;
		while(A>=B)
		{
			int tmp;
			if(A.n==B.n)
				tmp=A.n-B.n+1;
			else tmp=A.n-B.n;
			Bigint tt;tt.n=tmp;tt.a[tmp]=1;
			Bigint t2=tt*B;
			int l=1,r=100000000,ans=1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(A>=t2*mid)
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			tt=tt*ans;t2=t2*ans;
			A=A-t2;a=a+tt;
		}
		return a;
	}
};
Bigint fz[100001],fm[100001];
Bigint az[100001],am[100001];
Bigint gys(Bigint a,Bigint b)
{
	if(b.n==1&&b.a[1]==0)
		return a;
	return gys(b,a%b);
}
void op(Bigint a)
{
	printf("%lld",a.a[a.n]);
	for(int i=a.n-1;i>=1;i--)
		printf("%08lld",a.a[i]);
}
void ops(Bigint a)
{
	cerr<<a.a[a.n];
	for(int i=a.n-1;i>=1;i--)
		cerr<<a.a[i];
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sz[i]);
		for(int j=1;j<=sz[i];j++)
		{
			int v;scanf("%d",&v);
			addedge(i,v);
			rd[v]++;
		}
		fz[i]=0;fm[i]=1;az[i]=0;
	}
	for(int i=1;i<=m;i++)
		fz[i]=1;
	for(int i=1;i<=n;i++)
		if(rd[i]==0)Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		if(sz[u]!=0)
		{
			if(fz[u].n!=1||fz[u].a[1]!=0)
				fm[u]=fm[u]*sz[u];
			for(int i=head[u];i;i=edge[i].next)
			{
				int v=edge[i].v;
				if(fz[u].n!=1||fz[u].a[1]!=0)
				{
					Bigint t1=(fz[v]*fm[u]);
					//op(fz[v]);cout<<" ";
					//op(fm[u]);cout<<endl;
					Bigint t2=(fz[u]*fm[v]);
					fz[v]=t1+t2;
					fm[v]=fm[u]*fm[v];
				}
				rd[v]--;
				if(rd[v]==0)
					Q.push(v);
			}
		}
		else
			az[u]=fz[u],am[u]=fm[u];
	}
	for(int u=1;u<=n;u++)
		if(az[u].n!=1||az[u].a[1]!=0)
		{
			Bigint tmp=gys(az[u],am[u]);
			az[u]=az[u]/tmp;am[u]=am[u]/tmp;
			op(az[u]);printf(" ");
			op(am[u]);printf("\n");
		}
	return 0;
}
