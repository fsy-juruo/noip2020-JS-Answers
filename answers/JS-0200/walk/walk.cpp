#include <bits/stdc++.h>
using namespace std;
int ans,n,k,e[15],cc[15],pce2[15],pce3[15];
struct{
	int p;
	int n;
}s[100005];
void check1()
{
	for(int i=1;i<=k;i++)
	{
		if(cc[i])
		return ;
	}
	cout<<-1<<endl;
	exit(0);
}
bool check2()
{
	for(int i=1;i<=k;i++)
	{
		if(pce3[i]<1||pce3[i]>e[i])
		return 0;
	}
	return 1;
}
void getans()
{
	int i=0;
	for(int i=1;i<=k;i++)
	pce3[i]=pce2[i];
	while(check2())
	{
		ans=(ans+1)%1000000007;
		if(i==n)
		i=0;
		pce3[s[i].p]+=s[i].n;
		i++;
	}
//	cout<<ans<<endl;
}
void getintocircle(int pce)
{
	if(pce==k+1)
	getans();
	else
	{
		for(int i=1;i<=e[pce];i++)
		{
			pce2[pce]=i;
//			cout<<pce2[pce]<<" ";
			getintocircle(pce+1);
		}
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	cin>>e[i];
	for(int i=0;i<n;i++)
	{
		cin>>s[i].p;
		cin>>s[i].n;
		cc[s[i].p]+=s[i].n;
	}
	check1();
	getintocircle(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
