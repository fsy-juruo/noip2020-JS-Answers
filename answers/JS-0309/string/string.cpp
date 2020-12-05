#include<bits/stdc++.h>
#define N 1049005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
/* int 够不够，要不要long long?
	数组开得够不够？
	*/ 
using namespace std;
template<typename T>
inline void in(T &x)
{
	x=0;
	char c=getchar();
	bool fu=0;
	while(c<'0'||c>'9'){if(c=='-')fu=1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x=fu?-x:x;
}
template<typename T>
inline T Abs(T x){return x<0?-x:x;}
template<typename T>
inline void chmax(T &x,T y){x=x>y?x:y;}
template<typename T>
inline void chmin(T &x,T y){x=x<y?x:y;}
int n,LtoR[N],RtoL[N],bit[30],z[N+N];
bool cnt[30];
char s[N];
char t[N+N];
void calc_z(int m,char S[],int Z[])
{
	Z[0]=m;
	int l=0,r=0;
	for(int i=1;i<m;++i)
	{
		if(i>r)l=r=i;
		Z[i]=min(r-i,Z[i-l]);
		while(S[Z[i]]==S[Z[i]+i])++Z[i];
		if(i+Z[i]>r)l=i,r=i+Z[i];
	}
}
void add(int i,int val)
{
	++i;
	while(i<=27)bit[i]+=val,i+=i&-i;
}
int sum(int i)
{
	++i;
	int ret=0;
	while(i)ret+=bit[i],i-=i&-i;
	return ret;
}
namespace brute
{
	void work()
	{
		ll ans=0;
		for(int i=1;i<n;++i)
		{
			add(LtoR[i-1],1);
			for(int j=0;j<=i;++j)t[j]=s[j];
			t[i+1]='#';
			for(int j=0;j<n;++j)
			t[i+j+2]=s[j];
			calc_z(i+n+2,t,z);
//			puts(t);
//			for(int j=0;j<i+n+2;++j)cout<<z[j]<<' ';
//			cout<<endl;
			int x=0;
			while(i+x+1<n&&z[i+x+2]==i+1)
			{
//				cout<<"i+x+1:"<<i+x+1<<endl;
				ans+=sum(RtoL[x+i+1]);
				x+=i+1;
			}
		}
		printf("%lld\n",ans);
	}
}
void work()
{
	scanf("%s",s);
	n=strlen(s);
	memset(bit,0,sizeof(bit));
	memset(cnt,0,sizeof(cnt));
	LtoR[0]=cnt[s[0]-'a']=1;
	for(int i=1;i<n;++i)
	{
		if(cnt[s[i]-'a']==0)LtoR[i]=LtoR[i-1]+1,cnt[s[i]-'a']=1;
		else LtoR[i]=LtoR[i-1]-1,cnt[s[i]-'a']=0;
	}
	memset(cnt,0,sizeof(cnt));
	RtoL[n-1]=cnt[s[n-1]-'a']=1;
	for(int i=n-2;i>=0;--i)
	{
		if(cnt[s[i]-'a']==0)RtoL[i]=RtoL[i+1]+1,cnt[s[i]-'a']=1;
		else RtoL[i]=RtoL[i+1]-1,cnt[s[i]-'a']=0;
	}
//	for(int i=0;i<n;++i)cout<<LtoR[i]<<' ';
//	cout<<endl;
//	for(int i=0;i<n;++i)cout<<RtoL[i]<<' ';
//	cout<<endl;
		brute::work();
		return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	in(T);
	while(T--)work();
}
