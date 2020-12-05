#include <bits/stdc++.h>
using namespace std;
long long T,ans,a[2000000],stra[2000000][28],len,ans1;
char ch;
long long cm(long long x,long long y)
{
	long long mm;
	if(y==1)
	return x;
	mm=cm(x,y/2);
	if(y%2==0)
	return mm*mm;
	else return mm*mm*x;
}
bool check1(int ll1,int rr1,int ll2,int rr2)
{
	for (int i=1;i<=(rr1-ll1)+1;i++)
	{
		if(a[ll1+i-1]!=a[ll2+i-1])
		return 0;
	}
	return 1;
}
int check(long long ca,long long cd,long long bs)
{
	int f1,f2,fff;
	f1=0;
	f2=0;
	fff=cd*bs;
	if(!check1(1,cd,fff-cd+1,fff))
	return 2;
	if(fff>=len)
	return 2;
	for (int i=1;i<=26;i++)
	{
		if(stra[ca][i]%2==1)
		f1++;
		if((stra[len][i]-stra[fff][i])%2==1)
		f2++;
	}
	if(f1<=f2)
	return 1;
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&T);
	for (int p=1;p<=T;p++)
	{
		memset(a,0,sizeof(a));
		len=0;
		ch=getchar();
		while(ch<'a'||ch>'z')
		ch=getchar();
		while(ch>='a'&&ch<='z')
		{
			len++;
			a[len]=int(ch)-96;
			ch=getchar();
		}
		memset(stra,0,sizeof(stra));
		for (int i=1;i<=len;i++)
		{
			for (int j=1;j<=26;j++)
			{
				stra[i][j]=stra[i-1][j];
			}
			stra[i][a[i]]++;
		}
		ans=0;
		for (int ll=1;ll<=len-1;ll++)
		{
			for (int la=1;la<ll;la++)
			{
				for (int i=1;i<=((len-1)/ll);i++)
				{
					ans1=check(la,ll,i);
					if(ans1==2)
					break;
					if(ans1)
					{
						ans++;
//						cout<<la<<' '<<ll<<' '<<i<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
//		for (int i=1;i<=2;i++)
//		{
//			if(a[1+i]!=a[3+i])
//			cout<<440<<endl;
//		}
	}
	return 0;
}

