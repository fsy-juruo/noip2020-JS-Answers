#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
vector <int> v;
int a[55][405];

void work(int h1,int x,int h2,int y)
{
	if (m-x>x-1&&m-y>=y-1)
	{
		for (int i=1;i<=m;i++)
		{
			v.push_back(h1);
			v.push_back(n+1);
			ans++;
		}
		for (int i=1;i<=m;i++)
		{
		//	cout<<h2<<" "<<h1<<endl;
			ans++;
			v.push_back(h2);
			v.push_back(h1);
		}
		int t=0;
		for (int i=1;i<x;i++)
		{
			v.push_back(n+1);
			v.push_back(h2);
	//		cout<<n+1<<" "<<h2<<endl;
			ans++;
		}
		for (int i=1;i<y;i++)
		{
			v.push_back(h1);
			v.push_back(h2);
			ans++;
			//cout<<h1<<" "<<h2<<endl;
		}
		ans+=3;
		v.push_back(n+1);
		v.push_back(h2);
		v.push_back(h1); 
		v.push_back(n+1);
		v.push_back(h2);
		v.push_back(h1);
//		cout<<n+1<<" "<<h2<<endl;
//		cout<<h1<<" "<<n+1<<endl;
//		cout<<h2<<" "<<h1<<endl;
		for (int i=1;i<y;i++)
		{
			ans++;
			v.push_back(h2);
			v.push_back(h1);
			//cout<<h2<<" "<<h1<<endl;
		}
		for (int i=1;i<x;i++)
		{
			v.push_back(h2);
			v.push_back(n+1);
			ans++;
	//		cout<<h2<<" "<<n+1<<endl;
		}
		for (int i=1;i<=m;i++)
		{
			v.push_back(h1);
			v.push_back(h2);
			ans++;
			//cout<<h1<<" "<<h2<<endl;
		}
		for (int i=1;i<=m;i++)
		{
			v.push_back(n+1);
			v.push_back(h1);
			ans++;
			//cout<<n+1<<" "<<h1<<endl;
		}
		swap(a[h1][x],a[h2][y]);
		return;
	}
	if (m-x>x-1)
	{
		for (int i=1;i<=m;i++)
		{
			v.push_back(h1);
			v.push_back(n+1);
			ans++;
		//	cout<<h1<<" "<<n+1<<endl;
		}
		for (int i=1;i<x;i++)
		{
			ans++;
			v.push_back(n+1);
			v.push_back(h1);
		//	cout<<n+1<<" "<<h1<<endl;
		}
		for (int i=m;i>y;i--)
		{
			v.push_back(h2);
			v.push_back(h1);
			ans++;
		//	cout<<h2<<" "<<h1<<endl;
		}
		ans+=3;
		v.push_back(h2);
		v.push_back(h1);
		v.push_back(n+1);
		v.push_back(h2);
		v.push_back(h1);
		v.push_back(n+1);
//		cout<<h2<<" "<<h1<<endl;
//		cout<<n+1<<" "<<h2<<endl;
//		cout<<h1<<" "<<n+1<<endl;
		for (int i=m;i>y;i--)
		{
			v.push_back(h1);
			v.push_back(h2);
			ans++;
		//	cout<<h1<<" "<<h2<<endl;
		}
		for (int i=1;i<x;i++)
		{
			v.push_back(h1);
			v.push_back(n+1);
			ans++;
		//	cout<<h1<<" "<<n+1<<endl;
		}
		for (int i=1;i<=m;i++)
		{
			v.push_back(n+1);
			v.push_back(h1);
			ans++;
		//	cout<<n+1<<" "<<h1<<endl;
		}
		swap(a[h1][x],a[h2][y]);
		return ;
	}
	if (m-y>y-1)
	{
		for (int i=1;i<=m;i++)
		{
			v.push_back(h2);
			v.push_back(n+1);
			ans++;
		//	cout<<h2<<" "<<n+1<<endl;
		}
		for (int i=m;i>x;i--)
		{
			v.push_back(h1);
			v.push_back(h2);
			ans++;
		//	cout<h1<<" "<<h2<<endl;
		}
		for (int i=1;i<y;i++)
		{
			v.push_back(n+1);
			v.push_back(h2);
			ans++;
		//	cout<<n+1<<" "<<h2<<endl;
		}
		ans+=3;
		v.push_back(h1);
		v.push_back(h2);
		v.push_back(n+1);
		v.push_back(h1);
		v.push_back(h2);
		v.push_back(n+1);
	//	cout<<h1<<" "<<h2<<endl;
	//	cout<<n+1<<" "<<h1<<endl;
	//	cout<<h2<<" "<<n+1<<endl;
		for (int i=1;i<y;i++)
		{
			v.push_back(h2);
			v.push_back(n+1);
			ans++;
		//	cout<<h2<<" "<<n+1<<endl;
		}
		for (int i=m;i>x;i--)
		{
			v.push_back(h2);
			v.push_back(h1);
			ans++;
//			cout<<h2<<" "<<h1<<endl;
		}
		for (int i=1;i<=m;i++)
		{
			v.push_back(n+1);
			v.push_back(h2);
			ans++;
		//	cout<<n+1<<" "<<h2<<endl;
		}
		swap(a[h1][x],a[h2][y]);
		return ;
	}
//	cout<<"!1"<<endl;
//	cout<<h1<<" "<<x<<" "<<h2<<" "<<y<<endl;
	for (int i=m;i>x;i--)
	{
		v.push_back(h1);
		v.push_back(n+1);
		ans++;
	//	cout<<h1<<" "<<n+1<<endl;
	}
	for (int i=m;i>y;i--)
	{
		v.push_back(h2);
		v.push_back(n+1);
		ans++;
	//	cout<<h2<<" "<<n+1;
	}
	ans+=3;
	v.push_back(h1);
	v.push_back(n+1);
	v.push_back(h2);
	v.push_back(h1);
	v.push_back(n+1);
	v.push_back(h2);
//	cout<<h1<<" "<<n+1<<endl;
//	cout<<h2<<" "<<h1<<endl;
//	cout<<n+1<<" "<<h2<<endl;
	for (int i=m;i>y;i--)
	{
	v.push_back(n+1);
		v.push_back(h2);
		
		ans++;
	}
	for (int i=m;i>x;i--)
	{
		v.push_back(n+1);		
		v.push_back(h1);
		
		ans++;
	}
	swap(a[h1][x],a[h2][y]);
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int l=1;l<=m;l++)
		{
			if (a[i][l]==i) continue;
			for (int j=1;j<=n;j++)
			{
				if (j==i) continue;
				for (int k=1;k<=m;k++)
				{
					if (a[j][k]==i) work(i,l,j,k);
				}
			}
		}
	}
	cout<<ans<<endl;
	for (int i=0;i<v.size();i++)
	{
		if (i%2==0) cout<<v[i]<<" ";
		else cout<<v[i]<<endl;
	}
	return 0;
}

