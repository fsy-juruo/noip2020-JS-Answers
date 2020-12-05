#include<bits/stdc++.h>
#define Vector int
using namespace std;
int w[11];
int op[100100],dir[100100];
int mask(Vector v,int p)
{
	for(int i=0;i<p;i++)
		v/=w[i];
	return v%w[p];
}
int toVec(int x,int p)
{
	for(int i=0;i<p;i++)
		x*=w[i];
	return x;
}
long long ans;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	cin>>n>>k;
	Vector mx=1;
	for(int i=0;i<k;i++)
	{
		cin>>w[i];
		mx*=w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>op[i]>>dir[i];
		op[i]--;
	}
	for(Vector i=0;i<mx;i++)
	{
		Vector p=i;
		while(true)
		{
			bool ok=true;
			for(int j=0;j<n;j++)
			{
	//			for(int l=0;l<k;l++)
	//				cout<<mask(p,l)<<" ";
	//			puts("");
				if(dir[j]==-1)
				{
					if(mask(p,op[j])==0)
					{
						ok=false;
						break;
					}
					else
					{
						ans++;
						p+=toVec(dir[j],op[j]);
					}
				}
				else
				{
					if(mask(p,op[j])==w[op[j]]-1)
					{
						ok=false;
						break;
					}
					else
					{
						ans++;
						p+=toVec(dir[j],op[j]);
					}
				}
			}
//			puts("");
			if(!ok)
				break;
			if(p==i)
			{
				puts("-1");
				return 0;
			}
		}
	}
	cout<<ans+mx<<endl;
	return 0;
}
