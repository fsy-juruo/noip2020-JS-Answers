#include<bits/stdc++.h>
using namespace std;

int n,m;
int d[100010];

vector<int> v[100010];

int rd[100010];

queue<int> q,qq;

struct node
{
	int fm;
	int fz;
} liang[100010];

int GCD(int a,int b)
{
	return a%b==0?b:GCD(b,a%b);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		
		for(int j=1;j<=d[i];j++)
		{
			int y;
			cin>>y;
			
			v[i].push_back(y);
			
			rd[y]++;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		liang[i].fm=1;
		
		if (rd[i]==0)
		{
			liang[i].fz=1;
			
			q.push(i);
		}
		
		if (v[i].size()==0)
		{
			qq.push(i);
		}
	}
	
	while(!q.empty())
	{
		int h=q.front();
		q.pop();
		
		for(int i=0;i<v[h].size();i++)
		{
			int h_fm=liang[h].fm;
			int h_fz=liang[h].fz;
			
			int i_fm=liang[v[h][i]].fm;
			int i_fz=liang[v[h][i]].fz;
			
			h_fm*=d[h];
			
			int g_c_d=GCD(h_fm,i_fm);
			
			h_fm/=g_c_d;
			i_fm/=g_c_d;
			
			int ffm=h_fm*i_fm*g_c_d;
			int ffz=h_fz*i_fm+h_fm*i_fz;
			
			g_c_d=GCD(ffm,ffz);
			
			ffm/=g_c_d;
			ffz/=g_c_d;
			
			liang[v[h][i]].fm=ffm;
			liang[v[h][i]].fz=ffz;
			
			rd[v[h][i]]--;
			
			if (rd[v[h][i]]==0)
			{
				q.push(v[h][i]);
			}
		}
	}
	
	while(!qq.empty())
	{
		int l=qq.front();
		qq.pop();
		
		cout<<liang[l].fz<<" "<<liang[l].fm<<'\n';
	}
	
	return 0;
}
