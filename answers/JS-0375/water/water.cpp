#include<bits/stdc++.h>
using namespace std;
const int N=100005;
bool out1[N],flag;
long long n,m,d[N],Z1,a[N][2],temp,temp0,temp1;
vector<long long> p1[N],p2[N];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(out1,false,sizeof(out1));
	memset(a,0,sizeof(a));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		if(d[i]==0)
			out1[i]=true;
		for(int Z=1;Z<=d[i];Z++)
		{
			scanf("%lld",&Z1);
			p1[i].push_back(Z1);
			p2[Z1].push_back(i);
		}
		a[i][1]=1;
	}
	for(int i=1;i<=n;i++)
		if(p2[i].size()==0)
			a[i][0]=a[i][1]=1;
	while(1)
	{
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]!=0&&!out1[i])
			{
				flag=false;
				for(int j=0;j<p1[i].size();j++)
				{
					temp0=a[i][0],temp1=a[i][1]*p1[i].size();
					a[p1[i][j]][0]=a[p1[i][j]][0]*temp1+temp0*a[p1[i][j]][1];
					a[p1[i][j]][1]*=temp1;
					temp=__gcd(a[p1[i][j]][0],a[p1[i][j]][1]);
					a[p1[i][j]][0]/=temp,a[p1[i][j]][1]/=temp;
				}
				a[i][0]=0,a[i][1]=1;
			}
		}
		if(flag)
			break;
	}
	for(int i=1;i<=n;i++)
		if(out1[i])
			printf("%lld %lld\n",a[i][0],a[i][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
