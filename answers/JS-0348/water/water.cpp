#include <bits/stdc++.h>
using namespace std;
long long GCD(long long x,long long y)
{
	if (!y) return x;
	else return GCD(y,x%y);
}
pair<long long,long long> d[100010][2],ed[100010];
vector<int> v[100010];
int n,m;
bool isend[100010];
int tr=0;
pair<long long,long long> MerGe(pair<long long,long long> x,pair<long long,long long> y)
{
	long long ali=GCD(x.second,y.second);
	long long al=(x.second/ali)*y.second;
	//cout <<"Merge ==================\n";
	//cout <<x.first<<" "<<x.second<<" ##\n";
	//cout <<y.first<<" "<<y.second<<" ##\n";
	//cout <<al<<" ##\n";
	x.first*=al/x.second,y.first*=al/y.second;
	pair<long long,long long> pr=make_pair(x.first+y.first,al);
	long long t=GCD(pr.first,pr.second);
	pr.first/=t,pr.second/=t;
	return pr;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int siz;
		scanf("%d",&siz);
		if (!siz) isend[i]=1,ed[i]=make_pair(0,1);
		for (int j=0;j<siz;j++)
		{
			int x;
			scanf("%d",&x);
			x--;
			v[i].push_back(x);
		}
	}
	for (int i=0;i<n;i++) d[i][0]=d[i][1]=make_pair(0,1);
	for (int i=0;i<m;i++) d[i][tr]=make_pair(1,1);
	for (int tim=0;tim<13;tim++)
	{
		//cout <<tim<<" #########\n";
		for (int i=0;i<n;i++) d[i][tr^1]=make_pair(0,1);
		for (int i=0;i<n;i++)
		{
			if (!d[i][tr].first) continue;
			int siz=v[i].size();
			if (!siz)
			{
				//cout <<i<<" "<<siz<<" ##000\n";
				ed[i]=MerGe(ed[i],d[i][tr]);
				//cout <<i<<" "<<siz<<" ##000\n";
				continue;
			}
			//cout <<i<<" "<<siz<<" ##\n";
			pair<long long,long long> ad=d[i][tr];
			ad.second*=siz;
			for (int j=0;j<v[i].size();j++)
			{
				int x=v[i][j];
				d[x][tr^1]=MerGe(d[x][tr^1],ad);
			}
		}
		tr^=1;
	}
	for (int i=0;i<n;i++) if (!v[i].size()) printf("%lld %lld\n",ed[i].first,ed[i].second);
	return 0;
}
