#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,k;
int w[7];
int c[10010],d[10010];
int mx[7],mn[7];
int mv[7],nw[7];//move,now
long long ans=0;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	for(int i=0;i<7;i++)
	{
		mx[i]=0;
		mn[i]=0;
		mv[i]=0;
	}
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=0;i<n;i++)cin>>c[i]>>d[i];
	if(n<=5&&k>3)//15pts
	{
		if(k==4)
		{
			for(int i=0;i<n;i++)
			{
				mv[c[i]]+=d[i];
				if(mv[c[i]]>mx[c[i]])
				{
					mx[c[i]]=mv[c[i]];
				}
				if(mv[c[i]]<mn[c[i]])
				{
					mn[c[i]]=mv[c[i]];
				}
			}
			bool f=0;
			for(int i=1;i<=k;i++)if(mv[i]!=0)f=1;
			if(f==0)
			{
				for(int i=1;i<=k;i++)
				{
					if(mx[i]>=w[i]||mn[i]<=-w[i])break;
					else if(i==k)
					{
						cout<<-1<<endl;
						return 0;
					}
				}
			}	
			for(int i=0;i<w[1];i++)
			{
				for(int j=0;j<w[2];j++)
				{
					for(int kk=0;kk<w[3];kk++)
					{
						for(int l=0;l<w[4];l++)
						{
							nw[1]=i;
							nw[2]=j;
							nw[3]=kk;
							nw[4]=l;
							while(nw[1]+mx[1]<w[1]&&nw[1]+mn[1]>=0&&nw[2]+mx[2]<w[2]&&nw[2]+mn[2]>=0&&nw[3]+mx[3]<w[3]&&nw[3]+mn[3]>=0&&nw[4]+mx[4]<w[4]&&nw[4]+mn[4]>=0)
							{
								ans+=n;
								ans%=mod;
								for(int m=1;m<=k;m++)
									nw[m]+=mv[m];
							}
							bool ff=0;
							for(int o=-1;o<n;o++)
							{
								if(ff)break;
								if(o>=0)nw[c[o]]+=d[o];
								for(int m=1;m<=k;m++)
								{
									if(nw[m]<0||nw[m]>=w[m])
									{
										ans+=o;
										ans++;
										ans%=mod;
										ff=1;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
		if(k==5)
		{
			for(int i=0;i<n;i++)
			{
				mv[c[i]]+=d[i];
				if(mv[c[i]]>mx[c[i]])
				{
					mx[c[i]]=mv[c[i]];
				}
				if(mv[c[i]]<mn[c[i]])
				{
					mn[c[i]]=mv[c[i]];
				}
			}
			bool f=0;
			for(int i=1;i<=k;i++)if(mv[i]!=0)f=1;
			if(f==0)
			{
				for(int i=1;i<=k;i++)
				{
					if(mx[i]>=w[i]||mn[i]<=-w[i])break;
					else if(i==k)
					{
						cout<<-1<<endl;
						return 0;
					}
				}
			}	
			for(int i=0;i<w[1];i++)
			{
				for(int j=0;j<w[2];j++)
				{
					for(int kk=0;kk<w[3];kk++)
					{
						for(int l=0;l<w[4];l++)
						{
							for(int r=0;r<w[5];r++)
							{
								nw[1]=i;
								nw[2]=j;
								nw[3]=kk;
								nw[4]=l;
								nw[5]=r;
								while(nw[1]+mx[1]<w[1]&&nw[1]+mn[1]>=0&&nw[2]+mx[2]<w[2]&&nw[2]+mn[2]>=0&&nw[3]+mx[3]<w[3]&&nw[3]+mn[3]>=0&&nw[4]+mx[4]<w[4]&&nw[4]+mn[4]>=0&&nw[5]+mx[5]<w[5]&&nw[5]+mn[5]>=0)
								{
									ans+=n;
									ans%=mod;
									for(int m=1;m<=k;m++)
										nw[m]+=mv[m];
								}
								bool ff=0;
								for(int o=-1;o<n;o++)
								{
									if(ff)break;
									if(o>=0)nw[c[o]]+=d[o];
									for(int m=1;m<=k;m++)
									{
										if(nw[m]<0||nw[m]>=w[m])
										{
											ans+=o;
											ans++;
											ans%=mod;
											ff=1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n<=100&&k>=2)//15pts
	{
		if(k==2)
		{
			for(int i=0;i<n;i++)
			{
				mv[c[i]]+=d[i];
				if(mv[c[i]]>mx[c[i]])
				{
					mx[c[i]]=mv[c[i]];
				}
				if(mv[c[i]]<mn[c[i]])
				{
					mn[c[i]]=mv[c[i]];
				}
			}
			bool f=0;
			for(int i=1;i<=k;i++)if(mv[i]!=0)f=1;
			if(f==0)
			{
				for(int i=1;i<=k;i++)
				{
					if(mx[i]>=w[i]||mn[i]<=-w[i])break;
					else if(i==k)
					{
						cout<<-1<<endl;
						return 0;
					}
				}
			}	
			for(int i=0;i<w[1];i++)
			{
				for(int j=0;j<w[2];j++)
				{
					nw[1]=i;
					nw[2]=j;
					while(nw[1]+mx[1]<w[1]&&nw[1]+mn[1]>=0&&nw[2]+mx[2]<w[2]&&nw[2]+mn[2]>=0)
					{
						ans+=n;
						ans%=mod;
						for(int m=1;m<=k;m++)
							nw[m]+=mv[m];
					}
					bool ff=0;
					for(int o=-1;o<n;o++)
					{
						if(ff)break;
						if(o>=0)nw[c[o]]+=d[o];
						for(int m=1;m<=k;m++)
						{
							if(nw[m]<0||nw[m]>=w[m])
							{
								ans+=o;
								ans++;
								ans%=mod;
								ff=1;
								break;
							}
						}
					}
				}
			}
		}
		if(k==3)
		{
			for(int i=0;i<n;i++)
			{
				mv[c[i]]+=d[i];
				if(mv[c[i]]>mx[c[i]])
				{
					mx[c[i]]=mv[c[i]];
				}
				if(mv[c[i]]<mn[c[i]])
				{
					mn[c[i]]=mv[c[i]];
				}
			}
			bool f=0;
			for(int i=1;i<=k;i++)if(mv[i]!=0)f=1;
			if(f==0)
			{
				for(int i=1;i<=k;i++)
				{
					if(mx[i]>=w[i]||mn[i]<=-w[i])break;
					else if(i==k)
					{
						cout<<-1<<endl;
						return 0;
					}
				}
			}	
			for(int i=0;i<w[1];i++)
			{
				for(int j=0;j<w[2];j++)
				{
					for(int kk=0;kk<w[3];kk++)
					{
						nw[1]=i;
						nw[2]=j;
						nw[3]=kk;
						while(nw[1]+mx[1]<w[1]&&nw[1]+mn[1]>=0&&nw[2]+mx[2]<w[2]&&nw[2]+mn[2]>=0&&nw[3]+mx[3]<w[3]&&nw[3]+mn[3]>=0)
						{
							ans+=n;
							ans%=mod;
							for(int m=1;m<=k;m++)
								nw[m]+=mv[m];
						}
						bool ff=0;
						for(int o=-1;o<n;o++)
						{
							if(ff)break;
							if(o>=0)nw[c[o]]+=d[o];
							for(int m=1;m<=k;m++)
							{
								if(nw[m]<0||nw[m]>=w[m])
								{
									ans+=o;
									ans++;
									ans%=mod;
									ff=1;
									break;
								}
							}
						}
					}
				}
			}
			
		}
	}
	else if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			mv[1]+=d[i];
			if(mv[1]>mx[1])
			{
				mx[1]=mv[1];
			}
			if(mv[1]<mn[1])
			{
				mn[1]=mv[1];
			}
		}
		if(mv[1]==0)
		{
			if(mx[1]<w[1]&&mn[1]>-w[1])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		for(int i=0;i<w[1];i++)
		{
			nw[1]=i;
			while(nw[1]+mx[1]<w[1]&&nw[1]+mn[i]>=0)
			{
				ans+=n;
				ans%=mod;
				nw[1]+=mv[1]; 
			}
			for(int j=-1;j<n;j++)
			{
				if(j>=0)nw[1]+=d[j];
				if(nw[1]<0||nw[1]>=w[i])
				{
					ans+=j;
					ans++;
					ans%=mod;
					break;
				}
			}
		}
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
//[0,w[i])
