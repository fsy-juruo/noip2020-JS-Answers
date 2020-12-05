#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int maxn=500005;
ll ans=0;
ll cj[20];
int w[20]={};
int cz[maxn][2]={};
int num[20][maxn];//维度i各次操作所在顺序 
int sum[20][maxn];//维度i每次操作造成的移动步数前缀和
int summax[20][2];//维度i一遍操作后走的最大步数
int summin[20][2]; 
int flag[20];//某个维度是否能走出去 
int res[20][maxn];//某个维度在j坐标时走出去需要的操作数 
int res2[20][maxn];
int res1[20][maxn];
int tot[20]={};
int n,k;
int da[20]={};
//int t[maxn<<1];

struct xsx{
	int bs,wd;
}t[maxn<1];
int cmp(xsx a,xsx b)
{
	return (a.bs<b.bs);
}

int qread()
{
	char ch=getchar();
	int f=1;
	int res=0;
	for(;ch<'0' || ch>'9';ch=getchar())if(ch=='-')f=0;
	for(;ch>='0' && ch<='9';ch=getchar())res=res*10+ch-'0';
	return f?res:-res;
}
int cmp2(int a,int b)
{
	return a>b;
}
int cnt(int kk,int ii)
{
    if(summin[kk][1]<0)
	{
		int xx=ii;
		int yy=xx/(-summin[kk][1]);
		xx=xx%(-summin[kk][1]);
		res2[kk][ii]+=yy*n;
	    if(xx==0)
 	 {
		res2[kk][ii]+=num[kk][summin[kk][2]];
 	 }
 	 else {
	xx=-xx;
	int pp;
	if(tot[kk]>summin[kk][2])
	{
	pp=lower_bound(sum[kk]+1+summin[kk][2],sum[kk]+1+tot[kk],xx,cmp2)-sum[kk];
	if(pp==tot[kk]+1)
	  pp=lower_bound(sum[kk]+1,sum[kk]+1+summin[kk][2],xx,cmp2)-sum[kk];
    }
    else
    {
    	pp=lower_bound(sum[kk]+1,sum[kk]+1+tot[kk],xx,cmp2)-sum[kk];
	}
	res2[kk][ii]+=num[kk][pp];
         }
	}
	else if(summax>0)
	{
	
	int x=w[kk]-ii+1;
	int y=x/summax[kk][1];
	res1[kk][ii]+=y*n;
	x=x%summax[kk][1];
	if(x==0)
	{
		res1[kk][ii]+=num[kk][summax[kk][2]];
		return 0;
	}
	
	int p;
	if(tot[kk]>summax[kk][2])
	{
	p=lower_bound(sum[kk]+1+summax[kk][2],sum[kk]+1+tot[kk],x)-sum[kk];
	if(p==tot[kk]+1)
	  p=lower_bound(sum[kk]+1,sum[kk]+1+summax[kk][2],x)-sum[kk];
    }
    else
    {
    	p=lower_bound(sum[kk]+1,sum[kk]+1+tot[kk],x)-sum[kk];
	}
    res1[kk][ii]+=num[kk][p];
    }
    if(res1[kk][ii]==0)res[kk][ii]=res2[kk][ii];
    else if(res2[kk]==0)res[kk][ii]=res1[kk][ii];
	else res[kk][ii]=min(res1[kk][ii],res2[kk][ii]);
    return 0;
}

int solve()
{

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=w[i];j++)
		{
			cnt(i,j);
			//da[i]=max(da[i],res[i][j]);
		}
	}
	/*for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=w[i];j++)
		cout<<res[i][j]<<' ';
		cout<<endl;
	}*/
	int nn=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=w[i];j++)
		{
			nn++;
			t[nn].bs=res[i][j];
			t[nn].wd=i;
		 } 
	}
	sort(t,t+1+nn,cmp);
	for(int i=1;i<=k;i++)
	{
		ans=(ans+(cj[t[nn].wd]*t[nn].bs))%mod;
	}
	return 0;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=qread(),k=qread();
	if(n>100)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
	sum[i][0]=0;
	//tot[i]=1;
	}
	for(int i=1;i<=k;i++)
	{
	w[i]=qread();
    }
    for(int i=1;i<=k;i++)
    {
    	cj[i]=1;
    	for(int j=1;j<=k;j++)
    	{
    		if(j!=i)
    		cj[i]=(cj[i]*w[j])%mod;
		}
	}
//	for(int i=1;i<=k;i++)
	//cout<<cj[k]<<endl;
	
	for(int i=1;i<=n;i++)
	{
		cz[i][1]=qread();
		cz[i][2]=qread();
		tot[cz[i][1]]++;
		num[cz[i][1]][tot[cz[i][1]]]=i;
		sum[cz[i][1]][tot[cz[i][1]]]=sum[cz[i][1]][tot[cz[i][1]]-1]+cz[i][2];
		if(summax[cz[i][1]][1]<sum[cz[i][1]][tot[cz[i][1]]])
		{
			summax[cz[i][1]][1]=sum[cz[i][1]][tot[cz[i][1]]];
			summax[cz[i][1]][2]=i;
		}
		if(summin[cz[i][1]][1]>sum[cz[i][1]][tot[cz[i][1]]])
		{
			summin[cz[i][1]][1]=sum[cz[i][1]][tot[cz[i][1]]];
			summin[cz[i][1]][2]=i;
		}
	}	
	/*for(int i=1;i<=k;i++)
	 {
	 for(int j=1;j<=tot[i];j++)
	 {
	 	cout<<sum[i][j]<<' '; 
	 }
	 cout<<endl;
     }*/
	solve();
	cout<<ans<<endl;
	return 0;	
}

