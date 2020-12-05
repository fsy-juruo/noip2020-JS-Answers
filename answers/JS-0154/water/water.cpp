#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
queue <int> q;
const int INF=0x3f3f3f3f,maxn=1e5+10; 
struct node
{
	long long I_have_up,I_have_down;
	vector<int>nxt;
}jd[maxn];
vector <int> v,an;
int n,m,wtout[maxn],wts,coi[maxn],dw[maxn];
int yf(long long x,long long y)
{
	while(y!=0)
	{
		long long  t=y;
		y=x%y;
		x=t;			
	}	
	return x;
}
void pluss(int x,int y,int xs)
{
	long long x1=jd[x].I_have_up,y1=jd[x].I_have_down;
	long long x2=jd[y].I_have_up,y2=jd[y].I_have_down;
	y1*=xs;
	long long ff=yf(x1,y1);
//cout<<ff<<endl;
	x1/=ff;
	y1/=ff;//cout<<y1<<endl;
	long long x3,y3;
	if(y2==0)
		y2=1;
	x3=x2*y1+x1*y2;
	//unsigned long long ls=2305843009213693952;
	
	y3=y1*y2;
	ff=yf(x3,y3);	
	x3/=ff;
	y3/=ff;
	jd[y].I_have_up=x3;
	jd[y].I_have_down=y3;
}
void topo()
{
	int o=0;
	while(1)
	{
		if(o==n)
			break;
		int x;
		for(int i=1;i<=n;i++)
		{
			if(coi[i]==0)
			{
				coi[i]=-1;
				o++;
				v.push_back(i);
				x=i;
				break;
			}
		}
	//	cout<<x<<endl;
		for(int i=0;i<jd[x].nxt.size();i++)
		{
			coi[jd[x].nxt[i]]--;	
			int xxs=jd[x].nxt.size();
			pluss(x,jd[x].nxt[i],xxs);	
		}

	}
}
int main()
{
	freopen ("water.in","r",stdin);
	freopen ("water.out","w",stdout);
	int i,j,k,ans=0,sum=0,cnt=0;	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==0)
		{
			wtout[++wts]=i;
			continue;
		}
		for(j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			jd[i].nxt.push_back(y);
			coi[y]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(coi[i]==0)
		{
			jd[i].I_have_up=1;
			jd[i].I_have_down=1;	
			//cout<<i<<endl;
		}
	}
	topo();
	for(i=1;i<=wts;i++)
	{
		cout<<jd[wtout[i]].I_have_up<<" "<<jd[wtout[i]].I_have_down<<endl;
	}
	return 0;
}
