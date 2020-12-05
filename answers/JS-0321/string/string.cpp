#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
long long dp[1005][1005];
bool can[1005][1005];
long long pre[1005][1005];
long long vis[1005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	n=read();
	while(n--)
		{
			memset(dp,0,sizeof(dp));
			memset(can,0,sizeof(can));
			memset(pre,0,sizeof(pre));
			memset(vis,0,sizeof(vis));
			string h;
			cin>>h;
			for(int i=0;i<h.size();i++)
				{
					for(int j='a';j<='z';j++) vis[j]=0;
					dp[i][i]=1;
					vis[h[i]]=1;
					for(int j=i+1;j<h.size();j++)
						{
							if(vis[h[j]]&1) dp[i][j]=dp[i][j-1]-1;
							else dp[i][j]=dp[i][j-1]+1;
							vis[h[j]]++;
						}
				}
			
				
			for(int i=0;i<h.size();i++)
				{
					can[i][i]=1;
					for(int j=i+1;j<h.size();j++)
						{
							if(h[j]==h[j%(i+1)])
								{
									if((j+1)%(i+1)==0) can[i][j]=1;
								}
							else break;
						}
				}
			
			long long ans=0;
			for(int j=0;j<h.size();j++)
				{
					pre[0][j]=can[0][j];
					for(int i=0;i<h.size();i++)
						{
							pre[i][j]=pre[i-1][j]+can[i][j];
						}
				}
//			for(int i=0;i<h.size();i++)
//			{
//				for(int j=0;j<h.size();j++)
//					{
//						cout<<dp[i][j]<<" ";
//					}
//				cout<<endl;
//			}
//			
//			for(int i=0;i<h.size();i++)
//			{
//				for(int j=0;j<h.size();j++)
//					{
//						cout<<pre[i][j]<<" ";
//					}
//				cout<<endl;
//			}
			
			for(int i=0;i<h.size();i++)
				{
					for(int j=i+2;j<h.size();j++)
						{
							if(dp[0][i]>dp[j][h.size()-1]) continue;
							ans+=pre[j-1][j-1]-pre[i][j-1];
//							cout<<i<<" "<<j<<" "<<ans<<endl;
//							system("pause");
						}
				}
			cout<<ans<<endl;
		}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
