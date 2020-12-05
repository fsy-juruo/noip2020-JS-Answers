#include <bits/stdc++.h>
#define re register
#define SIZE 55
#define LL long long
#define INF 0x3f3f3f3f
#define mp make_pair
#define F first
#define S second
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int n,m;
int bal[SIZE][405],cnt[SIZE];
int maxd;
int ok[SIZE];
pair<int,int> ans[820005];
inline bool isok()
{
	if(cnt[n+1])
		return false;
	for(re int i=1;i<=n;++i)
	{
		if(cnt[i]!=m)
			return false;
		for(re int j=2;j<=m;++j)
			if(bal[i][j]!=bal[i][j-1])
				return false;
	}
	return true;
}
inline int gj1()
{
	int val=0;
	for(re int i=1;i<=n;++i)
		val+=abs(cnt[i]-m);
	return val/2;
}
inline int gj2()
{
	int val=0;
	for(re int i=1;i<=n;++i)
		for(re int j=2;j<=cnt[i];++j)
			if(bal[i][j]!=bal[i][j-1])
				++val;
	return val;
}
inline bool dfs(int d)
{
	if(d+gj1()>maxd)
		return false;
	if(d+gj2()>maxd)
		return false;
	//if(d+gj3()>maxd)
	//	return false;
	if(d<=maxd && isok())
		return true;
	for(re int i=1;i<=n+1;++i)
	{
		if(!cnt[i])
			continue;
		for(re int j=1;j<=n+1;++j)
		{
			if(cnt[j]==m)
				continue;
			if(i==ans[d-1].S && j==ans[d-1].F)
				continue;
			++cnt[j];
			bal[j][cnt[j]]=bal[i][cnt[i]];
			--cnt[i];
			ans[d]=mp(i,j);
			if(dfs(d+1))
				return true;
			++cnt[i];
			bal[i][cnt[i]]=bal[j][cnt[j]];
			--cnt[j];
		}
	}
	return false;
}
inline void Print()
{
	printf("%d\n",maxd-1);
	for(re int i=1;i<=maxd-1;++i)
		printf("%d %d\n",ans[i].F,ans[i].S);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(re int i=1;i<=n;++i)
		cnt[i]=m;
	for(re int i=1;i<=n;++i)
		for(re int j=1,x;j<=m;++j)
			read(x),bal[i][j]=x;
	for(maxd=1;;++maxd)
	{
		//cout<<"*"<<maxd<<endl;
		if(dfs(1))
		{
			Print();
			break;
		}
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
