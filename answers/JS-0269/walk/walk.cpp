//AFO
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxk 12
#define mo 1000000007
inline int read()
{
	char c;int sign=1;
	while((c=getchar())<'0'||c>'9') if(c=='-') sign=-1;
	int ret=c-'0';
	while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
	return ret*sign;
}
int n,k;
int kn[maxk];
struct node
{
	int n1,n2;
};
vector<node>walk;
ll ans;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++)
	{
		kn[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		x=read();
		y=read();
		node c;
		c.n1=x;
		c.n2=y;
		walk.push_back(c);
	}
	if(k==1)
	{
		ll ans1=0;
			ll cnt=0;
		for(int i=0;i<walk.size();i++)
		{
			int x=walk[i].n2;
			ans1+=x;
			cnt++;
		}
	//	cout<<ans1<<" "<<cnt<< " "<<kn[1];
		for(int i=1;i<=kn[1];i++)
		{
			
			ll ans2=0;
			ll x=i;
			while((x+ans1)>0&&(x+ans1)<=kn[1])
			{
				x+=ans1;
				ans2+=cnt;
			}
			
	//	cout<<x<< " "<<ans2<<endl;
		for(int i=0;i<walk.size();i++)
		{
			int y=walk[i].n2;
			x+=y;
			ans2++;
			if(x<=0||x>kn[1])
			{
				break;
			}
			
		}
//		cout<<ans2<< " ";
		ans+=ans2%mo;
	}
		cout<<ans%mo;
		return 0;
	}
	else
	cout<<"-1";
/*	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=kn[i];j++)
		{
			while(1)
			{
				
			}
		}
	}
	*/
	return 0;
}
