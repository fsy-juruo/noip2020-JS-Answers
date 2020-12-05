#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],c[100005],d[100005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	int maxs[155],mins[155],tdq[155]={0},movent=true;
	for(int i=1;i<=150;i++)maxs[i]=-99999999,mins[i]=99999999;
	for(int i=1;i<=n;i++)
	{
		tdq[c[i]]+=d[i];
		if(tdq[c[i]]>maxs[c[i]])maxs[c[i]]=tdq[c[i]];
		if(tdq[c[i]]<mins[c[i]])mins[c[i]]=tdq[c[i]];
	}
	for(int i=1;i<=k;i++)
	{
		if(tdq[i]!=0)movent=false;
		if(maxs[i]>=w[i]||mins[i]<=-w[i])movent=false;
	}
	if(movent){
		cout<<-1<<endl;
		return 0;
	}
	if(k==1)
	{
		int maxn=-99999999,minn=99999999,tdp=0;
		for(int i=1;i<=n;i++)
		{
			tdp+=d[i];
			if(tdp>maxn)maxn=tdp;
			if(tdp<minn)minn=tdp;
		}
		int tkj[100005];
		if(tdp>0)
		{
			for(int i=w[1];i>=1;i--)
			{
				if(i+maxn>w[1]||i+minn<1)
				{
					int kqy=i;
					for(int j=1;j<=n;j++)
					{
						kqy+=d[j];
						if(kqy>w[1]||kqy<1){
							tkj[i]=j;break;
						}
					}
				}
				else tkj[i]=tkj[i+tdp]+n;
			}
		}
		else
		{
			for(int i=1;i<=w[1];i++)
			{
				if(i+maxn>w[1]||i+minn<1)
				{
					int kqy=i;
					for(int j=1;j<=n;j++)
					{
						kqy+=d[j];
						if(kqy>w[1]||kqy<1){
							tkj[i]=j;break;
						}
					}
				}
				else tkj[i]=tkj[i+tdp]+n;
			}
		}
		int tot=0;
		for(int i=1;i<=w[1];i++)tot+=tkj[i];
		cout<<tot<<endl;
	}
	if(k==1)
	{
		int tot=0;
		for(int i=1;i<=w[1];i++)
			{
				int tx=i,turn=0,tuun=0;
				while(tx>=1&&tx<=w[1])
				{
					++turn;++tuun;
					if(turn==n+1)turn=1;
					if(c[turn]==1)tx+=d[turn];	
				}
				tot+=tuun;
			}
		cout<<tot<<endl;
	}
	else if(k==2)
	{
		int tot=0;
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			{
				int tx=i,ty=j,turn=0,tuun=0;
				while(tx>=1&&tx<=w[1]&&ty>=1&&ty<=w[2])
				{
					++turn;++tuun;
					if(turn==n+1)turn=1;
					if(c[turn]==1)tx+=d[turn];
					else ty+=d[turn];
					
				}
				tot+=tuun;
			}
		cout<<tot<<endl;
	}
	else if(k==3)
	{
		int tot=0;
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++)
			{
				int tx=i,ty=j,tz=k,turn=0,tuun=0;
				while(tx>=1&&tx<=w[1]&&ty>=1&&ty<=w[2]&&tz>=1&&tz<=w[3])
				{
					++turn;++tuun;
					if(turn==n+1)turn=1;
					if(c[turn]==1)tx+=d[turn];
					else if(c[turn]==2) ty+=d[turn];
					else if(c[turn]==3) tz+=d[turn];
				}
				tot+=tuun;
			}
		cout<<tot<<endl;
	}
	else if(k==4)
	{
		int tot=0;
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++)
				for(int l=1;l<=w[4];l++)
			{
				int tx=i,ty=j,tz=k,ta=l,turn=0,tuun=0;
				while(tx>=1&&tx<=w[1]&&ty>=1&&ty<=w[2]&&tz>=1&&tz<=w[3]&&ta>=1&&ta<=w[4])
				{
					++turn;++tuun;
					if(turn==n+1)turn=1;
					if(c[turn]==1)tx+=d[turn];
					else if(c[turn]==2) ty+=d[turn];
					else if(c[turn]==3) tz+=d[turn];
					else if(c[turn]==4) ta+=d[turn];
				}
				tot+=tuun;
			}
		cout<<tot<<endl;
	}
	else if(k==5)
	{
		int tot=0;
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++)
				for(int l=1;l<=w[4];l++)
				for(int o=1;o<=w[5];o++)
			{
				int tx=i,ty=j,tz=k,ta=l,tb=o,turn=0,tuun=0;
				while(tx>=1&&tx<=w[1]&&ty>=1&&ty<=w[2]&&tz>=1&&tz<=w[3]&&ta>=1&&ta<=w[4]&&tb>=1&&tb<=w[5])
				{
					++turn;++tuun;
					if(turn==n+1)turn=1;
					if(c[turn]==1)tx+=d[turn];
					else if(c[turn]==2) ty+=d[turn];
					else if(c[turn]==3) tz+=d[turn];
					else if(c[turn]==4) ta+=d[turn];
					else if(c[turn]==5) tb+=d[turn];
				}
				tot+=tuun;
			}
		cout<<tot<<endl;
	}
	else cout<<-1<<endl;
	return 0;
}
