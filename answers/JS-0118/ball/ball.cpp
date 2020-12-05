#include<bits/stdc++.h>
using namespace std;
void read(int &x);
const int MAXN=19260817;
struct f__k{
	int b[1007],idx,topc,topg;
}a[57];
int n,m;
int topall[1007],topmaxx,topmaxn;
bool coco[1007],cofk[1007];int comnum;
int main()
{
	f__k ccf;
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//freopen("ball.in","r",stdin);
	//freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(a[i].b[j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i].b[j]==a[i].topc)a[i].topg++;
			else a[i].topg=1,a[i].topc=a[i].b[j];
	for(int i=1;i<=n;i++)
	{
		topall[a[i].topc]+=a[i].topg;
		if(topall[a[i].topc]>topmaxx)
		{
			topmaxn=topall[a[i].topc];
			topmaxx=a[i].topc;
		}
	}
	for(int i=1;i<=MAXN;i++)
		cout<<"±¬Áã"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

