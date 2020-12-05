#include<bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=b;i>=a;i--)
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define MAXN (1<<20)+10
bool cmpq[MAXN][30],cmph[MAXN][30];
int sumq[MAXN],sumh[MAXN],dp[MAXN][30],p[MAXN];
bool check(int a,string s)
{
	forn(i,a,s.size()-1)
	{
		if(s[i]!=s[i-a])
		{
			return 0;
		}
	}
	return 1;
}
inline int solve(string s)
{
	int res=0;
	forn(i,2,s.size()-1)
	{
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(check(j,s.substr(0,i)))
			    {
			    	//cout<<sumh[i+1]<<endl;
			    	res+=dp[j-1][sumh[i+1]];
				}
				if(check(i/j,s.substr(0,i)))
			    {
			        res+=dp[i/j-1][sumh[i+1]];
				}
			}
		}
		res+=dp[i-1][sumh[i+1]];
		//cout<<res<<endl;
	}
	return res;
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	string s,c;
    	cin>>s;
    	ll ans=0;
        memset(cmpq,0,sizeof(cmpq));
        memset(cmph,0,sizeof(cmpq));
        memset(sumq,0,sizeof(cmpq));
        memset(sumh,0,sizeof(cmpq));
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
    	forn(i,1,s.size())
    	{
    		rep(j,26)
    		{
    			//k[i-1]+=cmp[i-1][j];
    			sumq[i-1]+=cmpq[i-1][j];
    			cmpq[i][j]=cmpq[i-1][j];
			}
			cmpq[i][s[i-1]-'a']=!cmpq[i][s[i-1]-'a'];
		}
		rep(j,26)
	    {
	    	sumq[s.size()]+=cmpq[s.size()][j];
		}
    	ford(i,1,s.size())
    	{
    		rep(j,26)
    		{
    			//k[i-1]+=cmp[i-1][j];
    			sumh[i+1]+=cmph[i+1][j];
    			cmph[i][j]=cmph[i+1][j];
			}
			cmph[i][s[i-1]-'a']=!cmph[i][s[i-1]-'a'];
		}
		rep(j,26)
		{
			sumh[1]+=cmph[1][j];
		}
		/*forn(i,1,s.size())
		{
			cout<<sumh[i]<<" ";
		}
		cout<<endl;
		*/
		forn(i,1,s.size())
		{
			forn(j,0,26)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=sumq[i])
				{
					dp[i][j]++;
				}
			}
		}
		ans=solve(s);
		cout<<ans<<endl;
	}
	return 0;
}

