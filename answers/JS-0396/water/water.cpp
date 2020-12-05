#include<bits/stdc++.h>
#define REP(i,n) for(int (i)=0;(i)<(int)n;i++)
#define ll long long
using namespace std;

const int SIZE=1e5+7;
vector<int> ch[SIZE],out;
queue<int> q;
ll sum[SIZE][2],ans[SIZE][2];

int gcd(int x,int y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	REP(i,n)
	{
		int len;
		cin>>len;
		if(len==0)out.push_back(i);
		REP(j,len)
		{
			int x;
			cin>>x;
			x--;
			ch[i].push_back(x);
		}
	}
	REP(i,m)q.push(i),sum[i][0]=sum[i][1]=1;
	REP(i,SIZE)sum[i][1]=ans[i][1]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(ch[x].size()==0)
		{
			ll l=ans[x][1]*sum[x][1]/gcd(ans[x][1],sum[x][1]);
			ans[x][0]=(l/sum[x][1])*sum[x][0]+(l/ans[x][1])*ans[x][0];
			ans[x][1]=l;
			ll g=gcd(ans[x][0],ans[x][1]);
			ans[x][0]/=g;ans[x][1]/=g;
			sum[x][0]=0;sum[x][1]=1;
			continue;
			//cout<<ans[x][0]<<" "<<ans[x][1]<<endl;
		}
		//cout<<x<<endl;
		
		ll pl[2];
		pl[0]=pl[1]=1;
		if(ch[x].size()!=0)
		{
			pl[0]=sum[x][0];pl[1]=(sum[x][1]*ch[x].size());
			int g=gcd(pl[0],pl[1]);
			pl[0]/=g;pl[1]/=g;
		}
		//cout<<x<<" "<<pl[0]<<" "<<pl[1]<<endl;
		REP(i,ch[x].size())
		{
			ll u=ch[x][i];
			//cout<<pl[0]<<" "<<pl[1]<<endl;
			//cout<<u<<" "<<sum[u][0]<<" "<<sum[u][1]<<endl;
			ll l=sum[u][1]*pl[1]/gcd(sum[u][1],pl[1]);
			sum[u][0]=(l/sum[u][1])*sum[u][0]+(l/pl[1])*pl[0];
			sum[u][1]=l;
			ll g=gcd(sum[u][0],sum[u][1]);
			sum[u][0]/=g;sum[u][1]/=g;
			//cout<<u<<" "<<sum[u][0]<<" "<<sum[u][1]<<endl;
			q.push(u);
		}
		sum[x][0]=0;sum[x][1]=1;
	}
	REP(i,out.size())
	{
		cout<<ans[out[i]][0]<<" "<<ans[out[i]][1]<<endl;
	}
	return 0;
}
//放平心态,保持冷静
//仔细读题,想好了再写
//注意long long和int
//注意清零
//算好时间和空间
//RP++

