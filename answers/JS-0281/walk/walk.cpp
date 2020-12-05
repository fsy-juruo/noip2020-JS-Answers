#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,k,w[1000],pos[1000],f=1,sum[1000010],fir[1000010][2];
long long ans;
pair<int,int>s[100010];

bool judge()
{
	if(pos[1]*pos[2]*pos[3]*pos[4]*pos[5]==0 || pos[1]>w[1] || pos[2]>w[2] || pos[3]>w[3] || pos[4]>w[4] || pos[5]>w[5])
		return 1;
	return 0;
}

void solve()
{
	int flag=1;
	int x1=pos[1],x2=pos[2],x3=pos[3],x4=pos[4],x5=pos[5];
	while(flag)
	{
		if(f==-1)
			return;
		for(int i=1;i<=n;i++)
		{
			ans++;
			if(ans>=1000000007)
				ans-=1000000007;
			int x=s[i].first,y=s[i].second;
			pos[x]+=y;
			//cout<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[5]<<endl;
			if(judge())
			{
				flag=0;
				break;
			}
		}
		if(x1==pos[1] && x2==pos[2] && x3==pos[3] && x4==pos[4] && x5==pos[5])
			cout<<(f=-1);
	}
}

void solve1()
{
	int maxl=0,maxr=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+s[i].second;
		if(sum[i]>0 && fir[sum[i]][0]==0)
			fir[sum[i]][0]=i;
		else if(sum[i]<0 && fir[sum[i]][1]==0)
			fir[sum[i]][1]=i;
		maxl=max(maxl,sum[i]);
		maxr=max(maxr,(-sum[i]));
	}
	//for(int i=1;i<=n;i++)
	//	cout<<fir[i][0]<<' ';
	//cout<<endl;
	//cout<<maxl<<' '<<maxr<<endl;
	for(int i=1;i<=w[1];i++)
	{
		if(fir[i][1]!=0 && fir[w[1]-i+1][0]!=0)
			ans+=min(fir[i][1],fir[w[1]-i+1][0]);
		else if(fir[i][1]!=0)
			ans+=fir[i][1];
		else if(fir[w[1]-i+1][0]!=0)
			ans+=fir[w[1]-i+1][0];
		else if(sum[n]>0)
		{
			int move=sum[n];
			int need=(w[1]-i+1)-maxl;
			long long temp=((need-1)/move+1)*n;
			//cout<<need<<' '<<temp<<' ';
			//cout<<(temp+fir[(w[1]-i+1-temp/n*move)][0])<<endl;
			ans+=(temp+fir[(w[1]-i+1-temp/n*move)][0]);
		}
		else
		{
			int move=-sum[n];
			int need=i-maxr;
			long long temp=((need-1)/move+1)*n;
			ans+=(temp+fir[i-temp/n*move][1]);
		}
		if(ans>=1000000007)
			ans-=1000000007;
		//cout<<ans<<endl;
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<1000;i++)
		w[i]=1;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>s[i].first>>s[i].second;
	if(k==1 && n>100 && k>5)
	{
		solve1();
		ans=ans%1000000007;
		cout<<ans;
		return 0;
	}
	for(int i1=1;i1<=w[1];i1++)
		for(int i2=1;i2<=w[2];i2++)
			for(int i3=1;i3<=w[3];i3++)
				for(int i4=1;i4<=w[4];i4++)
					for(int i5=1;i5<=w[5];i5++)
					{
						pos[1]=i1;
						pos[2]=i2;
						pos[3]=i3;
						pos[4]=i4;
						pos[5]=i5;
						solve();
						if(f==-1)
							return 0;
					}
	if(ans>=1000000007)
		ans-=1000000007;
	cout<<ans<<endl;
	return 0;
}
