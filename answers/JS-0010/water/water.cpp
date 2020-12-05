#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005][6],v[100005]={0},w[100005][2],d[100005],b[15],c[100005];


int tofe (int aa,int bb,int cc,int dd,int xx,int ii)
{
	int e;
	aa*=dd;
	cc*=bb;
	cc+=aa;
    bb=dd*bb;
    dd=bb;
   
    for(int i=2;i<=min(cc,dd);i++)
	{
		if((cc%i==0)&&(dd%i==0))
		{
			dd=dd/i;
			cc=cc/i;
		}
	}
	
    w[a[xx][ii]][0]=cc;
	w[a[xx][ii]][1]=dd;
	
}

int check(int x)
{
	for(int i=1;i<=d[x];i++)
	{
		tofe(w[x][0],w[x][1]*d[x],w[a[x][i]][0],w[a[x][i]][1],x,i);
		//cout<<x<<" "<<a[x][i]<<" "<<w[a[x][i]][0]<<" "<<w[a[x][i]][1]<<endl;
	}
	if(d[x]!=0)
	{
		w[x][0]=0;
	    w[x][1]=1;
	}
	for(int i=1;i<=d[x];i++)
	{
		check(a[x][i]);
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int k=0,l=0;
	for(int i=0;i<=100004;i++)
	{
		 w[i][0]=0;
		 w[i][1]=1;
	}  
	
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		for(int j=1;j<=d[i];j++)
		{
			cin>>a[i][j];
			v[a[i][j]]=1;
		}
		if(d[i]==0)
		{
			k++;
			c[k]=i;        //chu kou
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			l++;
			b[l]=i;          //ru kou
			w[i][0]=1;
			w[i][1]=1;
		}
	}
	for(int i=1;i<=l;i++)
	{
		check(b[i]);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=2;j<=min(w[c[i]][0],w[c[i]][1]);j++)
	    {
			if((w[c[i]][0]%j==0)&&(w[c[i]][1]%j==0))
			{
				w[c[i]][1]/=j;
				w[c[i]][0]/=j;
			}
		}	
		cout<<w[c[i]][0]<<" "<<w[c[i]][1]<<endl;
	}
	return 0;
}
