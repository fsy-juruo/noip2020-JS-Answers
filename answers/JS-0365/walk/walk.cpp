#include<bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) rep2(i,0,n)
#define rep1(i,n) rep2(i,1,n+1)
#define pb push_back
#define mp make_pair
#define re(x) {cout<<x<<endl;return 0;}
#define all(x) x.begin(),x.end()
#define ll long long
//define x first
//define y second

using namespace std;
int n,k,w[12],c[111111],d[111111];
ll ans=0;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	rep(i,k) cin>>w[i];
	rep(i,n)
	{
		cin>>c[i]>>d[i];
		c[i]--;
	}
	if(n<=1000)
	{
		if(k==1)
		{
			rep(i,w[0])
			{
				int x=i,y=0,tp=i;
				while(x<w[0]&&x>=0)
				{
					x+=d[y%n];
					y++;
					if(y==n&&tp==x) re(-1)
				}
				ans+=(ll)(y);
				ans%=1000000007;
			}
			re(ans)
		}
		if(k==2)
		{
			rep(i,w[0])
			rep(j,w[1])
			{
				int x[2]={i,j},y=0,tp[2]={i,j};
				while(x[0]<w[0]&&x[1]<w[1]&&x[0]>=0&&x[1]>=0)
				{
					x[c[y%n]]+=d[y%n];
					y++;
					if(y==n&&tp[0]==x[0]&&tp[1]==x[1]) re(-1)
				}
				ans+=(ll)(y);
				ans%=1000000007;
			}
			re(ans)
		}
		if(k==3)
		{
			rep(i,w[0])
			rep(j,w[1])
			rep(l,w[2])
			{
				int x[3]={i,j,l},y=0,tp[3]={i,j,l};
				while(x[2]<w[2]&&x[2]>=0&&x[0]<w[0]&&x[0]>=0&&x[1]<w[1]&&x[1]>=0)
				{
					x[c[y%n]]+=d[y%n];
					y++;
					if(y==n&&tp[2]==x[2]&&tp[0]==x[0]&&tp[1]==x[1]) re(-1)
				}
				ans+=(ll)(y);
				ans%=1000000007;
			}
			re(ans)
		}
		if(k==4)
		{
			rep(i,w[0])
			rep(j,w[1])
			rep(l,w[2])
			rep(o,w[3])
			{
				int x[4]={i,j,l,o},y=0,tp[4]={i,j,l,o};
				while(x[3]<w[3]&&x[3]>=0&&x[2]<w[2]&&x[2]>=0&&x[0]<w[0]&&x[0]>=0&&x[1]<w[1]&&x[1]>=0)
				{
					x[c[y%n]]+=d[y%n];
					y++;
					if(y==n&&tp[3]==x[3]&&tp[2]==x[2]&&tp[0]==x[0]&&tp[1]==x[1]) re(-1)
				}
				ans+=(ll)(y);
				ans%=1000000007;
			}
			re(ans)
		}
		if(k==5)
		{
			rep(i,w[0])
			rep(j,w[1])
			rep(l,w[2])
			rep(o,w[3])
			rep(p,w[4])
			{
				int tp[5]={i,j,l,o,p},x[5]={i,j,l,o,p},y=0;
				while(x[4]<w[4]&&x[4]>=0&&x[3]<w[3]&&x[3]>=0&&x[2]<w[2]&&x[2]>=0&&x[0]<w[0]&&x[0]>=0&&x[1]<w[1]&&x[1]>=0)
				{
					x[c[y%n]]+=d[y%n];
					y++;
					if(y==n&&tp[4]==x[4]&&tp[3]==x[3]&&tp[2]==x[2]&&tp[0]==x[0]&&tp[1]==x[1]) re(-1)	
				}
				ans+=(ll)(y);
				ans%=1000000007;
			}
			re(ans)
		}
	}
	if(k==1)
	{
		int maxx=-1111111,minn=1111111,mx=0,mn=0;
		rep2(i,1,n)
		{
			d[i]+=d[i-1];
			if(d[i]>maxx) maxx=d[i],mx=i;
			if(d[i]>minn) minn=d[i],mn=i;
		}
		rep(i,w[0])
		{
			int tmp=i,st=mn;
			bool ko=1;
			while(tmp+maxx<n)
			{
				if(tmp+minn<0) ko=0;
				tmp+=d[n-1],ans+=(ll)(n);
				ans%=1000000007;
			}
			if(ko) st=mx;
			rep(i,n)
			{
				if(tmp+d[i]<0||tmp+d[i]>=n) ans+=(ll)(i),ans%=1000000007;;
			}
		}
		re(ans)
	}
	return 0;}
