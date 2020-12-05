#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &num)
{
	num=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		num=num*10+c-48;
		c=getchar();
	}
	num*=f;
}
const int maxn = 407;
int n,m,bal[maxn][maxn],col[maxn][maxn],ans,ans1[1000007],ans2[1000007],cnt[maxn];
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(col[i][j]);
	cnt[1]=m;
	cnt[2]=m;
	int mo=1;
	while(col[1][mo]==col[1][1])
	{
		++mo;
	}
	--mo;
	int go=m-mo;
	for(int i=1;i<=go;++i)
		ans1[++ans]=1,ans2[ans]=3,++cnt[3];
	while(go--)
	{
		int e=0;
		while(col[2][cnt[2]]!=col[1][1])
		{
			--cnt[2];
			++e;
			ans1[++ans]=2;
			ans2[ans]=3;
			++cnt[3];
		}
		ans1[++ans]=2;
		ans2[ans]=1;
		for(int i=1;i<=e;++i)
		{
			ans1[++ans]=3;
			ans2[ans]=2;
			col[2][++cnt[2]]=col[3][cnt[3]--];
		}
	}
	while(cnt[3])
	{
		ans1[++ans]=3;
		ans2[ans]=2;
		--cnt[3];
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;++i)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	/*for(int i=1;i<=n;++i)
	{
		int di = col[i][1],ct=1;
		while(col[i][ct]==di)
			++ct;
		--ct;
//		for(int e=1;e<=ct;++e)
//			ans1[++ans]=i,ans2[ans]
		while(ct--)
		{
			int mn=0x7fffffff,id=0;
			for(int t=i+1;t<=n;++t)
			{
				int nct=0;
				for(int q=cnt[t];q>=1;--q)
				{
					if(col[t][q]==di)
						break;
					++nct;
				}
				if(nct<mn)
					mn=nct,id=t;
			}
			for(int e=1;e<=nct;++e)
				ans1[++ans]=id,ans2[ans]=n+1;
			ans1[++ans]=
		}
	}*/
	return 0;
}
