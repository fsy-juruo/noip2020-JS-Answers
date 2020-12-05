#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,ans;
int n,k,w[11],c[500001],d[500001];
int f1(int x)
{
	int a=0,k=1;
	
	for(int i=1;i<=n;i++)
	{
		a+=d[i];	
		if (x+a>w[1] || x+a<=0)
			ans=1;	
	}
	if (a==0 && ans!=1)
		ans=-1;
	else	
		while(x<=w[1] && x>0)
		{
			x+=d[k];		
			t++;	
			k++;
			if (k>n)
				k=k-n;	
		}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(register int i=1;i<=k;++i)
		scanf("%d",&w[i]);
	for(register int i=1;i<=n;++i)
		scanf("%d%d",&c[i],&d[i]);
	if (k==1)
	{
		for(register int i=1;i<=w[1];++i)
		{
			ans=0;
			f1(i);	
			if (ans==-1)
				break;				
		}	
		if (ans==-1)
			cout<<ans<<endl;
		else 
			cout<<t<<endl;	
	}
	else
		cout<<"-1"<<endl;
	return 0;
}

