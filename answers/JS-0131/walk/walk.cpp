#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,w[11],c[500010],d[500010],fro[11][500010],beh[11][500010],end[11];
ll mod=1e9+7,flag,maxn[11],minn[11],ans,sum,tot,x[11];
ll read(){
	ll cnt=0,b=1;
	char asd;
	asd=getchar();
	while(asd<'0'||asd>'9')
	{
		if(asd=='-')b=-1;
		asd=getchar();
	}
	while(asd<='9'&&asd>='0')
	{
		cnt=cnt*10+asd-'0';
		asd=getchar();
	}
	return b*cnt;
}
void deal(ll x[])
{
	tot=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		if((w[i]-x[i]+1>maxn[i])&&(x[i]+minn[i]>0))
		{
			if(end[i]>0)tot=min(tot,(w[i]-x[i]-maxn[i])/end[i]+1);
			if(end[i]<0)tot=min(tot,(x[i]+minn[i]-1)/(-end[i])+1);
		}
		else {
			tot=0;
			break;
		}
	}
	for(int i=1;i<=k;i++)
	{
		x[i]+=tot*end[i];
//		cout<<x[i]<<' ';
	}
//	cout<<endl;
	tot=(tot*n)%mod;
	for(int i=1;i<=k;i++)
	{
		
		if(fro[i][w[i]-x[i]+1]!=0)ans=min(ans,fro[i][w[i]-x[i]+1]);
		if(beh[i][x[i]]!=0)ans=min(ans,beh[i][x[i]]);
	}
	ans=(ans+tot)%mod;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	w[i]=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		d[i]=read();
		end[c[i]]+=d[i];
		maxn[c[i]]=max(maxn[c[i]],end[c[i]]);
		minn[c[i]]=min(minn[c[i]],end[c[i]]);
		if(end[c[i]]>0&&fro[c[i]][end[c[i]]]==0)
		fro[c[i]][end[c[i]]]=i;
		if(end[c[i]]<0&&beh[c[i]][-end[c[i]]]==0)
		beh[c[i]][(-end[c[i]])]=i;
	}
	for(int i=1;i<=k;i++)if(end[i]!=0)flag=1;
	if(!flag){
		for(int i=1;i<=k;i++)
		{
			if(maxn[i]<w[i]){
				cout<<-1;
				return 0;
			}
			if((-minn[i])<w[i]){
				cout<<-1;
				return 0;
			}
		}
	}
	if(k==1)
	for(int i1=1;i1<=w[1];i1++)
	{
		x[1]=i1;
		ans=INT_MAX;
		deal(x);
		sum=(sum+ans)%mod;
	}
	
	if(k==2)
	for(int i1=1;i1<=w[1];i1++)
	for(int i2=1;i2<=w[2];i2++)
	{
		x[1]=i1;
		x[2]=i2;
		ans=INT_MAX;
		deal(x);
		sum=(sum+ans)%mod;
	}
	
	if(k==3)
	for(int i1=1;i1<=w[1];i1++)
	for(int i2=1;i2<=w[2];i2++)
	for(int i3=1;i3<=w[3];i3++)
	{
		x[1]=i1;
		x[2]=i2;
		x[3]=i3;
		ans=INT_MAX;
		deal(x);
		sum=(sum+ans)%mod;
	}
	
	if(k==4)
	for(int i1=1;i1<=w[1];i1++)
	for(int i2=1;i2<=w[2];i2++)
	for(int i3=1;i3<=w[3];i3++)
	for(int i4=1;i4<=w[4];i4++)
	{
		x[1]=i1;
		x[2]=i2;
		x[3]=i3;
		x[4]=i4;
		ans=INT_MAX;
		deal(x);
		sum=(sum+ans)%mod;
	}
	
	if(k==5)
	for(int i1=1;i1<=w[1];i1++)
	for(int i2=1;i2<=w[2];i2++)
	for(int i3=1;i3<=w[3];i3++)
	for(int i4=1;i4<=w[4];i4++)
	for(int i5=1;i5<=w[5];i5++)
	{
		ans=INT_MAX;
		x[1]=i1;
		x[2]=i2;
		x[3]=i3;
		x[4]=i4;
		x[5]=i5;
		deal(x);
		sum=(sum+ans)%mod;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
