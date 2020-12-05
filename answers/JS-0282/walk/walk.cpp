#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int w[15];
int c[MAXN],d[MAXN];
int n,k;
struct num
{
	int a[15];
};
bool out(num pos)
{
	bool flag=false;
	for(int i=1;i<=k;i++)
	{
		if(pos.a[i]>=1&&pos.a[i]<=w[i])
			continue;
		flag=true;
		break;
	}
	return flag;
}
void kequal2()
{
	int cnt=0;
	bool flag=false;
	for(int x=1;x<=w[1];x++)
	{
		for(int y=1;y<=w[2];y++)
		{
			flag=false;
			num pos;
			pos.a[1]=x,pos.a[2]=y;
			while(1)
			{
				for(int i=1;i<=n;i++)
				{
					pos.a[c[i]]+=d[i];
					cnt++;
					if(out(pos))
					{
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
			
		}
	}
	cout<<cnt<<endl;
}
void kequal1()
{
	int cnt=0;
	for(int x=1;x<=w[1];x++)
	{
		bool flag=false;
		num pos;
		pos.a[1]=x;
		while(1)
		{
			for(int i=1;i<=n;i++)
			{
				pos.a[c[i]]+=d[i];
				cnt++;
				if(out(pos))
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	cout<<cnt<<endl;
}
void kequal3()
{
	int cnt=0;
	for(int x=1;x<=w[1];x++)
	for(int y=1;y<=w[2];y++)
	for(int z=1;z<=w[3];z++)
	{
		bool flag=false;
		num pos;
		pos.a[1]=x;
		pos.a[2]=y;
		pos.a[3]=z;
		while(1)
		{
			for(int i=1;i<=n;i++)
			{
				pos.a[c[i]]+=d[i];
				cnt++;
				if(out(pos))
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	cout<<cnt<<endl;
}
void kequal4()
{
	int cnt=0;
	for(int x=1;x<=w[1];x++)
	for(int y=1;y<=w[2];y++)
	for(int z=1;z<=w[3];z++)
	for(int t=1;t<=w[4];t++)
	{
		bool flag=false;
		num pos;
		pos.a[1]=x;
		pos.a[2]=y;
		pos.a[3]=z;
		pos.a[4]=t;
		while(1)
		{
			for(int i=1;i<=n;i++)
			{
				pos.a[c[i]]+=d[i];
				cnt++;
				if(out(pos))
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	cout<<cnt<<endl;
}
void kequal5()
{
	int cnt=0;
	for(int x=1;x<=w[1];x++)
	for(int y=1;y<=w[2];y++)
	for(int z=1;z<=w[3];z++)
	for(int t=1;t<=w[4];t++)
	for(int h=1;h<=w[5];h++)
	{
		bool flag=false;
		num pos;
		pos.a[1]=x;
		pos.a[2]=y;
		pos.a[3]=z;
		pos.a[4]=t;
		pos.a[5]=h;
		while(1)
		{
			for(int i=1;i<=n;i++)
			{
				pos.a[c[i]]+=d[i];
				cnt++;
				if(out(pos))
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	cout<<cnt<<endl;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	if(k==1)
		kequal1();
	if(k==2)
		kequal2();
	if(k==3)
		kequal3();
	if(k==4)
		kequal4();
	if(k==5)
		kequal5();
	return 0;
}
