#include<bits/stdc++.h>
using namespace std;
int Loc[20],w[20];
bool vis2[20][20][20][110],vis3[5][5][5][5][5][110],vis4[11][11][11][11][110];
bool vis5[20][20][110];
int c[100100],d[100100];
const int Mod=1e9+7;
bool check(int x)
{
	for(int i=1;i<=x;++i)
	{
		if(Loc[i]<1||Loc[i]>w[i])return false;
	}
	return true;
}
int main()
{
	freoepn("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i]>>d[i];
	}
	if(k==3)
	{
		int ans=0;
		int id=1;
		for(int i=1;i<=w[1];++i)
		{
			for(int j=1;j<=w[2];++j)
			{
				for(int p=1;p<=w[3];++p)
				{
					Loc[1]=i,Loc[2]=j,Loc[3]=p;
					id=1;
					memset(vis2,0,sizeof(vis2));
					while(1)
					{
						Loc[c[id]]+=d[id];
						
						if(vis2[Loc[1]][Loc[2]][Loc[3]][id])
						{
							cout<<-1<<endl;
							return 0;
						}
						vis2[Loc[1]][Loc[2]][Loc[3]][id]=1;
						id++,ans++;
						if(id>n)id=1;
						if(!check(k))break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	else if(k==2)
	{

		int ans=0;
		int id=1;
		for(int i=1;i<=w[1];++i)
		{
			for(int j=1;j<=w[2];++j)
			{
					memset(vis5,0,sizeof(vis5));
					id=1;
					Loc[1]=i,Loc[2]=j;
					while(1)
					{
						Loc[c[id]]+=d[id];
						
						int t=d[id];
						if(t==-1)t=0;
						if(vis5[Loc[1]][Loc[2]][id])
						{
							cout<<-1<<endl;
							return 0;
						}
						vis5[Loc[1]][Loc[2]][id]=1;
						id++,ans++;
						if(id>n)id=1;
						if(!check(k))break;
					}
			}
		}
		cout<<ans<<endl;
	}
	else if(k==4)
	{
		int ans=0;
		int id=1;
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
				for(int i3=1;i3<=w[3];++i3)
					for(int i4=1;i4<=w[4];++i4)
						{
							memset(vis4,0,sizeof(vis4));
							id=1;
							Loc[1]=i1,Loc[2]=i2,Loc[3]=i3,Loc[4]=i4;
							while(1)
							{
								Loc[c[id]]+=d[id];
								if(vis4[Loc[1]][Loc[2]][Loc[3]][Loc[4]][id])
								{
									cout<<-1<<endl;
									return 0;
								}
								vis4[Loc[1]][Loc[2]][Loc[3]][Loc[4]][id]=1;
								id++,ans++;
								if(id>n)id=1;
								if(!check(k))break;
							}
						}
			
		cout<<ans<<endl;
	}
	else if(k==5)
	{
		int ans=0;
		int id=1;
		for(int i1=1;i1<=w[1];++i1)
			for(int i2=1;i2<=w[2];++i2)
				for(int i3=1;i3<=w[3];++i3)
					for(int i4=1;i4<=w[4];++i4)
						for(int i5=1;i5<=w[5];++i5)	
						{
							memset(vis3,0,sizeof(vis3));
							Loc[1]=i1,Loc[2]=i2,Loc[3]=i3,Loc[4]=i4,Loc[5]=i5;
							id=1;
							while(1)
							{
								Loc[c[id]]+=d[id];
								
								int t=d[id];
								if(t==-1)t=0;
								if(vis3[Loc[1]][Loc[2]][Loc[3]][Loc[4]][Loc[5]][id])
								{
									cout<<-1<<endl;
									return 0;
								}
								vis3[Loc[1]][Loc[2]][Loc[3]][Loc[4]][Loc[5]][id]=1;
								id++,ans++;
								if(id>n)id=1;
								if(!check(k))break;
							}
						}
			
		cout<<ans<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}


