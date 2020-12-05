#include<bits/stdc++.h>
using namespace std;
int n,i,k,p[500005],q[500005],ans=0,u,e;
	long long w[12],o[12],m[12];
int main ()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=k;++i)
	{
		cin>>w[i];
		m[i]=w[i];
	}
	for(i=1;i<=n;++i)
	{
		cin>>p[i]>>q[i];
	}
	while(1)
	{
		u=0;
		int jk;
		for(i=1;i<=k;++i)
		{
			if(m[i]!=1)u++;
		}
		if(u==0) jk=1;
		for(i=1;i<=k;++i)
		{
			o[i]=m[i];
		}
		int t;
		for( e=1;e<=10000;++e)
		{
			int j=0;
			for(i=1;i<=n;++i)
			{
				o[p[i]]+=q[i];
				if(o[p[i]]<1||o[p[i]]>w[p[i]])
				{
						t=1;
						break;
				}
			}
			j+=i;
			if(t==1)
			{
				//cout<<"("<<m[1]<<","<<m[2]<<")"<<' '<<i<<endl;
				ans+=j;
				break;
			}
		}
		if(e==10000)
		{
			cout<<-1;
			return 0;
		}
		m[1]--;
		for(i=1;i<=11;i++)
		if(m[i]==0)
		{
			m[i]=w[i];
			m[i+1]--;
		}
		if(jk==1)break;
	}
	cout<<ans;
	return 0;
}
