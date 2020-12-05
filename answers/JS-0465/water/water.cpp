#include <bits/stdc++.h>
using namespace std;
long long ui[100010][7];
struct node{
	long long x,y;
};
node wat[10010];
deque <long long> de;
void add_f(long long uu,long long ii)
{
	node a=wat[ui[uu][ii]],b=wat[uu];
	long long c=ui[uu][0];
	b.y*=c;
	long long gu=(long long)__gcd(b.x,b.y);
	b.x=b.x/gu;	
	b.y=b.y/gu;
	if(a.x==0&&a.y==0)
	{
		a.x=b.x;
		a.y=b.y;
		wat[ui[uu][ii]]=a;		
		return ;
	}
	gu=b.y*a.y/(long long)__gcd(b.y,a.y);
	b.x=b.x*(gu/b.y);a.x=a.x*(gu/a.y);
	b.y=gu;a.y=gu;
	a.x+=b.x;
	gu=__gcd(a.x,a.y);
	a.x=a.x/gu;	
	a.y=a.y/gu;
	wat[ui[uu][ii]]=a;
	return;
}
deque<long long> chu;
bool vis[100010];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	de.clear();
	long long n,m;
	int d;
	cin>>n>>m;
	for(long long i=1;i<=m;i++)
	{
		wat[i].x=1;wat[i].y=1;
		de.push_back(i);
		vis[i]=1;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>d;
		ui[i][0]=(long long)d;
		for(int j=1;j<=d;j++)cin>>ui[i][j];
		if(d==0)chu.push_back(i);
	}
	while(!de.empty())
	{
		long long yu=de.front();
		de.pop_front();
		for(long long i=1;i<=ui[yu][0];i++)
		{			
		//	cout<<ui[yu][i]<<":"<<setw(5)<<wat[ui[yu][i]].x<<" "<<wat[ui[yu][i]].y;
			add_f(yu,i);
		//	cout<<ui[yu][i]<<":"<<setw(5)<<wat[ui[yu][i]].x<<" "<<wat[ui[yu][i]].y<<endl;
			if(vis[ui[yu][i]]==0)
			{
				de.push_back(ui[yu][i]);
			//	cout<<"Push:"<<ui[yu][i]<<endl;
				vis[ui[yu][i]]=1;
			}			
		}
	}
	for(long long i=0;i<chu.size();i++)cout<<wat[chu[i]].x<<" "<<wat[chu[i]].y<<endl;
	return 0;
}
