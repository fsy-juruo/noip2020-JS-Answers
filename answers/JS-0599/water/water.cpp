#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
vector<int> son[100000+5];
ll fa[100000+5];
queue<int> q;
int mm[10+5];
ll bc[100000+5], c[100000+5];
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y,count=1;
	for(int i=1;i<=m;++i){
		//bc[i]=1; c[i]=1;
		scanf("%d",&x);//cin>>x;
		for(int j=1;j<=x;++j)
		{	//cin>>y;
			scanf("%d",&y); son[i].push_back(y); fa[y]++;
		}
		q.push(i);
	}
	
	for(int i=m+1;i<=n;++i){
		//bc[i]=0; c[i]=0;
		scanf("%d",&x);//cin>>x;
		if(x==0) mm[count++]=i;
		for(int j=1;j<=x;++j)
		{
			//cin>>y;
			scanf("%d",&y); son[i].push_back(y); fa[y]++;
			
		}
	}
	for(int i=1;i<=m;++i)bc[i]=1,c[i]=1;
//	cout<<bc[1];
//	cout<<bc[1000];
	while(!q.empty())
	{
		//cout<<nmp++<<endl;
		x=q.front(); q.pop();
		if(son[x].size()!=0)
		{
			c[x]=c[x]*son[x].size();
			for(int i=0;i<son[x].size();++i)
			{	int erzi=son[x][i];
													//cout<<erzi<<" "<<bc[erzi]<<" "<<c[erzi]<<endl;
				if(bc[erzi]==0||c[erzi]==0)bc[erzi]=bc[x],c[erzi]=c[x];
				else   bc[erzi]=bc[x]*c[erzi]+bc[erzi]*c[x],c[erzi]=c[erzi]*c[x];
				//		if(bc[erzi]>c[erzi]){
				//		cout<<x<<" "<<bc[x]<<" "<<c[x]<<" "<<erzi<<" "<<bc[erzi]<<" "<<c[erzi]<<endl;return 0;}
				ll gys=gcd(bc[erzi],c[erzi]);
				bc[erzi]=bc[erzi]/gys; c[erzi]=c[erzi]/gys;	
				fa[erzi]--;
				if(fa[erzi]<=0)q.push(erzi);
			}
		}
	}											
											//	return 0;
	for(int j=1;j<count;++j)
	{
		int i=mm[j];
		ll gys=gcd(bc[i],c[i]);
		//cout<<gys;
		cout<<bc[i]/gys<<" "<<c[i]/gys<<endl;
	}
	return 0;
	//for(int i=1;i<=n;++i)
	//{
	//	if(a[i].size()!=0){
	//		c[i]=c[i]*a[i]
	//	}
	//}
	
	
}
