#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
#define int long long
typedef long long ll;

int n,cnt_in,d[100001],is_out[100001],l[100001][10],cnt_out=0,outi[100001],ini[13],anszi[100001],ansmu[100001];

ll fz(int a,int b,int c,int d)// a/b+c/d
{
	if (a==0)
	{
		return c;
	}
	if (c==0)
	{
		return a;
	}
	ll fenzi,fenmu;
	fenzi=a*d+b*c;
	fenmu=b*d;
	rep(i,2,(min(fenzi,fenmu)))
	{
		while (fenzi%i==0 && fenmu%i==0)
		{
			fenzi/=i;
			fenmu/=i;
		}
	}
	return fenzi;
}

ll fm(int a,int b,int c,int d)// a/b+c/d
{
	if (a==0)
	{
		return d;
	}
	if (c==0)
	{
		return b;
	}
	ll fenzi,fenmu;
	fenzi=a*d+b*c;
	fenmu=b*d;
	rep(i,2,(min(fenzi,fenmu)))
	{
		while (fenzi%i==0 && fenmu%i==0)
		{
			fenzi/=i;
			fenmu/=i;
		}
	}
	return fenmu;
}

int dfs(int x)
{
	/*
	rep(i,1,n)
	{
		cout<<anszi[i]<<" ";
	}
	cout<<endl;
	rep(i,1,n)
	{
		cout<<ansmu[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	*/
	rep(i,1,d[x])
	{
		//cout<<anszi[outi[1]]<<" "<<ansmu[outi[1]]<<" ";
		//cout<<anszi[outi[2]]<<" "<<ansmu[outi[2]]<<endl;
		
		ll t1,t2,t3=d[x]*ansmu[x];
		if (is_out[l[x][i]]==false)
		{
			t1=t3;
			t2=anszi[x];
			ansmu[l[x][i]]=t1;
			anszi[l[x][i]]=t2;
		}
		else
		{
			t1=fm(anszi[l[x][i]],ansmu[l[x][i]],anszi[x],t3);
			t2=fz(anszi[l[x][i]],ansmu[l[x][i]],anszi[x],t3);
			ansmu[l[x][i]]=t1;
			anszi[l[x][i]]=t2;
		}
		dfs(l[x][i]);
	}
	if (is_out[x]==false)
	{
		ansmu[x]=0;
		anszi[x]=0;
	}
}

signed main()
{
	//ios::sync_with_stdio(false);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>cnt_in;
	bool is_in[100001];
	rep(i,1,n)
	{
		is_in[i]=true;
		is_out[i]=false;
		anszi[i]=0;
		ansmu[i]=0;
	}
	rep(i,1,n)
	{
		cin>>d[i];
		if (d[i]==0)
		{
			cnt_out++;
			outi[cnt_out]=i;
		}
		else
		{
			rep(j,1,d[i])
			{
				cin>>l[i][j];
				is_in[l[i][j]]=false;
			}
		}
	}
	int s=0;
	rep(i,1,n)
	{
		if (is_in[i]==true)
		{
			++s;
			ini[s]=i;
		}
	}
	rep(i,1,cnt_out)
	{
		is_out[outi[i]]=true;
	}
	//进水口数cnt_in,ini[m+1]，出水口数cnt_out,outi[] 
	rep(i,1,cnt_in)
	{
		anszi[ini[i]]=1;
		ansmu[ini[i]]=cnt_in;
		dfs(i);
	}
	rep(i,1,cnt_out)
	{
		cout<<anszi[outi[i]]<<" "<<ansmu[outi[i]]<<endl;
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
