#include<bits/stdc++.h>

using namespace std;

template <class T>
inline void read(T &n)
{
	n=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	n*=f;
}

const int N=500010,K=12,Mod=1e9+7;

int n,k,ans;
int w[K];
int c[N],d[N];
int pr[N];
int a[K];

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<=k;++i)
		read(w[i]);
	for(int i=1;i<=n;++i)
	{
		read(c[i]);
		read(d[i]);
	}
	
//	if(k==1)
//	{
//		int x=0,maxn=0,minn=0;
//		for(int i=1;i<=n;++i)
//		{
//			x+=d[i];
//			if(pr[x]==0)
//				pr[x]=i;
//			maxn=max(x,maxn);
//			minn=min(x,minn);
//		}
//		
//		for(int i=1;i<=n;++i)
//		{
//			int lt=-i,rt=w[1]-i+1;
//			if(pr[rt]==0&&pr[-i]==0)
//			{
//				if(x==0)
//				{
//					cout<<"-1"<<endl;
//					return 0;
//				}
//				if(x>0)
//				{
////					(w-i-maxn)/x*n+
//				}
//			}
//			int cnt=min(pr[w[1]-i+1]-1,pr[i-2]-1);
//			ans+=cnt;
//		}
//	}
	
	if(k==1)
	{
		for(int i1=1;i1<=w[1];++i1)
		{
			a[1]=i1;
			int cnt=0,t=1;
			while(a[1]>=1&&a[1]<=w[1])
			{
				if(t==n+1)
				{
					t=1;
					if(a[1]==i1)
					{
						cout<<"-1"<<endl;
						return 0;
					}
				}
				cnt=(cnt+1)%Mod;
				a[c[t]]+=d[t];
				++t;
			}
			ans=(ans+cnt)%Mod;
		}
		printf("%d\n",ans);
	}
	
	if(k==2)
	{
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
			{
				a[1]=i1;
				a[2]=i2;
				int cnt=0,t=1;
				while(a[1]>=1&&a[1]<=w[1]&&a[2]>=1&&a[2]<=w[2])
				{
					if(t==n+1)
					{
						t=1;
						if(a[1]==i1&&a[2]==i2)
						{
							cout<<"-1"<<endl;
							return 0;
						}
					}
					cnt=(cnt+1)%Mod;
					a[c[t]]+=d[t];
					++t;
				}
				ans=(ans+cnt)%Mod;
			}
		printf("%d\n",ans);
	}
	
	if(k==3)
	{
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
				for(int i3=1;i3<=w[3];++i3)
				{
					a[1]=i1;
					a[2]=i2;
					a[3]=i3;
					int cnt=0,t=1;
					while(a[1]>=1&&a[1]<=w[1]&&a[2]>=1&&a[2]<=w[2]&&a[3]>=1&&a[3]<=w[3])
					{
						if(t==n+1)
						{
							t=1;
							if(a[1]==i1&&a[2]==i2&&a[3]==i3)
							{
								cout<<"-1"<<endl;
								return 0;
							}
						}
						cnt=(cnt+1)%Mod;
						a[c[t]]+=d[t];
						++t;
					}
					ans=(ans+cnt)%Mod;
				}
		printf("%d\n",ans);
	}
	
	if(k==4)
	{
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
				for(int i3=1;i3<=w[3];++i3)
					for(int i4=1;i4<=w[4];++i4)
					{
						a[1]=i1;
						a[2]=i2;
						a[3]=i3;
						a[4]=i4;
						int cnt=0,t=1;
						while(a[1]>=1&&a[1]<=w[1]&&a[2]>=1&&a[2]<=w[2]&&a[3]>=1&&a[3]<=w[3]&&a[4]>=1&&a[4]<=w[4])
						{
							if(t==n+1)
							{
								t=1;
								if(a[1]==i1&&a[2]==i2&&a[3]==i3&&a[4]==i4)
								{
									cout<<"-1"<<endl;
									return 0;
								}
							}
							cnt=(cnt+1)%Mod;
							a[c[t]]+=d[t];
							++t;
						}
						ans=(ans+cnt)%Mod;
					}
		printf("%d\n",ans);
	}
	
	if(k==5)
	{
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
				for(int i3=1;i3<=w[3];++i3)
					for(int i4=1;i4<=w[4];++i4)
						for(int i5=1;i5<=w[5];++i5)
						{
							a[1]=i1;
							a[2]=i2;
							a[3]=i3;
							a[4]=i4;
							a[5]=i5;
							int cnt=0,t=1;
							while(a[1]>=1&&a[1]<=w[1]&&a[2]>=1&&a[2]<=w[2]&&a[3]>=1&&a[3]<=w[3]&&a[4]>=1&&a[4]<=w[4]&&a[5]>=1&&a[5]<=w[5])
							{
								if(t==n+1)
								{
									t=1;
									if(a[1]==i1&&a[2]==i2&&a[3]==i3&&a[4]==i4&&a[5]==i5)
									{
										cout<<"-1"<<endl;
										return 0;
									}
								}
								cnt=(cnt+1)%Mod;
								a[c[t]]+=d[t];
								++t;
							}
							ans=(ans+cnt)%Mod;
						}
		printf("%d\n",ans);
	}
	
	return 0;
}
