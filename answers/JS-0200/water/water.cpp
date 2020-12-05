#include <bits/stdc++.h>
using namespace std;
long long a,b,num[100005],need[100005],uw[100005],dw[100005],c,d,e,f,u,g,cnt[100005];
queue<long long>q;
vector<long long>v[100005];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&c);
		num[i]=c;
		for(int j=0;j<c;j++)
		{
			scanf("%d",&e);
			v[i].push_back(e);
			need[e]++;
		}
		dw[i]=1;
	}
	for(int i=1;i<=b;i++)
	{
		uw[i]=1;
		q.push(i);
	}
	while(!q.empty())
	{
		f=q.front();
		u=uw[f];
		d=dw[f]*num[f];
		g=__gcd(u,d);
		u/=g;
		d/=g;
//		cout<<f<<endl;
		for(int i=0;i<v[f].size();i++)
		{
			uw[v[f][i]]=uw[v[f][i]]*d+u*dw[v[f][i]];
			dw[v[f][i]]*=d;
			g=__gcd(uw[v[f][i]],dw[v[f][i]]);
			uw[v[f][i]]/=g;
			dw[v[f][i]]/=g;
			cnt[v[f][i]]++;
			if(cnt[v[f][i]]==need[v[f][i]])
			{
				q.push(v[f][i]);
			}
			uw[f]=0;
		}
		q.pop();
	}
	for(int i=1;i<=a;i++)
	{
		if(uw[i]!=0)
		cout<<uw[i]<<" "<<dw[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
