#include <bits/stdc++.h>
#define re register
#define SIZE 1000005
#define LL long long
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
int T;
string s;
int Len;
int lef[SIZE],rig[SIZE];
int num[35],lodd[SIZE],rodd[SIZE];
int N;
LL ans=0;
queue<int> rou,MAX;
inline int round(int k)
{
	int v;
	for(re int t=2;t*k<=Len;++t)
	{
		int l=(t-1)*k+1,r=t*k;
		for(re int i=l;i<=r;++i)
			if(s[i]!=s[(i-1)%k+1])
				return t-1;
		v=t;
	}
	return v;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>s;
		Len=s.size();
		s=" "+s;
		int l=1;
		ans=0;
		for(re int r=2;r<(Len-1)/2+1;++r)
		{
			if(s[r+1]!=s[l])
				continue;
			int k=r-l+1;
			int p=round(k);
			if(p>1)
				rou.push(k),MAX.push(p);
		}
		memset(num,0,sizeof(num));
		for(re int i=1;i<=Len;++i)
		{
			++num[s[i]-'a'];
			if(num[s[i]-'a']%2==1)
				lodd[i]=lodd[i-1]+1;
			else
				lodd[i]=lodd[i-1]-1;
		}
		memset(num,0,sizeof(num));
		for(re int i=Len;i>=1;--i)
		{
			++num[s[i]-'a'];
			if(num[s[i]-'a']%2==1)
				rodd[i]=rodd[i+1]+1;
			else
				rodd[i]=rodd[i+1]-1;
		}
		for(re int i=1;i<Len;++i)
			for(re int j=Len;j>i+1;--j)
				if(lodd[i]<=rodd[j])
					++ans;
		else
		{
			while(!rou.empty())
			{
				int ro=rou.front(),Max=MAX.front();
				rou.pop();MAX.pop();
				for(re int i=1;i<ro;++i)//A
					for(re int j=2;j<=Max;++j)
						if(lodd[i]<=rodd[ro*j+1])
							++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
