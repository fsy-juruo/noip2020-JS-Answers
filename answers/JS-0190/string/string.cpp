#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#define int long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template<typename T> void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template<typename T> void writeln(T x){
	write(x);
	puts("");
}
int n;
long long ans=0;
char s[1050005];
int mat[1050005],id[1050005];
int pre[1050005],suf[1050005];
int app[30];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int tc;
	read(tc);
	while(tc--)
	{
		cin>>s+1;
		n=strlen(s+1);
		for(register int i=1;i<=n;++i)
			mat[i]=id[i]=1;
		for(register int len=1;len<=n;++len)
		{
			int cur=0,mx=0;
			for(register int i=id[len];i<=n;i++)
			{
				if(s[i]==s[cur+1]) cur++;
				else break;
				if(cur==len)
				{
					mat[i]=len;
					mx=i;
					cur=0;
				}
			}
			for(register int i=len*2;i<=n;i+=len)
				id[i]=max(id[i],(mx/i)*i+1);
		}
		memset(app,0,sizeof(app));
		int odd=0;
		for(register int i=1;i<=n;++i)
		{
			app[s[i]-'a']++;
			if(app[s[i]-'a']%2==1) odd++;
			else odd--;
			pre[i]=odd;
		}
		memset(app,0,sizeof(app));
		odd=0;
		for(register int i=n;i>=1;--i)
		{
			app[s[i]-'a']++;
			if(app[s[i]-'a']%2==1) odd++;
			else odd--;
			suf[i]=odd;
		}
		set<pair<int,int> > st;
		st.insert(make_pair(pre[1],1));
		ans=0;
		for(register int i=2;i<=n;++i)
		{
			set<pair<int,int> >::iterator it=st.upper_bound(make_pair(suf[i]+1,0));
			vector<int> vec;
			for(register int j=mat[i-1];j<=i-1;j+=mat[i-1])
				if((i-1)%j==0)
					vec.push_back(j);
			for(register set<pair<int,int> >::iterator ite=st.begin();ite!=it;++ite)
				ans+=vec.end()-upper_bound(vec.begin(),vec.end(),(*ite).second);
			st.insert(make_pair(pre[i],i));
		}
		writeln(ans);
	}
	return 0;
}

