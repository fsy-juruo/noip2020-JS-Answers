#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const long long MOD=(long long)(1e9+7);
int n,k,w[15],c[maxn],d[maxn];
vector<int> v;
long long dfs(int x)
{
	if(x==k+1)
	{
		vector<int> ww=v;
		int op=1;
		long long cnt=0LL;
		while(1)
		{
			v[c[op]]+=d[op];
			cnt++;
			if(cnt>MOD)
			{
				cnt-=MOD;
			}
			if(v[c[op]]<1||v[c[op]]>w[c[op]])
			{
				break;
			}
			if(op==n)
			{
				if(ww==v)
				{
					cout<<-1<<endl;
					exit(0);
				}
				op=1;
			}
			else
			{
				op++;
			}
		}
		v=ww;
		return cnt;
	}
	long long sum=0LL;
	for(int i=1;i<=w[x];i++)
	{
		v.push_back(i);
		sum+=dfs(x+1);
		sum%=MOD;
		v.pop_back();
	}
	return sum;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	int mxw=0;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
		mxw=max(mxw,w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
	}
	v.clear();
	v.push_back(0);
	cout<<dfs(1)<<endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
/*
check array size
check initilize
check int and long long
check freopen
*/
