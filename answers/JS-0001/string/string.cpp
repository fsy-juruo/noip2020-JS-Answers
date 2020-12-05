#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t,cnt;
string s;
bool use[30];

int o[50005],jo[50005];
void yueshu(int n)
{
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j*i<=n;j++)
		{
			//m[j*i].push_back(i);
			jo[j*i]+=i-1;
			if(i>=3) o[j*i]+=i%2==1?(i-1)/2:i/2-1;
		}
	}
}
ull ans=0;

vector <int> m[50005];
void yueshu2(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*i<=n;j++)
		{
			m[j*i].push_back(i);
			//jo[j*i]+=i-1;
			//if(i>=3) o[j*i]+=i%2==1?(i-1)/2:i/2-1;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	yueshu(33000);
	yueshu2(1000);
	while(t--)
	{
		ans=0;
		cin>>s;
		cnt=0;
		memset(use,0,sizeof(use));
		int l=s.size();
		if(l<3)
		{
			printf("0\n");
			continue;
		}
		for(int i=0;i<l;i++) 
		{
			if(!use[s[i]-'a'+1])
			{
				use[s[i]-'a'+1]=1,cnt++;
			}
		}
		//cout<<cnt<<' '<<l;
		if(cnt==1)
		{
			for(int i=1;i<=l-2;i++)
			{
				ull x=0;
				int y=l-i;
				if(i%2==1)
				{
					x+=y-1;
					x+=jo[y];
					/*for(int j=0;j<m[y].size();j++)
					{
						if(m[y][j]>=2) x+=m[y][j]-1;
					}*/
				}
				else
				{
					x+=y/2-1;
					x+=o[y];
					/*for(int j=0;j<m[y].size();j++)
					{
						if(m[y][j]>=3) x+=m[y][j]%2==1?(m[y][j]-1)/2:m[y][j]/2-1;
					}*/
				}
				//cout<<y<<' '<<x<<endl;
				ans+=x;
			}
			printf("%llu\n",ans);
			continue;
		}
		else if(l<=1000)
		{
			/*for(int i=1;i<=100;i++)
			{
				for(int j=0;j<m[i].size();j++) cout<<m[i][j]<<' ';
				cout<<endl;
			}*/
			for(int i=1;i<=l-2;i++)
			{
				ull x=0;
				int y=l-i;
				int fc=0,vis1[30];
				memset(vis1,0,sizeof(vis1));
				for(int j=l-1;j>=l-i;j--) vis1[s[j]-'a'+1]++;
				for(int j=0;j<=27;j++) if(vis1[j]%2==1) fc++;
				for(int k=1;k<y;k++)
				{
					int fa=0;
					int vis2[30];
					memset(vis2,0,sizeof(vis2));
				    for(int j=0;j<k;j++) vis2[s[j]-'a'+1]++;
				    for(int j=0;j<=27;j++) if(vis2[j]%2==1) fa++;
				    if(fa>fc) continue;
				    //x++;
				    //if(m[y].size()){
					for(int j=0;j<m[y].size();j++)
				    {
				    	if(m[y][j]>k)
				    	{
				    		//cout<<endl<<m[y][j]<<' '<<k<<endl<<endl;
				    	    bool f=1;
							int st=m[y][j],k0=0;
							while(st<y)
							{
								if(k0==k)
								{
									k0=0;st++;
								 } 
								//cout<<k0<<' '<<st<<endl;
								if(s[k0]!=s[st])
								{
									f=0;break;
								}
								k0++;st++;
								//cout<<m[i][j]<<endl;
								
							}
							//cout<<f<<endl;
							x+=f;
						}
					}//}
				}
				//cout<<i<<' '<<x<<endl;
				ans+=x;
				//cout<<i<<' '<<fc<<' '<<fa<<endl;
				
				//x++;
			}
			printf("%llu\n",ans);
			continue;
		}
    }
	return 0;
}
