#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
string s; 
long long ans=0;
const int INF=0x3f3f3f3f,maxn=1048576+10;
int pre[maxn][30],ro[maxn],vis[maxn],n,m,db[maxn][2]; 
void make_ro()
{
	int cnt=1;
	for(int i=1;i<=n/2;i++)
	{	//cout<<ro[i]<<endl;
		if(ro[i]!=1)
			continue;
		cnt=1;
		for(int j=1;j<=n-i;j++)
		{
			int k=j+i;
			if(s[j]!=s[k])
				break;				
			if(k%i==0)
				cnt++;
		}
		ro[i]=cnt;
		for(int j=1;j<=cnt;j++)
			if(cnt%j==0)
				ro[i*j]=cnt/j;
		//for(int j=1;j<=n;j++)
			//cout<<ro[j]<<" ";
			//	cout<<"\n";
	}
}
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int i,j,k,sum=0,cnt=0;	
	cin>>m;
	for(int ls=1;ls<=m;ls++)
	{
		int fll=1;
		cin>>s;
		n=s.size();		
		for(i=0;i<n-1;i++)
			if(s[i]!=s[i+1])
			{
				fll=0;
				break;
			}
		s="0"+s;
		ans=0;		
		for(i=0;i<=n;i++)
		{
			ro[i]=1,vis[i]=0;	
			for(j=0;j<='z'-'a';j++)
				pre[i][j]=0;		
		}

		if(fll=0)
		{
			for(i=2;i<=n;i++)
			{
				db[i][1]=i-1;
				db[i][0]=(i-1)/2;
			}
			for(i=2;i<=n;i++)
			{
				for(j=1;j*i<n;j++)
				{
					ans+=db[i][(n-i*j)%2];
				}
			}
		}
		else
		{

		for(j=1;j<=n;j++)
		{
			pre[j][s[j]-'a']++;
			
			for(k=0;k<='z'-'a';k++)
				pre[j][k]=pre[j-1][k]+pre[j][k];
			//cout<<pre[j][s[j]-'a']<<' ';
		}
		//cout<<n<<endl;
		make_ro();
		//for(i=1;i<=n;i++)
		//	cout<<ro[i]<<" ";
	//	cout<<"\n";
		for(i=2;i<=n;i++)
		{	
			for(j=1;j<=ro[i];j++)
			{
				int x=i*j;
				if(vis[x]==1 || x==n)
					continue;
				for(k=1;k<i;k++)
				{
					int x1=0,x2=0;
					for(int d=0;d<='z'-'a';d++)
					{
						x1+=(pre[k][d]-pre[0][d])%2;
						x2+=(pre[n][d]-pre[x][d])%2;
					}
					if(x1<=x2 )
					{
						ans++;	
						//cout<<' '<<' '<<k<<' '<<i<<" "<<x<<" "<<x1<<" "<<x2<<endl;					
					}
		
				}
			}
			
		}	
		}

		cout<<ans<<endl;
	} 

	return 0;
}
