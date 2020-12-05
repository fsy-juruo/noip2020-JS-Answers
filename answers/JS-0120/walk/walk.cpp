#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL MOD=1e9+7;
LL ans;
LL n,k,cnt=1;
LL w[15],x[15],m[15];
LL dep[8];
LL read()
{
	LL s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool check(int num)
{
	for(int i=1;i<=num;i++)
	    if(dep[i]<1||dep[i]>w[i]) return false;
	return true;
}
void hhh1()
{
	for(LL i=1;i<=w[1];i++)
	{
	    LL t=i;
	    cnt=1;
	    while(t>=1&&t<=w[1])
	    {
	    	t+=m[cnt];
	    	ans=(ans+1)%MOD;
	        cnt++;
	        if(cnt>n) cnt-=n;
		}
	}
    cout<<ans<<endl;
}
void hhh2()
{
	for(LL a=1;a<=w[1];a++)
	for(LL b=1;b<=w[2];b++)
	{
		dep[1]=a,dep[2]=b;
		cnt=1;
		while(check(2))
		{
			dep[x[cnt]]+=m[cnt];
			ans=(ans+1)%MOD;
			cnt++;
			if(cnt>n) cnt-=n;
		}
	}
	cout<<ans<<endl;
}
void hhh3()
{
	for(LL a=1;a<=w[1];a++)
	for(LL b=1;b<=w[2];b++)
    for(LL c=1;c<=w[3];c++)
    {
    	dep[1]=a,dep[2]=b,dep[3]=c;
    	cnt=1;
    	while(check(3))
    	{
    		dep[x[cnt]]+=m[cnt];
    		ans=(ans+1)%MOD;
	        cnt++;
	        if(cnt>n) cnt-=n;
		}
	}
	cout<<ans<<endl;
}
void hhh4()
{
	for(LL a=1;a<=w[1];a++)
	for(LL b=1;b<=w[2];b++)
    for(LL c=1;c<=w[3];c++)
    for(LL d=1;d<=w[4];d++)
    {
    	dep[1]=a,dep[2]=b,dep[3]=c,dep[4]=d;
    	cnt=1;
    	while(check(4))
    	{
    		dep[x[cnt]]+=m[cnt];
    		ans=(ans+1)%MOD;
	        cnt++;
	        if(cnt>n) cnt-=n;
		}
	}
	cout<<ans<<endl;
}
void hhh5()
{
	for(LL a=1;a<=w[1];a++)
	for(LL b=1;b<=w[2];b++)
    for(LL c=1;c<=w[3];c++)
    for(LL d=1;d<=w[4];d++)
    for(LL e=1;e<=w[5];e++)
    {
    	dep[1]=a,dep[2]=b,dep[3]=c,dep[4]=d,dep[5]=e;
    	cnt=1;
    	while(check(5))
    	{
    		dep[x[cnt]]+=m[cnt];
    		ans=(ans+1)%MOD;
	        cnt++;
	        if(cnt>n) cnt-=n;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(LL i=1;i<=k;i++)
		w[i]=read();
	for(LL i=1;i<=n;i++)
		x[i]=read(),m[i]=read();
	if(k==1)
	    hhh1();
	if(k==2)
	    hhh2();
	if(k==3)
	    hhh3();
	if(k==4)
	    hhh4();
	if(k==5)
	    hhh5();
	return 0;
}
