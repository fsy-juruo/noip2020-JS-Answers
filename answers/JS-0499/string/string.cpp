#include<bits/stdc++.h>
using namespace std;
struct ins{
	template<typename T>void read(T &n)
	{
		n=0;char c=getchar();bool f=1;
		while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(isdigit(c)){n=n*10+c-'0';c=getchar();}
		if(f==0)n=-n;
	}
	template<typename T>ins operator >>(T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
map<char,int> c;
const int maxn=1<<21;
char s[maxn];
int sum[maxn];
int x[30];
int n;
const int ba=103;
const int ba1=137;
const int mod=1e9+7;
long long p[maxn];
unsigned int p1[maxn];
long long h[maxn];
unsigned int h1[maxn];
int v[maxn];
int check(int l,int r,int l1,int r1)
{
//	cout<<(h[r]-h[l]*p[r-l]%mod+mod)%mod<<" "<<(h[r1]-h[l1]*p[r1-l1]%mod+mod)%mod<<endl;
	return ((h[r]-h[l]*p[r-l]%mod+mod)%mod==(h[r1]-h[l1]*p[r1-l1]%mod+mod)%mod)&&((h1[r]-h1[l]*p1[r-l])==(h1[r1]-h1[l1]*p1[r1-l1]));
}
int main()
{
	int TTT;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	yin>>TTT;
	while(TTT--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		c.clear();
		memset(v,0,sizeof(v));
		for(int i=0;i<=26;i++)x[i]=0;
		for(int i=n;i>=1;i--)
		{
			c[s[i]]++;
			if(c[s[i]]&1)++ans;
			else --ans;
			sum[i]=ans;
		}
		c.clear();
		p[0]=1;p1[0]=1;
		h[0]=ba;
		for(int i=1;i<=n;i++)
		{
			p[i]=p[i-1]*ba%mod;
			p1[i]=p1[i-1]*ba1;
			h[i]=h[i-1]*ba%mod+s[i]-'a';
			if(h[i]>=mod)h[i]-=mod;
			h1[i]=h1[i-1]*ba1+s[i]-'a';
		}
		long long ssum=0;
//		cout<<check(0,3,3,6)<<endl;
		ans=0;
		for(int i=1;i<n;i++)
		{
//			puts("!");
			if(!v[i]&&i!=1)
			{
				int ans=(n-1)/i;
				for(int j=1;j<=(n-1)/i;j++)
				{
					if(!check(0,i,i*j,i*(j+1)))
					{
						ans=j;
						break;
					}
				}
				for(int j=0;j<=sum[i*ans+1];j++)
					ssum+=(long long)((ans+1)/2)*x[j];
				for(int j=0;j<=sum[i*(ans-1)+1];j++)
					ssum+=(long long)((ans)/2)*x[j];
				
			}
			c[s[i]]++;
			if(c[s[i]]&1)++ans;
			else --ans;
			x[ans]++;
		}
		cout<<ssum<<endl;
	}
	return 0;
}

