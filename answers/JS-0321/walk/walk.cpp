#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
const long long Mod=1e9+7;
bool flag;
long long n,k;
long long w[7];
long long minn[7];
long long maxx[7];
long long opt[205][205][15];
long long fn[7];
long long cs[7];
long long ds[7];
long long c[100005];
long long d[100005];
long long kmnn[100005];
long long kmxx[100005];
long long ktt[100005];
long long ans;
long long answ;
long long calc()
{
	for(long long i=1;i<=k;i++) ds[i]=cs[i];
	int gs=0;
	while(1)
	{
		for(long long i=1;i<=n;i++)
		{
			ds[c[i]]+=d[i];
			gs++;
			if(ds[c[i]]<1) return gs;
			if(ds[c[i]]>w[c[i]]) return gs;
		}
		gs%=Mod;
	}
	
	
}
long long pd()
{
	if(k<=3)
		{
			if(opt[cs[1]][cs[2]][cs[3]])
				{
					return opt[cs[1]][cs[2]][cs[3]];
				}
		}
	for(long long i=1;i<=k;i++)
		{
			if(cs[i]+minn[i]<1||cs[i]+maxx[i]>w[i])
			{
				return calc();
			}
		}
	if(flag)
		{
			cout<<-1<<endl;
			exit(0);
		}
	for(long long i=1;i<=k;i++)
		{
			cs[i]+=fn[i];
		}
	long long q=pd()+n;
	q%=Mod;
	for(long long i=1;i<=k;i++) cs[i]-=fn[i];
	if(k<=3)
		{
			opt[cs[1]][cs[2]][cs[3]]=q;
			q%=Mod;
		}
	return q;
}
void dfs(long long now)
{
	if(now>k)
		{
			ans+=pd();
			ans%=Mod;
		}
	for(long long i=1;i<=w[now];i++)
		{
			cs[now]=i;
			dfs(now+1);
		}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(long long i=1;i<=k;i++) w[i]=read();
	for(long long i=1;i<=n;i++) c[i]=read(),d[i]=read();
	for(long long i=1;i<=n;i++)
	{
		fn[c[i]]+=d[i];
		if(fn[c[i]]<minn[c[i]]) minn[c[i]]=fn[c[i]];
		if(fn[c[i]]>maxx[c[i]]) maxx[c[i]]=fn[c[i]];
		if(k==1)
			{
				kmnn[i]=min(kmnn[i-1],minn[1]);
				kmxx[i]=max(kmxx[i-1],maxx[1]);
			}
	}
	if(k==1)
		{
//			cout<<fn[1]<<" "<<maxx[1]<<" "<<minn[1]<<endl;
			if(fn[1]>0)
				{
					fn[1]*=-1;
					minn[1]*=-1;
					maxx[1]*=-1;
					swap(minn[1],maxx[1]);
					for(int i=1;i<=n;i++) kmnn[i]*=-1,kmxx[i]*=-1;
				}
//			cout<<fn[1]<<" "<<maxx[1]<<" "<<minn[1]<<endl;
			int ans=0;
			for(int i=1;i<=w[1];i++)
				{
//					cout<<i<<"  "<<i+minn[1]<<" "<<i+maxx[1]<<endl;
					if(i+minn[1]>=1&&i+maxx[1]<=w[1])
						{
							ans+=ktt[i+fn[1]]+n;
							ktt[i]=ktt[i+fn[1]]+n;
							ans%=Mod;
							ktt[i]%=Mod;
							continue;
						}
					int ll=1,rr=n,anss=0;
					while(ll<=rr)
						{
							int mid=(ll+rr)>>1;
							if(i+kmnn[mid]>=1&&i+kmxx[mid]<=w[1]) ll=mid+1,anss=mid;
							else rr=mid-1;
						}
					ktt[i]=anss+1;
					ktt[i]%=Mod;
					ans=ans+anss+1;
					ans%=Mod;
				}
//			for(int i=1;i<=10;i++) cout<<ktt[i]<<" ";
//			cout<<endl;
			cout<<ans<<endl;
			return 0;
		}
	flag=1;
	for(long long i=1;i<=k;i++)
	{
		if(fn[i]!=0) {flag=0;break;}	
	}
	dfs(1);
	cout<<ans%Mod<<endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1


5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

6 1
10
1 -1
1 1
1 1
1 -1
1 -1
1 -1
*/
